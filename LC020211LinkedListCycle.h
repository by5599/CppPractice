#ifndef LC020211_LINKED_LIST_CYCLE_H
#define LC020211_LINKED_LIST_CYCLE_H

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

class Solution020211
{
public:
   static bool hasCycle(Node *head) {
      Node *slow = head, *fast = head;
      while (fast && fast->next) {
         slow = slow->next;
         fast = fast->next->next;
         if (slow == fast) return true;
      }
      return false;
   }

};

void doLC020211LinkedListCycle()
{
   std::vector<int> a = {1,2,3,4,5,6};

   std::cout << "---------------------------------\n";
   std::cout << "Linked List Cycle:\n";
   std::cout << "The List:\n";
   PrintVector(a);
   Node* l = createLinkedList(a, true);
   bool res = Solution020211::hasCycle(l);
   std::string str = (res)?"true":"false";
   std::cout << "The result: " << str << "\n";
}

#endif
