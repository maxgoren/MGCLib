#ifndef MGC_SORT_HPP
#define MGC_SORT_HPP
#include "mgc_util.hpp"
#include "mgc_introsort.hpp"
#include "mgc_mergesort.hpp"

namespace mgc {

template <typename T>
void sort(T a[], int n)
{
    mgc::introsort(a, n);
}

template <typename T>
void stable_sort(T a[], int n)
{
    mgc::mergesort(a, n);
}

}


#endif