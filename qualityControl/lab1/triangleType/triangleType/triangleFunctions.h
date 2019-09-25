#pragma once
#include <iostream>
#include <string.h>

using namespace std;

const string NOT_TRIANGLE = "�� �����������";
const string UNKNOWN_ERROR = "����������� ������";
const string USUAL = "�������";
const string ISOSCELES = "��������������";
const string EQUILATERAL = "��������������";
const string SUCCESFULL = "�������";

string definitionType(string &a, string &b, string &c)
{
	int sideA = 0, sideB = 0, sideC = 0;
	string abc = a + b + c;

	for (int i = 0; i < abc.size(); i++)
	{
		if (!isdigit(abc[i]))
		{
			cout << UNKNOWN_ERROR << endl;
			return UNKNOWN_ERROR;
		}
	}
	try
	{
		sideA = stoi(a);
		sideB = stoi(b);
		sideC = stoi(c);
	}
	catch (out_of_range)
	{
		cout << UNKNOWN_ERROR << endl;
		return UNKNOWN_ERROR;
	}

	if ((sideA <= 0) || (sideB <= 0) || (sideC <= 0))
	{
		cout << NOT_TRIANGLE << endl;
		return NOT_TRIANGLE;
	}
	if ((sideA == sideB) && (sideA == sideC))
	{
		cout << EQUILATERAL << endl;
		return EQUILATERAL;
	}
	if ((sideA == sideB) || (sideA == sideC) || (sideB == sideC))
	{
		cout << ISOSCELES << endl;
		return ISOSCELES;
	}

	cout << USUAL << endl;
	return USUAL;
}

string checkNumberOfArguments(int quantity)
{
	if (quantity != 4)
	{
		cout << NOT_TRIANGLE << endl;
		return NOT_TRIANGLE;
	}

	return SUCCESFULL;
}