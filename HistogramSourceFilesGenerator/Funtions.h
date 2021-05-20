#pragma once
#include <iostream>
#include <fstream>

using namespace std;
/// <summary>
/// Pseudo random number generator
/// </summary>
/// <param name="size">Range of numbers that must be generated</param>
/// <returns>Randomly generated number</returns>
int randomNumberGenerator(const int size)
{
	if (size <= 0)
	{
		return 0;
	}
	else
	{
		return rand() % size + 1;
	}
}

/// <summary>
/// Function to generate text files with specific number of items, each having random amount
/// </summary>
/// <param name="filename">The name of the file</param>
/// <param name="numOfItemsInFile">Number of items that the file should contain</param>
void singleFileGenerator(string filename, int numOfItemsInFile)
{
	string strArr[] = { "item1", "item2", "item3", "item4", "item5", "item6", "item7", "item8", "item9", "item10" };
	int strArrSize = sizeof(strArr) / sizeof(strArr[0]);

	ofstream outFile;
	outFile.open(filename.c_str(), std::ofstream::out | std::ofstream::trunc);

	if (outFile.is_open())
	{
		for (int i = 0; i < numOfItemsInFile; ++i)
		{
			outFile << strArr[randomNumberGenerator(strArrSize - 1)];
			outFile << ' ';
			outFile << randomNumberGenerator(100);
			outFile << endl;
		}
	}
	else
	{
		cout << "Problem: Unable to open subFile: " + filename;
	}

	outFile.close();
}
