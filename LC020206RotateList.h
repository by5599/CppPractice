
#ifndef LC020206_H
#define LC020206_H

#include "Common.h"
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <limits.h>

using namespace std;

/**********************************************************************************
*
* Given a list, rotate the list to the right by k places, where k is non-negative.
*
* For example:
* Given 1->2->3->4->5->NULL and k = 2,
* return 4->5->1->2->3->NULL.
*
**********************************************************************************/


/************
[Medium]
Time Complexity O()
Space Complexity O()
To remember:
1.
2.
3.
************/

class Solution020206
{
public:
   static Node *rotateRight(Node *head, int k) {
        if (!head || k<=0){
            return head;
        }

        //find the length of List
        int len=1;
        Node *p=head;
        while( p->next != NULL ){
            p = p->next;
            len++;
        }
        //connect the tail to head
        p->next = head;
        //find the left place (take care the case - k > len)
        k = len - k % len;

        //find the place
        for(int i=0; i<k; i++){
            p = p->next;
        }

        //break the list
        head = p->next;
        p->next = NULL;

        return head;

    }

};

void doLC020206RotateList()
{
   std::cout << "---------------------------------\n";
   std::cout << "02.02.06 Rotate List:\n";
   std::vector<int> a = {1,2,3,4,5};
   Node* list1 = createLinkedList(a);

   std::cout << "The list: \n";
   PrintVector(a);
   Node *res = Solution020206::rotateRight(list1,2);
   std::cout << "The Result: \n";
   PrintLinkedList(res);

}

#endif
