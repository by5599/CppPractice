
#ifndef LC020112_NEXT_PERMUTATION_H
#define LC020112_NEXT_PERMUTATION_H

#include "Common.h"
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <limits.h>

/**********************************************************************************
*
* Implement next permutation, which rearranges numbers into the lexicographically next
* greater permutation of numbers.
*
* If such arrangement is not possible, it must rearrange it as the lowest possible order
* (ie, sorted in ascending order).
*
* The replacement must be in-place, do not allocate extra memory.
*
* Here are some examples. Inputs are in the left-hand column and its corresponding outputs
* are in the right-hand column.
*
*   1,2,3 ¡ú 1,3,2
*   3,2,1 ¡ú 1,2,3
*   1,1,5 ¡ú 1,5,1
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

class Solution020112
{
public:
   static void nextPermutation(std::vector<int> &num) {
      if(num.size()<=1) return;
      for(int i=num.size()-1; i>0; i--) {
         if (num[i-1] < num[i]){
            int j = num.size()-1;
            while( num[i-1] >= num[j]) {
               //pass;
               j--;
            }
            int tmp = num[j];
            num[j] = num[i-1];
            num[i-1] = tmp;
            //sort works as well
            //sort(num.begin()+i, num.end());
            reverse(num.begin()+i, num.end());
            return;
         }
         //edge case: 4 3 2 1
         if (i == 1 ){
            //sort works as well
            //sort(num.begin(), num.end());
            reverse(num.begin(), num.end());
            return;
         }
      }
   }
};

void doLC020112NextPermutation()
{
   std::vector<int> a = {1,4,3,2};

   std::cout << "---------------------------------\n";
   std::cout << "Next Permutation:\n";
   std::cout << "The vector:\n";
   PrintVector(a);
   Solution020112::nextPermutation(a);
   std::cout << "The new vector: ";
   PrintVector(a);
   int i = 3;
   std::cout << "test division: " << i / 2 << "\n";
}

#endif
