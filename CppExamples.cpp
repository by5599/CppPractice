// Sorting.cpp : Defines the entry point for the console application.
//

#include "CppExamples.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <conio.h>
#include <vector>
#include "Common.h"

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

int* func1()
{
   int a[3];
   return a;
}

void testUninitializedPointer()
{
   // Uninitialized pointer
   char *pc;
   //printf("The contents of pc: %s\n", pc);  // Print garbage, it may cause segfault!
   //*pc = 'x';  // Segfault
   //*(pc + 10) = 'y';  // Segfault
}

void testUninitializedMemory()
{
   char *pc = (char*)malloc(10);
   printf("The contents of pc: %s\n", pc);  // This will print some garbage
}

void testIllegalAccessHeap()
{
   char *pc = (char*)malloc(10);
   memset(pc, 0, 10);
   pc[0] = 'x';
   *(pc+11) = 'a';  // This is "okay" but not good
   printf("The contents of pc: %s\n", pc); // Will print "x"
   //pc1[8000] = 'z';  // This will cause segfault b/c it goes out of page

   free(pc);
   pc = NULL;
   //free(pc);   // Crash!
   //*pc = 'y';  // Dereference NULL pointer will cause segfault
   printf("The contents of pc1: %s\n", pc);

   int a[] = {1,2,3};
   free(a);
}

void testMemoryOverwrite()
{
   char *pc = (char *)malloc(10);
   char *name = (char *)malloc(11);
   name = "Andy Smith";
   memcpy(pc, name, 11); // Problem begins here
   printf("The contents of pc: %s\n", pc);
}

void testMemoryOverread()
{
   char *pc = (char *)malloc(10);
   pc = "Nice Day!";
   char arr[20];
   memcpy(arr, pc, 20); // Problem begins here
   printf("The contents of arr: %s\n", arr);
}

void testMismatchOfPointerType()
{
   int a = 320;
   char *pc;
   pc = (char*)&a;
   printf("The content of pc: %d\n", *pc); // Print 64!
}

void testUsePointerWithoutAllocateMemory()
{
   char *ptr1 = NULL;
   char *ptr2 = 0;
   //strcpy(ptr1, "seg");
   //strcpy(ptr2, "fault");
   //printf("ptr1 and ptr2: %s %s", ptr1, ptr2);
}

void testWriteToReadOnlyMemory()
{
   char *pc = "Hello";
   //*pc = 'x';

}
void testReassignArray()
{
   char arr[10];
   //arr = "world";  // Compilation error!
}

void testAdjcentPointer()
{
   int a = 5,b = 10,c;
   int *p = &a,*q = &b;
   c = p - q;
   printf("difference: %d\n" , c);
}

unsigned long int (* avg())[3]{
static unsigned long int arr[3] = {1,2,3};
return &arr;
}
void testWeirdFunctionReturn()
{
unsigned long int (*ptr)[3];
ptr = avg();
printf("Weird function return: %d %d\n" , *(*ptr+2), sizeof(ptr));
}

void testWeirdFunctionOutput()
{
int i = 5;
int *p;
p = &i;
printf("Weird output: %u %u\n", *&p , &*p);
}
void TestPointers()
{
   testUninitializedPointer();
   testUninitializedMemory();
   testIllegalAccessHeap();
   testMemoryOverwrite();
   testMemoryOverread();
   testMismatchOfPointerType();
   testUsePointerWithoutAllocateMemory();
   testReassignArray();
   testAdjcentPointer();
   testWeirdFunctionReturn();
   testWeirdFunctionOutput();
   testWriteToReadOnlyMemory();
   return;
   // Uninitialized memory

   int pi1[] = {1,2,3};
   pi1[3] = 5;  // This is "fine"
   *(pi1+5) = 8;  // This will cause segfault b/c it go out of the page

   //char *pc = "Hello";
   //pc[1] = 'E';  // This is illegal b/c it accesses memory not allowed
   //printf("Check the contents of pc: %s\n", pc);
   //char *pc100;
   //printf("Check the contents of pc1: %s\n", pc100);
   char *pc2 = NULL;
   //printf("Check the contents of pc2: %s\n", pc2);
   char *pc3 = "World";
   //pc3[10] = 'x';
   //printf("Check the contents of pc3: %s\n", pc3);
   char testarr1[3] = {'a','b','c'};
   printf("Print testarr1: %s\n", testarr1);
   char testarr2[] = "World";
   //testarr2 = "New";  // this will cause compile error
   printf("Print testarr2: %s\n", testarr2);
   int *pi = func1();
   printf("Print pi: %p\n", pi);

   char *ptr1 = (char*)malloc(10);
   ptr1 = "okokokoko";
   printf("Print ptr: %s\n", ptr1);
   char *ptr2 = (char*)malloc(11);
   ptr2 = "nonononono";
   printf("Print ptr: %s\n", ptr2);
   //memcpy(ptr1,ptr2,11);
   //printf("Print ptr: %s\n", ptr1);

   char *ptr = (char *)malloc(10);
   ptr = "goodgood";
   char name[20] = "name 20";
   memcpy ( name,ptr,20); // Problem begins here
   printf("Print ptr: %s\n", name);

   int val1 = 320;
   char *pc5 = (char*)&val1;
   printf("Print pc5: %d\n", *pc5);

   int *ptr5;
   //*ptr5 = 42;
}

