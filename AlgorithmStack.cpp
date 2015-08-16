// LinkedList.cpp : Defines the entry point for the console application.
//

//
//http://www.bogotobogo.com/cplusplus/linkedlist.php#linkedlistexample1
//
/*
Example 1
When the head of the list is not a global pointer.
Example 2 and Example 3
When the head of the list is a global pointer.
There are some implementation differences between these two examples.
Example 4
Used class & structure in that class.
Example 5A
Detecting circular (loop) linked list.
Example 5B
Detecting circular (loop) linked list (Generic Class with Template).
Example 6
Stack with linked list data structure.

Example 7
Class Stack with linked list data structure.
Example 7B
Class Stack with linked list data structure.
Example 7C
Class Stack using linked list with query for minimum value.
Example 7D
Stack Class Using Linked List with Query for Minimum Value (additional stack).
Example 8
Queue Struct with linked list data structure.
Example 8B
Queue Class with linked list data structure.
Example 9
Finding intersection and union of two linked lists.
Example 10
Generic linked lists.
*/

#include <iostream>
#include "AlgorithmStack.h"

using namespace std;

Stack::Stack()
{
	top = NULL;
}

Stack::~Stack()
{
	while(top) {
		NODE *tmp = top;
		top = top->next;
		delete tmp;
	}
}

void Stack::push(int n)
{
	NODE *ptr = new NODE;
	ptr->next = top;
	ptr->data = n;
	top = ptr;
}

int Stack::pop()
{
	NODE *tmp = top;
	int val = top->data;
	top = top->next;
	delete tmp;
	return val;
}

int Stack::peek()
{
	return top->data;
}

void print(Stack &s)
{
	Stack::NODE *cur = s.top;
	while(cur) {
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << endl;
}

int TestStack()
{
	Stack *st = new Stack;
	st->push(10);
	st->push(20);
	st->push(30);
	st->push(40);
	st->push(50);
	print(*st);
	st->pop();
	st->pop();
	print(*st);
	cout << "current top=" << st->peek();
	return 0;
}
