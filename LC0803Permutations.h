#ifndef LC0803_H
#define LC0803_H

#include "Common.h"
#include "AlgorithmBase.h"
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

/**********************************************************************************
*
* Given a collection of numbers, return all possible permutations.
*
* For example,
* [1,2,3] have the following permutations:
* [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*
*
**********************************************************************************/

/************
[Medium]
Time Complexity O()
Space Complexity O()
To remember:
1.
2.
3.
************/

/*
{ 1 2 3 }
{ 2 1 3 }
{ 3 2 1 }
{ 1 3 2 }
{ 2 3 1 }
{ 3 1 2 }
*/

/*
 *    The algroithm - Take each element in array to the first place.
 *
 *    For example:
 *
 *         0) initalization
 *
 *             pos = 0
 *             [1, 2, 3]
 *
 *         1) take each element into the first place,
 *
 *             pos = 1
 *             [1, 2, 3]  ==>  [2, 1, 3] , [3, 1, 2]
 *
 *             then we have total 3 answers
 *             [1, 2, 3],  [2, 1, 3] , [3, 1, 2]
 *
 *         2) take each element into the "first place" -- pos
 *
 *             pos = 2
 *             [1, 2, 3]  ==>  [1, 3, 2]
 *             [2, 1, 3]  ==>  [2, 3, 1]
 *             [3, 1, 2]  ==>  [3, 2, 1]
 *
 *             then we have total 6 answers
 *             [1, 2, 3],  [2, 1, 3] , [3, 1, 2], [1, 3, 2], [2, 3, 1], [3, 2, 1]
 *
 *          3) pos = 3 which greater than length of array, return.
 *
 */
class Solution0803
{
public:
   static vector<vector<int> > permute(vector<int> &num) {

    vector<vector<int> > vv;
    vv.push_back(num);

    if (num.size() <2){
        return vv;
    }

    int pos=0;
    while(pos<num.size()-1){
        int size = vv.size();
        for(int i=0; i<size; i++){
            //take each number to the first place
            for (int j=pos+1; j<vv[i].size(); j++) {
                vector<int> v = vv[i];
                int t = v[j];
                v[j] = v[pos];
                v[pos] = t;
                vv.push_back(v);
            }
        }
        pos++;
    }
    return vv;
}

};

void doLC0803Permutations()
{
   std::cout << "---------------------------------\n";
   std::cout << "08.03 Permutations:\n";
   vector<int> v = {1,2,3};
   std::cout << "The vector: \n";
   PrintVector(v);

   vector<vector<int>> res = Solution0803::permute(v);
   cout << "The result: \n";
   for (auto x : res)
      PrintVector(x);

}

#endif