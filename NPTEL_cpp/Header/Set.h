#pragma once
#include  "List.h"

template<class T>
class Set
{
private:
	List<T> lists;
public:
	Set();
	virtual ~Set();
	virtual void add(const T& val);
	int length();
	bool find(const T& val);
};

template<class T>
Set<T>::Set() {}

template<class T>
Set<T>::~Set() {}

template<class T>
void Set<T>::add(const T& val)
{
	if (lists.find(val)) return;
	lists.put(val);
}

template<class T>
int Set<T>::length() { return lists.length(); }

template<class T>
bool Set<T>::find(const T& val) { return lists.find(val); }