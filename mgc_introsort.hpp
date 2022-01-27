#ifndef MGC_INTROSORT_HPP
#define MGC_INTROSORT_HPP
#include <cstdlib> //rand(), until rng is implemented.
#include "mgc_util.hpp"
namespace mgc {

void heapsort(int a[], int l, int r)
{
    int k, N = r-l+1;
    int *pq = a+l-1;
    for (k = N/2; k >= 1; k--)
        mgc::downHeap(pq, k, N);
    while (N > 1)
    {
        mgc::swap(pq, 1, N);
        mgc::downHeap(pq, 1, --N);
    }
}

void inssort(int a[], int l, int r)
{
    for (int i = l; i <= r; i++)
    {
        int j = i;
        int v = a[j];
        while (j > l && a[j-1] > v)
        {
            a[j] = a[j-1];
            j--;
        }
        a[j] = v;
    }
}

int partition(int a[], int l, int r)
{
    int rpiv = rand() % (r-l+1) + l;
    mgc::swap(a, r, rpiv);
    int i = l - 1;
    int j = r;
    rpiv = a[r];
    for (;;)
    {
        while (a[++i] < rpiv);
        while (a[--j] > rpiv)if (j == l) break;
        if (i >= j) break;
        mgc::swap(a, i, j);
    } 
    mgc::swap(a, i, r);
    return i;
}

void _introsort(int a[], int l,int r, int depthLimit)
{
    if (r-l <= 1) return;
    if (depthLimit == 0)
    {
        heapsort(a, l, r);
        return;
    }
    depthLimit -= 1;
    if (r -l > 16)
    {
        int i = partition(a, l, r);
        _introsort(a, l, i - 1, depthLimit);
        _introsort(a, i + 1, r, depthLimit);
    }
}

void introsort(int a[], int n)
{
    int l = 0;
    int r = n-1;
    int depthLimit = 2 * floor(log(n));
    mgc::_introsort(a, r, l, depthLimit);
    mgc::_ins_sort(a, r, l);
}

}

#endif