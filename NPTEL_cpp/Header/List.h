#pragma once
#include <vector>
using namespace std;

template<class T>
class List
{
private:
	vector<T> items;
public:
	void put(const T& val) { items.push_back(val); }
	int length() { return items.size(); }
	bool find(const T& val) {
		for (unsigned int i = 0; i < length(); ++i)
			if (items[i] == val) return true;
		return false;
	}
};