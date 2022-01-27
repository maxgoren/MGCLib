#ifndef MGC_STACK
#define MGC_STACK
#include "mgc_node.hpp"

namespace mgc {

template <typename T>
class Stack {
    private:
    snode<T>* head;
    snode<T>* z;
    int N;
    public:
    Stack()
    {
        head = new snode<T>;
        z = new snode<T>;
        head->next = z;
        z->next = z;
        N = 0;
    }
    ~Stack()
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
        head->next = new snode<T>(info, head->next);
        N++;
    }
    void pop()
    {
        snode<T>* t = head->next;
        head->next = head->next->next;
        delete t;
        N--;
    }
    T top()
    {
        return head->next->info;
    }
    void clear()
    {
        while (!empty()) pop();
    }
};

}

#endif