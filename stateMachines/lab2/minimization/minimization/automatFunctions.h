#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>

using namespace std;

const string OUTPUT_STATE_CHAR = "A";
//-------------------------------------------mealy
class MealyAutomat
{
public:
	int sumClasses;
	vector<vector<string>> sourceGraph;
	vector<vector<string>> graphWithOutSignals;
	map<string, vector<vector<string>>> classes;
	map<string, vector<vector<string>>> sourceClasses;
	map<string, vector<vector<string>>> modifiedClasses;
	map<string, vector<vector<string>>> finalClasses;
	vector<vector<string>> finalOutput;
};

class MooreAutomat
{
public:
	vector<vector<string>> sourceGraph;
	map<string, vector<vector<string>>> classes;
	map<string, vector<vector<string>>> finalClasses;
	vector<vector<string>> output;
};

vector<string> getSubVectorWithOutputSignals(vector<string> sourceVector, int begIndex)
{
	vector<string> result = {};
	for (int i = begIndex; i < sourceVector.size(); i++)
	{
		result.push_back(sourceVector.at(i).substr(2));
	}

	return result;
}

vector<string> getSubVectorWithClassNames(vector<string> sourceVector, int begIndex)
{
	vector<string> result = {};
	for (int i = begIndex; i < sourceVector.size(); i++)
	{
		result.push_back(sourceVector.at(i));
	}

	return result;
}

