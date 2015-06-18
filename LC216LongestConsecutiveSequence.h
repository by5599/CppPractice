#ifndef LC216_LONGEST_CONSECUTIVE_SEQUENCE_H
#define LC216_LONGEST_CONSECUTIVE_SEQUENCE_H

#include "Common.h"
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>

/**********************************************************************************
*
* Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
*
* For example,
* Given [100, 4, 200, 1, 3, 2],
* The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
*
* Your algorithm should run in O(n) complexity.
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

class Solution216
{
public:
   static int longestConsecutive(const std::vector<int> &num) {
      std::unordered_map<int, bool> used;
      for (auto i : num) used[i] = false;
      int longest = 0;

      for (auto i : num) {
         if (used[i]) continue;
         int length = 1;
         used[i] = true;
         for (int j = i + 1; used.find(j) != used.end(); ++j) {
            used[j] = true;
            ++length;
         }
         for (int j = i - 1; used.find(j) != used.end(); --j) {
            used[j] = true;
            ++length;
         }
         longest = std::max(longest, length);
      }
      return longest;
   }
};

void doLC216()
{
   std::vector<int> a = {100,4,200,1,3,2};

   std::cout << "---------------------------------\n";
   std::cout << "Longest Consecutive Sequence:\n";
   std::cout << "The vector:\n";
   PrintVector(a);
   int res = Solution216::longestConsecutive(a);
   std::cout << "The longest consecutive: " << res << std::endl;
}

#endif
