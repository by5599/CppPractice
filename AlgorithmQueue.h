
#ifndef ALGORITHMS_QUEUE_H
#define ALGORITHMS_QUEUE_H

#include "AlgorithmBase.h"
#include <vector>


class Queue
{
public:
	Queue();
	~Queue();
	void push(int);
	int pop();
	void print();
private:
	typedef struct Node {
		Node *next;
		int data;
	} NODE;
	NODE* head;
};
int TestQueue();

#endif
