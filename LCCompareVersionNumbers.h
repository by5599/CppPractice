#ifndef LC_COMPARE_VERSION_NUMBERS_H
#define LC_COMPARE_VERSION_NUMBERS_H

#include "Common.h"
#include "AlgorithmBase.h"
#include "AlgorithmLinkedList.h"

#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>

/**********************************************************************************
 *
 * Compare two version numbers version1 and version1.
 * If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
 *
 * You may assume that the version strings are non-empty and contain only digits and the . character.
 * The . character does not represent a decimal point and is used to separate number sequences.
 * For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
 *
 * Here is an example of version numbers ordering:
 * 0.1 < 1.1 < 1.2 < 13.37
 *
 * Credits:Special thanks to @ts for adding this problem and creating all test cases.
 *
 **********************************************************************************/

/************
[Easy]
Time Complexity O()
Space Complexity O()
To remember:
1.
************/

class SolutionCompareVersionNumbers
{
public:
        static vector<int> &split(const string &s, char delim, vector<int> &elems) {
            stringstream ss(s);
            string item;
            while (getline(ss, item, delim)) {
                elems.push_back(atoi(item.c_str()));
            }
            return elems;
        }


        static vector<int> split(const string &s, char delim) {
            vector<int> elems;
            split(s, delim, elems);
            return elems;
        }

        static void rightTrimZero(vector<int> &v){
            while (v.back() == 0){
                v.pop_back();
            }
        }

        static int compareVersion(string version1, string version2) {

            //split the version by delimer '.'
            vector<int> ver1 = split(version1, '.');
            vector<int> ver2 = split(version2, '.');

            //remove the right Zeros
            rightTrimZero(ver1);
            rightTrimZero(ver2);

            //compare two versions
            for (int i=0; i<ver1.size() && i < ver2.size(); i++) {
                if (ver1[i] < ver2[i]){
                    return -1;
                }else if(ver1[i] > ver2[i]){
                    return 1;
                }
            }

            //if the above for-loop is not returned, which means they are equal so far
            //then check the length.
            if (ver1.size() > ver2.size()) {
                return 1;
            }else if (ver1.size() < ver2.size()) {
                return -1;
            }

            return 0;

        }

};

string getResultString(int val)
{
   string str = "";
   switch (val)
   {
   case 0:
      str = " equals to ";
      break;
   case 1:
      str = " greater than ";
      break;
   case -1:
      str = " less than ";
      break;
   default:
      break;
   }
   return str;
}

void doLCCompareVersionNumbers()
{
   std::cout << "---------------------------------\n";
   std::cout << "Compare Version Numbers\n";

   string ver1 = "1.1.2";
   string ver2 = "1.1.2";
   cout << ver1 << " " << ver2 << "\n";
   int res = SolutionCompareVersionNumbers::compareVersion(ver1,ver2);
   cout << ver1 << getResultString(res) << ver2 << "\n";

   ver1 = "1.1.2";
   ver2 = "1.1.2.3";
   cout << ver1 << " " << ver2 << "\n";
   res = SolutionCompareVersionNumbers::compareVersion(ver1,ver2);
   cout << ver1 << getResultString(res) << ver2 << "\n";
}


#endif
