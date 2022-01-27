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

template <typename T>
void _ins_sort(T a[], int l, int r)
{
    for (int i = l; i < r; i++)
    {
        int j = i;
        T v = a[j];
        while (j > l && a[j - 1] > v)
        {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = v;
    }
}

}


#endif