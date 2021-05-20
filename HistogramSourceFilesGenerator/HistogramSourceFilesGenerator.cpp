#include <string>
#include <time.h>
#include "Funtions.h"

int main()
{
	const string outFileName = "fileList.txt";
	const string subFileNamePrefix = "file";
	string subFileName;
	int numOfFiles, numOfItemsInFile;
	ofstream outFile;

	srand((long)time(NULL));

	cout << "How many files to prepare: ";
	cin >> numOfFiles;

	cout << "How many item to have in each file: ";
	cin >> numOfItemsInFile;

	outFile.open(outFileName.c_str());

	if (outFile.is_open())
	{

		for (int i = 0; i < numOfFiles; ++i)
		{
			subFileName = subFileNamePrefix + to_string(i) + ".txt";
			singleFileGenerator(subFileName, numOfItemsInFile);
			outFile << subFileName << endl;
		}
	}
	else
	{
		cout << "Problem: Unable to open output file";
	}

	outFile.close();
}