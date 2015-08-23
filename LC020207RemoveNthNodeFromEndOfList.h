#ifndef LC020207_REMOVE_NTH_NODE_FROM_END_OF_LIST_H
#define LC020207_REMOVE_NTH_NODE_FROM_END_OF_LIST_H

#include "Common.h"
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include "AlgorithmBase.h"
#include "AlgorithmLinkedList.h"

/**********************************************************************************
*
* Given a linked list, remove the nth node from the end of list and return its head.
*
* For example,
*
*    Given linked list: 1->2->3->4->5, and n = 2.
*
*    After removing the second node from the end, the linked list becomes 1->2->3->5.
*
* Note:
* Given n will always be valid.
* Try to do this in one pass.
*
**********************************************************************************/


/************
[Easy]
Time Complexity O(N)
Space Complexity O(1)
To remember:
1.
************/

class Solution020207
{
public:
   static Node *removeNthFromEnd(Node *head, int n) {
      if (head==NULL || n<=0){
         return NULL;
      }

      Node *headPtr = head;
      Node *p = head, *q = head;
      for (int i = 0; i < n; i++)
      {
         if (q == NULL) return NULL;
         q = q->next;
      }

      while(q->next) {
         p = p->next;
         q = q->next;
      }
      Node *tmp = p->next;
      p->next = p->next->next;
      delete tmp;
      return headPtr;
   }
};


void doLC020207RemoveNthNodeFromEndOfList()
{
   std::vector<int> a = {1,2,3,4,5};

   std::cout << "---------------------------------\n";
   std::cout << "Remove Nth Node from End of List:\n";
   std::cout << "The vector:\n";
   PrintVector(a);
   std::cout << "The current list: ";
   Node* theList = createLinkedList(a);
   Node* updatedList = Solution020207::removeNthFromEnd(theList,2);
   std::cout << "The updated list: ";
   PrintLinkedList(updatedList);
   //std::cout << "The longest consecutive: " << res << std::endl;
}

#endif
