#ifndef MGC_PRIORITY_QUEUE_HPP
#define MGC_PRIORITY_QUEUE_HPP
#include "mgc_node.hpp" //pqnode
#include "mgc_util.hpp" //swap()
namespace mgc {

template <typename T, typename T2 = int>
class PriorityQueue {
    private:
    pqnode<T, T2> **pqarr;
    int N;
    int maxN;
    void fixDown(int k, int N)
    {
        while (2*k <= N)
        {
            int j = 2*k;
            if (j < N && pqarr[j]->priority < pqarr[j+1]->priority) j++;
            if (!(pqarr[k]->priority < pqarr[j]->priority)) break;
            swap(pqarr, j, k); k = j;
        }
    }
    void fixUp(int k)
    {
        while (k > 1 && pqarr[k/2]->priority < pqarr[k]->priority)
        { 
            swap(pqarr, k, k/2); 
            k = k/2; 
        }
    }
    public:
    PriorityQueue(int default_size = 100)
    {
        maxN = default_size;
        N = 0;
        pqarr = new pqnode<T,T2>*[maxN+1];
    }
    int size() const {
        return N;
    }
    bool empty() {
        return (N == 0);
    }
    void push(T info, T2 priority)
    {
        pqarr[++N] = new pqnode<T, T2>(info, priority);
        fixUp(N);
    }
    void push(T info)
    {
        ++N;
        pqarr[N] = new pqnode<T,T2>(info, N);
        fixUp(N);
    }
    T top()
    {
        return pqarr[1]->info;
    }
    void pop()
    {
        swap(pqarr, 1, N);
        fixDown(1, N-1);
        N--;
    }
    void dump()
    {
        for (int i = 1; i <= N; i++)
          std::cout<<pqarr[i]->info<<" - "<<pqarr[i]->priority<<"\n";
    }
};


}

#endif