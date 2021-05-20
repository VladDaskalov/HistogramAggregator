#include "GlobalAggregator.h"

GlobalAggregator::GlobalAggregator()
{
}

GlobalAggregator::~GlobalAggregator()
{
}

void GlobalAggregator::addItem(string itemName, int quantity)
{
	map<string, int>::iterator it;
	it = m_Items.find(itemName);

	if (it == m_Items.end()) //Item not existing -> add it
	{
		m_Items.insert(pair<string, int>(itemName, quantity));
	}
	else //Item already existing -> we increment the quantity with the new one
	{
		m_Items[it->first] = m_Items[it->first] + quantity;
	}
}

void GlobalAggregator::aggregateData(map<string, int> data)
{
	for (map<string, int>::iterator it = data.begin(); it != data.end(); ++it)
	{
		addItem(it->first, it->second);
	}
}

void GlobalAggregator::dumpData(string fileName)
{
	ofstream outFile;
	outFile.open(fileName.c_str(), std::ofstream::out | std::ofstream::trunc);

	if (outFile.is_open())
	{
		for (map<string, int>::iterator it = m_Items.begin(); it != m_Items.end(); ++it)
		{
			outFile << it->first;
			outFile << ' ';
			outFile << it->second;
			outFile << endl;
		}
	}

	outFile.close();
}
