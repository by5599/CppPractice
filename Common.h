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

#endif // COMMON_H_INCLUDED
