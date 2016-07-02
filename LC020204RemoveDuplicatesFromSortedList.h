
#ifndef LC020204_H
#define LC020204_H

#include "Common.h"
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <limits.h>

using namespace std;

/**********************************************************************************
*
* Given a sorted linked list, delete all nodes that have duplicate numbers,
* leaving only distinct numbers from the original list.
*
* For example,
* Given 1->2->3->3->4->4->5, return 1->2->3->4->5.
* Given 1->1->1->2->3, return 1->2->3.
*
*
**********************************************************************************/


/************
[Easy]
Time Complexity O(n)
Space Complexity O(1)
To remember:
1.
2.
3.
************/

class Solution020204
{
public:
   static Node *deleteDuplicates(Node *head) {
      if (head == nullptr) return nullptr;
      for (Node *prev = head, *cur = head->next; cur; cur = prev->next) {
         if (prev->data == cur->data) {
            prev->next = cur->next;
            delete cur;
         } else {
            prev = cur;
         }
      }
      return head;
   }

};

void doLC020204RemoveDuplicatesFromeSortedList()
{
   std::cout << "---------------------------------\n";
   std::cout << "02.02.04 Remove Duplicates from Sorted List:\n";
   std::vector<int> a = {1,1,2,3,3};
   Node* list1 = createLinkedList(a);

   std::cout << "The list: \n";
   PrintVector(a);
   Node *res = Solution020204::deleteDuplicates(list1);
   std::cout << "The Result: \n";
   PrintLinkedList(res);

}

#endif
