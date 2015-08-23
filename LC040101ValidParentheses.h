#ifndef LC040101_H
#define LC040101_H

#include "Common.h"
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <stack>

using namespace std;

/**********************************************************************************
*
* Write a function to find the longest common prefix string amongst an array of strings.
*
*
**********************************************************************************/

/************
[Easy]
Time Complexity O()
Space Complexity O()
To remember:
1.
************/

class Solution040101
{
public:
   static bool isValid(string s) {

    string stack;

    while(s.size()>0){

        char lch = s.back();

        if (lch == '[' || lch=='{' || lch=='(') {
            if (s.size()<=0) return false;
            char rch = stack.back();
            if ((lch=='[' && rch ==']') ||
                    (lch=='{' && rch =='}') ||
                    (lch=='(' && rch ==')') ) {
                s.pop_back();
                stack.pop_back();
            }else{
                return false;
            }
        } else if (lch== ']' || lch=='}' || lch==')' ) {
            s.pop_back();
            stack.push_back(lch);
        } else {
            //skip the other charactors
            s.pop_back();
        }
    }
    return (s.size()==0 && stack.size()==0 );
}

};

void doLC040101ValidParentheses()
{
   std::cout << "---------------------------------\n";
   std::cout << "Valid Parentheses\n";
   string s = "{{}{[]()}}";
   cout << s << "\n";
   //int res = Solution33::atoi(str);
   //std::cout << "The integer: " << res << std::endl;
   //printf("\"%s\" = %d\n", "2147483648", Solution33::atoi("2147483648"));
   bool res = Solution040101::isValid(s);
   string str = res?"True":"False";
   cout << "The result: " << str << "\n";
}

#endif
