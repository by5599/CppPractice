#ifndef LC0304_H
#define LC0304_H

#include "Common.h"
#include <string.h>
#include <limits.h>
#include <stdio.h>

using namespace std;

/**********************************************************************************
*
* Given two binary strings, return their sum (also a binary string).
*
* For example,
* a = "11"
* b = "1"
* Return "100".
*
*
**********************************************************************************/

/************
[Easy]
Time Complexity O(N)
Space Complexity O(1)
To remember:
1.
************/

class Solution0304
{
public:
   static string addBinary(string a, string b) {
    int alen = a.size();
    int blen = b.size();
    bool carry = false;
    string result;
    while( alen>0 || blen>0) {
        int abit = alen<=0 ? 0 : a[alen-1]-'0';
        int bbit = blen<=0 ? 0 : b[blen-1]-'0';
        int cbit = carry ? 1 : 0;
        result.insert(result.begin(), '0' + ((abit+bbit+cbit) & 1) );
        carry = (abit+bbit+cbit>1);
        alen--; blen--;
    }
    if (carry){
        result.insert(result.begin(), '1');
    }
    return result;
}

};

void doLC0304AddBinary()
{
   std::cout << "---------------------------------\n";
   std::cout << "Add Binary\n";
   string a = "101";
   string b = "11";
   cout << a << " " << b << "\n";
   string str = Solution0304::addBinary(a,b);
   cout << "The result: " << str << "\n";
}

#endif
