
#ifndef LC020111_REMOVE_ELEMENT_H
#define LC020111_REMOVE_ELEMENT_H

#include "Common.h"
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <limits.h>

/**********************************************************************************
*
* Given an array and a value, remove all instances of that value in place and return the new length.
*
* The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*
*
**********************************************************************************/


/************
[Medium]
Time Complexity O(n), Space Complexity O(n)
To remember:
1.
2.
3.
************/

class Solution020111
{
public:
   static int removeElement(int A[], int n, int elem) {
      int index = 0;
      for (int i = 0; i < n; ++i) {
         if (A[i] != elem) {
            A[index++] = A[i];
         }
      }
      return index;
   }
};

void doLC020111RemoveElement()
{
   int a[] = {1,7,2,4,2,1,3};

   std::cout << "---------------------------------\n";
   std::cout << "Remove Element:\n";
   std::cout << "The vector:\n";
   PrintArray(a, sizeof(a)/sizeof(int));
   int res = Solution020111::removeElement(a, sizeof(a)/sizeof(int), 2);
   std::cout << "The new length: " << res << "\n";
}

#endif
