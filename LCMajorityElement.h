#ifndef LC_MAJORITY_ELEMENT_H
#define LC_MAJORITY_ELEMENT_H

#include "Common.h"
#include "AlgorithmBase.h"
#include "AlgorithmLinkedList.h"

#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;
/**********************************************************************************
 *
 * Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 *
 * You may assume that the array is non-empty and the majority element always exist in the array.
 *
 * Credits:Special thanks to ts for adding this problem and creating all test cases.
 *
 **********************************************************************************/

/************
[Easy]
Time Complexity O()
Space Complexity O()
To remember:
1.
************/

class SolutionMajorityElement
{
public:
   static int majorityElement(vector<int> &num) {
    int majority;
    int cnt = 0;
    for(int i=0; i<num.size(); i++){
        if ( cnt ==0 ){
            majority = num[i];
            cnt++;
        }else{
            majority == num[i] ? cnt++ : cnt --;
            if (cnt >= num.size()/2+1) return majority;
        }
    }
    return majority;

}


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

};

void doLCMajorityElement()
{
   std::cout << "---------------------------------\n";
   std::cout << "Majority Element\n";

   string array = "1,2,1,2,1,2,1,2,1,2,1";

    vector<int> num = SolutionMajorityElement::split(array, ',');
    PrintVector(num);
    cout << SolutionMajorityElement::majorityElement(num) <<endl;
}


#endif
