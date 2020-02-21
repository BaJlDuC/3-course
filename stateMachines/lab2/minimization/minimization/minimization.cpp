// minimization.cpp : 2 программа по ТАИФЯ
// Садовин Владислав, ПС-32 | Visual Studio 17
#include "pch.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include "vizualization.h"
#include "automatFunctions.h"

using namespace std;


int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Enter minimization.exe inputFile.txt outputFile.txt" << endl;
		return 0;
	}
	ifstream inputFile(argv[1]);
	ofstream outputFile(argv[2]);
	if (!inputFile)
	{
		cout << "Input file not found" << endl;
		return 0;
	}
	int inputAlphabetCount = 0, outputAlphabetCount = 0, vertexCount = 0;
	string automat = "";
	inputFile >> inputAlphabetCount >> outputAlphabetCount >> vertexCount >> automat;

	if (automat == "mealy")
	{
		mealyMachineHandler(inputFile, outputFile, inputAlphabetCount, vertexCount);
	}
	else if (automat == "moore")
	{
		//doing something... later
	}
	else
	{
		cout << "Unknown automat. Try again" << endl;
	}

}
