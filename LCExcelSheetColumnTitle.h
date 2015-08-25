#ifndef LC_EXCEL_SHEET_COLUMN_TITLE_H
#define LC_EXCEL_SHEET_COLUMN_TITLE_H

#include "Common.h"
#include "AlgorithmBase.h"
#include "AlgorithmLinkedList.h"

#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>

/**********************************************************************************
 *
 * Given a positive integer, return its corresponding column title as appear in an Excel sheet.
 *
 * For example:
 *
 *     1 -> A
 *     2 -> B
 *     3 -> C
 *     ...
 *     26 -> Z
 *     27 -> AA
 *     28 -> AB
 *
 * Credits:Special thanks to @ifanchu for adding this problem and creating all test cases.
 *
 **********************************************************************************/

/************
[Easy]
Time Complexity O()
Space Complexity O()
To remember:
1.
************/

class SolutionExcelSheetColumnTitle
{
public:
   static string base26_int2str(long long n) {
      string ret;
      while(n>0){
        char ch = 'A' + (n-1)%26;
        ret.insert(ret.begin(), ch  );
        n -= (n-1)%26;
        n /= 26;
      }
      return ret;
   }
};

void doLCExcelSheetColumnTitle()
{
   std::cout << "---------------------------------\n";
   std::cout << "Excel Sheet Column Title\n";

   int n = 28;
   cout << "The value: " << n << "\n";
   string res = SolutionExcelSheetColumnTitle::base26_int2str(n);
   cout << "The result " << res << "\n";
}


#endif
