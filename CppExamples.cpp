// Sorting.cpp : Defines the entry point for the console application.
//

#include "CppExamples.h"
#include <iostream>

using namespace std;

Base::Base()
{}

Base::~Base()
{}

void Base::func1()
{
   cout << "This is Base::func1()" << endl;
}

void Base::func3()
{
   cout << "This is Base::func3()" << endl;
}

void Base::func4()
{
   cout << "This is Base::func4()" << endl;
}

void Derived::func2()
{
   cout << "This is Derived::func2()" << endl;
}

void Derived::func3()
{
   cout << "This is Derived::func3()" << endl;
}

void Derived2::func1(int i)
{
   cout << "This is Derived2::func1(int)" << endl;
}

void Derived2::func3()
{
   cout << "This is Derived2::func3()" << endl;
}
