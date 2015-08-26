#ifndef LC1513_H
#define LC1513_H

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
* Divide two integers without using multiplication, division and mod operator.
*
* If it is overflow, return MAX_INT.
*
**********************************************************************************/


/************
[Medium]
Time Complexity
Space Complexity
To remember:
1.
************/

#define INT_MAX     2147483647
#define INT_MIN     (-INT_MAX - 1)

class Solution1513
{
public:
   static int divide(int dividend, int divisor) {
      long long a = dividend >= 0 ? dividend : -(long long)dividend;
      long long b = divisor >= 0 ? divisor : -(long long)divisor;
      long long result = 0;
      while (a >= b) {
         long long c = b;
         for (int i = 0; a >= c; ++i, c <<= 1) {
            a -= c;
            result += 1 << i;
         }
      }
      return ((dividend^divisor) >> 31) ? (-result) : (result);
   }

};

void doLC1513DivideTwoIntegers()
{

   std::cout << "---------------------------------\n";
   std::cout << "15.13 Divide Two Integers:\n";
    cout << "0/2=" << Solution1513::divide(0, 2) << endl;
    cout << "10/2=" << Solution1513::divide(10, 2) << endl;
    cout << "10/3=" << Solution1513::divide(10, 3) << endl;
    cout << "10/5=" << Solution1513::divide(10, 5) << endl;
    cout << "10/7=" << Solution1513::divide(10, 7) << endl;
    cout << "10/10=" << Solution1513::divide(10, 10) << endl;
    cout << "10/11=" << Solution1513::divide(10, 11) << endl;
    cout << "-1/1=" << Solution1513::divide(1, -1) << endl;
    cout << "1/-1=" << Solution1513::divide(1, -1) << endl;
    cout << "-1/-1=" << Solution1513::divide(-1, -1) << endl;
    cout << "2147483647/1=" << Solution1513::divide(2147483647, 1) << endl;
    cout << "-2147483647/1=" << Solution1513::divide(-2147483647, 1) << endl;
    cout << "2147483647/-1=" << Solution1513::divide(2147483647, -1) << endl;
    cout << "-2147483647/-1=" << Solution1513::divide(-2147483647, -1) << endl;
    cout << "2147483647/2=" << Solution1513::divide(2147483647, 2) << endl;
    cout << "2147483647/10=" << Solution1513::divide(2147483647, 10) << endl;
    cout << "-2147483648/1=" << Solution1513::divide(-2147483648, 1) << endl;
    cout << "-2147483648/-1=" << Solution1513::divide(-2147483648, -1) << endl;
}

#endif
