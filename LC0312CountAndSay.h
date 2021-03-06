#ifndef LC0312_H
#define LC0312_H

#include "Common.h"
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <sstream>

using namespace std;

/**********************************************************************************
*
* The count-and-say sequence is the sequence of integers beginning as follows:
* 1, 11, 21, 1211, 111221, ...
*
* 1 is read off as "one 1" or 11.
* 11 is read off as "two 1s" or 21.
* 21 is read off as "one 2, then one 1" or 1211.
*
* Given an integer n, generate the nth sequence.
*
* Note: The sequence of integers will be represented as a string.
*
*
**********************************************************************************/

/************
[Easy]
Time Complexity O(N^2)
Space Complexity O(N)
To remember:
1.
************/

class Solution0312
{
public:
   static string vecToStr(vector<int> v) {
    stringstream ss;
    for (int i=0; i<v.size(); i++) {
        ss << v[i];
    }
    return ss.str();
}

static vector<int> getNext(vector<int>& v) {
    int cnt=0;
    int val=0;
    vector<int> ret;
    for(int i=0; i<v.size(); i++){
        if (i==0){
            val = v[i];
            cnt = 1;
            continue;
        }
        if (v[i] == val){
            cnt++;
        }else{
            ret.push_back(cnt);
            ret.push_back(val);
            val = v[i];
            cnt = 1;
        }
    }
    if (cnt>0 && val>0){
        ret.push_back(cnt);
        ret.push_back(val);
    }
    return ret;
}


static string countAndSay(int n) {
    if (n<=0) return "";
    if (n==1) return "1";

    string s;
    vector<int> v;
    v.push_back(1);
    for(int i=2; i<=n; i++){
       v = getNext(v);
       //s = s + ", " +vecToStr(v);
    }
    s = vecToStr(v);
    return s;
}

};

void doLC0312CountAndSay()
{
   std::cout << "---------------------------------\n";
   std::cout << "Count And Say\n";
   string res = Solution0312::countAndSay(3);
   cout << "The result: " << res << "\n";
   res = Solution0312::countAndSay(4);
   cout << "The result: " << res << "\n";
   res = Solution0312::countAndSay(5);
   cout << "The result: " << res << "\n";
}

#endif
