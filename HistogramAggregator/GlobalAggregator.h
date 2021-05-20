#pragma once
#include <fstream>
#include <map>

using namespace std;

/// <summary>
/// Class that aggregates the results gathered from Single File Aggregator class
/// </summary>
class GlobalAggregator
{
private:
	map<string, int> m_Items;

public:
	GlobalAggregator();
	~GlobalAggregator();

	void addItem(string itemName, int quantity);
	void aggregateData(map<string,int> data);
	void dumpData(string fileName);
};

