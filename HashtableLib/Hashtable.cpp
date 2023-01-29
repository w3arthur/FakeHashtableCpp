#include "pch.h"
#include "Hashtable.h"


int Hashtable::HashFunction_GetIndex(const string& entryString) const
{
	return entryString.back() - 'a';	//entryString[entryString.size() - 1];//last char
	// 27 = a, ascii key
}

bool Hashtable::Find(const string& entryString, int* outIndex = nullptr) const
{
	int index = HashFunction_GetIndex(entryString);
	while (true)
	{
		if (m_Entries[index].Data == entryString)
		{
			if (outIndex) *outIndex = index;
			return true;
		}
		if (m_Entries[index].Status == "never used" || m_Entries[index].Status == "tombstone")
			return false;
		index = (index + 1) % Size;
	}
	return false;
}

int Hashtable::GetFreeIndex(const string& entryString) const
{
	int index = HashFunction_GetIndex(entryString);
	while (true)
	{
		//if (m_Entries[index].Data == entryString)
		//	return true;
		if (m_Entries[index].Status == "never used" || m_Entries[index].Status == "tombstone")
			return index;
		index = (index + 1) % Size;
	}
	return -1;
}

void Hashtable::Add(const string& entryString)
{
	const bool exists{ Find(entryString) };
	if (!exists)
	{
		int insertIndex = GetFreeIndex(entryString);
		m_Entries[insertIndex].Data = entryString;
		m_Entries[insertIndex].Status = "occupied";
	}
}

void Hashtable::Delete(const string& entryString)
{
	int index;
	const bool exists{ Find(entryString, &index) };
	if (exists)
		m_Entries[index].Status = "tombstone";
}

void Hashtable::SetValues(const string& input)
{

	stringstream ss(input);
	int i{};
	while (ss.good())
	{
		string token;
		ss >> token;

		string entryString = token.substr(1);		//&token[1];
		//cout << "token" << ++i << " (" << token << ")" << endl;

		if (token[0] == 'A')
		{
			//cout << "Add - " << entryString << endl;
			Add(entryString);
		}
		else if (token[0] == 'D')
		{
			//cout << "Delete - " << entryString << endl;
			Delete(entryString);
		}
	}
}

const string Hashtable::Print() const
{
	string str{ "" };
	char character{ 'a' };
	for (int i{}; i < Size; ++i)
	{
		//cout << character << " " << m_Entries[i].Data << "(" << m_Entries[i].Status << ")" << endl;
		if (m_Entries[i].Status == "occupied") { str += m_Entries[i].Data + " "; }
		++character;
	}
	str.pop_back(); //delete last char, instead "\b \b"
	cout << str << endl;
	return str;
}