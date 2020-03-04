//3 программа по ТАиФЯ, Садовин Владислав, ПС-32 | Microsoft Visual Studio 2017
#include "pch.h"
#include "functions.h"

int main(int argc, char* argv[])
{
	NondetMachine nondetMachine = ReadNondetMachine(argv[1]);
	DetMachine detMachine = DetermineMachine(nondetMachine);
	PrintDetMachine(detMachine, argv[2]);
	CreateGraph(detMachine);
}