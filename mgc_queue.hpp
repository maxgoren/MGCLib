#ifndef MGC_QUEUE_HPP
#define MGC_QUEUE_HPP
#include "mgc_node.hpp"

namespace mgc {

template <typename T>
class Queue {
    private:
    snode<T>* head;
    snode<T>* z;
    snode<T>* tail;
    int N;
    public:
    Queue()
    {
        head = new snode<T>;
        z = new snode<T>;
        head->next = z;
        z->next = z;
        N = 0;
    }
    ~Queue()
    {
        clear();
        delete head;
        delete z;
    }
    bool empty() const {
        return (head->next == z);
    }
    int size() const {
        return N;
    }
    void push(T info)
    {
        snode<T>* n = new snode<T>(info);
        if (empty())
        {
            n->next = head->next;
            head->next = n;
            tail = n;
        } else {
            n->next = tail->next;
            tail->next = n;
            tail = n;
        }
        N++;
    }
    T front()
    {
        return head->next->info;
    }
    void pop()
    {
        snode<T>* t = head->next;
        head->next = head->next->next;
        delete t;
        N--;
    }
    void clear()
    {
        while (!empty()) pop();
    }
};

};

#endif;