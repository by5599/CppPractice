#ifndef LC0314_H
#define LC0314_H

#include "Common.h"
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <sstream>
#include <map>

using namespace std;

/**********************************************************************************
*
* Given an absolute path for a file (Unix-style), simplify it.
*
* For example,
* path = "/home/", => "/home"
* path = "/a/./b/../../c/", => "/c"
*
*
* Corner Cases:
*
* Did you consider the case where path = "/../"?
* In this case, you should return "/".
* Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
* In this case, you should ignore redundant slashes and return "/home/foo".
*
*
**********************************************************************************/

/************
[Medium]
Time Complexity O(N)
Space Complexity O(N)
To remember:
1.
************/

class Solution0314
{
public:
   static vector<string> &split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


static vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}


static string simplifyPath(string path) {

    string result;
    vector<string> elems = split(path, '/');
      for (auto x : elems)
         cout << x << endl;
    int ignor = 0;
    for(int i = elems.size()-1; i>=0; i--) {
      //cout << result << endl;
        if (elems[i]=="" || elems[i]=="." ){
            continue;
        }
        if (elems[i]==".."){
            ignor++;
            continue;
        }
        if (ignor>0){
            ignor--;
            continue;
        }
        if (result.size()==0){
            result = "/" + elems[i];
        }else{
            result = "/" + elems[i] + result;
        }
    }

    return  result.size() ? result : "/";

}


};

void doLC0314SimplifyPath()
{
   std::cout << "---------------------------------\n";
   std::cout << "3.14 Simplify Path\n";
    string path("/a/./b/../../c/");


    cout << path << " : " << Solution0314::simplifyPath(path) << endl;
}

#endif
