
#ifndef LC020116_ROTATE_IMAGE_H
#define LC020116_ROTATE_IMAGE_H

#include "Common.h"
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <limits.h>

/**********************************************************************************
*
* You are given an n x n 2D matrix representing an image.
* Rotate the image by 90 degrees (clockwise).
* Follow up:
* Could you do this in-place?
*
*
**********************************************************************************/


/************
[Medium]
Time Complexity O(n), Space Complexity O(n)
To remember:
1.
2.
3.
************/

class Solution020116
{
public:
   static void rotateImage(std::vector<std::vector<int>>& matrix) {
      const int n = matrix.size();
      for (int i = 0; i < n; ++i)
         for (int j = 0; j < n - i; ++j)
            std::swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);

      for (int i = 0; i < n / 2; ++i)
         for (int j = 0; j < n; ++j)
            std::swap(matrix[i][j], matrix[n - 1 - i][j]);
   }
};

void doLC020116RotateImage()
{
   std::vector<std::vector<int>> a =
   {
     {1,2},
     {3,4}
   };

   std::cout << "---------------------------------\n";
   std::cout << "Rotate Image:\n";
   std::cout << "The Matrix:\n";
   for (auto x : a)
   {
      PrintVector(x);
   }
   Solution020116::rotateImage(a);
   std::cout << "The Result:\n";
   for (auto x : a)
   {
      PrintVector(x);
   }
}

#endif
