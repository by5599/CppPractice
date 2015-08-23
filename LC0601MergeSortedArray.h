#ifndef LC0601_H
#define LC0601_H

#include "Common.h"
#include "AlgorithmBase.h"
#include "AlgorithmLinkedList.h"

#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>

/**********************************************************************************
*
* Given two sorted integer arrays A and B, merge B into A as one sorted array.
*
* Note:
*   You may assume that A has enough space (size that is greater or equal to m + n)
*   to hold additional elements from B. The number of elements initialized in A and B
*   are m and n respectively.
*
**********************************************************************************/

/************
[Easy]
Time Complexity O(M+N)
Space Complexity O(1)
To remember:
1.
************/

class Solution0601
{
public:
   static void merge(int A[], int m, int B[], int n) {
    int ia = m-1 ;
    int ib = n-1 ;
    int i = m + n - 1;
    for (int i=m+n-1; i>=0; i--){

        if (ia>=0 && ib<0){
            break;
        }
        if (ia<0 && ib>=0){
            A[i] = B[ib--];
            continue;
        }
        if (ia>=0 && ib>=0){
            if (A[ia] > B[ib]){
                A[i] = A[ia--];
            }else{
                A[i] = B[ib--];
            }
        }

    }
   }
};

void doLC0601MergeSortedArray()
{
   int a[10] = {1,2,8};
   int b[10] = {3,5,6,9};

   std::cout << "---------------------------------\n";
   std::cout << "06.01 Merge Sorted Array:\n";
   std::cout << "The array:\n";
   PrintArray(a,3);
   PrintArray(b,4);

   Solution0601::merge(a,3,b,4);
   std::cout << "The result: " << std::endl;
   PrintArray(a,7);
}

#endif
