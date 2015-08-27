#ifndef LC1308_H
#define LC1308_H

#include "Common.h"
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>

/**********************************************************************************
*
* Given a m x n grid filled with non-negative numbers, find a path from top left to
* bottom right which minimizes the sum of all numbers along its path.
*
* Note: You can only move either down or right at any point in time.
*
**********************************************************************************/

#define INT_MIN     (-2147483647 - 1)


/************
[Medium]
Time Complexity O(), Space Complexity O()
To remember:
1.
************/


class Solution1308
{
public:
static int minPathSum(vector<vector<int> > &grid) {
    if (grid.size()<=0){
        return 0;
    }
    int i, j;
    for(i=0; i<grid.size(); i++){
        for(j=0; j<grid[i].size(); j++){
            int top = i-1<0 ? INT_MAX : grid[i-1][j] ;
            int left = j-1<0 ? INT_MAX : grid[i][j-1];
            if (top==INT_MAX && left==INT_MAX){
                continue;
            }
            grid[i][j] += (top < left? top: left);

        }
    }

    return grid[grid.size()-1][grid[0].size()-1];
}


};

void doLC1308MinimumPathSum()
{
   std::cout << "---------------------------------\n";
   std::cout << "13.08 Minimum Path Sum:\n";
    int a[6][2]={{7,2},{6,6},{8,6},{8,7},{5,0},{6,0}};
    vector< vector<int> > grid;
    for(int i=0; i<6; i++){
        vector<int> v;
        for(int j=0; j<2; j++){
            v.push_back(a[i][j]);
        }
        grid.push_back(v);
    }

    cout << "minPathSum=" << Solution1308::minPathSum(grid) << endl;
}

#endif
