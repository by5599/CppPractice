
#ifndef LC020115_TRAPPING_RAIN_WATER_H
#define LC020115_TRAPPING_RAIN_WATER_H

#include "Common.h"
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <limits.h>

/**********************************************************************************
*
* Given n non-negative integers representing an elevation map where the width of each bar is 1,
* compute how much water it is able to trap after raining.
*
* For example,
* Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*
*     ^
*     |
*   3 |                       +--+
*     |                       |  |
*   2 |          +--+xxxxxxxxx|  +--+xx+--+
*     |          |  |xxxxxxxxx|  |  |xx|  |
*   1 |   +--+xxx|  +--+xxx+--+  |  +--+  +--+
*     |   |  |xxx|  |  |xxx|  |  |  |  |  |  |
*   0 +---+--+---+--+--+---+--+--+--+--+--+--+----->
*       0  1   0  2  1   0  1  3  2  1  2  1
*
* The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case,
* 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
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

class Solution020115
{
public:
   static int trap(int A[], int n) {
      int *max_left = new int[n]();
      int *max_right = new int[n]();
      for (int i = 1; i < n; i++) {
         max_left[i] = std::max(max_left[i - 1], A[i - 1]);
         max_right[n - 1 - i] = std::max(max_right[n - i], A[n - i]);
      }
      int sum = 0;
      for (int i = 0; i < n; i++) {
         int height = std::min(max_left[i], max_right[i]);
         if (height > A[i]) {
            sum += height - A[i];
         }
      }
      delete[] max_left;
      delete[] max_right;
      return sum;
   }
};

void doLC020115TrappingRainWater()
{
   int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};
   std::cout << "---------------------------------\n";
   std::cout << "Trapping Rain Water:\n";
   std::cout << "The Array:\n";
   int arrSize = sizeof(a)/sizeof(int);
   PrintArray(a,arrSize);

   int res = Solution020115::trap(a,arrSize);

   std::cout << "The result: " << res << "\n";
}

#endif
