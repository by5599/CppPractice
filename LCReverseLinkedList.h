#ifndef LC_REVERSE_LINKED_LIST_H
#define LC_REVERSE_LINKED_LIST_H

#include "Common.h"
#include "AlgorithmBase.h"
#include "AlgorithmLinkedList.h"

#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>

/**********************************************************************************
*
*
**********************************************************************************/


/************
[Medium]
Time Complexity O(n), Space Complexity O(n)
To remember:
1. Use a map
2. Extend the finding and set the flag
3.
************/

void doLCReverseLinkedList()
{
   std::vector<int> a = {1,2,3,4,5};
   Node* l = createLinkedList(a);

   std::cout << "---------------------------------\n";
   std::cout << "Reverse Linked List:\n";
   std::cout << "The List:\n";
   PrintVector(a);

   Node* res = LinkedList::reverse(&l);
   std::cout << "The result: " << std::endl;
   PrintLinkedList(res);
}

#endif
