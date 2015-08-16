// LinkedList.cpp : Defines the entry point for the console application.
//

//
//http://www.bogotobogo.com/cplusplus/linkedlist.php#linkedlistexample1
//
/*
Example 1
When the head of the list is not a global pointer.
Example 2 and Example 3
When the head of the list is a global pointer.
There are some implementation differences between these two examples.
Example 4
Used class & structure in that class.
Example 5A
Detecting circular (loop) linked list.
Example 5B
Detecting circular (loop) linked list (Generic Class with Template).
Example 6
Stack with linked list data structure.

Example 7
Class Stack with linked list data structure.
Example 7B
Class Stack with linked list data structure.
Example 7C
Class Stack using linked list with query for minimum value.
Example 7D
Stack Class Using Linked List with Query for Minimum Value (additional stack).
Example 8
Queue Struct with linked list data structure.
Example 8B
Queue Class with linked list data structure.
Example 9
Finding intersection and union of two linked lists.
Example 10
Generic linked lists.
*/

#include <iostream>
#include "Common.h"
#include "AlgorithmSearching.h"

using namespace std;


bool Searching::BinarySearch(int *inputArray, int numOfElements, int key)
{
   int low = 0, high = numOfElements - 1, mid;
   while(low <= high)
   {
      mid = (low + high)/2;
      if(inputArray[mid] < key)
      {
         low = mid + 1;
      }
      else if(inputArray[mid] == key)
      {
         return true;
      }
      else if(inputArray[mid] > key)
      {
         high = mid - 1;
      }
   }
   return false;
}

void Searching::doBinarySearch()
{
   int a[] = {1,2,3,5,8,9};
   cout << "---------------------\n";
   cout << "Binary search:\n";
   int arrSize = sizeof(a)/sizeof(int);
   PrintArray(a, arrSize);
   bool res = BinarySearch(a, arrSize, 5);
   cout << "Result: " << (res?"True":"False") << "\n";
}



