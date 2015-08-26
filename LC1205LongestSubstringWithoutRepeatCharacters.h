#ifndef LC1205_H
#define LC1205_H

#include "Common.h"
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>

/**********************************************************************************
*
* Given a string, find the length of the longest substring without repeating characters.
* For example, the longest substring without repeating letters for "abcabcbb" is "abc",
* which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*
**********************************************************************************/


/************
[Medium]
Time Complexity O(N)
Space Complexity O(1)
To remember:
1.
************/

class Solution1205
{
public:
   static int lengthOfLongestSubstring(string s) {
    const int MAX_CHARS = 256;
    int m[MAX_CHARS];
    memset(m, -1, sizeof(m));

    int maxLen = 0;
    int lastRepeatPos = -1;
    for(int i=0; i<s.size(); i++){
        if (m[s[i]]!=-1 && lastRepeatPos < m[s[i]]) {
            lastRepeatPos = m[s[i]];
        }
        if ( i - lastRepeatPos > maxLen ){
            maxLen = i - lastRepeatPos;
        }
        m[s[i]] = i;
    }
    return maxLen;
}
};

void doLC1205LongestSubstringWithoutRepeatCharacters()
{
   std::cout << "---------------------------------\n";
   std::cout << "12.05 Longest Substring Without Repeat Characters:\n";
   string s = "abcabcbb";
   std::cout << "The value: " << s << "\n";

   int res = Solution1205::lengthOfLongestSubstring(s);
   std::cout << "The result: " << res << std::endl;
}

#endif
