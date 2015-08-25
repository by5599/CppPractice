#ifndef LC_TWO_SUM_III_H
#define LC_TWO_SUM_III_H

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
* Design and implement a TwoSum class. It should support the following operations: add and find.
*
* add - Add the number to an internal data structure.
* find - Find if there exists any pair of numbers which sum is equal to the value.
*
* For example,
*
*   add(1); add(3); add(5);
*   find(4) -> true
*   find(7) -> false
*
**********************************************************************************/

/************
[Easy]
Time Complexity O()
Space Complexity O()
To remember:
1.
************/

class SolutionTwoSumIII
{
public:
   static unordered_map<int, int> nums;
           //O(1) add
   static void add(int number) {
            nums[number]++;
        }

        //O(n) find
   static bool find(int value) {
            int one, two;
            for(auto it = nums.begin(); it != nums.end(); it++){
                one = it->first;
                two = value - one;
                if ( (one == two && it->second > 1) ||
                        (one != two && nums.find(two) != nums.end() ) ){
                    return true;
                }
            }
            return false;
        }
};

 unordered_map<int, int> SolutionTwoSumIII::nums = {{0,0}};

void doLCTwoSumIII()
{
   std::cout << "---------------------------------\n";
   std::cout << "Two Sum III\n";

   SolutionTwoSumIII::add(1);
   SolutionTwoSumIII::add(3);
   SolutionTwoSumIII::add(5);
   bool res = SolutionTwoSumIII::find(4);
   string str = res?"True":"False";
   cout << "The result: " << str << "\n";
}


#endif
