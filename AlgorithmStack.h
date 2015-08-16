
#ifndef ALGORITHMS_STACK_H
#define ALGORITHMS_STACK_H

#include "AlgorithmBase.h"
#include <vector>

class Stack
{
public:
	Stack();
	~Stack();
	void push(int);
	int pop();
	int peek();
	friend void print(Stack&);

private:
	typedef struct node {
		node *next;
		int data;
	} NODE;

	NODE *top;
};
int TestStack();

#endif
