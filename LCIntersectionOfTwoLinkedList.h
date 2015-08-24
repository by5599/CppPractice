#ifndef LC_INTERSECTION_OF_TWO_LINKED_LIST_H
#define LC_INTERSECTION_OF_TWO_LINKED_LIST_H

#include "Common.h"
#include "AlgorithmBase.h"
#include "AlgorithmLinkedList.h"

#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>

/**********************************************************************************
 *
 * Write a program to find the node at which the intersection of two singly linked lists begins.
 *
 * For example, the following two linked lists:
 *
 *
 *    A:          a1 ¡ú a2
 *                       ¨K
 *                         c1 ¡ú c2 ¡ú c3
 *                       ¨J
 *    B:     b1 ¡ú b2 ¡ú b3
 *
 * begin to intersect at node c1.
 *
 * Notes:
 *
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function returns.
 * You may assume there are no cycles anywhere in the entire linked structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.
 *
 **********************************************************************************/


/************
[Easy]
Time Complexity O()
Space Complexity O()
To remember:
1.
************/

class SolutionIntersectionOfTwoLinkedList
{
public:
        static Node *getIntersectionNode(Node *headA, Node *headB) {

            //caculate the length of each List
            int lenA = getListLength(headA);
            int lenB = getListLength(headB);

            if (lenA<=0 || lenB<=0 ) return NULL;

            //let List A is the longest List;
            if (lenA < lenB){
                swap(headA, headB);
            }

            //move head of List A, make both of Lists are same length
            for (int i=0; i<abs(lenA-lenB); i++){
                headA = headA->next;
            }

            //synced travel both of Lists and check their nodes are same or not
            while (headA != headB){
                headA = headA->next;
                headB = headB->next;
            }

            return headA;
        }

        static int getListLength(Node *head){
            int len=0;
            while(head!=NULL){
                head = head->next;
                len++;
            }
            return len;
        }

};

void doLCIntersectionOfTwoLinkedList()
{
   std::cout << "---------------------------------\n";
   std::cout << "Intersection of Two Linked List\n";

   std::vector<int> commonVector = {2,6,8};
   Node* common = createLinkedList(commonVector);
   std::vector<int> aVector = {1,3};
   Node* alist = createLinkedList(aVector);
   std::vector<int> bVector = {5,7,9};
   Node* blist = createLinkedList(bVector);
   Node* cursor = alist;
   while (cursor->next)
   {
      cursor = cursor->next;
   }
   cursor->next = common;
   cursor = blist;
   while (cursor->next)
   {
      cursor = cursor->next;
   }
   cursor->next = common;
   PrintLinkedList(alist);
   PrintLinkedList(blist);

   Node* res = SolutionIntersectionOfTwoLinkedList::getIntersectionNode(alist,blist);
   PrintLinkedList(res);
}


#endif
