#pragma once
#include <iostream>
using namespace std;

class Fraction
{
private:
	int n_;
	unsigned int d_;
public:
	explicit Fraction(int n = 1, int d = 1);
	~Fraction();
	Fraction(const Fraction&);
	Fraction& operator=(const Fraction&);
	static const Fraction UNITY;
	static const Fraction ZERO;

private:
	static int gcd(int, int);
	static int lcm(int, int);
	Fraction& Reduce();

public:
	// Input and Output
	friend ostream& operator<<(ostream&, const Fraction&);
	friend istream& operator>>(istream&, Fraction&);

	// Unary Arthmetic Oprations: Preserve, Negate, Componendo, Dividendo & Postfix operators.
	Fraction operator+() const;
	Fraction operator-() const;
	Fraction& operator++();
	Fraction& operator--();
	Fraction operator++(int);
	Fraction operator--(int);

	// Binary Arithmetic Oprations: Add, Sub, Mul, Div and Modulo.
	Fraction operator+(const Fraction&) const;
	Fraction operator-(const Fraction&) const;
	Fraction operator*(const Fraction&) const;
	Fraction operator/(const Fraction&) const;
	Fraction operator%(const Fraction&) const;

	// Advanced Assignment Operators.
	Fraction& operator+=(const Fraction&);
	Fraction& operator-=(const Fraction&);
	Fraction& operator*=(const Fraction&);
	Fraction& operator/=(const Fraction&);
	Fraction& operator%=(const Fraction&);

	// Binary Relationl Operations
	bool operator==(const Fraction&) const;
	bool operator!=(const Fraction&) const;
	bool operator<(const Fraction&) const;
	bool operator<=(const Fraction&) const;
	bool operator>(const Fraction&) const;
	bool operator>=(const Fraction&) const;

	// Extended Operations: Invert and Convert to double.
	Fraction operator!() const;
	operator double() const;
};