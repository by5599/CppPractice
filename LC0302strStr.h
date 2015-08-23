#ifndef LC0302_H
#define LC0302_H

#include "Common.h"
#include <string.h>
#include <limits.h>
#include <stdio.h>

using namespace std;

/**********************************************************************************
*
* Implement strStr().
*
* Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.
*
*
**********************************************************************************/

/************
[Easy]
Time Complexity O(N*M)
Space Complexity O(1)
To remember:
1.
************/

class Solution0302
{
public:
   static char *strStr2(char *haystack, char *needle) {

    if(!haystack || !needle ) {
        return NULL;
    }
    if (!*needle ) {
        return haystack;
    }

    char *ph = haystack;
    char* pn = needle;
    for( ;*ph && *pn ; ph++, pn++ );

    //len(haystack) < len(needle)
    if (!*ph && *pn){
        return NULL;
    }
    ph--;

    for( ; *ph; haystack++, ph++) {
        char *q=needle;
        char *p=haystack;
        while(*q && *p && *p==*q){
            p++; q++;
        }
        if (!*q){
            return haystack;
        }
    }

    return NULL;
   }
};

void doLC0302strStr()
{
   std::cout << "---------------------------------\n";
   std::cout << "strStr\n";
   char haystack[] = "mississippi";
   char needle[] = "issi";
   std::cout << "The string: " << haystack << " " << needle << "\n";
   //int res = Solution33::atoi(str);
   //std::cout << "The integer: " << res << std::endl;
   //printf("\"%s\" = %d\n", "2147483648", Solution33::atoi("2147483648"));
   char *res = Solution0302::strStr2(haystack, needle);
   cout << "The result: " << res << "\n";
}

#endif
