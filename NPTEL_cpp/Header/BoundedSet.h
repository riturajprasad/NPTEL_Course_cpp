#pragma once
#include "Set.h"

template<class T>
class BoundedSet : public Set<T>
{
private:
	T min;
	T max;
public:
	BoundedSet(const T& lower, const T& upper);
	void add(const T& val);
};

template<class T>
BoundedSet<T>::BoundedSet(const T& lower, const T& upper) : min(lower), max(upper) {}

template<class T>
void BoundedSet<T>::add(const T& val)
{
	if (Set<T>::find(val)) return;
	if ((val <= max) && (val >= min))
		Set<T>::add(val);
}