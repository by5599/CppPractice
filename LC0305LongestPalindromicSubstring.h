#ifndef LC0305_H
#define LC0305_H

#include "Common.h"
#include <string.h>
#include <limits.h>
#include <stdio.h>

using namespace std;

/**********************************************************************************
*
* Given a string S, find the longest palindromic substring in S.
* You may assume that the maximum length of S is 1000,
* and there exists one unique longest palindromic substring.
*
**********************************************************************************/

/************
[Medium]
Time Complexity O()
Space Complexity O()
To remember:
1.
************/

class Solution0305
{
public:
   static string findPalindrome(string s, int left, int right)
{
    int n = s.size();
    int l = left;
    int r = right;
    while (left>=0 && right<=n-1 && s[left] == s[right]) {
        left--;
        right++;
    }
    return s.substr(left+1, right-left-1);
}


// This is the common solution.
// Actuatlly it's faster than DP solution under Leetcode's test
// the below optimized DP solution need 700ms+, this needs around 250ms.
static string longestPalindrome_recursive_way(string s) {
    int n = s.size();
    if (n<=1) return s;

    string longest;

    string str;
    for (int i=0; i<n-1; i++) {
        str = findPalindrome(s, i, i);
        if (str.size() > longest.size()){
            longest = str;
        }
        str = findPalindrome(s, i, i+1);
        if (str.size() > longest.size()){
            longest = str;
        }
    }

    return longest;
}

};

void doLC0305LongestPalindromicSubstring()
{
   std::cout << "---------------------------------\n";
   std::cout << "Longest Palindromic Substring\n";
   string s = "abacdfgdcaba";

   cout << "The string: " << s << "\n";
   string res = Solution0305::longestPalindrome_recursive_way(s);
   cout << "The result: " << res << "\n";
}

#endif
