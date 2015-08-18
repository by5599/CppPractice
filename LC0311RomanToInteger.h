#ifndef LC0311_H
#define LC0311_H

#include "Common.h"
#include <string.h>
#include <limits.h>
#include <stdio.h>

/**********************************************************************************
*
* Given a roman numeral, convert it to an integer.
*
* Input is guaranteed to be within the range from 1 to 3999.
*
**********************************************************************************/

/************
[Easy]
Time Complexity O(N)
Space Complexity O(1)
To remember:
1.
************/

class Solution0311
{
public:
   static int romanCharToInt(char ch){
    int d = 0;
    switch(ch){
        case 'I':
            d = 1;
            break;
        case 'V':
            d = 5;
            break;
        case 'X':
            d = 10;
            break;
        case 'L':
            d = 50;
            break;
        case 'C':
            d = 100;
            break;
        case 'D':
            d = 500;
            break;
        case 'M':
            d = 1000;
            break;
    }
    return d;
   }

   static int romanToInt(string s) {
       if (s.size()<=0) return 0;
       int result = romanCharToInt(s[0]);
       for (int i=1; i<s.size(); i++){
           int prev = romanCharToInt(s[i-1]);
           int curr = romanCharToInt(s[i]);
           //if left<right such as : IV(4), XL(40), IX(9) ...
           if (prev < curr) {
               result = result - prev + (curr-prev);
           }else{
               result += curr;
           }
       }
       return result;
   }
};

void doLC0311RomanToInteger()
{
   std::cout << "---------------------------------\n";
   std::cout << "Roman to Integer\n";
   string v = "CXX";
   std::cout << "The Roman: " << v << "\n";
   //int res = Solution33::atoi(str);
   //std::cout << "The integer: " << res << std::endl;
   //printf("\"%s\" = %d\n", "2147483648", Solution33::atoi("2147483648"));
   int res = Solution0311::romanToInt(v);
   cout << "The result: " << res << "\n";
}

#endif