class test1
{
};

class test2
{
   short s1;
   short s2;
   short s3;
};

class test3
{
   char a;
   short b;
   int c;
};

bool checkMissingNumber(int *pi, int len, int num)
{
   int low = 0, high = len, mid;
   int i = 0;
   for (i = 0; i < len; ++i)
   {
      mid = (low + high) / 2;
      if (pi[mid] == num)
         return true;
      else if (pi[mid] < num)
      {
         low = mid + 1;
      }
      else
      {
         high = mid - 1;
      }
   }
   return false;
}

struct s { int i; char c; long d; void *p; int a[0]; };
struct s1 { int i; char c; long d; void *p; };
struct s2 { int i; char c; long d; };
struct s3 { int i; char c; };
struct s4 { int i; };
struct s5 { char c0; char c1; char c2; };
struct s6 { char c0; double dd; };
struct s7 { char c0; short ss; };
struct s8 { char c0; double dd; int ii;  };
struct s9 { int i1; double dd; int i2;  };

 int get() { static int i = 1; return i++; }

void doNothing()
{

}

void TestDataTypesAndAlignments()
{
   int a[5] = {1,2,5,7,8};
   bool res = checkMissingNumber(a,5,8);
   string str = res?"true":"false";
   cout << "Found the number in array: " << str << endl;

   printf("The size of char: %d\n", sizeof(char));
   printf("The size of short: %d\n", sizeof(short));
   printf("The size of int: %d\n", sizeof(int));
   printf("The size of long: %d\n", sizeof(long));
   printf("The size of long long: %d\n", sizeof(long long));
   printf("The size of float: %d\n", sizeof(float));
   printf("The size of double: %d\n", sizeof(double));
   printf("The size of empty class: %d\n", sizeof(test1));
   printf("The size of test2 class: %d\n", sizeof(test2));
   printf("The size of test3 class: %d\n", sizeof(test3));
   printf("The size of struct s: %d\n", sizeof(s));
   printf("The size of struct s1: %d\n", sizeof(s1));
   printf("The size of struct s2: %d\n", sizeof(s2));
   printf("The size of struct s3: %d\n", sizeof(s3));
   printf("The size of struct s4: %d\n", sizeof(s4));
   printf("The size of struct s5: %d\n", sizeof(s5));
   printf("The size of struct s6: %d\n", sizeof(s6));
   printf("The size of struct s7: %d\n", sizeof(s7));
   printf("The size of struct s8: %d\n", sizeof(s8));
   printf("The size of struct s9: %d\n", sizeof(s9));
   int fi[0];
   int fi2[1];
   //int fi3[];
   printf("The size of struct fi fi2 : %d %d \n", sizeof(fi), sizeof(fi2));
   printf("Function stack: %d %d %d\n", get(), get(), get());
   printf("sizeof trick: %d %d\n", sizeof(get()), sizeof(doNothing()));

   char *string1 = "Hello";
   char string2[] = "World";
   printf("%s %s %p %p\n", string1, string2, string1, string2);

   if (-1 < (unsigned char) 1)
      cout << "this is the if condition\n";
   else
      cout << "this is the else condition\n";
}


