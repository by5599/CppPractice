#ifndef LC1501_REVERSE_INTEGER_H
#define LC1501_REVERSE_INTEGER_H

#include "Common.h"
#include <string.h>
#include <limits.h>
#include <stdio.h>

/**********************************************************************************
*
* Reverse digits of an integer.
*
* Example1: x =  123, return  321
* Example2: x = -123, return -321
*
*
* Have you thought about this?
*
* Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
*
* > If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
*
* > Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer,
*   then the reverse of 1000000003 overflows. How should you handle such cases?
*
* > Throw an exception? Good, but what if throwing an exception is not an option?
*   You would then have to re-design the function (ie, add an extra parameter).
*
**********************************************************************************/

/************
[Easy]
Time Complexity O(n), Space Complexity O(1)
To remember:
1. Skip the leading spaces
2. Find the sign
3. Calculate but consider the max numbers
************/

class Solution1501
{
public:
   static int reverse(int x) {
      int y=0;
      int n;
      while( x != 0){
         n = x%10;
         //Checking the over/underflow.
         //Actually, it should be y>(INT_MAX-n)/10, but n/10 is 0, so omit it.
         if (y > INT_MAX/10 || y < INT_MIN/10){
            return 0;
         }
         y = y*10 + n;
         x /= 10;
      }
      return y;
   }
};

void doLC1501ReverseInteger()
{
   std::cout << "---------------------------------\n";
   std::cout << "Reverse integer\n";
   int v = 123;
   std::cout << "The integer: " << v << "\n";
   int res = Solution1501::reverse(v);
   std::cout << "Reversed integer: " << res << "\n";
   res = Solution1501::reverse(1000);
   std::cout << "The integer: " << 1000 << "\n";
   std::cout << "Reversed integer: " << res << "\n";
}

#endif
