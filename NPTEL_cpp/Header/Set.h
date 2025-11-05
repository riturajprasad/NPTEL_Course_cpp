#pragma once
#include  "List.h"

template<class T>
class Set
{
private:
	List<T> lists;
public:
	Set() {}
	virtual ~Set() {}
	virtual void add(const T& val) {
		if (lists.find(val)) return;
		lists.put(val);
	}
	int length() { return lists.length(); }
	bool find(const T& val) { return lists.find(val); }
};