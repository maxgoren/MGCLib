#ifndef MGC_MERGESORT_HPP
#define MGC_MERGESORT_HPP
#include "mgc_util.hpp"

namespace mgc {

template <typename T>
void merge(T a[], T temp[], int l, int m, int r)
{
    int i = l;
    int j = m;
    int k = l;
    while (i < m && j < r) temp[k++] = (a[i] <= a[j]) ? a[i++]:a[j++];
    while (i < m) temp[k++] = a[i++];
    while (j < r) temp[k++] = a[j++];
    for (k = l; k < r; k++)
        a[k] = temp[k];  
}

template <typename T>
void mergesort(T a[], int l, int r)
{
    int arrSize = r-l;
    T* temp = new T[r-l];
    for (int i = 1; i < arrSize; i *= 2)
    { 
        for (int j = 0; j < arrSize; j += 2*i)
        {
           int sliceSize = min(arrSize, j + 2*i);
           if (sliceSize <= 12)
           {
                _ins_sort(a, j, j+2*i);
           } else {
                merge(a, temp, j, min(arrSize, j + i), sliceSize);
           }
        }
    }
    delete temp;
}
}

#endif