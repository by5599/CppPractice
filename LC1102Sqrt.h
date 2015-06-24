#ifndef LC1102_SQRT_H
#define LC1102_SQRT_H

#include "Common.h"
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>

/**********************************************************************************
*
* Implement int sqrt(int x).
*
* Compute and return the square root of x.
*
**********************************************************************************/


/************
[Hard]
Time Complexity O(n), Space Complexity O(n)
To remember:
1. Use a map
2. Extend the finding and set the flag
3.
************/

class Solution1102
{
public:
   static int sqrt(int x) {
      int left = 1, right = x / 2;
      int last_mid;
      if (x < 2) return x;
      while(left <= right) {
         const int mid = left + (right - left) / 2;
         if(x / mid > mid) {
            left = mid + 1;
            last_mid = mid;
         } else if(x / mid < mid) {
            right = mid - 1;
         } else {
            return mid;
         }
      }
      return last_mid;
   }
};

void doLC1102Sqrt()
{
   std::cout << "---------------------------------\n";
   std::cout << "Sqrt:\n";
   std::cout << "The value: 9\n";

   int res = Solution1102::sqrt(9);
   std::cout << "The Sqrt: " << res << std::endl;
}

#endif
