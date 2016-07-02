#ifndef LC33_STRING_TO_INTEGER_H
#define LC33_STRING_TO_INTEGER_H

#include "Common.h"
#include <string.h>
#include <limits.h>
#include <stdio.h>

/**********************************************************************************
*
* Implement atoi to convert a string to an integer.
*
* Hint: Carefully consider all possible input cases. If you want a challenge,
*       please do not see below and ask yourself what are the possible input cases.
*
* Notes:
*   It is intended for this problem to be specified vaguely (ie, no given input specs).
*   You are responsible to gather all the input requirements up front.
*
*
* Requirements for atoi:
*
* The function first discards as many whitespace characters as necessary until the first
* non-whitespace character is found. Then, starting from this character, takes an optional
* initial plus or minus sign followed by as many numerical digits as possible, and interprets
* them as a numerical value.
*
* The string can contain additional characters after those that form the integral number,
* which are ignored and have no effect on the behavior of this function.
*
* If the first sequence of non-whitespace characters in str is not a valid integral number,
* or if no such sequence exists because either str is empty or it contains only whitespace
* characters, no conversion is performed.
*
* If no valid conversion could be performed, a zero value is returned. If the correct value
* is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648)
* is returned.
*
**********************************************************************************/

/************
[Easy]
Time Complexity O(n)
Space Complexity O(1)
To remember:
1. Skip the leading spaces
2. Find the sign
3. Calculate but consider the max numbers
************/

class Solution33
{
public:
   static int atoi(const char *str) {
      int num = 0;
      int sign = 1;
      const int n = strlen(str);
      int i = 0;
      // Skip the leading spaces
      while (str[i] == ' ' && i < n) i++;

      // Find the sign
      if (str[i] == '+') {
         i++;
      } else if (str[i] == '-') {
         sign = -1;
         i++;
      }
      for (; i < n; i++) {
         if (str[i] < '0' || str[i] > '9')
            break;
         if ( num > INT_MAX / 10 ||
             (num == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10))
         {
            return sign == -1 ? INT_MIN : INT_MAX;
         }
         num = num * 10 + str[i] - '0';
      }
      return num * sign;
   }
};

void doLC33atoi()
{
   std::cout << "---------------------------------\n";
   std::cout << "String to integer\n";
   char str[] = "123";
   std::cout << "The string: " << str << "\n";
   //int res = Solution33::atoi(str);
   //std::cout << "The integer: " << res << std::endl;
   //printf("\"%s\" = %d\n", "2147483648", Solution33::atoi("2147483648"));

   printf("\"%s\" = %d\n", "123", Solution33::atoi("123"));
   printf("\"%s\" = %d\n", "   123", Solution33::atoi("    123"));
   printf("\"%s\" = %d\n", "+123", Solution33::atoi("+123"));
   printf("\"%s\" = %d\n", " -123", Solution33::atoi(" -123"));
   printf("\"%s\" = %d\n", "123ABC", Solution33::atoi("123ABC"));
   printf("\"%s\" = %d\n", " abc123ABC", Solution33::atoi(" abc123ABC"));
   printf("\"%s\" = %d\n", "2147483647", Solution33::atoi("2147483647"));
   printf("\"%s\" = %d\n", "-2147483648", Solution33::atoi("-2147483648"));
   printf("\"%s\" = %d\n", "2147483648", Solution33::atoi("2147483648"));
   printf("\"%s\" = %d\n", "-2147483649", Solution33::atoi("-2147483649"));
}

#endif
