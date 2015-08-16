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
#include "AlgorithmLinkedList.h"

using namespace std;

void LinkedList::initNode(Node *head, int n)
{
   head->data = n;
   head->next = NULL;
}

void LinkedList::addNode(Node *head, int n)
{
   Node *newNode = new Node;
   newNode->data = n;
   newNode->next = NULL;

   Node *cur = head;

   while (cur)
   {
      if (cur->next == NULL)
      {
         cur->next = newNode;
         return;
      }
      cur = cur->next;
   }
}

void LinkedList::insertFront(Node **head, int n)
{
   Node* newNode = new Node;
   newNode->data = n;
   newNode->next = *head;  // Just make the next point to head even if head could be NULL
   *head = newNode;
}

Node* LinkedList::searchNode(Node *head, int n)
{
   Node *cur = head;
   while (cur)
   {
      if (cur->data == n)
      {
         return cur;
      }
      cur = cur->next;
   }
   cout << "No Node" << n << " in list.\n";
}

bool LinkedList::deleteNode(Node **head, Node *ptrDel)
{
   Node *cur = *head;
   if (ptrDel == *head)
   {
      *head = cur->next;
      delete ptrDel;
      return true;
   }

   while (cur)
   {
      if (cur->next == ptrDel)
      {
         cur->next = ptrDel->next;
         delete ptrDel;
         return true;
      }
      cur = cur->next;
   }
   return false;
}

Node* LinkedList::reverse(Node** head)
{
   Node *parent = *head;
   Node *me = parent->next;
   Node *child = me->next;

   parent->next = NULL;
   while (child)
   {
      me->next = parent;
      parent = me;
      me = child;
      child = child->next;
   }
   me->next = parent;
   *head = me;
   return *head;
}

void LinkedList::copyLinkedList(Node *node, Node **pNew)
{
   if (node != NULL)
   {
      *pNew = new Node;
      (*pNew)->data = node->data;
      (*pNew)->next = NULL;
      copyLinkedList(node->next, &((*pNew)->next));
   }
}

int LinkedList::compareLinkedList(Node* node1, Node* node2)
{
   static int flag;
   if (node1 == NULL && node2 == NULL)
   {
      flag = 1;
   }
   else
   {
      if (node1 == NULL && node2 == NULL)
      {
         flag = 0;
      }
      else if (node1->data != node2->data)
      {
         flag = 0;
      }
      else
      {
         compareLinkedList(node1->next, node2->next);
      }
   }
   return flag;
}

void LinkedList::deleteLinkedList(Node **node)
{
   Node* tmpNode;
   while (*node)
   {
      tmpNode = *node;
      *node = tmpNode->next;
      delete tmpNode;
   }
}

void LinkedList::display(Node *head)
{
   Node *list = head;
   while (list)
   {
      cout << list->data << " ";
      list = list->next;
   }
   cout << endl;

}

void LinkedList::doLinkedListExample1()
{
	struct Node *newHead;
	struct Node *head = new Node;

	initNode(head,10);
	display(head);

	addNode(head,20);
	display(head);

	addNode(head,30);
	display(head);

	addNode(head,35);
	display(head);

	addNode(head,40);
	display(head);

	insertFront(&head,5);
	display(head);

	int numDel = 5;
	Node *ptrDelete = searchNode(head,numDel);
	if(deleteNode(&head,ptrDelete))
		cout << "Node "<< numDel << " deleted!\n";
	display(head);

	cout << "The list is reversed\n";
	reverse(&head);
	display(head);

	cout << "The list is copied\n";
	copyLinkedList(head,&newHead);
	display(newHead);

	cout << "Comparing the two lists...\n";
	cout << "Are the two lists same?\n";
	if(compareLinkedList(head,newHead))
		cout << "Yes, they are same!\n";
	else
		cout << "No, they are different!\n";
	cout << endl;

	numDel = 35;
	ptrDelete = searchNode(newHead,numDel);
	if(deleteNode(&newHead,ptrDelete)) {
		cout << "Node "<< numDel << " deleted!\n";
		cout << "The new list after the delete is\n";
		display(newHead);
	}
	cout << "Comparing the two lists again...\n";
	cout << "Are the two lists same?\n";
	if(compareLinkedList(head,newHead))
		cout << "Yes, they are same!\n";
	else
		cout << "No, they are different!\n";

	cout << endl;
	cout << "Deleting the copied list\n";
	deleteLinkedList(&newHead);
	display(newHead);
}

