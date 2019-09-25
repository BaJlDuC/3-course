#include "pch.h"
#include <iostream>
#include <string>
#include "triangleFunctions.h"

using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "");
	string a = "", b = "", c = "";
	if (checkNumberOfArguments(argc) != "Не треугольник")
	{
		a = argv[1];
		b = argv[2];
		c = argv[3];
		definitionType(a, b, c);
	}

	return 0;
}
