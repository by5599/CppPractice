
#ifndef ALGORITHMS_BASE_H
#define ALGORITHMS_BASE_H

struct Node
{
   int data;
   Node* next;
   Node(): data(0),next(nullptr) {};
   Node(int i): data(i),next(nullptr) {};
};

#endif
