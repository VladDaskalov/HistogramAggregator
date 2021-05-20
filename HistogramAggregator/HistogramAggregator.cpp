// HistogramAggregator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "GlobalAggregator.h"
#include "SingleFileAggregator.h"

int main(int argc, char* argv[])
{
	string tmpFilename;
	ifstream inputFile;
	SingleFileAggregator sAggr;
	GlobalAggregator gAggr;
		
	inputFile.open(argv[1]);

	if (!inputFile.is_open())
	{
		cout << "Unable to open input file";
		return 1;
	}

	while (inputFile >> tmpFilename)
	{
		sAggr.aggregateData(tmpFilename);
		gAggr.aggregateData(sAggr.getItems());
		sAggr.clear();
	}

	inputFile.close();
	gAggr.dumpData(argv[2]);

	return 0;
}
