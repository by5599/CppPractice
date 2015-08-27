#ifndef LC1002_H
#define LC1003_H

#include "Common.h"
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;
/**********************************************************************************
*
* A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
*
* The robot can only move either down or right at any point in time. The robot is trying to reach
* the bottom-right corner of the grid (marked 'Finish' in the diagram below).
*
* How many possible unique paths are there?
*
* Above is a 3 x 7 grid. How many possible unique paths are there?
*
* Note: m and n will be at most 100.
*
**********************************************************************************/

/************
[Medium]
Time Complexity O()
Space Complexity O()
To remember:
1.
************/

class Solution1002
{
public:
   static int uniquePaths(int m, int n) {
    int* matrix = new int[m*n];
    printMatrix(matrix, m, n);
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if(i==0 || j==0){
                matrix[i*n+j]=1;
            }else{
               // Add: use the one unit above and the one on the left
               matrix[i*n+j] = matrix[(i-1)*n+j] + matrix[i*n+j-1];
            }
        }
    }
    printMatrix(matrix, m, n);
    int u = matrix[m*n-1];
    delete[] matrix;
    return u;
}

static void printMatrix(int*a, int m, int n)
{
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            printf("%4d ", a[i*n+j]);
        }
        printf("\n");
    }
    printf("\n");
}
};

void doLC1002UniquePaths()
{
   std::cout << "---------------------------------\n";
   std::cout << "10.02 Unique Paths:\n";

   int res = Solution1002::uniquePaths(3,7);
   std::cout << "The result: " << res << "\n";
}

#endif
