#ifndef LC020208_H
#define LC020208_H

#include "Common.h"
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include "AlgorithmBase.h"
#include "AlgorithmLinkedList.h"

/**********************************************************************************
*
* Given a linked list, swap every two adjacent nodes and return its head.
*
* For example,
* Given 1->2->3->4, you should return the list as 2->1->4->3.
*
* Your algorithm should use only constant space. You may not modify the values in the list,
* only nodes itself can be changed.
*
*
**********************************************************************************/


/************
[Medium]
Time Complexity O(N)
Space Complexity O(1)
To remember:
1.
************/

class Solution020208
{
public:
   static Node *swapPairs2(Node *head) {
        Node *h = NULL;
        //using `*p` to traverse the linked list
        for (Node *p = head; p && p->next; p = p->next) {
            //`n` is `p`'s next node, and swap `p` and `n` physcially
            Node *n = p->next;
            p->next = n->next;
            n->next = p;
            //using `h` as `p`'s previous node
            if (h){
                h->next = n;
            }
            h=p;

            //determin the really 'head' pointer
            if (head == p){
                head = n;
            }
        }

        return head;
    }

   // My version:
   static Node *swapPairs3(Node *head) {
      Node *cur = head;
      Node *pre = NULL;
      Node *newHead = NULL;
      while (cur != NULL && cur->next != NULL)
      {
         //PrintLinkedList(h);
         Node *n = cur->next;
         cur->next = n->next;
         n->next = cur;

         if (pre)
            pre->next = n;
         pre = cur;

         cur = cur->next;

         if (newHead == NULL)
            newHead = n;
      }
      return newHead;
    }
};


void doLC020208SwapNodeInPairs()
{
   std::vector<int> a = {1,2,3,5};

   std::cout << "---------------------------------\n";
   std::cout << "Swap Nodes in Pairs:\n";
   std::cout << "The vector:\n";
   PrintVector(a);
   std::cout << "The current list: ";
   Node* theList = createLinkedList(a);
   Node* updatedList = Solution020208::swapPairs3(theList);
   std::cout << "The updated list: ";
   PrintLinkedList(updatedList);
   //std::cout << "The longest consecutive: " << res << std::endl;
}

#endif
