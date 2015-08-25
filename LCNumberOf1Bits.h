#ifndef LC_NUMBER_OF_1_BITS_H
#define LC_NUMBER_OF_1_BITS_H

#include "Common.h"
#include "AlgorithmBase.h"
#include "AlgorithmLinkedList.h"

#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>

/**********************************************************************************
*
* Write a function that takes an unsigned integer and returns the number of ¡¯1' bits it has
* (also known as the Hamming weight).
*
* For example, the 32-bit integer ¡¯11' has binary representation 00000000000000000000000000001011,
* so the function should return 3.
*
* Credits:Special thanks to for adding this problem and creating all test cases.
*
**********************************************************************************/

/************
[Easy]
Time Complexity O()
Space Complexity O()
To remember:
1.
************/

class SolutionNumberOf1Bits
{
public:
   static int hammingWeight(uint32_t n) {
        int cnt = 0;
        for(;n>0; n/=2){
            if (n & 0x1) cnt++;
        }
        return cnt;
    }
};

void doLCNumberOf1Bits()
{
   std::cout << "---------------------------------\n";
   std::cout << "Number of 1 Bits\n";

   uint32_t n = 0X0B;
   printf("%d\n", n);
   int res = SolutionNumberOf1Bits::hammingWeight(n);
   cout << "Number of 1 bits: " << res << "\n";
}


#endif
