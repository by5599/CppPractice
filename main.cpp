
#include "AlgorithmLinkedList.h"
#include "AlgorithmSorting.h"
#include "CppExamples.h"
#include "LC211RemoveDuplicatesFromSortedArray026.h"
#include "LC212RemoveDuplicatesFromSortedArrayII080.h"
#include "LC213SearchInRotatedSortedArray033.h"
#include "LC214SearchInRotatedSortedArrayII081.h"
#include "LC33StringToIntegeratoi008.h"
#include "LC215MedianOfTwoSortedArrays_004.h"
#include "LC216LongestConsecutiveSequence.h"
#include "LC511BinaryTreePreorderTraversal.h"
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

void print(const int ia[10])
{
for (size_t i = 0; i != 10; ++i)
cout << ia[i] << endl;
}
int main()
{
   doLC211();
   doLC212();
   doLC213();
   doLC214();
   doLC33();
   doLC215();
   doLC216();
   doLC511();


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
