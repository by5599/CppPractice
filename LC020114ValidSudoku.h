
#ifndef LC020114_VALID_SUDOKU_H
#define LC020114_VALID_SUDOKU_H

#include "Common.h"
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <limits.h>

/**********************************************************************************
*
* The set [1,2,3,…,n] contains a total of n! unique permutations.
*
* By listing and labeling all of the permutations in order,
* We get the following sequence (ie, for n = 3):
*
* "123"
* "132"
* "213"
* "231"
* "312"
* "321"
*
* Given n and k, return the kth permutation sequence.
*
* Note: Given n will be between 1 and 9 inclusive.
*
*
**********************************************************************************/


/************
[Medium]
Time Complexity O(n), Space Complexity O(n)
To remember:
1.
2.
3.
************/

class Solution020114
{
public:
   static bool isValidSudoku(const std::vector<std::vector<char>>& board) {
      bool used[9];
      for (int i = 0; i < 9; ++i) {
         std::fill(used, used + 9, false);
         for (int j = 0; j < 9; ++j)
            if (!check(board[i][j], used))
               return false;
         std::fill(used, used + 9, false);
         for (int j = 0; j < 9; ++j)
            if (!check(board[j][i], used))
               return false;
      }
      for (int r = 0; r < 3; ++r)
      {
         for (int c = 0; c < 3; ++c) {
            std::fill(used, used + 9, false);
            for (int i = r * 3; i < r * 3 + 3; ++i)
               for (int j = c * 3; j < c * 3 + 3; ++j)
                  if (!check(board[i][j], used))
                     return false;
         }
      }
      return true;
   }
   static bool check(char ch, bool used[9]) {
      if (ch == '.') return true;
      if (used[ch - '1']) return false;
      return used[ch - '1'] = true;
   }
};

void doLC020114ValidSudoku()
{
   std::vector<std::vector<char>> a =
      {
         {'5','3','.','.','7','.','.','.','.'},
         {'6','.','.','1','9','5','.','.','.'},
         {'.','9','8','.','.','.','.','6','.'},
         {'8','.','.','.','6','.','.','.','3'},
         {'4','.','.','8','.','3','.','.','1'},
         {'7','.','.','.','2','.','.','.','6'},
         {'.','6','.','.','.','.','2','8','.'},
         {'.','.','.','4','1','9','.','.','5'},
         {'.','.','.','.','8','.','.','7','9'},
      };

   std::cout << "---------------------------------\n";
   std::cout << "Valid Sudoku:\n";
   std::cout << "The Sudoku:\n";
   for (auto x : a)
   {
      PrintAnything(x);
   }
   //PrintVector(a);
   bool res = Solution020114::isValidSudoku(a);
   std::string result = res?"true":"false";
   std::cout << "The result: " << result << "\n";
   //PrintVector(a);
   //int i = 3;
   //std::cout << "test division: " << i / 2 << "\n";
}

#endif
