/*
*   Heap based Priority Queue implementing
*   both Min Heap and Max Heap through the use
*   of compartor objects.
*   std::greater<Priority, Item> - MinHeap
*   std::less<Priority, Item> - MaxHeap
*
*  (C) Max Goren 2022 - http://www.maxgcoding.com
*  Distributed under MIT License
*/

#ifndef MGC_HEAP_PRIORITY_QUEUE_HPP
#define MGC_HEAP_PRIORITY_QUEUE_HPP

#include <iostream>
using namespace std;

namespace mgc {

template <class Priority, class Item, class Comp>
class PriorityQueue {
    private:
    typedef pair<Priority, Item> heapPair;
    Comp comp;
    heapPair *Heap;
    int heapMaxSize;
    int N;
    void exch(heapPair& a, heapPair& b)
    {
        auto tmp = a;
        a = b;
        b = tmp;
    }
    void upHeap(int k)
    {
        while (k > 1 && comp(Heap[k/2], Heap[k]))
        {
            exch(Heap[k], Heap[k/2]);
            k /= 2;
        }
    }
    void downHeap(int k, int N)
    {
        while (2*k <= N)
        {
            int j = 2*k;
            if (j < N && comp(Heap[j], Heap[j+1])) j++;
            if (!comp(Heap[k], Heap[j])) break;
            exch(Heap[k], Heap[j]);
            k = j;
        }
    }
    public:
    PriorityQueue(int maxN = 255)
    {
        N = 0;
        heapMaxSize = maxN;
        Heap = new heapPair[heapMaxSize+1];
    }
    void push(Priority pri, Item item)
    {
        if (N+1 < heapMaxSize)
        {
            Heap[++N] = make_pair(pri, item);
        } else {
            //i thought this was a nice little addition 
            heapMaxSize *= 1.75;
            heapPair *tmp = new heapPair[heapMaxSize+1];
            for (int i = 0; i < N; i++)
            {
                tmp[i] = Heap[i];
            }
            delete Heap;
            Heap = tmp;
            Heap[++N] = make_pair(pri, item);
        }
        upHeap(N);
    }
    Item pop()
    {
        exch(Heap[1], Heap[N]);
        downHeap(1, N-1);
        return Heap[N--].second;
    }
    bool empty()
    {
        return (N == 0);
    }
    int size()
    {
        return 0;
    }
};

}

#endif