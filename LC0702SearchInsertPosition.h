#ifndef LC0702_H
#define LC0702_H

#include "Common.h"
#include "AlgorithmBase.h"
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

/**********************************************************************************
*
* Given a sorted array and a target value, return the index if the target is found.
* If not, return the index where it would be if it were inserted in order.
*
* You may assume no duplicates in the array.
*
* Here are few examples.
* [1,3,5,6], 5 ¡ú 2
* [1,3,5,6], 2 ¡ú 1
* [1,3,5,6], 7 ¡ú 4
* [1,3,5,6], 0 ¡ú 0
*
*
**********************************************************************************/

/************
[Medium]
Time Complexity O()
Space Complexity O()
To remember:
1.
2.
3.
************/


class Solution0702
{
public:
   static int binary_search(int A[], int n, int key) {
    int low = 0;
    int high = n-1;
    while (low <= high){
        int mid = low +(high-low)/2;
        if (A[mid] == key){
            return mid;
        }
        if ( key> A[mid] ) {
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return low;
}
static int searchInsert(int A[], int n, int target) {
    if (n==0) return n;
    return binary_search(A, n, target);
}

};

void doLC0702SearchInsertPosition()
{
   std::cout << "---------------------------------\n";
   std::cout << "07.02 Search Insert Position:\n";
    int a[]={1,3,5,6};
    printf("%d -> %d\n", 5, Solution0702::searchInsert(a, 4, 5));
    printf("%d -> %d\n", 2, Solution0702::searchInsert(a, 4, 2));
    printf("%d -> %d\n", 7, Solution0702::searchInsert(a, 4, 7));
    printf("%d -> %d\n", 0, Solution0702::searchInsert(a, 4, 0));
}

#endif
