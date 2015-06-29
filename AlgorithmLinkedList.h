
#ifndef ALGORITHMS_LINKEDLIST_H
#define ALGORITHMS_LINKEDLIST_H

#include "AlgorithmBase.h"
#include <vector>

class LinkedList
{
public:
   static void initNode(Node *head, int n);
   static void addNode(Node *head, int n);
   static void insertFront(Node **head, int n);
   static Node* searchNode(Node *head, int n);
   static bool deleteNode(Node **head, Node *ptrDel);
   static Node* reverse(Node** head);
   static void copyLinkedList(Node *node, Node **pNew);
   static int compareLinkedList(Node* node1, Node* node2);
   static void deleteLinkedList(Node **node);
   static void display(Node *head);
   static void doLinkedListExample1();
};

static Node* createLinkedList(std::vector<int>& v, bool cycled = false)
{
   if (v.size() == 0)
      return nullptr;

	struct Node *newHead;
	struct Node *head = new Node;
	LinkedList::initNode(head,*v.cbegin());
	for (auto iter = v.cbegin() + 1; iter != v.cend(); iter++)
   {
      LinkedList::addNode(head,*iter);
   }
   //LinkedList::display(head);

   if (cycled)
   {
      Node* p = head;
      while (p->next != nullptr)
      {
         p = p->next;
      }
      p->next = head;
   }
   return head;
}

#endif
