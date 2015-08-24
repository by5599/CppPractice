#ifndef LC050110_H
#define LC050110_H

#include "Common.h"
#include "AlgorithmBase.h"
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

/**********************************************************************************
*
* Given a binary tree, determine if it is height-balanced.
*
* For this problem, a height-balanced binary tree is defined as a binary tree in which
* the depth of the two subtrees of every node never differ by more than 1.
*
*
**********************************************************************************/

/************
[Easy]
Time Complexity O(N)
Space Complexity O(LogN)
To remember:
1.
2.
3.
************/


class Solution050110
{
public:
   static bool isBalanced (TreeNode* root) {
      return balancedHeight (root) >= 0;
   }
   /**
   * Returns the height of `root` if `root` is a balanced tree,
   * otherwise, returns `-1`.
   */
   static int balancedHeight (TreeNode* root) {
      if (root == nullptr) return 0;
      int left = balancedHeight (root->left);
      int right = balancedHeight (root->right);
      if (left < 0 || right < 0 || abs(left - right) > 1) return -1;
      return max(left, right) + 1;
   }
};

void doLC050110BalancedBinaryTree()
{
   int v[] = {1,2,3,0,0,4,5};
   int arrSize = sizeof(v)/sizeof(int);
   TreeNode* p = createTree(v, arrSize);

   std::cout << "---------------------------------\n";
   std::cout << "05.01.10 Balanced Binary Tree:\n";
   std::cout << "The tree:\n";
   PrintArray(v, arrSize);

   bool res = Solution050110::isBalanced(p);
   string str = res?"True":"False";
   cout << "The result: " << str << "\n";

}

#endif
