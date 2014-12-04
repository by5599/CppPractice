
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
};

#endif
