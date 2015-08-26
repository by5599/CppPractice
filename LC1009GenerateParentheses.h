#ifndef LC1009_H
#define LC1009_H

#include "Common.h"
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;
/**********************************************************************************
*
* Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
*
* For example, given n = 3, a solution set is:
*
* "((()))", "(()())", "(())()", "()(())", "()()()"
*
*
**********************************************************************************/


/************
[Medium]
Time Complexity O()
Space Complexity O(n)
To remember:
1.
************/

class Solution1009
{
public:
   static vector<string> generateParenthesis(int n) {

    vector<string> result;
    string s;
    generator(result, n, n, s);
    return result;
}

static void generator(vector<string>& result, int left, int right, string s){
    if (left==0 && right==0){
        result.push_back(s);
        return;
    }
    if (left>0){
        generator(result, left-1, right, s+'(');
    }
    if (right>0 && right>left){
        generator(result, left, right-1, s+')');
    }
}

};

void doLC1009GenerateParentheses()
{
   std::cout << "---------------------------------\n";
   std::cout << "10.09 Generate Parentheses:\n";
   std::cout << "The value: 3\n";

   vector<string> res = Solution1009::generateParenthesis(3);
   std::cout << "The result: \n";
   PrintAnything(res);
}

#endif
