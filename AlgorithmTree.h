
#ifndef ALGORITHMS_TREE_H
#define ALGORITHMS_TREE_H

#include "AlgorithmBase.h"
#include <vector>


struct Tree
{
	char data;
	Tree *left;
	Tree *right;
	Tree *parent;
};

int TestBinaryTree();

#endif
