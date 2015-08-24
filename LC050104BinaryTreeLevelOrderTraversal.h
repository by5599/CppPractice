#ifndef LC050104_H
#define LC050104_H

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
* Given a binary tree, return the level order traversal of its nodes' values.
* (ie, from left to right, level by level).
*
* For example:
* Given binary tree {3,9,20,#,#,15,7},
*
*     3
*    / \
*   9  20
*     /  \
*    15   7
*
* return its level order traversal as:
*
* [
*   [3],
*   [9,20],
*   [15,7]
* ]
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
Space Complexity O(N)
To remember:
1.
2.
3.
************/


class Solution050104
{
public:
    static vector<vector<int> > levelOrder(TreeNode *root) {
    //if (random()%2){
        return levelOrder1(root);
    //}
    //return levelOrder2(root);
}

   static vector<vector<int> > levelOrder1(TreeNode *root) {
    queue<TreeNode*> q;
    vector< vector<int> > vv;
    vector<int> v;
    if (root){
        v.push_back(root->val);
        vv.push_back(v);
    }
    q.push(root);
    int i=0;
    vector<TreeNode*> vt;
    while(q.size()>0){
        TreeNode *p = q.front();
        q.pop();
        vt.push_back(p);
        if ( p==NULL ) {
            continue;
        }
        q.push(p->left);
        q.push(p->right);
    }


    int step = 2;
    int j;
    for (int i=1; i<vt.size(); i=j ){
        v.clear();

        int cnt=0;
        for (j=i; j<i+step && j<vt.size(); j++){
            if (vt[j]) {
                v.push_back(vt[j]->val);
                cnt += 2;
            }
        }
        step = cnt;
        if (v.size()>0) {
            vv.push_back(v);
        }
    }

    return vv;
}

   static vector<vector<int> > levelOrder2(TreeNode *root) {
    vector< vector<int> > vv;
    vector<int> v;
    if (root){
        v.push_back(root->val);
        vv.push_back(v);
    }

    vector< vector<int> > vv_left, vv_right;
    if(root && root->left) {
        vv_left = levelOrder2(root->left);
    }
    if(root && root->right) {
        vv_right = levelOrder2(root->right);
    }

    //merge
    for(int i=0; i<vv_left.size() || i < vv_right.size(); i++){
        if (i<vv_left.size() && i<vv_right.size()){
            vv_left[i].insert(vv_left[i].end(), vv_right[i].begin(), vv_right[i].end());
            vv.push_back(vv_left[i]);
        }else if (i<vv_left.size()) {
            vv.push_back(vv_left[i]);
        }else {
            vv.push_back(vv_right[i]);
        }
    }

    return vv;
}

};

void doLC050104BinaryTreeLevelOrderTraversal()
{
   int v[] = {3,9,20,0,0,15,7};
   int arrSize = sizeof(v)/sizeof(int);
   TreeNode* p = createTree(v, arrSize);

   std::cout << "---------------------------------\n";
   std::cout << "05.01.04 Binary Tree Level Order Traversal:\n";
   std::cout << "The tree:\n";
   printTree_level_order(p);

   vector<vector<int>> res = Solution050104::levelOrder(p);
   printMatrix(res);
}

#endif
