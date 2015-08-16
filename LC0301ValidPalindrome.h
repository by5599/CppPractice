#ifndef LC0301_VALID_PALINDROME_H
#define LC0301_VALID_PALINDROME_H

#include "Common.h"
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>

/**********************************************************************************
*
* Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
*
* For example,
* "A man, a plan, a canal: Panama" is a palindrome.
* "race a car" is not a palindrome.
*
* Note:
* Have you consider that the string might be empty? This is a good question to ask during an interview.
*
* For the purpose of this problem, we define empty string as valid palindrome.
*
*
**********************************************************************************/


/************
[Easy]
Time Complexity O(n), Space Complexity O(n)
To remember:
1.
2.
3.
************/

class Solution0301
{
public:
   static bool isPalindrome(std::string s) {
        s = removeNoise(s);
        for(int i=0; i<s.size()/2; i++){
            if (s[i]!= s[s.size()-i-1]){
                return false;
            }
        }
        return true;
    }

    static std::string removeNoise(std::string& s){
        std::string d;
        for(int i=0; i<s.size(); i++){
            if(::isalpha(s[i]) || ::isdigit(s[i])){
                d.push_back(::tolower(s[i]));
            }
        }
        return d;
    }
};

void doLC0301ValidPalindrome()
{
   std::string s = "A man, a plan, a canal: Panama";

   std::cout << "---------------------------------\n";
   std::cout << "Valid Palindrome:\n";
   std::cout << "The string:\n";
   std::cout << s << "\n";
   bool res = Solution0301::isPalindrome(s);
   std::cout << "The string is palindrome: " << (res?"True":"False") << std::endl;

}

#endif
