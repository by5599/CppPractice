
#ifndef ALGORITHMS_LINKEDLIST_H
#define ALGORITHMS_LINKEDLIST_H

#include "AlgorithmBase.h"

class LinkedList
{
public:
   void initNode(Node *head, int n);
   void addNode(Node *head, int n);
   void insertFront(Node **head, int n);
   Node* searchNode(Node *head, int n);
   bool deleteNode(Node **head, Node *ptrDel);
   Node* reverse(Node** head);
   void copyLinkedList(Node *node, Node **pNew);
   int compareLinkedList(Node* node1, Node* node2);
   void deleteLinkedList(Node **node);
   void display(Node *head);
   void doLinkedListExample1();
};

#endif
