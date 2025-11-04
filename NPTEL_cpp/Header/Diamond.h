#pragma once
#include <iostream>
using namespace std;

class A
{
public:
	virtual ~A() { cout << "A::~A()" << endl; }
	virtual void foo() { cout << "A::foo()" << endl; }
};
class B : public virtual A
{
public:
	virtual ~B() { cout << "B::~B()" << endl; }
	virtual void foo() { cout << "B::foo()" << endl; }
};
class C : public A
{
public:
	virtual ~C() { cout << "C::~C()" << endl; }
	virtual void foobar() { cout << "C::foobar()" << endl; }
};
class D : public B, public C
{
public:
	virtual ~D() { cout << "D::~D()" << endl; }
	virtual void foo() { cout << "D::foo()" << endl; }
	virtual void foobar() { cout << "D::foobar()" << endl; }
};
