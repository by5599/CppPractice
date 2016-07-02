#ifndef LC050109_H
#define LC050109_H

#include "Common.h"
#include "AlgorithmBase.h"
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <stdlib.h>
using namespace std;
/**********************************************************************************
*
* Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
*
* For example, this binary tree is symmetric:
*
*     1
*    / \
*   2   2
*  / \ / \
* 3  4 4  3
*
* But the following is not:
*
*     1
*    / \
*   2   2
*    \   \
*    3    3
*
* Note:
* Bonus points if you could solve it both recursively and iteratively.
*
* confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*
* OJ's Binary Tree Serialization:
*
* The serialization of a binary tree follows a level order traversal, where '#' signifies
* a path terminator where no node exists below.
*
* Here's an example:
*
*    1
*   / \
*  2   3
*     /
*    4
*     \
*      5
*
* The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
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


class Solution050109
{
public:
    static bool isSymmetric(TreeNode *root) {
        if (root == NULL ) return true;
        return isSymmetric(root->left, root->right);

    }

    static bool isSymmetric(TreeNode *p, TreeNode *q){
        //if (rand()%2){
        //   return isSymmetric1(p, q);
        //}
        return isSymmetric2(p, q);
    }

    static bool isSymmetric1(TreeNode *p, TreeNode *q){
        if (p==NULL && q==NULL) return true;
        if (p==NULL || q==NULL) return false;

        return (p->val == q->val) &&
                isSymmetric(p->left, q->right) &&
                isSymmetric(p->right, q->left);
    }


   static bool isSymmetric2(TreeNode *p, TreeNode *q){

        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(p);
        q2.push(q);
        while(q1.size()>0 && q2.size()>0){
            TreeNode* p1 = q1.front();
            q1.pop();
            TreeNode* p2 = q2.front();
            q2.pop();
            if (p1==NULL && p2==NULL) continue;
            if (p1==NULL || p2==NULL) return false;

            if (p1->val != p2->val) return false;

            q1.push(p1->left);
            q2.push(p2->right);

            q1.push(p1->right);
            q2.push(p2->left);

        }
        return true;

    }

};

void doLC050109SymmetricTree()
{
   int v[] = {1,2,2,3,4,4,3};
   int arrSize = sizeof(v)/sizeof(int);
   TreeNode* p = createTree(v, arrSize);

   std::cout << "---------------------------------\n";
   std::cout << "05.01.09 Symmetric Tree:\n";
   std::cout << "The tree:\n";
   PrintArray(v, arrSize);

   bool res = Solution050109::isSymmetric(p);
   string str = res?"True":"False";
   cout << "The result: " << str << "\n";

}

#endif