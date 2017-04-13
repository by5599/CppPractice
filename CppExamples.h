
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

class Basic;
void friendFuncA(Basic &b);


class Basic
{
private:
   int priv;
   void privFunc() {
      priv = 0;
      prot = 1;
      pub = 2;
      }
   static void staticPrivFunc() {}
   friend void privfriendFuncA(Basic &b);

protected:
   int prot;
   void protFunc() {
      priv = 3;
      prot = 4;
      pub = 5;
      }
   static void staticProtFunc() {}

public:
   int pub;
   void pubFunc() {
      priv = 6;
      prot = 7;
      pub = 8;
      staticPrivFunc();
      }
   static void staticPubFunc() {}

   friend void friendFuncA(Basic &b);
};


class Level1;
void friendFuncB(Level1 &l);

class Level1: public Basic
{
private:
   int privL1;
   void privL1Func() {
      //priv = 0;
      prot = 1;
      pub = 2;
      privL1 = 3;
      protL1 = 4;
      pubL1 = 5;
      }
protected:
   int protL1;
   void protL1Func() {
      //priv = 0;
      prot = 1;
      pub = 2;
      privL1 = 3;
      protL1 = 4;
      pubL1 = 5;
      }
public:
   int pubL1;
   void pubL1Func() {
      //priv = 0;
      prot = 1;
      pub = 2;
      privL1 = 3;
      protL1 = 4;
      pubL1 = 5;

      }
   friend void friendFuncB(Level1 &l);
};

class Level2;
void friendFuncC(Level2 &l);
class Level2: protected Basic
{
private:
   int privL2;
   void privL2Func() {
      //priv = 0;
      prot = 1;
      pub = 2;
      privL2 = 3;
      protL2 = 4;
      pubL2 = 5;
      }
protected:
   int protL2;
   void protL1Func() {
      //priv = 0;
      prot = 1;
      pub = 2;
      privL2 = 3;
      protL2 = 4;
      pubL2 = 5;
      }
public:
   int pubL2;
   void pubL2Func() {
      //priv = 0;
      prot = 1;
      pub = 2;
      privL2 = 3;
      protL2 = 4;
      pubL2 = 5;
      }
   friend void friendFuncC(Level2 &l);
};

class Level3;
void friendFuncD(Level3 &l);
class Level3: private Basic
{
private:
   int privL3;
   void privL3Func() {
      //priv = 0;
      prot = 1;
      pub = 2;
      privL3 = 3;
      protL3 = 4;
      pubL3 = 5;
      }
protected:
   int protL3;
   void protL3Func() {
      //priv = 0;
      prot = 1;
      pub = 2;
      privL3 = 3;
      protL3 = 4;
      pubL3 = 5;
      }
public:
   int pubL3;
   void pubL3Func() {
      //priv = 0;
      prot = 1;
      pub = 2;
      privL3 = 3;
      protL3 = 4;
      pubL3 = 5;
      Basic::staticPubFunc();
      }
   friend void friendFuncD(Level3 &l);
};

void TestDataTypesAndAlignments();
void TestPointers();
void testConstness();
void test5();
void test6();
void test7();
#endif
