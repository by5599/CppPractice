#ifndef LC050403_H
#define LC050403_H

#include "Common.h"
#include "AlgorithmBase.h"
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

/**********************************************************************************
*
* Given a binary tree and a sum, determine if the tree has a root-to-leaf path
* such that adding up all the values along the path equals the given sum.
*
* For example:
* Given the below binary tree and sum = 22,
*
*               5
*              / \
*             4   8
*            /   / \
*           11  13  4
*          /  \      \
*         7    2      1
*
* return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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


class Solution050403
{
public:
   static bool hasPathSum(TreeNode *root, int sum) {
        //if (random()%2){
            return hasPathSum1(root, sum);
        //}
        //return hasPathSum2(root, sum);
    }

    static bool hasPathSum1(TreeNode *root, int sum) {
        if (root==NULL) return false;
        vector<TreeNode*> v;
        v.push_back(root);
        while(v.size()>0){
            TreeNode* node = v.back();
            v.pop_back();
            if (node->left==NULL && node->right==NULL){
                if (node->val == sum){
                    return true;
                }
            }
            if (node->left){
                node->left->val += node->val;
                v.push_back(node->left);
            }
            if (node->right){
                node->right->val += node->val;
                v.push_back(node->right);
            }
        }
        return false;

    }

    static bool hasPathSum2(TreeNode *root, int sum) {

        if (root==NULL) return false;

        if (root->left==NULL && root->right==NULL ){
            return (root->val==sum);
        }

        if (root->left){
            root->left->val += root->val;
            if (hasPathSum2(root->left, sum)){
                return true;
            }
        }

        if (root->right){
            root->right->val += root->val;
            if (hasPathSum2(root->right, sum)){
                return true;
            }
        }

        return false;
    }


};

void doLC050403PathSum()
{
   int v[] = {5,4,8,11,0,13,4,7,2,0,0,0,1};
   int arrSize = sizeof(v)/sizeof(int);
   TreeNode* p = createTree(v, arrSize);

   std::cout << "---------------------------------\n";
   std::cout << "05.04.03 Path Sum:\n";
   std::cout << "The tree:\n";
   PrintArray(v, arrSize);

   bool res = Solution050403::hasPathSum(p,22);
   string str = res?"True":"False";
   cout << "The result: " << str << "\n";

}

#endif
