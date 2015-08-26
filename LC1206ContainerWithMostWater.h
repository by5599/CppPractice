#ifndef LC1206_H
#define LC1206_H

#include "Common.h"
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>

/**********************************************************************************
*
* Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
* n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
*
* Find two lines, which together with x-axis forms a container, such that the container contains the most water.
*
* Note: You may not slant the container.
*
*
**********************************************************************************/

/************
[Medium]
Time Complexity O()
Space Complexity O()
To remember:
1.
************/

class Solution1206
{
public:
   static int maxArea(vector<int> &height) {

        int maxArea = 0;
        // two pointers scan from two sides to middle
        int left = 0;
        int right = height.size()-1;

        int area;
        while ( left < right ){
            // calculate the area
            area = (right - left) * ( height[left] < height[right] ? height[left] : height[right]);
            // tracking the maxium area
            maxArea = area > maxArea ? area : maxArea;
            // because the area is decided by the shorter edge
            // so we increase the area is to increase the shorter edge
            //
            //     height[left] < height[right] ? left++ : right-- ;
            //
            // However, the above code could cause the unnecessary `area` cacluation
            // We can do some improvement as below:
            if (height[left] < height[right]) {
                do {
                    left++;
                } while (left < right && height[left-1] >= height[left]);
            } else {
                do {
                    right--;
                } while (right > left && height[right+1] >= height[right]);
            }
        }

        return maxArea;
    }
};

void doLC1206ContainerWithMostWater()
{
   std::cout << "---------------------------------\n";
   std::cout << "12.06 Container With Most Water:\n";
   vector<int> v = {2,5,6};
   std::cout << "The vector: \n";
   PrintVector(v);

   int res = Solution1206::maxArea(v);
   std::cout << "The result: " << res << std::endl;
}

#endif
