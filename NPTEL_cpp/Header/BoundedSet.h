#pragma once
#include "Set.h"

template<class T>
class BoundedSet : public Set<T>
{
private:
	T min;
	T max;
public:
	BoundedSet(const T& lower, const T& upper) : min(lower), max(upper) {}
	void add(const T& val) {
		if (Set<T>::find(val)) return;
		if ((val <= max) && (val >= min))
			Set<T>::add(val);
	}
};