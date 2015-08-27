#ifndef LC1101_H
#define LC1101_H

#include "Common.h"
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>

/**********************************************************************************
*
* Implement pow(x, n).
*
*
**********************************************************************************/


/************
[Medium]
Time Complexity O(), Space Complexity O()
To remember:
1.
************/

/*
 *   Basically, most people think this is very easy as below:
 *
 *      double result = 1.0;
 *      for (int i=0; i<n; i++){
 *           result *=x;
 *      }
 *
 *   However,
 *
 *     1) We need think about the `n` is negtive number.
 *
 *     2) We need more wisely deal with the following cases:
 *
 *         pow(1, MAX_INT);
 *         pow(-1,BIG_INT);
 *         pow(2, BIG_INT);
 *
 *        To deal with such kind case, we can use x = x*x to reduce the `n` more quickly
 *
 *        so, if `n` is an even number, we can `x = x*x`, and `n = n>>1;`
 *            if `n` is an odd number, we can just `result *= x;`
 *
 */
class Solution1101
{
public:
   static double pow(double x, int n) {

    bool sign = false;
    unsigned int exp = n;
    if(n<0){
        exp = -n;
        sign = true;
    }
    double result = 1.0;
    while (exp) {
        if (exp & 1){
            result *= x;
        }
        exp >>= 1;
        x *= x;
    }

    return sign ? 1/result : result;

}

};

void doLC1101Pow()
{
   std::cout << "---------------------------------\n";
   std::cout << "11.01 Pow:\n";
   std::cout << "The value: 3^4\n";

   double res = Solution1101::pow(3.0,4);
   std::cout << "The result: " << res << std::endl;
}

#endif
