#ifndef LC511_BINARY_TREE_PREORDER_TRAVERSAL_H
#define LC511_BINARY_TREE_PREORDER_TRAVERSAL_H

#include "Common.h"
#include "AlgorithmBase.h"
#include <algorithm>
#include <vector>
#include <stack>

/**********************************************************************************
*
* Given a binary tree, return the preorder traversal of its nodes' values.
*
* For example:
* Given binary tree {1,#,2,3},
*
*    1
*     \
*      2
*     /
*    3
*
* return [1,2,3].
*
* Note: Recursive solution is trivial, could you do it iteratively?
*
**********************************************************************************/


/************
[Hard]
Time Complexity O(log(m+n))
To remember:
1.
2.
3.
************/

class Solution511
{
public:
   static std::vector<int> preorderTraversalStack(TreeNode *root) {
      std::vector<int> result;
      const TreeNode *p;
      std::stack<const TreeNode *> s;
      p = root;
      if (p != nullptr) s.push(p);
      while (!s.empty()) {
      p = s.top();
      s.pop();
      result.push_back(p->val);
      if (p->right != nullptr) s.push(p->right);
      if (p->left != nullptr) s.push(p->left);
      }
      return result;
   }
};

void doLC511PreorderTraversalTree()
{
   int a[] = {1,0,2,3};
   TreeNode* p = createTree(a, sizeof(a)/sizeof(int));

   std::cout << "---------------------------------\n";
   std::cout << "Binary Tree Preorder Traversal:\n";
   std::cout << "The arrays:\n";

   std::vector<int> res = Solution511::preorderTraversalStack(p);
   PrintVector(res);

/*
        1
       / \
      2   3
         / \
        4   5
             \
              6
*/
   int b[] = {1,2,3,0,0,4,5,0,0,0,6};
   TreeNode* q = createTree(b, sizeof(b)/sizeof(int));
   std::vector<int> res2 = Solution511::preorderTraversalStack(q);
   PrintVector(res2);
}

#endif
