#ifndef LC0701_H
#define LC0701_H

#include "Common.h"
#include "AlgorithmBase.h"
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

/**********************************************************************************
*
* Given a sorted array of integers, find the starting and ending position of a given target value.
*
* Your algorithm's runtime complexity must be in the order of O(log n).
*
* If the target is not found in the array, return [-1, -1].
*
* For example,
* Given [5, 7, 7, 8, 8, 10] and target value 8,
* return [3, 4].
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


class Solution0701
{
public:
   static vector<int> searchRange(int A[], int n, int target) {
    int pos = binary_search(A, 0, n-1, target);

    vector<int> v;
    int low = -1, high = -1;
    if (pos >=0){
        low = high = pos;
        int l = low;
        do {
            low = l;
            l = binary_search(A, 0, low - 1, target);
        }while (l>=0);

        int h = high;
        do {
            high = h;
            h = binary_search(A, high + 1, n-1, target);
        }while (h>=0);
    }

    v.push_back(low);
    v.push_back(high);
    return v;

}

static int binary_search(int A[], int low, int high, int key){

    while (low<=high) {
        int mid = low + (high-low)/2;
        if (A[mid] == key) {
            return mid;
        }
        if (key > A[mid]) {
            low = mid + 1;
        }
        if (key < A[mid]) {
            high = mid - 1;
        }
    }
    return -1;
}


};

void doLC0701SearchForARange()
{
   std::cout << "---------------------------------\n";
   std::cout << "07.01 Search for A Range:\n";
   int v[] = {5,7,7,8,8,10};
   int arrsize = sizeof(v)/sizeof(int);
   std::cout << "The array: " << "\n";
   PrintArray(v,arrsize);


   vector<int> res = Solution0701::searchRange(v,arrsize,8);
   cout << "The result: \n";
   PrintAnything(res);

}

#endif
