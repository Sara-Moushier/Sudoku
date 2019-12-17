#include "ReadFromFile.h"
#include <iostream>
#include <fstream>
using namespace std;
ReadFromFile::ReadFromFile()
{
	ifstream inputFile;
	inputFile.open("SudokuData.txt");
	if (!inputFile)		//alternative to file.fail()
	{
		cout << "Error in finding file" << endl;
		system("pause");
		exit(-1);
	}
	inputFile >> sizeOfBoard;
	if (!inputFile.eof())	// if not End Of File 
	{
		arrayBoard = new int*[sizeOfBoard];
		for (int i = 0; i < sizeOfBoard; i++)
		{
			arrayBoard[i] = new int[sizeOfBoard];
		}
		char x;
		for (int i = 0; i < sizeOfBoard; i++)
		{
			for (int j = 0; j < sizeOfBoard; j++)
			{

				inputFile >> x;
				if (x == '|')j--;
				else if (x == '-') arrayBoard[i][j] = -1; //empty space = -1 in the array
				else arrayBoard[i][j] = x - '0';
			}
		}
	}
	else
	{
		cout << "Error in reading board" << endl;
		system("pause");
		exit(-1);
	}
	/*
	//output 
	for (int i = 0; i < sizeOfBoard; i++)
	{
		for (int j = 0; j < sizeOfBoard; j++)
		{
			cout << arrayBoard[i][j]<<" ";
		}
		cout << endl;
	}
	*/
}
