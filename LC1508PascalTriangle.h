#ifndef LC1509_H
#define LC1509_H

#include "Common.h"
#include <string.h>
#include <limits.h>
#include <stdio.h>

/**********************************************************************************
*
* Given an index k, return the kth row of the Pascal's triangle.
*
* For example, given k = 3,
* Return [1,3,3,1].
*
* Note:
* Could you optimize your algorithm to use only O(k) extra space?
*
*
**********************************************************************************/

/************
[Easy]
Time Complexity O(N^2)
Space Complexity O(N)
To remember:
1.
************/

class Solution1509
{
public:
   static vector<int> getRow(int rowIndex) {
    vector<int> v(rowIndex+1, 0);
    v[0]=1;

    for (int i=0; i<rowIndex; i++){
        for(int j=i+1; j>0; j--){
           v[j] += v[j-1];
        }
    }
    return v;

}

};

void doLC1509PascalTriangleII()
{
   std::cout << "---------------------------------\n";
   std::cout << "Pascal Triangle II\n";
   int n = 3;
   std::cout << "The rows: " << n << "\n";
   vector<int> res = Solution1509::getRow(n);
   PrintVector(res);

}

#endif