void testConstness()
{
   {
      // Reference to const can be bound to general object
      int i = 42;
      int &r = i;
      const int &r1 = i; // we can bind a const int& to a plain int object
      const int &r2 = 42; // ok: r1 is a reference to const
      const int &r3 = r1 * 2; // ok: r3 is a reference to const
   //   int &r4 = r * 2; // error: r4 is a plain, nonconst reference
   }

   {
      // A reference to count may refer to an object that is not const
      int i = 42;
      int &r1 = i; // r1 bound to i
      const int &r2 = i; // r2 also bound to i; but cannot be used to change i
      r1 = 0; // r1 is not const; i is now 0
      //r2 = 0; // error: r2 is a reference to const
   }

   {
      // A pointer to const can point to a non-const object
      const double *cptr;
      double dval = 3.14;
      cptr = &dval;
   }

   {
      // const pointer: it always points to an object
   }
printf("%d %d %d\n", get(), get(), get());
   {
      const int i = -1, &r = 0; // this is okay, it is equal to: const int &r = 0;
      const int *p;  // we can define a pointer to const but without assign value to it
   }

   {
      // When copy, high-level const is ignored
      int i = 0;
      const int ci = 42;
      const int *p2 = &ci;
      const int *const p3 = p2;
      i = ci; // ok: copying the value of ci; top-level const in ci is ignored
      p2 = p3; // ok: pointed-to type matches; top-level const in p3 is ignored
   }

   {
      int i = 0;
      const int v2 = 0; int v1 = v2;
      int *p1 = &v1, &r1 = v1;
      const int *p2 = &v2, *const p3 = &i, &r2 = v2;

      r1 = v2;
      //p1 = p2; // low-level const not match
      p2 = p1;
      //p1 = p3; // low-level const not match
      p2 = p3;
      cout << r1 << endl;
      r1 = 3;
      cout << r1 << endl;

      const int v10 = 1;
      int v11 = 2;
      int &r10 = v11;
      r10 = v10;

      cout << v11 << endl;
      r10 = 20;
      cout << v11 << endl;

   }

   {
      int aa[] = {1,2,3};
      int *p1 = aa;
      int *p2 = aa + 2;
      p1 += p2 - p1;
   }

   {
      int i = 1;
      cout << "Value evalution order not specified:\n";
      cout << i << "," << ++i << "," << i++ << endl;
      i = 1;
      printf("%d %d %d\n", i, ++i, ++i);  // 3 3 3
      i = 1;
      printf("%d %d %d\n", i, ++i, i++);  // 3 3 1
      i = 1;
      printf("%d %d %d\n", i, i++, ++i);  // 3 2 3
   }

   {
      int i = 1;
      printf("Function call tricks 2: %d %d\n", i++, ++i);
   }

   {
      int a[] = {1,2,3,4,5};
      int i = 0;
      cout << "Check complex assignment:\n";
      a[i++] = a[++i];
      cout << "i = " << i << endl;
      PrintArray(a,5);
      i = 0;
      a[++i] = a[++i];
      cout << "i = " << i << endl;
      PrintArray(a,5);
   }

   {
      char *aa[] = {"abc","def","xyz"};
      aa[1] = "mmm";
      char *a = "something";
      //a[0] = 'S';
   }

   {
      int i = 0;
      //for (i = 0; i < 10000; ++i)
   }
   int i = 1;
   printf("Function call tricks: %d %d\n", i, i++);

   int x = 2; int y = 1;
   y = i * i++;
   cout << y << endl;
}

void test5()
{
   typedef union
   {
      int a;
      char b[10];
      float c;
   } Union;

   Union x,y = {100};
   x.a = 50;
   strcpy(x.b,"hello");
   x.c = 21.50;
   printf("Union x : %d - %s - %f \n",x.a,x.b,x.c );
   printf("Union y : %d - %s - %f \n",y.a,y.b,y.c);

   long value;
   value &= 0xFFFF;

   int a[] = {1,2,3,4,5};
   printf("%x %x %d %d\n", a+1, &a+1, *(a+1), *((int*)(&a + 1)-1));
}

int g_var1;
int g_var2 = 10;

