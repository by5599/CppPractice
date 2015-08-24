#ifndef LC050401_H
#define LC050401_H

#include "Common.h"
#include "AlgorithmBase.h"
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

/**********************************************************************************
*
* Given a binary tree, find its minimum depth.
*
* The minimum depth is the number of nodes along the shortest path from the root node
* down to the nearest leaf node.
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


class Solution050401
{
public:
   static int minDepth(TreeNode *root) {
        if (root==NULL){
            return 0;
        }
        if (root->left==NULL && root->right==NULL){
            return 1;
        }
        int left=INT_MAX;
        if (root->left){
            left = minDepth(root->left) + 1 ;
        }
        int right=INT_MAX;
        if (root->right){
            right = minDepth(root->right) + 1;
        }

        return left<right ? left : right;

    }
};

void doLC050401MinimumDepthOfBinaryTree()
{
   int v[] = {1,2,3,0,0,4,5,0,0,6};
   int arrSize = sizeof(v)/sizeof(int);
   TreeNode* p = createTree(v, arrSize);

   std::cout << "---------------------------------\n";
   std::cout << "05.04.01 Minimum Depth of Binary Tree:\n";
   std::cout << "The tree:\n";
   PrintArray(v, arrSize);

   int res = Solution050401::minDepth(p);

   cout << "The result: " << res << "\n";

}

#endif
