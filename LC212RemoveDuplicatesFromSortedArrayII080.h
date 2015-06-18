#ifndef LC212_REMOVE_DUPLICATES_FROM_SORTED_ARRAYII_H
#define LC212_REMOVE_DUPLICATES_FROM_SORTED_ARRAYII_H

#include "Common.h"

/**********************************************************************************
*
* Follow up for "Remove Duplicates":
* What if duplicates are allowed at most twice?
*
* For example,
* Given sorted array A = [1,1,1,2,2,3],
*
* Your function should return length = 5, and A is now [1,1,2,2,3].
*
*
**********************************************************************************/

/************
[Easy]
Time Complexity O(n), Space Complexity O(1)
To remember:
1. Set the initial left pointer to 2 and the index(right pointer) to 2
2. If the contents of the lp and rp is different:
   2.1 move lp one step to right,
   2.2 then copy from rp to lp
3. return the lp
************/

class Solution212
{
public:
   static int removeDuplicates(int arr[], int n)
   {
      if (n <= 2)
      {
         return n;
      }

      // lp is the left pointer that points to the last item
      int lp = 2;
      for (int rp = 2; rp < n; rp++)
      {
         if (arr[rp] != arr[lp - 2])
         {
            arr[lp++] = arr[rp]; // Move the different item to left
         }
      }
      return (lp);  // return the left pointer index
   }
};

void doLC212()
{
   int A[] = {1, 1, 1, 2, 2, 3};

   std::cout << "--------------------------------------\n";
   std::cout << "Remove duplicates from sorted array II\n";
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
   int res = Solution212::removeDuplicates(A, sizeof(A) / sizeof(int));
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
