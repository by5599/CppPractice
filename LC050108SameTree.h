#ifndef LC050108_H
#define LC050108_H

#include "Common.h"
#include "AlgorithmBase.h"
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

/**********************************************************************************
*
* Given two binary trees, write a function to check if they are equal or not.
*
* Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
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


class Solution050108
{
public:
   static bool isSameTree(TreeNode *p, TreeNode *q) {

        queue<TreeNode*> q1, q2;
        q1.push(p);
        q2.push(q);
        while (q1.size()>0 && q2.size()>0 ){
            TreeNode* p1 = q1.front();
            q1.pop();
            TreeNode* p2 = q2.front();
            q2.pop();
            if (!p1 && !p2) continue;
            if (!p1 || !p2)  return false;

            if ( p1->val != p2->val) {
                return false;
            }

            q1.push(p1->left);
            q2.push(p2->left);

            q1.push(p1->right);
            q2.push(p2->right);

        }
        return true;
    }
};

void doLC050108SameTree()
{
   int v[] = {1,2,5,6,8};
   int arrSize = sizeof(v)/sizeof(int);
   TreeNode* p = createTree(v, arrSize);
   TreeNode* q = createTree(v, arrSize);

   std::cout << "---------------------------------\n";
   std::cout << "05.01.08 Same Tree:\n";
   std::cout << "The tree:\n";
   PrintArray(v, arrSize);

   bool res = Solution050108::isSameTree(p,q);
   string str = res?"True":"False";
   cout << "The result: " << str << "\n";

}

#endif
