#ifndef MGC_UTIL_HPP
#define MGC_UTIL_HPP

namespace mgc {

template <typename T>
void swap(T a[], int l, int r)
{
    T temp = a[l];
    a[l] = a[r];
    a[r] = temp;
}

}


#endif