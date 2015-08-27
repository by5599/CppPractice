#ifndef LC0313_H
#define LC0313_H

#include "Common.h"
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <sstream>
#include <map>

using namespace std;

/**********************************************************************************
*
* Given an array of strings, return all groups of strings that are anagrams.
*
* Note: All inputs will be in lower-case.
*
**********************************************************************************/

/************
[Medium]
Time Complexity O(N)
Space Complexity O(N)
To remember:
1.
************/

class Solution0313
{
public:
   static vector<string> anagrams(vector<string> &strs) {
        vector<string> result;
        map<string, int> m;
        for(int i=0; i<strs.size(); i++){
            string word = strs[i];
            //sort it can easy to check they are anagrams or not
            sort(word.begin(), word.end());
            if (m.find(word)==m.end()){
                m[word] = i;
            }else{
                if (m[word]>=0){
                    result.push_back(strs[m[word]]);
                    m[word]=-1;
                }
                result.push_back(strs[i]);
            }
        }
        return result;
    }

};

void doLC0313Anagrams()
{
   std::cout << "---------------------------------\n";
   std::cout << "3.13 Anagrams\n";
   vector<string> v = {"dormitory", "dirtyroom", "special"};
   for (auto x : v)
      cout << x << endl;
   vector<string> res = Solution0313::anagrams(v);
   for (auto x : res)
      cout << x << endl;
}

#endif
