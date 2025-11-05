#include<iostream>
#include "BoundedSet.h"
using namespace std;

int main()
{
	BoundedSet<int> bsi(3, 21);
	Set<int>* setptr = &bsi;

	for (unsigned int i = 0; i < 25; i++)
		setptr->add(i);
	if (bsi.find(4))
		cout << "We found an expected value\n";
	if (!bsi.find(0))
		cout << "We found NO unexpected value\n";
	if (!bsi.find(25))
		cout << "We found NO unexpected value\n";
	return 0;
}