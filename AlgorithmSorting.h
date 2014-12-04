
#ifndef ALGORITHMS_SORTING_H
#define ALGORITHMS_SORTING_H

#include "AlgorithmBase.h"

class MergeSort
{
public:
   void merge(int *a, int low, int high, int mid);
   void mergesort(int *a, int low, int high);
   void doMergeSort();
};

#endif
