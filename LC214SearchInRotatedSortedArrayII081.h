#ifndef LC214_SEARCH_IN_ROTATED_SORTED_ARRAYII_H
#define LC214_SEARCH_IN_ROTATED_SORTED_ARRAYII_H

#include "Common.h"

/**********************************************************************************
*
* Follow up for "Search in Rotated Sorted Array":
* What if duplicates are allowed?
*
* Would this affect the run-time complexity? How and why?
*
* Write a function to determine if a given target is in the array.
*
**********************************************************************************/


/************
[Easy]
Time Complexity O(log n), Space Complexity O(1)
To remember:
1.
2.
3.
************/

class Solution214
{
public:
   static bool search(int arr[], int n, int target)
   {
      int first = 0, last = n;
      while (first != last) {
         const int mid = first + (last - first) / 2;
         if (arr[mid] == target)
            return true;
         if (arr[first] < arr[mid]) {
            if (arr[first] <= target && target < arr[mid])
               last = mid;
            else
               first = mid + 1;
         } else if (arr[first] > arr[mid]) {
            if (arr[mid] < target && target <= arr[last-1])
               first = mid + 1;
            else
               last = mid;
         } else {
            //skip duplicate one
            first++;
         }
      }
      return false;
   }
};

void doLC214Search()
{
   int A[] = {6, 7, 7, 0, 1, 2, 3, 3, 3, 4, 5};

   std::cout << "---------------------------------\n";
   std::cout << "Search in rotated sorted array II\n";
   std::cout << "The array:\n";
   int arrSize = sizeof(A) / sizeof(int);
   for (int i = 0; i < arrSize; i++)
   {
      if ( i == arrSize - 1)
      {
         std::cout << A[i];
      }
      else
      {
         std::cout << A[i] << ",";
      }
   }
   std::cout << "\n";
   int searchValue = 3;
   bool res = Solution214::search(A, sizeof(A) / sizeof(int), searchValue);
   std::cout << "The array contents \'" << searchValue << "\': " << (res?"true":"false") << std::endl;
}

#endif
