#ifndef LC_ROTATE_ARRAY_H
#define LC_ROTATE_ARRAY_H

#include "Common.h"
#include "AlgorithmBase.h"
#include "AlgorithmLinkedList.h"

#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>

/**********************************************************************************
*
* Rotate an array of n elements to the right by k steps.
* For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
*
* Note:
* Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
*
* Hint:
* Could you do it in-place with O(1) extra space?
*
* Related problem: Reverse Words in a String II
*
* Credits:Special thanks to for adding this problem and creating all test cases.
*
**********************************************************************************/

/************
[Easy]
Time Complexity O()
Space Complexity O()
To remember:
1.
************/

class SolutionRotateArray
{
public:
   static void rotate2(int nums[], int n, int k) {
    if (k<=0) return;
    k %= n;
    int currIdx=0, newIdx=k;
    int tmp1 = nums[currIdx], tmp2;
    int origin = 0;

    for(int i=0; i<n; i++){

        tmp2 = nums[newIdx];
        nums[newIdx] = tmp1;
        tmp1 = tmp2;

        currIdx = newIdx;

        //if we meet a circle, move the next one
        if (origin == currIdx) {
            origin = ++currIdx;
            tmp1 = nums[currIdx];
        }
        newIdx = (currIdx + k) % n;

    }
}
};

void doLCRotateArray()
{
   std::cout << "---------------------------------\n";
   std::cout << "Rotate Array\n";

   int nums[] = {1,2,3,4,5,6,7};
   int numsSize = sizeof(nums)/sizeof(int);
   PrintArray(nums, numsSize);
   SolutionRotateArray::rotate2(nums,numsSize,3);
   PrintArray(nums, numsSize);
}


#endif
