// Sorting.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <conio.h>
#include "AlgorithmSorting.h"
#include "Common.h"
#include <deque>
#include <climits>
#include <vector>

using namespace std;

void Sorting::merge(int *a, int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            c[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        a[i] = c[i];
    }
}

void Sorting::mergesort(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,high,mid);
    }
    return;
}

void Sorting::doMergeSort()
{
   int a[20] = {20, 30, 10, 50, 40};
   int i;

    for (i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    mergesort(a, 0, 4);
    cout << "sorted array:\n";
    for (i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl << endl;
}

void Sorting::quickSort( int a[], int l, int r)
{
   int j;

   if( l < r )
   {
   	// divide and conquer
      j = partition( a, l, r);
      quickSort( a, l, j-1);
      quickSort( a, j+1, r);
   }
}

int Sorting::partition( int a[], int l, int r)
{
   int pivot, i, j, t;
   pivot = a[l];
   i = l; j = r+1;

   while( 1)
   {
   	do ++i; while( a[i] <= pivot && i <= r );
   	do --j; while( a[j] > pivot );
   	if( i >= j ) break;
   	t = a[i]; a[i] = a[j]; a[j] = t;
   }
   t = a[l]; a[l] = a[j]; a[j] = t;
   return j;
}

void Sorting::doQuickSort()
{
   int a[] = {11,5,2,1,8,7,3};
   cout << "---------------------\n";
   cout << "QuickSort:\n";
   int arrSize = sizeof(a)/sizeof(int);
   PrintArray(a, arrSize);
   quickSort(a, 0, arrSize-1);
   PrintArray(a, arrSize);

}

void Sorting::BubbleSort(int iarr[], int num) {
   int i, j, k, temp;

   for (i = 1; i < num; i++) {
      for (j = 0; j < num - 1; j++) {
         if (iarr[j] > iarr[j + 1]) {
            temp = iarr[j];
            iarr[j] = iarr[j + 1];
            iarr[j + 1] = temp;
         }
      }

      PrintArray(iarr, num);
   }
}

void Sorting::doBubbleSort()
{
   int a[] = {11,5,2,1,8,7,3};
   cout << "---------------------\n";
   cout << "BubbleSort:\n";
   int arrSize = sizeof(a)/sizeof(int);
   PrintArray(a, arrSize);
   BubbleSort(a, arrSize);
   PrintArray(a, arrSize);
}

void Sorting::SelectionSort (int *a, int n) {
    int i, j, m, t;
    for (i = 0; i < n; i++) {
        for (j = i, m = i; j < n; j++) {
            if (a[j] < a[m]) {
                m = j;
            }
        }
        t = a[i];
        a[i] = a[m];
        a[m] = t;
    }
}

void Sorting::doSelectionSort()
{
   int a[] = {11,5,2,1,8,7,3};
   cout << "---------------------\n";
   cout << "SelectionSort:\n";
   int arrSize = sizeof(a)/sizeof(int);
   PrintArray(a, arrSize);
   SelectionSort(a, arrSize);
   PrintArray(a, arrSize);
}

void Sorting::InsertionSort(int *a, int n) {
    int i, j, t;
    for (i = 1; i < n; i++) {
        t = a[i];
        for (j = i; j > 0 && t < a[j - 1]; j--) {
            a[j] = a[j - 1];
        }
        a[j] = t;
    }
}

void Sorting::doInsertionSort()
{
   int a[] = {11,5,2,1,8,7,3};
   cout << "---------------------\n";
   cout << "InsertionSort:\n";
   int arrSize = sizeof(a)/sizeof(int);
   PrintArray(a, arrSize);
   InsertionSort(a, arrSize);
   PrintArray(a, arrSize);
}

