//Visual Studio 17, Садовин Владислав
//В автомате Мура, если у какой либо вершины отсутствует у, то писать у-
#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

const string MOORE_VERTEX_CHAR = "q";
const string MEALY_VERTEX_CHAR = "Z";

int main()
{
	int inputCharsCount = 0, outputCharsCount = 0, vertexCount = 0;
	string inputChar = "", outputChar = "", vertexValue = "", automat = "";

	ifstream inputFile("inputFile.txt");
	ofstream outputAutomat("outputAutomat.txt");

	inputFile >> inputCharsCount >> outputCharsCount >> vertexCount >> automat;

	string** outputTable = new string*[inputCharsCount]; //создаем таблицу вывода
	for (int i = 0; i < inputCharsCount; i++)
	{
		outputTable[i] = new string[vertexCount];
	}

	map<string, string> states;
	map<string, string>::iterator it = states.begin();

	if (automat == "moore")
	{
		cout << "automat: moore" << endl; //добавляем вершины без выходных символов
		for (int i = 0; i < vertexCount; i++)
		{
			vertexValue = MOORE_VERTEX_CHAR;
			vertexValue += to_string(i);
			states.insert(make_pair(vertexValue, ""));
		}

		for (int i = 0; i < vertexCount; i++, it++) // добавляем выходные символы к вершинам
		{
			inputFile >> outputChar;
			it->second = outputChar;
		}

		for (int i = 0; i < inputCharsCount; i++) //заполняем выход
		{
			for (int j = 0; j < vertexCount; j++)
			{
				inputFile >> inputChar;
				it = states.find(inputChar);
				outputTable[i][j] = it->first + it->second;
				outputAutomat << outputTable[i][j] << ' ';
			}
			outputAutomat << endl;
		}
	}
	else if ("mealy")
	{
		cout << "automat: mealy" << endl;

		for (int i = 0; i < inputCharsCount; i++) //заполняем таблицу c исходными состояниями (Мили)
		{
			for (int j = 0; j < vertexCount; j++)
			{
				inputFile >> vertexValue;
				outputTable[i][j] = vertexValue;
			}
		}

		int newValue = 0;
		for (int i = 0; i < inputCharsCount; i++)
		{
			for (int j = 0; j < vertexCount; j++)
			{
				it = states.find(outputTable[i][j]);
				if (it == states.end())
				{
					states.insert(make_pair(outputTable[i][j], MEALY_VERTEX_CHAR + to_string(newValue)));
					outputTable[i][j] = MEALY_VERTEX_CHAR + to_string(newValue);
					newValue++;
				}
				else
				{
					outputTable[i][j] = it->second;
				}
			}
		}

		for (int i = 0; i < inputCharsCount; i++)
		{
			for (int j = 0; j < vertexCount; j++)
			{
				outputAutomat << outputTable[i][j] << ' ';
			}
			outputAutomat << endl;
		}
	}
	else
	{
		outputAutomat << "Unknown automat" << endl;
	}
}