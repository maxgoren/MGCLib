#ifndef MGC_VECTOR_HPP
#define MGC_VECTOR_HPP

namespace mgc {

template <typename T>
class Vector {
    private:
    T *arr;
    int N;
    int maxN;
    public:
    Vector(int max)
    {
        N = 0;
        maxN = max;
        arr = new T[maxN];
        for (int i = 0; i < maxN; i++)
            arr[i] = T(0);
    }
    Vector()
    {
        N = 0;
        maxN = 5;
        arr = new T[maxN];
        for (int i = 0; i < maxN; i++)
          arr[i] = T(0);
    }
    void pop_back(T value)
    {
        N--;
    }
    void push_back(T value)
    {
        if (N+1 == maxN)
        {
            maxN *= 1.5;
            T* next = new T[maxN];
            for (int i = 0; i < N; i++)
                next[i] = arr[i];
            delete arr;
            arr = next;
        }
        arr[N++] = value;
    }
    int size()
    {
        return N;
    }
    bool empty()
    {
        return (N == 0);
    }
    T& operator[](int i) {
        return arr[i];
    }

};

}

#endif