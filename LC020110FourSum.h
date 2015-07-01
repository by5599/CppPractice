


#ifndef LC020110_FOUR_SUM_H
#define LC020110_FOUR_SUM_H

#include "Common.h"
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <limits.h>

/**********************************************************************************
*
* Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target?
* Find all unique quadruplets in the array which gives the sum of target.
*
* Note:
*
* Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ¡Ü b ¡Ü c ¡Ü d)
* The solution set must not contain duplicate quadruplets.
*
*     For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
*
*     A solution set is:
*     (-1,  0, 0, 1)
*     (-2, -1, 1, 2)
*     (-2,  0, 0, 2)
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

class Solution020110
{
public:
   static std::vector<std::vector<int>> fourSum(std::vector<int>& num, int target) {
      std::vector<std::vector<int>> result;
      if (num.size() < 4) return result;
      sort(num.begin(), num.end());
      auto last = num.end();
      for (auto a = num.begin(); a < prev(last, 3); ++a) {
         for (auto b = next(a); b < prev(last, 2); ++b) {
            auto c = next(b);
            auto d = prev(last);
            while (c < d) {
               if (*a + *b + *c + *d < target) {
                  ++c;
               } else if (*a + *b + *c + *d > target) {
                  --d;
               } else {
                  result.push_back({ *a, *b, *c, *d });
                  ++c;
                  --d;
               }
            }
         }
      }
      sort(result.begin(), result.end());
      result.erase(unique(result.begin(), result.end()), result.end());
      return result;
   }
};

void doLC020110FourSum()
{
   std::vector<int> a = {1,0,-1,0,-2,2};

   std::cout << "---------------------------------\n";
   std::cout << "Four Sum:\n";
   std::cout << "The vector:\n";
   PrintVector(a);
   std::vector<std::vector<int>> res = Solution020110::fourSum(a,0);
   std::cout << "Four Sum:\n";
   for (auto x : res)
   {
      PrintVector(x);
   }
}

#endif
