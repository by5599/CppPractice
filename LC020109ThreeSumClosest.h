#ifndef LC020109_THREE_SUM_CLOSEST_H
#define LC020109_THREE_SUM_CLOSEST_H

#include "Common.h"
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <limits.h>

/**********************************************************************************
*
* Given an array S of n integers, find three integers in S such that the sum is
* closest to a given number, target. Return the sum of the three integers.
* You may assume that each input would have exactly one solution.
*
*     For example, given array S = {-1 2 1 -4}, and target = 1.
*
*     The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
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

class Solution020109
{
public:
   static int threeSumClosest(std::vector<int>& num, int target) {
      int result = 0;
      int min_gap = INT_MAX;
      sort(num.begin(), num.end());
      for (auto a = num.begin(); a != prev(num.end(), 2); ++a) {
      auto b = next(a);
      auto c = prev(num.end());
      while (b < c) {
         const int sum = *a + *b + *c;
         const int gap = abs(sum - target);
         if (gap < min_gap) {
            result = sum;
            min_gap = gap;
         }
         if (sum < target) ++b;
         else --c;
         }
      }
      return result;
   }
};

void doLC020109ThreeSumClosest()
{
   std::vector<int> a = {-1,2,1,-4};

   std::cout << "---------------------------------\n";
   std::cout << "Three Sum Closest:\n";
   std::cout << "The vector:\n";
   PrintVector(a);
   int res = Solution020109::threeSumClosest(a, 1);
   std::cout << "Three Sum Closest: " << res << std::endl;
}

#endif
