// FakeHashtable.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include <iostream>
//#include "../HashtableLib/pch.h"
#include <pch.h>

#include <HashTable.h>

//credits to https://www.youtube.com/watch?v=kQsHF7C-FUY

int main(int argc, char* argv[])
{
	std::cout << "Hello World!\n";

	std::stringstream ss;
	string str;
	for (size_t i{ 1 }; i < argc; ++i)
	{
		str = str + static_cast<string>(argv[i]) + " ";
	}

	const string input{ str };


	//const string input{ "Aapple Aorange Dapple Agrape Asttrawberry" };


	HashTable hashTable;

	hashTable.SetValues(input);

	hashTable.Print();


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
