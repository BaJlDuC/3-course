// minimization.cpp : 2 программа по ТАИФЯ
// Садовин Владислав, ПС-32 | Visual Studio 17
#include "pch.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include "vizualization.h";

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
//--------------------------------------------------------------------------------------------------------

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
	string automat = "", state = "";

	inputFile >> inputAlphabetCount >> outputAlphabetCount >> vertexCount >> automat;

	if (automat == "mealy")
	{
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
		mealyAutomat.sourceGraph = graph;
	
		for (int i = 0; i < mealyAutomat.sourceGraph.size(); i++)
		{
			for (int j = 0; j < mealyAutomat.sourceGraph.at(i).size(); j++)
			{
				cout << mealyAutomat.sourceGraph.at(i).at(j) << ' ';
			}
			cout << endl;
		}
		cout << "new format" << endl;
		int classCount = 0;
		
		//-----------------------------------------------------------------------------------------------------------------------------------------
			for (int i = 0; i < mealyAutomat.graphWithOutSignals.at(0).size(); i++)
			{
				bool findClass = false;
				vector<string> signals;
				for (int j = 0; j < mealyAutomat.graphWithOutSignals.size(); j++)
				{
					cout << mealyAutomat.graphWithOutSignals.at(j).at(i) << ' ';
					signals.push_back(mealyAutomat.sourceGraph.at(j).at(i));
				}
				cout << endl;
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
					/*for (map<string, vector<vector<string>>>::iterator it = mealyAutomat.classes.begin(); it != mealyAutomat.classes.end(); it++)
					{*/
						//cout << "iterator cycle" << endl;
						for (int k = 0; k < it->second.size(); k++)
						{
							cout << it->second.size();
							/*cout << "| " << getSubVectorWithOutputSignals(signals, 1).at(0)
								<< ' ' << getSubVectorWithOutputSignals(signals, 1).at(1)
								<< ' ' << getSubVectorWithOutputSignals(signals, 1).at(2) << " | " << getSubVectorWithOutputSignals(it->second.at(k), 1).at(0)
								<< ' ' << getSubVectorWithOutputSignals(it->second.at(k), 1).at(1) << " "
								<< getSubVectorWithOutputSignals(it->second.at(k), 1).at(2) << " |" << endl;*/
							for (map<string, vector<vector<string>>>::iterator iter = mealyAutomat.classes.begin(); iter != mealyAutomat.classes.end(); iter++)
							{
								/*for (int n = 0; n < iter->second.at(0).size(); n++)
								{*/
									if (getSubVectorWithOutputSignals(signals, 1) == getSubVectorWithOutputSignals(iter->second.at(0), 1))//was it, not iter && was k, not n
									{
										findClass = true;
									}
							//	}
							}
						}
						if (findClass == false)
						{
							cout << "Create new class" << endl; //возможно вместе с выходными сигналами есть и вершины, поэтому всегда сюда
							vector<vector<string>> classes = { signals };
							mealyAutomat.classes.insert(make_pair(OUTPUT_STATE_CHAR + to_string(classCount), classes));
							classCount++;
						}
						else
						{
							cout << "Add in existing class" << endl;
							for (int l = 0; l <= classCount; l++)
							{
								map<string, vector<vector<string>>>::iterator search = mealyAutomat.classes.find(OUTPUT_STATE_CHAR + to_string(l));
								if (search != mealyAutomat.classes.end() && getSubVectorWithOutputSignals(search->second.at(0), 1) == getSubVectorWithOutputSignals(signals, 1))
								{
									cout << "find, good" << endl;
				                    //наилить процесс добавления
									search->second.push_back(signals);// work???
								}
							}
						}
				//	}
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
						cout << it->second.at(i).at(j).substr(0, 2) << ' ';
					}
					cout << endl;
				}
			}
			mealyAutomat.sumClasses = mealyAutomat.classes.size();
			
			//----------------------------------------разбиение на классы до последнего
			bool done = false;
			//classCount = 1;
			int addIndex;
			while (!done)
			{
				classCount = 0;
			    int index = 0;
				//int ifIndex = 1;
				vector<string> signals;
				for (map<string, vector<vector<string>>>::iterator iter = mealyAutomat.modifiedClasses.begin(); iter != mealyAutomat.modifiedClasses.end(); iter++, index++)
				{
					if (mealyAutomat.finalClasses.empty())
					{
						//bool find = false; 
						//vector<vector<string>> classes = { iter->second.at(0) };
						//mealyAutomat.finalClasses.insert(make_pair("B1", classes));
						//classCount++; //первое добавление есть
							for (int j = 0; j < iter->second.size(); j++)
							{
								bool find = false;
								cout << "FIRST ITER---------------" << endl;
								for (map<string, vector<vector<string>>>::iterator searchIter = mealyAutomat.finalClasses.begin(); searchIter != mealyAutomat.finalClasses.end(); searchIter++)
								{
									if (getSubVectorWithClassNames(iter->second.at(j), 1) == getSubVectorWithClassNames(searchIter->second.at(0), 1)) //iter-at-0 was
									{
										//добавляем в существующий класс
										searchIter->second.push_back(iter->second.at(j));
										find = true;
										cout << "--FIND" << endl;
										//signals = iter->second.at(i);
									}
								}
								if (!find)
								{
									vector<vector<string>> classes = { iter->second.at(j) }; // was ifIndex
									mealyAutomat.finalClasses.insert(make_pair(OUTPUT_STATE_CHAR + to_string(classCount), classes));
									classCount++;
									//ifIndex++;
								}
							}
							/*if (!find)
							{
								vector<vector<string>> classes = { iter->second.at(ifIndex) };
								mealyAutomat.finalClasses.insert(make_pair("B" + to_string(classCount), classes));
								classCount++;
								ifIndex++;
								
							}*/
					}
					else
					{
						cout << "DONT FIRST CYCLE" << endl;
						bool find = false;
						//for (map<string, vector<vector<string>>>::iterator searchIter = mealyAutomat.finalClasses.begin(); searchIter != mealyAutomat.finalClasses.end(); searchIter++)
						for (int i = 0; i < iter->second.size(); i++)
						{
							bool find = false;
							for (map<string, vector<vector<string>>>::iterator searchIter = mealyAutomat.finalClasses.begin(); searchIter != mealyAutomat.finalClasses.end(); searchIter++)
							{
								cout << getSubVectorWithClassNames(iter->second.at(i), 1).at(0) << " "
									<< getSubVectorWithClassNames(iter->second.at(i), 1).at(1) << " "
									<< getSubVectorWithClassNames(iter->second.at(i), 1).at(2) << " | "
									<< getSubVectorWithClassNames(searchIter->second.at(0), 1).at(0) << " "
									<< getSubVectorWithClassNames(searchIter->second.at(0), 1).at(1) << " "
									<< getSubVectorWithClassNames(searchIter->second.at(0), 1).at(2) << endl;
								if (getSubVectorWithClassNames(iter->second.at(i), 1) == getSubVectorWithClassNames(searchIter->second.at(0), 1)) //iter-at-0 was
								{
									//добавляем в существующий класс
									searchIter->second.push_back(iter->second.at(i));
									find = true;
									cout << "--FIND" << endl;
									//signals = iter->second.at(i);
								}
							}
							if (!find)
							{
								vector<vector<string>> classes = { iter->second.at(i) }; // was at var index
								mealyAutomat.finalClasses.insert(make_pair(OUTPUT_STATE_CHAR + to_string(classCount), classes));
								classCount++;
								//index++;
							}
						}

						for (map<string, vector<vector<string>>>::iterator it = mealyAutomat.finalClasses.begin(); it != mealyAutomat.finalClasses.end(); it++)
						{
							for (int i = 0; i < it->second.size(); i++)
							{
								for (int j = 0; j < mealyAutomat.sourceGraph.at(0).size(); j++)
								{
									//cout << "_______FIND " << it->second.at(i).at(0) << " and " << mealyAutomat.sourceGraph.at(0).at(j);
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
														cout << it->second.at(i).at(k) << " => " << iter->first << endl;
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
			//--------------------------------------------------------------------------------сверху готово, теперь убирание недостижимых вершин
			map<string, vector<vector<string>>>::iterator delUnreach = mealyAutomat.finalClasses.begin();
			vector<string> finalStates;
			for (int i = 1; i < delUnreach->second.at(0).size(); i++)
			{
				finalStates.push_back(delUnreach->second.at(0).at(i).substr(0, 2));
				cout << "START STATE " << delUnreach->second.at(0).at(i) << endl;
			}
			
			//bool end = false;
			for(map<string, vector<vector<string>>>::iterator it = mealyAutomat.finalClasses.begin(); it != mealyAutomat.finalClasses.end();)
			{
					bool del = true;
					for (int i = 0; i < finalStates.size(); i++)
					{
						if (it->first == finalStates.at(i))
						{
							del = false;
						}
					}
					if (it != mealyAutomat.finalClasses.begin() && del)
					{
						it = mealyAutomat.finalClasses.erase(it);
					}
					else
					{
						++it;
					}
			}
			//--------------------------------------------------------------------------------удаление работает(да), ниже подготовка к выводу
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
			//========================================================================================= ниже просто вывод
			map<string, vector<vector<string>>>::iterator iterForOut = mealyAutomat.classes.begin();
			for (int i = 0; iterForOut != mealyAutomat.classes.end(); i++, iterForOut++)
			{
				cout << i << ") Key " << iterForOut->first << ", values :" << endl;
				for (int j = 0; j < iterForOut->second.size(); j++)
				{
					for (int k = 0; k < iterForOut->second.at(0).size(); k++)
					{
						cout << "  " << iterForOut->second.at(j).at(k);
					}
					cout << endl;
				}
				cout << endl;
			}
			cout << "--------------------------------OTHER OUT----------------------------------" << endl;
			//---------------------------------------------------------------------вывод с названиями классов
			 iterForOut = mealyAutomat.modifiedClasses.begin();
			for (int i = 0; iterForOut != mealyAutomat.modifiedClasses.end(); i++, iterForOut++)
			{
				cout << i << ") Key " << iterForOut->first << ", values :" << endl;
				for (int j = 0; j < iterForOut->second.size(); j++)
				{
					for (int k = 0; k < iterForOut->second.at(0).size(); k++)
					{
						cout << "  " << iterForOut->second.at(j).at(k);
					}
					cout << endl;
				}
				cout << endl;
			}

			//---------------------------------------------------------------------вывод с названиями классов, 2 этап
			cout << "----------more info---------" << endl;
			iterForOut = mealyAutomat.finalClasses.begin();
			for (int i = 0; iterForOut != mealyAutomat.finalClasses.end(); i++, iterForOut++)
			{
				cout << i << ") Key " << iterForOut->first << ", values :" << endl;
				for (int j = 0; j < iterForOut->second.size(); j++)
				{
					for (int k = 0; k < iterForOut->second.at(0).size(); k++)
					{
						cout << "  " << iterForOut->second.at(j).at(k);
					}
					cout << endl;
				}
				cout << endl;
			}

			cout << "print source graph: " << endl;
			for (int i = 0; i < mealyAutomat.sourceGraph.at(0).size(); i++)
			{
				for (int j = 0; j < mealyAutomat.sourceGraph.size(); j++)
				{
					cout << mealyAutomat.sourceGraph.at(j).at(i) << ' ';
				}
				cout << endl;
			}
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
