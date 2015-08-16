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
#include "AlgorithmQueue.h"

using namespace std;

Queue::Queue()
{
	head = NULL;
}

Queue::~Queue()
{
	if(head == NULL) return;
	NODE *cur = head;
	while(cur) {
		Node *ptr = cur;
		cur = cur->next;
		delete ptr;
	}
}

void Queue::push(int n)
{
	if(head == NULL) {
		head = new NODE;
		head->data = n;
		head->next = NULL;
		return;
	}
	NODE *cur = head;
	while(cur) {
		if(cur->next == NULL) {
			NODE *ptr = new NODE;
			ptr->data = n;
			ptr->next = NULL;
			cur->next = ptr;
			return;
		}
		cur = cur->next;
	}
}

void Queue::print()
{
	if(head==NULL) return;
	Node *cur = head;
	while(cur) {
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << endl;
}

int Queue::pop()
{
	if(head == NULL) {
		cout << "empty estack!" << endl;
		return NULL;
	}
	NODE *tmp = head;
	int value = head->data;
	if(head->next) {
		head = head->next;
	}
	// pop the last element (head)
	else {
		delete tmp;
		head = NULL;
	}
	cout << "pop: " << value << endl;;
	return value;
}

int TestQueue()
{
	Queue *que = new Queue();
	que->push(10);
	que->push(20);
	que->push(30);
	que->push(40);
	que->push(50);
	que->print();
	que->pop();que->print();
	que->pop();que->print();
	que->pop();que->print();
	que->pop();que->print();
	que->pop();que->print();
	que->pop();que->print();
	return 0;
}

