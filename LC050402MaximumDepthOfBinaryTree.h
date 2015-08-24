#ifndef LC050402_H
#define LC050402_H

#include "Common.h"
#include "AlgorithmBase.h"
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

/**********************************************************************************
*
* Given a binary tree, find its maximum depth.
*
* The maximum depth is the number of nodes along the longest path from the root node
* down to the farthest leaf node.
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


class Solution050402
{
public:
   static int maxDepth(TreeNode *root) {
        if (root==NULL){
            return 0;
        }
        if (!root->left && !root->right){
            return 1;
        }
        int left=1, right=1;
        if (root->left){
            left += maxDepth(root->left);
        }
        if (root->right){
            right += maxDepth(root->right);
        }
        return left>right?left:right;
    }
};

void doLC050402MaximumDepthOfBinaryTree()
{
   int v[] = {1,2,3,0,0,4,5,0,0,6};
   int arrSize = sizeof(v)/sizeof(int);
   TreeNode* p = createTree(v, arrSize);

   std::cout << "---------------------------------\n";
   std::cout << "05.04.02 Maximum Depth of Binary Tree:\n";
   std::cout << "The tree:\n";
   PrintArray(v, arrSize);

   int res = Solution050402::maxDepth(p);

   cout << "The result: " << res << "\n";

}

#endif
