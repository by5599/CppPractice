#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

#include <iostream>
#include <vector>

void PrintArray(int* arr, int n)
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

void PrintVector(std::vector<int> vi)
{
   for(auto iter = vi.cbegin(); iter != vi.cend(); ++iter)
   {
      if (*iter == vi.back())
      {
         std::cout << *iter << "\n";
      }
      else{
         std::cout << *iter << ",";
      }
   }
}

void PrintLinkedList(Node* l)
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
