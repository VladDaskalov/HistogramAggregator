#include "SingleFileAggregator.h"

SingleFileAggregator::SingleFileAggregator()
{
}

SingleFileAggregator::~SingleFileAggregator()
{
}

void SingleFileAggregator::addItem(string itemName, int quantity)
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

void SingleFileAggregator::aggregateData(string fileName)
{
	ifstream file;
	string sItem;
	int iQuantity;

	file.open(fileName.c_str(), ifstream::in);
	if (file.is_open())
	{
		while (file >> sItem >> iQuantity)
		{
			addItem(sItem, iQuantity);
		}
	}

	file.close();
}

void SingleFileAggregator::operator()(string fileName)
{
	aggregateData(fileName);
}

map<string, int> SingleFileAggregator::getItems()
{
	return m_Items;
}

void SingleFileAggregator::clear()
{
	m_Items.clear();
}
