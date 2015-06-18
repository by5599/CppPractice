#ifndef LC215_MEDIAN_OF_TWO_SORTED_ARRAYS_H
#define LC215_MEDIAN_OF_TWO_SORTED_ARRAYS_H

#include "Common.h"
#include <algorithm>>

/**********************************************************************************
*
* There are two sorted arrays A and B of size m and n respectively.
* Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*
**********************************************************************************/


/************
[Hard]
Time Complexity O(log(m+n))
To remember:
1.
2.
3.
************/

class Solution215
{
public:
   static int findMedianSortedArrays(int A[], int m, int B[], int n) {
      int total = m + n;
      if (total & 0x1)
         return find_kth(A, m, B, n, total / 2 + 1);
   }
private:
   static int find_kth(int A[], int m, int B[], int n, int k) {
      //always assume that m is equal or smaller than n
      if (m > n) return find_kth(B, n, A, m, k);
      if (m == 0) return B[k - 1];
      if (k == 1) return std::min(A[0], B[0]);
      //divide k into two parts
      int ia = std::min(k / 2, m), ib = k - ia;
      if (A[ia - 1] < B[ib - 1])
      return find_kth(A + ia, m - ia, B, n, k - ia);
      else if (A[ia - 1] > B[ib - 1])
      return find_kth(A, m, B + ib, n - ib, k - ib);
      else
      return A[ia - 1];
   }
};

void doLC215()
{
   int A[] = {1, 3, 5, 6, 8};
   int B[] = {2, 4, 7, 9, 11, 15, 16, 23};

   std::cout << "---------------------------------\n";
   std::cout << "Median of two sorted arrays:\n";
   std::cout << "The arrays:\n";
   int arrSize = sizeof(A) / sizeof(int);
   PrintArray(A, 5);
   PrintArray(B, 8);

   int res = Solution215::findMedianSortedArrays(A, 5, B, 8);
   std::cout << "The result is: " << res << std::endl;
}

#endif
