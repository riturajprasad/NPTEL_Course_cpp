#include "FractionNo.h"

Fraction::Fraction(int n, int d) : n_(d < 0 ? -n : n), d_(d < 0 ? -d : d) { Reduce(); }
Fraction::~Fraction() {}
Fraction::Fraction(const Fraction& f) : n_(f.n_), d_(f.d_) {}
Fraction& Fraction::operator=(const Fraction& f)
{
	if (this != &f)
	{
		n_ = f.n_;
		d_ = f.d_;
	}
	return *this;
}
const Fraction Fraction::UNITY(1, 1);
const Fraction Fraction::ZERO(0, 1);

int Fraction::gcd(int a, int b)
{
	while (a != b)
	{
		if (a > b) a = a - b;
		else b = b - a;
	}
	return a;
}
int Fraction::lcm(int a, int b)
{
	return (a / gcd(a, b)) * b;
}
Fraction& Fraction::Reduce()
{
	if (d_ == 0) { throw "Fraction with Denominator 0 is undefined"; }
	if (d_ < 0)
	{
		n_ = -n_;
		d_ = static_cast<unsigned int>(-static_cast<int>(d_));
		return *this;
	}
	if (n_ == 0) { d_ = 1; return *this; }
	unsigned int n = (n_ > 0) ? n_ : -n_, g = gcd(n, d_);
	n_ /= static_cast<int>(g); // as n_ is int g is un_int the division may not work.
	d_ /= g;
	return *this;
}

// Input and Output
ostream& operator<<(ostream& os, const Fraction& f)
{
	os << f.n_;
	if ((f.n_ != 0) && (f.d_ != 1)) os << "/" << f.d_; // remove denominator if n_=0 or d_=1;
	return os;
}
istream& operator>>(istream& is, Fraction& f)
{
	is >> f.n_ >> f.d_;
	f.Reduce();
	return is;
}

// Unary Arthmetic Oprations: Preserve, Negate, Componendo, Dividendo & Postfix operators.
Fraction Fraction::operator+() const { return *this; }
Fraction Fraction::operator-() const { return Fraction(-n_, d_); }
Fraction& Fraction::operator++() { return *this += Fraction::UNITY; }
Fraction& Fraction::operator--() { return *this -= Fraction::UNITY; }
Fraction Fraction::operator++(int) { Fraction f = *this; ++*this; return f; }
Fraction Fraction::operator--(int) { Fraction f = *this; --*this; return f; }

// Binary Arithmetic Oprations: Add, Sub, Mul, Div and Modulo.
Fraction Fraction::operator+(const Fraction& f2) const
{
	unsigned int d = lcm(d_, f2.d_);
	int n = n_ * (d / d_) + f2.n_ * (d / f2.d_);
	return Fraction(n, d);
}
Fraction Fraction::operator-(const Fraction& f2) const { return *this + (-f2); }
Fraction Fraction::operator*(const Fraction& f2) const { return Fraction(n_*f2.n_, d_*f2.d_); }
Fraction Fraction::operator/(const Fraction& f2) const
{
	if (f2.n_ == 0) { throw "Divide by 0 is undefined\n"; }
	return Fraction(n_ * f2.d_, d_ * f2.n_);
}
Fraction Fraction::operator%(const Fraction& f2) const
{
	if (f2.n_ == 0) { throw "Divide by 0 is undefined\n"; }
	Fraction tf = (*this) / f2;
	return (*this) - Fraction(tf - Fraction(tf.n_%tf.d_, tf.d_)) * f2;
}

// Advanced Assignment Operators.
Fraction& Fraction::operator+=(const Fraction& f) { *this = *this + f; return *this; }
Fraction& Fraction::operator-=(const Fraction& f) { *this = *this - f; return *this; }
Fraction& Fraction::operator*=(const Fraction& f) { *this = *this * f; return *this; }
Fraction& Fraction::operator/=(const Fraction& f) { *this = *this / f; return *this; }
Fraction& Fraction::operator%=(const Fraction& f) { *this = *this % f; return *this; }

// Binary Relationl Operations
bool Fraction::operator==(const Fraction& f2) const { return ((n_ == f2.n_) && (d_ == f2.d_)); }
bool Fraction::operator!=(const Fraction& f2) const { return !(*this == f2); }
bool Fraction::operator<(const Fraction& f2) const { return (*this - f2).n_ < 0; }
bool Fraction::operator<=(const Fraction& f2) const { return !(*this > f2); }
bool Fraction::operator>(const Fraction& f2) const { return (*this - f2).n_ > 0; }
bool Fraction::operator>=(const Fraction& f2) const { return !(*this < f2); }

// Extended Operations: Invert and Convert to double.
Fraction Fraction::operator!() const
{
	if (d_ == 0) { throw "Divide by 0 is undefined\n"; }
	return Fraction(d_, n_);
}
Fraction::operator double() const { return static_cast<double>(n_) / static_cast<double>(d_); }