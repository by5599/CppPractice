#ifndef LC_EXCEL_SHEET_COLUMN_NUMBER_H
#define LC_EXCEL_SHEET_COLUMN_NUMBER_H

#include "Common.h"
#include "AlgorithmBase.h"
#include "AlgorithmLinkedList.h"

#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>

/**********************************************************************************
 *
 * Related to question Excel Sheet Column Title
 * Given a column title as appear in an Excel sheet, return its corresponding column number.
 *
 * For example:
 *     A -> 1
 *     B -> 2
 *     C -> 3
 *     ...
 *     Z -> 26
 *     AA -> 27
 *     AB -> 28
 *
 * Credits:Special thanks to for adding this problem and creating all test cases.
 *
 **********************************************************************************/

/************
[Easy]
Time Complexity O()
Space Complexity O()
To remember:
1.
************/

class SolutionExcelSheetColumnNumber
{
public:
   static long long base26_str2int(string& s){
    long long ret=0;
    for (int i=0; i<s.size(); i++){
        int n = s[i] - 'A' + 1;
        ret = ret*26 + n;
    }
    return ret;
}
};

void doLCExcelSheetColumnNumber()
{
   std::cout << "---------------------------------\n";
   std::cout << "Excel Sheet Column Number\n";

   string title = "ABAB";
   cout << "The title: " << title << "\n";
   long long res = SolutionExcelSheetColumnNumber::base26_str2int(title);
   cout << "The result " << res << "\n";
}


#endif
