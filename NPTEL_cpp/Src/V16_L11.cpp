#include <iostream>
using namespace std;

class Complex {
public:
	double re;
	double im;
};

int main()
{
	Complex cx1 = { 2.2, 5.3 };
	cout << cx1.re << " + i(" << cx1.im <<")" << endl;
	return 0;
}