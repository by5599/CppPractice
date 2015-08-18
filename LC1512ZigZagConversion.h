#ifndef LC1512_ZIGZAG_CONVERSION_H
#define LC1512_ZIGZAG_CONVERSION_H

#include "Common.h"
#include "AlgorithmBase.h"
#include "AlgorithmLinkedList.h"

#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;
/**********************************************************************************
*
* The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
* (you may want to display this pattern in a fixed font for better legibility)
*
* P   A   H   N
* A P L S I I G
* Y   I   R
*
* And then read line by line: "PAHNAPLSIIGYIR"
*
* Write the code that will take a string and make this conversion given a number of rows:
*
* string convert(string text, int nRows);
*
* convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*
*
**********************************************************************************/


/************
[Easy]
Time Complexity
Space Complexity
To remember:
1.
************/

class Solution1512
{
public:
   static std::string convert(std::string s, int nRows) {
      if (nRows <= 1 || s.size() <= 1) return s;
         std::string result;
         for (int i = 0; i < nRows; i++) {
            for (int j = 0, index = i; index < s.size(); j++, index = (2 * nRows - 2) * j + i) {
               result.append(1, s[index]);
               if (i == 0 || i == nRows - 1) continue;
               if (index + (nRows - i - 1) * 2 < s.size())
                  result.append(1, s[index + (nRows - i - 1) * 2]);
            }
         }
      return result;
   }

};

void doLC1512ZigzagConversion()
{
   std::string s = "PAYPALISHIRING";

   std::cout << "---------------------------------\n";
   std::cout << "Zigzag Conversion:\n";
   std::cout << "The string: " << s << "\n";

   string res = Solution1512::convert(s, 5);
   std::cout << "The result: " << res << "\n";
}

#endif