void mealyMachineHandler(ifstream &inputFile, ofstream &outputFile, int inputAlphabetCount, int vertexCount)
{
	string state = "";
	MealyAutomat mealyAutomat;
	vector<vector<string>> graph;
	for (int i = 0; i < inputAlphabetCount + 1; i++)
	{
		graph.push_back({});
		mealyAutomat.graphWithOutSignals.push_back({});
		for (int j = 0; j < vertexCount; j++)
		{
			if (i != 0)
			{
				inputFile >> state;
				graph.at(i).push_back(state);
				mealyAutomat.graphWithOutSignals.at(i).push_back(state.substr(2));
			}
			else
			{
				mealyAutomat.graphWithOutSignals.at(i).push_back("q" + to_string(j));
				graph.at(i).push_back("q" + to_string(j));
			}
		}
	}

	//удаление недостижимых вершин
	vector<string> sourceGraphLineWithoutUnreachable;

	bool endDeleting = false;
	while (!endDeleting)
	{
		if (sourceGraphLineWithoutUnreachable.empty())
		{
			for (int i = 0; i < graph.size(); i++)
			{
				string element = graph.at(i).at(0).substr(0, 2);
				vector<string>::iterator search = find(sourceGraphLineWithoutUnreachable.begin(), sourceGraphLineWithoutUnreachable.end(), element);
				if (search == sourceGraphLineWithoutUnreachable.end())
				{
					sourceGraphLineWithoutUnreachable.push_back(graph.at(i).at(0).substr(0, 2));
				}
			}
		}
		else
		{
			for (int i = 1; i < sourceGraphLineWithoutUnreachable.size(); i++)
			{
				for (int j = 1; j < graph.size(); j++)
				{
					string element = graph.at(j).at(stoi(sourceGraphLineWithoutUnreachable.at(i).substr(1, 2))).substr(0, 2);
					vector<string>::iterator it = find(sourceGraphLineWithoutUnreachable.begin(), sourceGraphLineWithoutUnreachable.end(), element);
					if (it == sourceGraphLineWithoutUnreachable.end())
					{
						sourceGraphLineWithoutUnreachable.push_back(element);
					}
				}
			}
			endDeleting = true;
		}
	}

	//само удаление
	for (int i = 0; i < graph.at(0).size(); i++)
	{
		bool find = false;
		for (int j = 0; j < sourceGraphLineWithoutUnreachable.size(); j++)
		{
			if (graph.at(0).at(i).substr(0, 2) == sourceGraphLineWithoutUnreachable.at(j))
			{
				find = true;
			}
		}

		if (!find)
		{
			for (int k = 0; k < inputAlphabetCount + 1; k++)
			{
				vector<string>::iterator delElement = graph.at(k).begin();
				graph.at(k).erase(delElement + i);
			}
			i--;
		}
	}
	sort(sourceGraphLineWithoutUnreachable.begin(), sourceGraphLineWithoutUnreachable.end());

	for (int i = 0; i < graph.at(0).size(); i++)
	{
		graph.at(0).at(i) = sourceGraphLineWithoutUnreachable.at(i);
	}
	//----------------------------
	mealyAutomat.sourceGraph = graph;
	int classCount = 0;

	//-----------------------------------------------------------------------------------------------------------------------------------------
	for (int i = 0; i < mealyAutomat.sourceGraph.at(0).size(); i++) //was ...withOutSignals
	{
		bool findClass = false;
		vector<string> signals;
		for (int j = 0; j < mealyAutomat.sourceGraph.size(); j++)
		{
			signals.push_back(mealyAutomat.sourceGraph.at(j).at(i));
		}
		//
		map<string, vector<vector<string>>>::iterator it = mealyAutomat.classes.begin(); //сделать цикл
		if (i == 0)
		{
			vector<vector<string>> classes = { signals };
			mealyAutomat.classes.insert(make_pair(OUTPUT_STATE_CHAR + to_string(classCount), classes));
			classCount++;
		}
		else
		{
			for (int k = 0; k < it->second.size(); k++)
			{
				for (map<string, vector<vector<string>>>::iterator iter = mealyAutomat.classes.begin(); iter != mealyAutomat.classes.end(); iter++)
				{
					if (getSubVectorWithOutputSignals(signals, 1) == getSubVectorWithOutputSignals(iter->second.at(0), 1))//was it, not iter && was k, not n
					{
						findClass = true;
					}
				}
			}
			if (findClass == false)
			{
				vector<vector<string>> classes = { signals };
				mealyAutomat.classes.insert(make_pair(OUTPUT_STATE_CHAR + to_string(classCount), classes));
				classCount++;
			}
			else
			{
				for (int l = 0; l <= classCount; l++)
				{
					map<string, vector<vector<string>>>::iterator search = mealyAutomat.classes.find(OUTPUT_STATE_CHAR + to_string(l));
					if (search != mealyAutomat.classes.end() && getSubVectorWithOutputSignals(search->second.at(0), 1) == getSubVectorWithOutputSignals(signals, 1))
					{
						search->second.push_back(signals);// work???
					}
				}
			}
		}
	}
	//--------------------------------------------------------------------------------------первый этап разбиения на классы экивалентности работает

	//=======================================================================================присвоение имени класса вершинам
	mealyAutomat.modifiedClasses = mealyAutomat.classes;
	mealyAutomat.sourceClasses = mealyAutomat.classes;
	for (map<string, vector<vector<string>>>::iterator it = mealyAutomat.modifiedClasses.begin(); it != mealyAutomat.modifiedClasses.end(); it++)
	{
		for (int i = 0; i < it->second.size(); i++)
		{
			for (int j = 1; j < it->second.at(0).size(); j++)
			{
				for (map<string, vector<vector<string>>>::iterator iter = mealyAutomat.modifiedClasses.begin(); iter != mealyAutomat.modifiedClasses.end(); iter++)
				{
					for (int k = 0; k < iter->second.size(); k++)
					{
						if (it->second.at(i).at(j).substr(0, 2) == iter->second.at(k).at(0).substr(0, 2))
						{
							it->second.at(i).at(j) = iter->first;
						}
					}
				}
			}
		}
	}
	mealyAutomat.sumClasses = mealyAutomat.classes.size();

	//----------------------------------------разбиение на классы до последнего
	bool done = false;
	while (!done)
	{
		classCount = 0;
		int index = 0;
		vector<string> signals;
		for (map<string, vector<vector<string>>>::iterator iter = mealyAutomat.modifiedClasses.begin(); iter != mealyAutomat.modifiedClasses.end(); iter++, index++)
		{
			if (mealyAutomat.finalClasses.empty())
			{
				for (int j = 0; j < iter->second.size(); j++)
				{
					bool find = false;
					for (map<string, vector<vector<string>>>::iterator searchIter = mealyAutomat.finalClasses.begin(); searchIter != mealyAutomat.finalClasses.end(); searchIter++)
					{
						if (getSubVectorWithClassNames(iter->second.at(j), 1) == getSubVectorWithClassNames(searchIter->second.at(0), 1) && j != 0) //iter-at-0 was
						{
							searchIter->second.push_back(iter->second.at(j));
							find = true;
						}
					}
					if (!find)
					{
						vector<vector<string>> classes = { iter->second.at(j) }; // was ifIndex
						mealyAutomat.finalClasses.insert(make_pair(OUTPUT_STATE_CHAR + to_string(classCount), classes));
						classCount++;
					}
				}
			}
			else
			{
				bool find = false;
				for (int i = 0; i < iter->second.size(); i++)
				{
					bool find = false;
					for (map<string, vector<vector<string>>>::iterator searchIter = mealyAutomat.finalClasses.begin(); searchIter != mealyAutomat.finalClasses.end(); searchIter++)
					{
						if (getSubVectorWithClassNames(iter->second.at(i), 1) == getSubVectorWithClassNames(searchIter->second.at(0), 1) && i != 0) //iter-at-0 was
						{
							searchIter->second.push_back(iter->second.at(i));
							find = true;
						}
					}
					if (!find)
					{
						vector<vector<string>> classes = { iter->second.at(i) }; // was at var index
						mealyAutomat.finalClasses.insert(make_pair(OUTPUT_STATE_CHAR + to_string(classCount), classes));
						classCount++;
					}
				}

				for (map<string, vector<vector<string>>>::iterator it = mealyAutomat.finalClasses.begin(); it != mealyAutomat.finalClasses.end(); it++)
				{
					for (int i = 0; i < it->second.size(); i++)
					{
						for (int j = 0; j < mealyAutomat.sourceGraph.at(0).size(); j++)
						{
							if (it->second.at(i).at(0) == mealyAutomat.sourceGraph.at(0).at(j))
							{
								for (int k = 1; k < mealyAutomat.sourceGraph.size(); k++)
								{
									for (map<string, vector<vector<string>>>::iterator iter = mealyAutomat.finalClasses.begin(); iter != mealyAutomat.finalClasses.end(); iter++)
									{
										for (int l = 0; l < iter->second.size(); l++)
										{
											if (mealyAutomat.sourceGraph.at(k).at(j).substr(0, 2) == iter->second.at(l).at(0))
											{
												it->second.at(i).at(k) = iter->first + mealyAutomat.sourceGraph.at(k).at(j).substr(2);
											}
										}
									}

								}
							}
						}
					}
				}

			}
		}
		if (mealyAutomat.finalClasses.size() == mealyAutomat.modifiedClasses.size())
		{
			done = true;
		}
		else
		{
			mealyAutomat.modifiedClasses = mealyAutomat.finalClasses;
			mealyAutomat.finalClasses.clear();
		}
	}

	//--------------------------------------------------------------------------------ниже подготовка к выводу
	for (map<string, vector<vector<string>>>::iterator it = mealyAutomat.finalClasses.begin(); it != mealyAutomat.finalClasses.end(); it++)
	{
		mealyAutomat.finalOutput.push_back(it->second.at(0));
	}
	for (int i = 1; i < mealyAutomat.finalOutput.at(0).size(); i++)
	{
		for (int j = 0; j < mealyAutomat.finalOutput.size(); j++)
		{
			outputFile << mealyAutomat.finalOutput.at(j).at(i) << ' ';
		}
		outputFile << endl;
	}
	MealyMachine mealyMachine;
	mealyMachine.graph = mealyAutomat.finalOutput;
	CreateMealyGraph(mealyMachine);
	cout << "mealy: done" << endl;
}
void mooreMachineHandler(ifstream &inputFile, ofstream &outputFile, int inputAlphabetCount, int vertexCount)
{
	int classCount = 0;
	string state = "";
	MooreAutomat mooreAutomat;
	vector<vector<string>> sourceGraph;

	for (int i = 0; i < inputAlphabetCount + 2; i++)
	{
		sourceGraph.push_back({});
		for (int j = 0; j < vertexCount; j++)
		{
			if (i == 0)
			{
				sourceGraph.at(i).push_back("q" + to_string(j));
			}
			else
			{
				inputFile >> state;
				sourceGraph.at(i).push_back(state);
			}
		}
	}
	//удаление недостижимых вершин
	vector<string> sourceGraphLineWithoutUnreachable;

	bool endDeleting = false;
	while (!endDeleting)
	{
		if (sourceGraphLineWithoutUnreachable.empty())
		{
			for (int i = 0; i < sourceGraph.size(); i++)
			{
				string element = sourceGraph.at(i).at(0);
				vector<string>::iterator search = find(sourceGraphLineWithoutUnreachable.begin(), sourceGraphLineWithoutUnreachable.end(), element);
				if (i != 1 || search == sourceGraphLineWithoutUnreachable.end())
				{
					sourceGraphLineWithoutUnreachable.push_back(sourceGraph.at(i).at(0));
				}
			}
		}
		else
		{
			for (int i = 1; i < sourceGraphLineWithoutUnreachable.size(); i++)
			{
				for (int j = 2; j < sourceGraph.size(); j++)
				{
					string element = sourceGraph.at(j).at(stoi(sourceGraphLineWithoutUnreachable.at(i).substr(1)));
					vector<string>::iterator it = find(sourceGraphLineWithoutUnreachable.begin(), sourceGraphLineWithoutUnreachable.end(), element);
					if (it == sourceGraphLineWithoutUnreachable.end())
					{
						sourceGraphLineWithoutUnreachable.push_back(element);
					}
				}
			}
			endDeleting = true;
		}
	}

	//само удаление
	for (int i = 0; i < sourceGraph.at(0).size(); i++)
	{
		bool find = false;
		for (int j = 0; j < sourceGraphLineWithoutUnreachable.size(); j++)
		{
			if (sourceGraph.at(0).at(i) == sourceGraphLineWithoutUnreachable.at(j))
			{
				find = true;
			}
		}
	
		if (!find)
		{
			for (int k = 0; k < inputAlphabetCount + 2; k++)
			{
				vector<string>::iterator delElement = sourceGraph.at(k).begin();
				sourceGraph.at(k).erase(delElement + i);
			}
			i--;
		}
	}
	sort(sourceGraphLineWithoutUnreachable.begin(), sourceGraphLineWithoutUnreachable.end());

	for (int i = 0; i < sourceGraph.at(0).size(); i++)
	{
		sourceGraph.at(0).at(i) = sourceGraphLineWithoutUnreachable.at(i);
	}

	mooreAutomat.sourceGraph = sourceGraph;
	//1 разбиение
	for (int i = 0; i < mooreAutomat.sourceGraph.at(0).size(); i++)
	{
		vector<string> verticalElements;
		for (int j = 0; j < mooreAutomat.sourceGraph.size(); j++)
		{
			verticalElements.push_back(mooreAutomat.sourceGraph.at(j).at(i));
		}

		if (mooreAutomat.classes.empty())
		{
			vector<vector<string>> classes = { verticalElements };
			mooreAutomat.classes.insert(make_pair(OUTPUT_STATE_CHAR + to_string(classCount), classes));
			classCount++;
		}
		else
		{
			bool find = false;
			map<string, vector<vector<string>>>::iterator finded;
			for (map<string, vector<vector<string>>>::iterator it = mooreAutomat.classes.begin(); it != mooreAutomat.classes.end(); it++)
			{
				if (it->second.at(0).at(1) == verticalElements.at(1))
				{
					find = true;
					finded = it;
				}
			}
			if (find)
			{
				finded->second.push_back(verticalElements);
			}
			else
			{
				vector<vector<string>> classes = { verticalElements };
				mooreAutomat.classes.insert(make_pair(OUTPUT_STATE_CHAR + to_string(classCount), classes));
				classCount++;
			}
		}
	}

	//присвоение имени классов вершинам
	for (map<string, vector<vector<string>>>::iterator it = mooreAutomat.classes.begin(); it != mooreAutomat.classes.end(); it++)
	{
		for (int i = 0; i < it->second.size(); i++)
		{
			for (int j = 1; j < it->second.at(0).size(); j++)
			{
				for (map<string, vector<vector<string>>>::iterator iter = mooreAutomat.classes.begin(); iter != mooreAutomat.classes.end(); iter++)
				{
					for (int k = 0; k < iter->second.size(); k++)
					{
						if (it->second.at(i).at(j) == iter->second.at(k).at(0))
						{
							it->second.at(i).at(j) = iter->first;
						}
					}
				}
			}
		}
	}
	//разбиение до последнего

	bool done = false;
	while (!done)
	{
		classCount = 0;
		int index = 0;
		vector<string> signals;
		for (map<string, vector<vector<string>>>::iterator iter = mooreAutomat.classes.begin(); iter != mooreAutomat.classes.end(); iter++, index++)
		{
			if (mooreAutomat.finalClasses.empty())
			{
				for (int j = 0; j < iter->second.size(); j++)
				{
					bool find = false;
					for (map<string, vector<vector<string>>>::iterator searchIter = mooreAutomat.finalClasses.begin(); searchIter != mooreAutomat.finalClasses.end(); searchIter++)
					{
						if (getSubVectorWithClassNames(iter->second.at(j), 2) == getSubVectorWithClassNames(searchIter->second.at(0), 2) && j != 0) //iter-at-0 was
						{
							searchIter->second.push_back(iter->second.at(j));
							find = true;
						}
					}
					if (!find)
					{
						vector<vector<string>> classes = { iter->second.at(j) }; // was ifIndex
						mooreAutomat.finalClasses.insert(make_pair(OUTPUT_STATE_CHAR + to_string(classCount), classes));
						classCount++;
					}
				}
			}
			else
			{
				bool find = false;
				for (int i = 0; i < iter->second.size(); i++)
				{
					bool find = false;
					for (map<string, vector<vector<string>>>::iterator searchIter = mooreAutomat.finalClasses.begin(); searchIter != mooreAutomat.finalClasses.end(); searchIter++)
					{
						if (getSubVectorWithClassNames(iter->second.at(i), 2) == getSubVectorWithClassNames(searchIter->second.at(0), 2) && i != 0) //iter-at-0 was
						{
							searchIter->second.push_back(iter->second.at(i));
							find = true;
						}
					}
					if (!find)
					{
						vector<vector<string>> classes = { iter->second.at(i) }; // was at var index
						mooreAutomat.finalClasses.insert(make_pair(OUTPUT_STATE_CHAR + to_string(classCount), classes));
						classCount++;
					}
				}

				for (map<string, vector<vector<string>>>::iterator it = mooreAutomat.finalClasses.begin(); it != mooreAutomat.finalClasses.end(); it++)
				{
					for (int i = 0; i < it->second.size(); i++)
					{
						for (int j = 0; j < mooreAutomat.sourceGraph.at(0).size(); j++)
						{
							if (it->second.at(i).at(0) == mooreAutomat.sourceGraph.at(0).at(j))
							{
								for (int k = 2; k < mooreAutomat.sourceGraph.size(); k++)
								{
									for (map<string, vector<vector<string>>>::iterator iter = mooreAutomat.finalClasses.begin(); iter != mooreAutomat.finalClasses.end(); iter++)
									{
										for (int l = 0; l < iter->second.size(); l++)
										{
											if (mooreAutomat.sourceGraph.at(k).at(j) == iter->second.at(l).at(0))
											{
												it->second.at(i).at(k) = iter->first;// + mooreAutomat.sourceGraph.at(k).at(j);
											}
										}
									}

								}
							}
						}
					}
				}

			}
		}
		if (mooreAutomat.finalClasses.size() == mooreAutomat.classes.size())
		{
			done = true;
		}
		else
		{
			mooreAutomat.classes = mooreAutomat.finalClasses;
			mooreAutomat.finalClasses.clear();
		}
	}
	
	//подготовка к выводу и вывод
	for (map<string, vector<vector<string>>>::iterator it = mooreAutomat.finalClasses.begin(); it != mooreAutomat.finalClasses.end(); it++)
	{
		mooreAutomat.output.push_back(it->second.at(0));
	}

	for (int i = 1; i < mooreAutomat.output.at(0).size(); i++)
	{
		for (int j = 0; j < mooreAutomat.output.size(); j++)
		{
			outputFile << mooreAutomat.output.at(j).at(i) << ' ';
		}
		outputFile << endl;
	}
	//out------------------------------------------------
	MooreMachine mooreMachine;
	mooreMachine.graph = mooreAutomat.output;

	CreateMooreGraph(mooreMachine);
	cout << "moore: done" << endl;
}