//#include "pch.h"
#include <iostream>
#include <fstream>
#define CATCH_CONFIG_MAIN
#include <../../catch.hpp>
#include "../triangleType/triangleFunctions.h"

TEST_CASE("case #1")
{
	setlocale(LC_ALL, "");
	int argumQuantity = 0;
	string message = "", a = "", b = "", c = "";
 
	ifstream testCases("testCases.txt");
 
	while (!testCases.eof())
	{
		testCases >> argumQuantity;
		if (argumQuantity != 4)
		{
			testCases.seekg(1, ios::cur);
			getline(testCases, message);
			CHECK((checkNumberOfArguments(argumQuantity) == message));
		}
		else
		{
			testCases >> a >> b >> c;
			testCases.seekg(1, ios::cur);
			getline(testCases, message);
			//CHECK((checkNumberOfArguments(argumQuantity) == "Успешно"));
			cout << a << ' ' << b << ' ' << c << endl;
			CHECK((definitionType(a, b, c) == message));
		}
	}
}