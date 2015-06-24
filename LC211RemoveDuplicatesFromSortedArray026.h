#ifndef LC211_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_H
#define LC211_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_H

#include "Common.h"

/**********************************************************************************
*
* Given a sorted array, remove the duplicates in place such that each element appear
* only once and return the new length.
*
* Do not allocate extra space for another array, you must do this in place with constant memory.
*
* For example,
* Given input array A = [1,1,2],
*
* Your function should return length = 2, and A is now [1,2].
*
*
**********************************************************************************/

/************
[Easy]
Time Complexity O(n), Space Complexity O(1)
To remember:
1. Set the initial left pointer to 0 and the index(right pointer) to 1
2. If the contents of the lp and rp is different:
   2.1 move lp one step to right,
   2.2 then copy from rp to lp
3. return the lp
************/

class Solution211
{
public:
   static int removeDuplicates(int arr[], int n)
   {
      if (n == 0 || n == 1)
      {
         return 0;
      }

      // lp is the left pointer that points to the last item
      int lp = 0;
      for (int rp = 1; rp < n; rp++)
      {
         if (arr[lp] != arr[rp])
         {
            arr[++lp] = arr[rp]; // Move the different item to left
         }
      }
      return (lp + 1);  // return the left pointer index
   }
};

void doLC211RemoveDuplicates()
{
   int A[] = {1, 1, 2, 3, 3, 3, 5, 8};

   std::cout << "-----------------------------------\n";
   std::cout << "Remove duplicates from sorted array\n";
   std::cout << "The array before operation:\n";
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
   int res = Solution211::removeDuplicates(A, sizeof(A) / sizeof(int));
   std::cout << "After remove duplicates: the size of array is " << res << std::endl;
   std::cout << "The new array:" << std::endl;
   for (int i = 0; i < res; i++)
   {
      if (i + 1 == res)
      {
         std::cout << A[i];
      }
      else
      {
         std::cout << A[i] << ",";
      }
   }
   std::cout << "\n";
}

#endif
