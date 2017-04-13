#ifndef LC_BITWISE_AND_OF_NUMBERS_RANGE_H
#define LC_BITWISE_AND_OF_NUMBERS_RANGE_H

#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>

/**********************************************************************************
* Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
* For example, given the range [5, 7], you should return 4.
*
**********************************************************************************/


/************
[Medium]
Time Complexity O(n), Space Complexity O(n)
To remember:
1. Use a map
2. Extend the finding and set the flag
3.
************/

class SolutionBitwiseAndOfNumbersRange
{
public:
   static int rangeBitwiseAnd(int m, int n) {
        int d = INT_MAX;
        while ((m & d) != (n & d)) {
            d <<= 1;
        }
        return m & d;
    }
};

void doLCBitwiseAndOfNumbersRange()
{
   std::cout << "---------------------------------\n";
   std::cout << "Bitwise AND of Numbers Range\n";
   int m = 5, n = 7;
   std::cout << "The integer: " << m << " " << n << "\n";
   int res = SolutionBitwiseAndOfNumbersRange::rangeBitwiseAnd(m, n);
   std::cout << "Result: " << res << "\n";
}

#endif
