#ifndef LC_REVERSE_BITS_H
#define LC_REVERSE_BITS_H

#include "Common.h"
#include "AlgorithmBase.h"
#include "AlgorithmLinkedList.h"

#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>

/**********************************************************************************
*
* Reverse bits of a given 32 bits unsigned integer.
*
* For example, given input 43261596 (represented in binary as 00000010100101000001111010011100),
* return 964176192 (represented in binary as 00111001011110000010100101000000).
*
* Follow up:
* If this function is called many times, how would you optimize it?
*
* Related problem: Reverse Integer
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

class SolutionReverseBits
{
public:
   static uint32_t reverseBits(uint32_t n) {
        uint32_t ret=0;
        for(int i=0; i<32; i++) {
            ret = (ret << 1) + (n & 0x1);
            n = n >> 1 ;
        }
        return ret;
    }
};

void doLCReverseBits()
{
   std::cout << "---------------------------------\n";
   std::cout << "Reverse Bits\n";

   uint32_t n = 43261596;
   printf("%d\n", n);
   uint32_t res = SolutionReverseBits::reverseBits(n);
   printf("%d\n", res);
}


#endif
