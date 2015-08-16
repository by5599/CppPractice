
#include "AlgorithmLinkedList.h"
#include "AlgorithmStack.h"
#include "AlgorithmQueue.h"
#include "AlgorithmTree.h"
#include "AlgorithmSearching.h"
#include "AlgorithmSorting.h"
#include "CppExamples.h"
#include "LCChapter2.h"
#include "LCChapter3.h"
#include "LCChapter4.h"
#include "LCChapter5.h"
#include "LCChapter6.h"
#include "LCChapter7.h"
#include "LCChapter8.h"
#include "LCChapter9.h"
#include "LCChapter10.h"
#include "LCChapter11.h"
#include "LCChapter12.h"
#include "LCChapter13.h"
#include "LCChapter14.h"
#include "LCChapter15.h"
#include "LCReverseWordsInAString.h"

#include <thread>
#include <windows.h>
#include "Common.h"

using namespace std;

void doLinkedListExample1()
{
   LinkedList linkedList;
   linkedList.doLinkedListExample1();
}

void doSorting()
{
   Sorting sorting;
   sorting.doMergeSort();
   sorting.doQuickSort();
   sorting.doBubbleSort();
   sorting.doSelectionSort();
   sorting.doInsertionSort();
}

void doTestSizeOfNoneClass()
{
   cout << sizeof(None) << endl;
   cout << sizeof(Empty) << endl;
   cout << sizeof(PureAbstract) << endl;
   cout << sizeof(Something) << endl;
}

void doCppExample1()
{
   //Base base;
   Base* derived = new Derived();
   derived->func1();
   derived->func2();
   derived->func3();
   derived->func4();

   Base* d2 = new Derived2();
   //d2->func1(1); // this line won't compile
   d2->func3();

   Derived2* d2obj = new Derived2();
   d2obj->func1(1);
   d2obj->func3();
}

void foo(string msg)
{
    cout << "thread1 says: " << msg;
}

void bar(string msg)
{
    cout << "thread2 says: " << msg;
}

void print(const int ia[10])
{
for (size_t i = 0; i != 10; ++i)
cout << ia[i] << endl;
}
int main()
{
   doChapter2();
   doChapter3();
   doChapter4();
   doChapter5();
   doChapter6();
   doChapter7();
   doChapter8();
   doChapter9();
   doChapter10();
   doChapter11();
   doChapter12();
   doChapter13();
   doChapter14();
   doChapter15();

   doLCReverseString();

    int i, &ri = i;
    i = 5; ri = 10;
    //std::cout << i << " " << ri << std::endl;
    //doLinkedListExample1();
    //doMergeSort();
    doCppExample1();
    //doTestSizeOfNoneClass();

   Searching::doBinarySearch();
   doSorting();
   TestStack();
   TestQueue();
   TestBinaryTree();

   ::system("pause");

   return 0;
}
