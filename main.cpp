#include <iostream>
#include "AlgorithmLinkedList.h"
#include "AlgorithmSorting.h"
#include "CppExamples.h"
#include "LeetCode_211RemoveDuplicatesFromSortedArray.h"

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

void doLeetCode211()
{
    int A[] = {1, 1, 2, 3, 3, 3, 5, 8};
    int res = Solution::removeDuplicates(A, sizeof(A) / sizeof(int));
    cout << "After remove duplicates: " << res << endl;
    cout << "The new array:" << endl;
    for (int i = 0; i < res; i++)
    {
        if (i + 1 == res)
        {
            cout << A[i];
        }
        else
        {
            cout << A[i] << ",";
        }
    }
    cout << endl;
}
int main()
{
   doLinkedListExample1();
   doMergeSort();
   doCppExample1();
   doTestSizeOfNoneClass();
    doLeetCode211();
//   ::system("pause");
   return 0;
}
