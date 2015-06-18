#ifndef LC511_BINARY_TREE_PREORDER_TRAVERSAL_H
#define LC511_BINARY_TREE_PREORDER_TRAVERSAL_H

#include "Common.h"
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

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
};

TreeNode* createTree(int a[], int n)
{
    if (n<=0) return NULL;

    TreeNode **tree = new TreeNode*[n];

    for(int i=0; i<n; i++) {
        if (a[i]==0 ){
            tree[i] = NULL;
            continue;
        }
        tree[i] = new TreeNode(a[i]);
    }
    int pos=1;
    for(int i=0; i<n && pos<n; i++) {
        if (tree[i]){
            tree[i]->left = tree[pos++];
            if (pos<n){
                tree[i]->right = tree[pos++];
            }
        }
    }
    return tree[0];
}

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

void doLC511()
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
