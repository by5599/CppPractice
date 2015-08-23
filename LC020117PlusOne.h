
#ifndef LC020117_H
#define LC020117_H

#include "Common.h"
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <limits.h>

using namespace std;

/**********************************************************************************
*
* Given a non-negative number represented as an array of digits, plus one to the number.
*
* The digits are stored such that the most significant digit is at the head of the list.
*
**********************************************************************************/


/************
[Easy]
Time Complexity O(n)
Space Complexity O(1)
To remember:
1.
2.
3.
************/

class Solution020117
{
public:
   static void add(vector<int> &digits) {
      int c = 1;
      for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
         *it += c;
         c = *it / 10;
         *it %= 10;
      }
      if (c > 0) digits.insert(digits.begin(), 1);
   }
};

void doLC020117PlusOne()
{
   std::cout << "---------------------------------\n";
   std::cout << "Plus One:\n";
   vector<int> v = {1,8,9};
   std::cout << "The vector:\n";
   PrintVector(v);
   Solution020117::add(v);
   std::cout << "The Result:\n";
   PrintVector(v);
}

#endif
