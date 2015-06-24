#ifndef LC217_TWO_SUM_H
#define LC217_TWO_SUM_H

#include "Common.h"
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>

/**********************************************************************************
*
* Given an array of integers, find two numbers such that they add up to a specific target number.
*
* The function twoSum should return indices of the two numbers such that they add up to the target,
* where index1 must be less than index2. Please note that your returned answers (both index1 and index2)
* are not zero-based.
*
* You may assume that each input would have exactly one solution.
*
* Input: numbers={2, 7, 11, 15}, target=9
* Output: index1=1, index2=2
*
**********************************************************************************/


/************
[Medium]
Time Complexity O(n), Space Complexity O(n)
To remember:
1. Use a map
2. Extend the finding and set the flag
3.
************/

class Solution217
{
public:
   static std::vector<int> twoSum(std::vector<int> &num, int target) {
      std::unordered_map<int, int> mapping;
      std::vector<int> result;
      for (int i = 0; i < num.size(); i++) {
         mapping[num[i]] = i;
      }
      for (int i = 0; i < num.size(); i++) {
         const int gap = target - num[i];
         if (mapping.find(gap) != mapping.end() && mapping[gap] > i) {
            result.push_back(i + 1);
            result.push_back(mapping[gap] + 1);
            break;
         }
      }
      return result;
   }
};

void doLC217TwoSum()
{
   std::vector<int> a = {2,7,11,15};

   std::cout << "---------------------------------\n";
   std::cout << "Two Sum:\n";
   std::cout << "The vector:\n";
   PrintVector(a);
   std::vector<int> res = Solution217::twoSum(a, 9);
   std::cout << "Two Sum: " << std::endl;
   PrintVector(res);
}

#endif
