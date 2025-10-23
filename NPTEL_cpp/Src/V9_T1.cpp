#include <iostream>
#include "QSolver.h"

int main()
{
	double a = 1, b = -2, c = 1, r1, r2;
	quadraticEquationSolver(a, b, c, r1, r2);
	std::cout << "Solution of " << a << "x^2 + " << b << "x + " << c << " is " << r1 << " and " << r2 << std::endl;
	return 0;
}