
#include "AlgorithmLinkedList.h"
#include "AlgorithmSorting.h"
#include "CppExamples.h"
#include "LC026_211RemoveDuplicatesFromSortedArray.h"
#include "LC080_212RemoveDuplicatesFromSortedArrayII.h"
#include "LC033_213SearchInRotatedSortedArray.h"
#include <thread>
#include <windows.h>
#include "Common.h"

using namespace std;

void doLinkedListExample1()
{
   LinkedList linkedList;
   linkedList.doLinkedListExample1();
}

void doMergeSort()
{
   MergeSort mergeSort;
   mergeSort.doMergeSort();
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
}



void foo(string msg)
{
    cout << "thread1 says: " << msg;
}

void bar(string msg)
{
    cout << "thread2 says: " << msg;
}

int main()
{
    doLC026();
    doLC080();
    doLC033();



    int i, &ri = i;
    i = 5; ri = 10;
    //std::cout << i << " " << ri << std::endl;
    //doLinkedListExample1();
    //doMergeSort();
    //doCppExample1();
    //doTestSizeOfNoneClass();

   ::system("pause");

   return 0;
}
