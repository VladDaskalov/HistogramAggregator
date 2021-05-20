#pragma once
#include <fstream>
#include <map>

using namespace std;

/// <summary>
/// Class to handle separate files which contains list of items
/// </summary>
class SingleFileAggregator
{
private:
	map<string, int> m_Items;
	
public:
	SingleFileAggregator();
	~SingleFileAggregator();

	void addItem(string itemName, int quantity);
	void aggregateData(string fileName);
	void operator () (string fileName);
	map<string, int> getItems();
	void clear();
};

