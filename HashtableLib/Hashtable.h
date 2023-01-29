#pragma once


#include "Entry.h"
//#include <string> ^
//using std::string; ^
//#include <sstream>
//using std::stringstream;

class Hashtable
{
private:
	static const int Size = 26;
	class Entry m_Entries[Size];

public:
	Hashtable() = default;

private:
	int HashFunction_GetIndex(const string&) const;	//Hash Key for 26 slots

	bool Find(const string&, int*) const;

	int GetFreeIndex(const string& entryString) const;

	void Add(const string&);		//string_view,		prefer!

	void Delete(const string&);		//string_view,		prefer!

public:		// for test!

	void SetValues(const string&);

	const string Print() const;

};