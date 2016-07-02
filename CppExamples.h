
#ifndef CPP_EXAMPLE_H
#define CPP_EXAMPLE_H

class Base
{
public:
   Base();
   ~Base();

   virtual void func1();
   virtual void func2() = 0;
   virtual void func3();
   void func4();
};

class Derived : public Base
{
public:
   Derived() {}
   ~Derived() {}
   //virtual void func1();
   virtual void func2() override;
   virtual void func3();
   virtual void func5() {}
};

class Derived2 : public Derived
{
public:
   virtual void func5() {}
   void func1(int i);
   void func3();
};

class None
{
};

class PureAbstract
{
public:
   virtual void func() = 0;
};

class Empty : public None
{
};

class Something : public PureAbstract
{
public:
   virtual void func() {}
};

void TestDataTypesAndAlignments();
void TestPointers();
void testConstness();

#endif
