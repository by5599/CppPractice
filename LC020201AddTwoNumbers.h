#ifndef LC020201_ADD_TWO_NUMBERS_H
#define LC020201_ADD_TWO_NUMBERS_H

#include "Common.h"
#include "AlgorithmBase.h"
#include "AlgorithmLinkedList.h"

#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>

/**********************************************************************************
*
* You are given two linked lists representing two non-negative numbers.
* The digits are stored in reverse order and each of their nodes contain a single digit.
* Add the two numbers and return it as a linked list.
*
* Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
* Output: 7 -> 0 -> 8
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

class Solution020201
{
public:
   static Node *addTwoNumbers(Node *l1, Node *l2) {
      Node dummy(-1);
      int carry = 0;
      Node *prev = &dummy;
      for (Node *pa = l1, *pb = l2;
      pa != nullptr || pb != nullptr;
      pa = pa == nullptr ? nullptr : pa->next,
      pb = pb == nullptr ? nullptr : pb->next,
      prev = prev->next)
      {
         const int ai = pa == nullptr ? 0 : pa->data;
         const int bi = pb == nullptr ? 0 : pb->data;
         const int value = (ai + bi + carry) % 10;
         carry = (ai + bi + carry) / 10;
         prev->next = new Node(value);
      }
      if (carry > 0)
         prev->next = new Node(carry);
      return dummy.next;
   }
};

void doLC020201AddTwoNumbers()
{
   std::vector<int> a = {2,4,3};
   std::vector<int> b = {5,6,4};
   Node* list1 = createLinkedList(a);
   Node* list2 = createLinkedList(b);

   std::cout << "---------------------------------\n";
   std::cout << "Add Two Numbers:\n";
   std::cout << "The List1:\n";
   PrintVector(a);
   std::cout << "The List2:\n";
   PrintVector(b);

   Node* res = Solution020201::addTwoNumbers(list1, list2);
   std::cout << "The result: " << std::endl;
   PrintLinkedList(res);
}

#endif
