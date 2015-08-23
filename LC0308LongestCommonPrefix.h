#ifndef LC0308_H
#define LC0308_H

#include "Common.h"
#include <string.h>
#include <limits.h>
#include <stdio.h>

using namespace std;

/**********************************************************************************
*
* Write a function to find the longest common prefix string amongst an array of strings.
*
*
**********************************************************************************/

/************
[Easy]
Time Complexity O(N1+N2+...+NM)
Space Complexity O()
To remember:
1.
************/

class Solution0308
{
public:
   static string longestCommonPrefix(vector<string> &strs) {
    string word;
    if (strs.size()<=0) return word;
    for(int i=1; i<=strs[0].size(); i++){
        string w = strs[0].substr(0, i);
        bool match = true;
        int j=1;
        for(j=1; j<strs.size(); j++){
            if (i>strs[j].size() || w!=strs[j].substr(0, i) ) {
                match=false;
                break;
            }
        }
        if (!match) {
            return word;
        }
        word = w;
    }
    return word;
   }

};

void doLC0308LongestCommonPrefix()
{
   std::cout << "---------------------------------\n";
   std::cout << "Longest Common Prefix\n";
    const char* s[]={"abab","aba","abc"};
    vector<string> v(s, s+3);
   for (auto x : v)
   {
      cout << x << "\n";
   }
   //int res = Solution33::atoi(str);
   //std::cout << "The integer: " << res << std::endl;
   //printf("\"%s\" = %d\n", "2147483648", Solution33::atoi("2147483648"));
   string str = Solution0308::longestCommonPrefix(v);
   cout << "The result: " << str << "\n";
}

#endif
