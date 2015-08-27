#ifndef LC1302_H
#define LC1302_H

#include "Common.h"
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>

/**********************************************************************************
*
* Find the contiguous subarray within an array (containing at least one number)
* which has the largest sum.
*
* For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
* the contiguous subarray [4,−1,2,1] has the largest sum = 6.
*
* More practice:
*
* If you have figured out the O(n) solution, try coding another solution using
* the divide and conquer approach, which is more subtle.
*
*
**********************************************************************************/

#define INT_MIN     (-2147483647 - 1)


/************
[Medium]
Time Complexity O(), Space Complexity O()
To remember:
1.
************/


class Solution1302
{
public:
static int max(int x, int y){
    return x>y?x:y;
}
   static int maxSubArray1(int A[], int n) {
    int *sum = new int[n];
    sum[0] = A[0];
    int m = A[0];
    for (int i=1; i<n; i++){
        sum[i] = max(A[i], A[i] + sum[i-1]);
        m = max(m, sum[i]);
    }
    delete[] sum;
    return m;
}

};

void doLC1302MaximumSubarray()
{
   std::cout << "---------------------------------\n";
   std::cout << "13.02 Maximum Subarray:\n";
   int a[] = {-2,1,-3,4,-1,2,1,-5,4};
   int arrsize = sizeof(a)/sizeof(int);
   std::cout << "The value: \n";
   PrintArray(a,arrsize);

   int res = Solution1302::maxSubArray1(a,arrsize);
   std::cout << "The result: " << res << std::endl;
}

#endif
