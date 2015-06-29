#ifndef LC0602_MERGE_TWO_SORTED_LIST_H
#define LC0602_MERGE_TWO_SORTED_LIST_H

#include "Common.h"
#include "AlgorithmBase.h"
#include "AlgorithmLinkedList.h"

#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>

/**********************************************************************************
*
* Given a linked list, determine if it has a cycle in it.
*
* Follow up:
* Can you solve it without using extra space?
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

class Solution0602
{
public:
   static Node *mergeTwoLists(Node *l1, Node *l2) {
      if (l1 == nullptr) return l2;
      if (l2 == nullptr) return l1;
      Node dummy(-1);
      Node *p = &dummy;
      for (; l1 != nullptr && l2 != nullptr; p = p->next) {
         if (l1->data > l2->data)
         {
            p->next = l2;
            l2 = l2->next;
         }
         else
         {
            p->next = l1;
            l1 = l1->next;
         }
      }
      p->next = l1 != nullptr ? l1 : l2;
      return dummy.next;
   }
};

void doMergeTwoSortedList()
{
   std::vector<int> a = {1,4,6,9};
   std::vector<int> b = {2,7,8};
   Node* l1 = createLinkedList(a);
   Node* l2 = createLinkedList(b);

   std::cout << "---------------------------------\n";
   std::cout << "Merge Two Sorted List:\n";
   std::cout << "The List:\n";
   PrintVector(a);
   PrintVector(b);

   Node* res = Solution0602::mergeTwoLists(l1, l2);
   std::cout << "The result: " << std::endl;
   PrintLinkedList(res);
}

#endif
