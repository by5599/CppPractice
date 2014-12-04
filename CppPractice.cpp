// CppPractice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "AlgorithmLinkedList.h"
#include "AlgorithmSorting.h"
#include "CppExamples.h"

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

void doCppExample1()
{
   //Base base;
   Base* derived = new Derived();
   derived->func1();
   derived->func2();     
   derived->func3();
   derived->func4();
}

int _tmain(int argc, _TCHAR* argv[])
{
   doLinkedListExample1();
   doMergeSort();
   doCppExample1();

   ::system("pause");
   return 0;
}

