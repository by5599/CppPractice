
#ifndef ALGORITHMS_SORTING_H
#define ALGORITHMS_SORTING_H

#include "AlgorithmBase.h"

class Sorting
{
public:
   void merge(int *a, int low, int high, int mid);
   void mergesort(int *a, int low, int high);
   void doMergeSort();
   void quickSort( int a[], int l, int r);
   int partition( int a[], int l, int r);
   void doQuickSort();
   void BubbleSort(int iarr[], int num);
   void doBubbleSort();
   void SelectionSort (int *a, int n);
   void doSelectionSort();
   void InsertionSort (int arr[], int length);
   void doInsertionSort();
};



#endif
