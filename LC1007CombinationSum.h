#ifndef LC1007_H
#define LC1007_H

#include "Common.h"
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;
/**********************************************************************************
*
* Given a set of candidate numbers (C) and a target number (T), find all unique combinations
* in C where the candidate numbers sums to T.
*
* The same repeated number may be chosen from C unlimited number of times.
*
* Note:
*
* All numbers (including target) will be positive integers.
* Elements in a combination (a1, a2, ¡­ , ak) must be in non-descending order. (ie, a1 ¡Ü a2 ¡Ü ¡­ ¡Ü ak).
* The solution set must not contain duplicate combinations.
*
* For example, given candidate set 2,3,6,7 and target 7,
* A solution set is:
* [7]
* [2, 2, 3]
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

class Solution1007
{
public:
   static void combinationSumHelper(vector<int> &candidates, int start, int target, vector<int> &solution, vector< vector<int> > &result) {
    if (target<0){
        return;
    }
    if (target==0){
        result.push_back(solution);
    }
    for(int i=start; i<candidates.size(); i++){
        //remote duplicates
        if (i>start && candidates[i] == candidates[i-1]) {
            continue;
        }
        solution.push_back(candidates[i]);
        combinationSumHelper(candidates, i, target - candidates[i], solution, result);
        solution.pop_back();
    }
}

static vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    vector< vector<int> > result;
    if (candidates.size()<=0){
        return result;
    }
    sort(candidates.begin(), candidates.end());

    vector<int> solution;
    combinationSumHelper(candidates, 0, target, solution, result);

    return result;
}

};

void doLC1007CombinationSum()
{
   std::cout << "---------------------------------\n";
   std::cout << "10.07 Combination Sum:\n";
   std::cout << "The candidates: \n";
   vector<int> v = {2,3,6,7};
   PrintVector(v);

   vector<vector<int>> res = Solution1007::combinationSum(v,7);
   std::cout << "The result: \n";
   for (auto x : res)
      PrintVector(x);
}

#endif
