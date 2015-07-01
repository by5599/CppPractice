
#ifndef LC020113_PERMUTATION_SEQUENCE_H
#define LC020113_PERMUTATION_SEQUENCE_H

#include "Common.h"
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <limits.h>

/**********************************************************************************
*
* The set [1,2,3,…,n] contains a total of n! unique permutations.
*
* By listing and labeling all of the permutations in order,
* We get the following sequence (ie, for n = 3):
*
* "123"
* "132"
* "213"
* "231"
* "312"
* "321"
*
* Given n and k, return the kth permutation sequence.
*
* Note: Given n will be between 1 and 9 inclusive.
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

class Solution020113
{
public:
   static std::string getPermutation(int n, int k) {
      std::vector<int> nums(n);
      int permCount =1;
      for(int i =0; i< n; i++)
      {
         nums[i] = i+1;
         permCount *= (i+1);
      }
      // change K from (1,n) to (0, n-1) to accord to index
      k--;
      std::string targetNum;
      for(int i =0; i< n; i++)
      {
         permCount = permCount/ (n-i);
         int choosed = k / permCount;
         targetNum.push_back(nums[choosed] + '0');
         //restruct nums since one num has been picked
         for(int j =choosed; j< n-i; j++)
         {
            nums[j]=nums[j+1];
         }
         k = k%permCount;
      }
      return targetNum;
   }
};

void doLC020113PermutationSequence()
{
   std::vector<int> a = {1,4,3,2};

   std::cout << "---------------------------------\n";
   int n = 4;
   int k = 9;
   std::cout << "Permutation Sequence:\n";
   std::cout << "The value: n=" << n << " k=" << k << "\n";
   //PrintVector(a);
   std::string res = Solution020113::getPermutation(n,k);
   std::cout << "The result: " << res << "\n";
   //PrintVector(a);
   //int i = 3;
   //std::cout << "test division: " << i / 2 << "\n";
}

#endif
