
#ifndef ALGORITHMS_BASE_H
#define ALGORITHMS_BASE_H

#include <cstdlib>
#include <stdio.h>
#include <queue>
#include <iostream>

using namespace std;

struct Node
{
   int data;
   Node* next;
   Node(): data(0),next(nullptr) {};
   Node(int i): data(i),next(nullptr) {};
};

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
};

static TreeNode* createTree(int a[], int n)
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

static void printTree(TreeNode *root)
{
    if (root == NULL){
        printf("# ");
        return;
    }
    printf("%d ", root->val );

    printTree(root->left);
    printTree(root->right);
}

static void printTree_level_order(TreeNode *root)
{
    queue<TreeNode*> q;
    q.push(root);
    while (q.size()>0){
        TreeNode* n = q.front();
        q.pop();
        if (n==NULL){
            cout << "# ";
            continue;
        }
        cout << n->val << " ";
        q.push(n->left);
        q.push(n->right);
    }
    cout << endl;
}

static int printMatrix(vector< vector<int> > &vv)
{
    for(int i=0; i<vv.size(); i++) {
        cout << "[";
        for(int j=0; j<vv[i].size(); j++) {
            cout << " " << vv[i][j];
        }
        cout << "]" << endl;;
    }
}

#endif
