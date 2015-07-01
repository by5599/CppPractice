#ifndef LC213_SEARCH_IN_ROTATED_SORTED_ARRAY_H
#define LC213_SEARCH_IN_ROTATED_SORTED_ARRAY_H

#include "Common.h"

/**********************************************************************************
*
* Suppose a sorted array is rotated at some pivot unknown to you beforehand.
*
* (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
*
* You are given a target value to search. If found in the array return its index, otherwise return -1.
*
* You may assume no duplicate exists in the array.
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

class Solution213
{
public:
   static int search(int arr[], int n, int target)
   {
      int first = 0, last = n;
      while (first != last)
      {
         const int mid = first + (last - first) / 2;
         if (arr[mid] == target)
            return mid;
         if (arr[first] <= arr[mid])
         {
            // Search in the upper half zone
            if (arr[first] <= target && target < arr[mid])
               last = mid;       // Set the last border if it is positive order
            else
               first = mid + 1;  // Set the first border if is not
         }
         else
         {
            // Search in the bottom half zone
            if (arr[mid] < target && target <= arr[last-1])
               first = mid + 1;  // Set the first border if it is positive order
            else
               last = mid;  // Set the last border if it is not
         }
      }
      return -1;
   }
};

void doLC213Search()
{
   int A[] = {4, 5, 6, 7, 0, 1, 2};

   std::cout << "------------------------------\n";
   std::cout << "Search in rotated sorted array\n";
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
   int res = Solution213::search(A, sizeof(A) / sizeof(int), 1);
   std::cout << "The index: " << res << std::endl;
}

#endif
