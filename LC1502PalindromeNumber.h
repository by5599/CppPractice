#ifndef LC1502_H
#define LC1502_H

#include "Common.h"
#include <string.h>
#include <limits.h>
#include <stdio.h>

/**********************************************************************************
*
* Determine whether an integer is a palindrome. Do this without extra space.
*
*
* Some hints:
*
* Could negative integers be palindromes? (ie, -1)
*
* If you are thinking of converting the integer to string, note the restriction of using extra space.
*
* You could also try reversing an integer. However, if you have solved the problem "Reverse Integer",
* you know that the reversed integer might overflow. How would you handle such case?
*
* There is a more generic way of solving this problem.
*
*
**********************************************************************************/

/************
[Easy]
Time Complexity O(1)
Space Complexity O(1)
To remember:
1.
************/

class Solution1502
{
public:
   static bool isPalindrome(int x) {
        if (x<0) {
            return false;
        }

        int len=1;
        for (len=1; (x/len) >= 10; len*=10 );

        while (x != 0 ) {
            int left = x / len;
            int right = x % 10;

            if(left!=right){
                return false;
            }

            x = (x%len) / 10;
            len /= 100;
        }
        return true;
    }
};

void doLC1502PalindromeNumber()
{
   std::cout << "---------------------------------\n";
   std::cout << "Palindrome Number\n";
   int v = 12321;
   std::cout << "The integer: " << v << "\n";
   bool res = Solution1502::isPalindrome(v);
   string str = res?"True":"False";
   std::cout << "The number is palindrome: " << str << "\n";

}

#endif
