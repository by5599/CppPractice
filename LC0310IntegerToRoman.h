#ifndef LC0310_H
#define LC0310_H

#include "Common.h"
#include <string.h>
#include <limits.h>
#include <stdio.h>

using namespace std;

/**********************************************************************************
*
* Given an integer, convert it to a roman numeral.
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

class Solution0310
{
public:
   static string intToRoman(int num) {
    string symbol[] =   {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    int value[]     =   {1000,900,500,400, 100, 90,  50, 40,  10, 9,   5,  4,   1};
    string result;

    for(int i=0; num!=0; i++){
        while(num >= value[i]){
            num -= value[i];
            result+=symbol[i];
        }
    }

    return result;
   }
};

void doLC0310IntegerToRoman()
{
   std::cout << "---------------------------------\n";
   std::cout << "Integer to Roman\n";
   int v = 380;
   std::cout << "The integer: " << v << "\n";
   //int res = Solution33::atoi(str);
   //std::cout << "The integer: " << res << std::endl;
   //printf("\"%s\" = %d\n", "2147483648", Solution33::atoi("2147483648"));
   string str = Solution0310::intToRoman(v);
   cout << "The result: " << str << "\n";
}

#endif