void test6()
{
   char *str1  = "Some Text";
   char str2[] = "Some Other Text";
   char str3[16] = "New Text";
   int var3 = 1;
   int var4;
   int arr1[5] = {1, 2, 3, 4, 5};
   int i = 0;
   char *p;
   //str1[0] = 's';
   str2[0] = 's';
   //str2 = str3;
   printf("%s - %p %s - %p\n", str1, str1, str2, str2);
   printf("%d - %p %d - %p\n", g_var1, &g_var1, g_var2, &g_var2);
   printf("%d - %p %d - %p\n", var3, &var3, var4, &var4);
   var3 = var3++;
   printf("%d %d %d\n", var3++, var3++, sizeof(p));
   arr1[i++] = arr1[i++] + 2;
   for (i = 0; i < 5; i++)
   {
      printf("arr1[%d] = %d\n", i, arr1[i]);
   }

   int a = 0, x = 1, y = 2;
   a = x, y;
   printf("%d\n", a);


   float c = 8.0;
   c *= 1.0 / 2;  // c gets 4.0
   printf("c = %.3f\n", c);
   c *= 1 / 2.0;  // c gets 2.0
   printf("c = %.3f\n", c);
   c *= 1.0 / 2.0;  // c gets 1.0
   printf("c = %.3f\n", c);

   c = 1.0 / 2;  // c gets 4.0
   printf("c = %.3f\n", c);
   c = 1 / 2.0;  // c gets 2.0
   printf("c = %.3f\n", c);
   c = 1.0 / 2.0;  // c gets 1.0
   printf("c = %.3f\n", c);

}

void privfriendFuncA(Basic &b)
{
   b.priv = 9;
   b.prot = 10;
   b.pub = 11;
   b.privFunc();
   b.protFunc();
   b.pubFunc();
}


void friendFuncA(Basic &b)
{
   b.priv = 9;
   b.prot = 10;
   b.pub = 11;
   b.privFunc();
   b.protFunc();
   b.pubFunc();
}

void friendFuncB(Level1 &l)
{
//   l.priv = 0;
   l.prot = 1;
   l.pub = 2;
   l.privL1 = 3;
   l.protL1 =4;
   l.pubL1 = 5;
//   l.privFunc();
   l.protFunc();
   l.pubFunc();
   l.privL1Func();
   l.protL1Func();
   l.pubL1Func();
}

void friendFuncC(Level2 &l)
{
//   l.priv = 0;
   l.prot = 1;
   l.pub = 2;
   l.privL2 = 3;
   l.protL2 =4;
   l.pubL2 = 5;
//   l.privFunc();
   l.protFunc();
   l.pubFunc();
   l.privL2Func();
   l.privL2Func();
   l.pubL2Func();
}

void friendFuncD(Level3 &l)
{
//   l.priv = 0;
   l.prot = 1;
   l.pub = 2;
   l.privL3 = 3;
   l.protL3 =4;
   l.pubL3 = 5;
//   l.privFunc();
   l.protFunc();
   l.pubFunc();
   l.privL3Func();
   l.protL3Func();
   l.pubL3Func();
}


void test7()
{
   Basic b;
//   b.priv = 0;
//   b.prot = 1;
   b.pub = 2;
//   b.privFunc();
//   b.protFunc();
   b.pubFunc();
   friendFuncA(b);
   privfriendFuncA(b);
//   Basic::staticPrivFunc();
   Basic::staticPubFunc();

/*****************************/
   Level1 l;
//   l.priv = 0;
//   l.prot = 1;
   l.pub = 2;
//   l.privL1 = 3;
//   l.protL1 = 4;
   l.pubL1 = 5;
//   l.privFunc();
//   l.protFunc();
   l.pubFunc();
//   l.privL1Func();
//   l.protL1Func();
   l.pubL1Func();
   friendFuncB(l);

/*****************************/
   Level2 l2;
//   l2.priv = 0;
//   l2.prot = 1;
//   l2.pub = 2;
//   l2.privL2 = 3;
//   l2.protL2 = 4;
   l2.pubL2 = 5;
//   l2.privFunc();
//   l2.protFunc();
//   l2.pubFunc();
//   l2.privL2Func();
//   l2.protL2Func();
   l2.pubL2Func();
   friendFuncC(l2);

/*****************************/
   Level3 l3;
//   l3.priv = 0;
//   l3.prot = 1;
//   l3.pub = 2;
//   l3.privL3 = 3;
//   l3.protL3 = 4;
   l3.pubL3 = 5;
//   l3.privFunc();
//   l3.protFunc();
//   l3.pubFunc();
//   l3.privL3Func();
//   l3.protL3Func();
   l3.pubL3Func();
   friendFuncD(l3);


}
