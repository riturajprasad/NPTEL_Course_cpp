#include <iostream>
#include "FractionNo.h"
using namespace std;

int main()
{
	/*
	cout << "Construction, copy Oprations and Write Test" << endl;
	Fraction f1(7, 3); cout << "Fraction f1(7, 3) = " << f1 << endl;
	Fraction f2(7); cout << "Fraction f2(7) = " << f2 << endl;
	Fraction f3; cout << "Fraction f3 = " << f3 << endl;
	Fraction f4(f1); cout << "Fraction f4(f1) = " << f4 << endl;
	Fraction f5(3, 6); cout << "Fraction f5(3, 6) = " << f5 << endl;
	Fraction f6(0, 6); cout << "Fraction f6(0, 6) = " << f6 << endl;
	cout << "Assignment: f2 = f1: f2 = " << (f2 = f1) << endl << endl;

	cout << "Read Test" << endl;
	cin >> f1; cout << "Read f1 = " << f1 << endl << endl;

	f1 = Fraction(2, 5); f2 = f1;
	cout << "Unary OPs Test: Using f1 = " << f1 << " for all" << endl;
	cout << "Nagate: -f1 = " << -f1 << endl;
	cout << "Preserve: +f1 = " << +f1 << endl;
	cout << "Componendo: ++f1 = " << ++f1 << endl; f1 = f2;
	cout << "Dividendo: --f1 = " << --f1 << endl; f1 = f2;
	cout << "Lazy Componendo: f1++ = " << f1++ << endl; f1 = f2;
	cout << "Lazy Dividendo: f1-- = " << f1-- << endl<< endl;

	f1 = Fraction(5, 12); f2 = Fraction(7, 18);

	// Binary Operations Test
	cout << "Binary OPs Test: Using f1 = " << f1 << " f2 = " << f2 << " for all" << endl;
	cout << "Binary +: f1 + f2 = " << (f1 + f2) << endl;
	cout << "Binary -: f1 - f2 = " << (f1 - f2) << endl;
	cout << "Binary x: f1 * f2 = " << (f1 * f2) << endl;
	cout << "Binary /: f1 / f2 = " << (f1 / f2) << endl;
	cout << "Binary %: f1 % f2 = " << (f1 % f2) << endl << endl;

	f3 = f1;
	// Binary Assignment Operations Test
	cout << "Binary Assignment OPs Test: Using f1 = " << f1 << " f2 = " << f2 << " for all" << endl;
	cout << "+ Assign: f1 += f2 = " << (f1 += f2) << endl; f1 = f3;
	cout << "- Assign: f1 -= f2 = " << (f1 -= f2) << endl; f1 = f3;
	cout << "x Assign: f1 *= f2 = " << (f1 *= f2) << endl; f1 = f3;
	cout << "/ Assign: f1 /= f2 = " << (f1 /= f2) << endl; f1 = f3;
	cout << "% Assign: f1 %= f2 = " << (f1 %= f2) << endl << endl; f1 = f3;

	// Logical Operations Test
	cout << "Logical OPs Test: Using f1 = " << f1 << " f2 = " << f2 << " for all" << endl;
	cout << "== : " << ((f1 == f2) ? "True" : "False") << endl;
	cout << "!= : " << ((f1 != f2) ? "True" : "False") << endl;
	cout << "< : " << ((f1 < f2) ? "True" : "False") << endl;
	cout << "<= : " << ((f1 <= f2) ? "True" : "False") << endl;
	cout << "> : " << ((f1 > f2) ? "True" : "False") << endl;
	cout << ">= : " << ((f1 >= f2) ? "True" : "False") << endl << endl;

	// Extended Operations Test
	cout << "Extended OPs Test: Using f1 = " << f1 << " for all" << endl;
	cout << "Invert: !f1 = " << !f1 << endl;
	cout << "double: (double)f1 = " << static_cast<double>(f1) << endl << endl;
	
	// Static Operations Test
	cout << "Static Operations Test" << endl;
	cout << "UNITY = " << Fraction::UNITY << endl;
	cout << "ZERO = " << Fraction::ZERO << endl << endl;
	*/

	try 
	{ 
		cout << "Construct Fraction (1, 0): ";
		Fraction f1(1, 0);
	}
	catch (const char* s) { cout << s << endl; } cout << endl;
	
	Fraction f1;
	try
	{
		cout << "Read f1 = ";
		cin >> f1; cout << f1 << endl;
	}
	catch (const char* s) { cout << s << endl; } cout << endl;

	f1 = Fraction(5, 12); Fraction f2 = Fraction::ZERO, f3;
	try
	{
		cout << "Binary Divide f3 = " << f1 << " / " << f2 << ": ";
		f3 = f1 / f2;
		cout << f3 << endl;
	}
	catch (const char* s) { cout << s << endl; }
	try
	{
		cout << "Binary % f3 = " << f1 << " % " << f2 << ": ";
		f3 = f1 % f2;
		cout << f3 << endl;
	}
	catch (const char* s) { cout << s << endl; } cout << endl;

	try
	{
		cout << "Binary Divide f3 = " << f1 << " /= " << f2 << ": ";
		f3 = f1 /= f2;
		cout << f3 << endl;
	}
	catch (const char* s) { cout << s << endl; }
	try
	{
		cout << "Binary % f3 = " << f1 << " %= " << f2 << ": ";
		f3 = f1 %= f2;
		cout << f3 << endl;
	}
	catch (const char* s) { cout << s << endl; } cout << endl;

	try
	{
		cout << "Invert: f1 = " << " ! " << f2 << ": ";
		f1 = !f2;
		cout << f1 << endl;
	}
	catch (const char* s) { cout << s << endl; } cout << endl;

	return 0;
}