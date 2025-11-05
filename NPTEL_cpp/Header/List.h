#pragma once
#include <vector>
using namespace std;

template<class T>
class List
{
private:
	vector<T> items;
public:
	void put(const T& val);
	int length();
	bool find(const T& val);
};

template<class T>
void List<T>::put(const T& val) { items.push_back(val); }

template<class T>
int List<T>::length() { return items.size(); }

template<class T>
bool List<T>::find(const T& val)
{
	for (unsigned int i = 0; i < length(); ++i)
		if (items[i] == val) return true;
	return false;
}