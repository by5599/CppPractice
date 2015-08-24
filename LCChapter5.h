#ifndef LC_CHAPTER5_H
#define LC_CHAPTER5_H

#include "LC050101BinaryTreePreorderTraversal.h"
#include "LC050104BinaryTreeLevelOrderTraversal.h"
#include "LC050105BinaryTreeLevelOrderTraversalII.h"
#include "LC050108SameTree.h"
#include "LC050109SymmetricTree.h"
#include "LC050110BalancedBinaryTree.h"
#include "LC050401MinimumDepthOfBinaryTree.h"
#include "LC050402MaximumDepthOfBinaryTree.h"
#include "LC050403PathSum.h"

void doChapter5()
{
   std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Chapter 5\n";
   doLC511PreorderTraversalTree();
   doLC050104BinaryTreeLevelOrderTraversal();
   doLC050105BinaryTreeLevelOrderTraversalII();
   doLC050108SameTree();
   doLC050109SymmetricTree();
   doLC050110BalancedBinaryTree();
   doLC050401MinimumDepthOfBinaryTree();
   doLC050402MaximumDepthOfBinaryTree();
   doLC050403PathSum();
}
#endif
