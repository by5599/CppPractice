#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

#include <iostream>
#include <vector>
#include "AlgorithmBase.h"

static void PrintArray(int* arr, int n)
{
   for (int i = 0; i < n; i++)
   {
      if ( i == n - 1)
      {
         std::cout << arr[i];
      }
      else
      {
         std::cout << arr[i] << ",";
      }
   }
   std::cout << "\n";
}

static void PrintVector(std::vector<int> vi)
{
   for(auto iter = vi.cbegin(); iter != vi.cend(); ++iter)
   {
      if (iter == prev(vi.end()))
      {
         std::cout << *iter << "\n";
      }
      else{
         std::cout << *iter << ",";
      }
   }
}

template <typename X>
void PrintAnything(std::vector<X> vx)
{
   for(auto iter = vx.cbegin(); iter != vx.cend(); ++iter)
   {
      if ( iter == prev(vx.end()) )
      {
         std::cout << *iter << "\n";
      }
      else{
         std::cout << *iter << " ";
      }
   }
}

static void PrintLinkedList(Node* l)
{
   if (l == NULL)
      std::cout<< "Empty list!!\n";
   Node* p = l;
   for (;p != NULL; p = p->next)
   {
      std::cout << p->data << " ";
   }
   std::cout << "\n";
}

#endif // COMMON_H_INCLUDED
