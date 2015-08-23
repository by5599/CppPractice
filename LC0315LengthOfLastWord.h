#ifndef LC0315_H
#define LC0315_H

#include "Common.h"
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <sstream>
#include <ctype.h>

using namespace std;

/**********************************************************************************
*
* Given a string s consists of upper/lower-case alphabets and empty space characters ' ',
* return the length of last word in the string.
*
* If the last word does not exist, return 0.
*
* Note: A word is defined as a character sequence consists of non-space characters only.
*
* For example,
* Given s = "Hello World",
* return 5.
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

class Solution0315
{
public:
   static int lengthOfLastWord(const char *s) {

    if ( !s ||!*s ) return 0;

    int wordLen=0;
    int cnt=0;

    for (;*s!='\0';s++) {
        if (isalpha(*s)){
            cnt++;
        }
        if (!isalpha(*s)){
            if (cnt>0){
                wordLen = cnt;
            }
            cnt=0;
        }
    }

    return cnt>0 ? cnt : wordLen;
}
};

void doLC0315LengthOfLastWord()
{
   std::cout << "---------------------------------\n";
   std::cout << "Length of Last Word\n";
   char str[] = "Hello World";
   cout << str << "\n";
   int res = Solution0315::lengthOfLastWord(str);
   cout << "The result: " << res << "\n";
}

#endif
