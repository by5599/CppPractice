
#ifndef LC020118_H
#define LC020118_H

#include "Common.h"
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <limits.h>

using namespace std;

/**********************************************************************************
*
* You are climbing a stair case. It takes n steps to reach to the top.
*
* Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*
*
**********************************************************************************/


/************
[Easy]
Time Complexity O(n)
Space Complexity O(1)
To remember:
1.
2.
3.
************/

class Solution020118
{
public:
   static     int climbStairs(int n) {
       if (n<=3) return n;
       int a[2]={2,3};
       for(int i=4; i<=n; i++){
           int t = a[0] + a[1];
           a[0] = a[1];
           a[1] = t;
       }
       return a[1];
    }

};

void doLC020118ClimbingStairs()
{
   std::cout << "---------------------------------\n";
   std::cout << "Climbing Stairs:\n";
   int n = 5;
   std::cout << "The stairs: " << n << "\n";

   int res = Solution020118::climbStairs(n);
   std::cout << "The Result: " << res << "\n";

}

#endif
