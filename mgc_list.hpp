#ifndef MGC_LIST_HPP
#define MGC_LIST_HPP
#include "mgc_node.hpp"
namespace mgc {

template <typename T>
class List {
    private:
    lnode<T>* head;
    lnode<T>* z;
    public:
    List()
    {
        head = new lnode<T>;
        z = new lnode<T>;
        head->next = z;
        head->prev = head;
        z->prev = head;
        z->next = z;
    }
    void push_back(T info)
    {
        lnode<T>* n = new lnode<T>(info);
        n->prev = z->prev;
        z->prev->next = n;
        n->next = z;
        z->prev = n;
    }
    void push_front(T info)
    {
        lnode<T>* n = new lnode<T>(info);
        n->next = head->next;
        head->next->prev = n;
        n->prev = head;
        head->next = n;
    }
    void insert(T info, T after)
    {
        lnode<T>* n = new lnode<T>(info);
        for (lnode<T>* itr = head; itr != z; itr = itr->next)
        {
            if (info == itr->info)
            {
                itr->next->prev = n;
                n->prev = itr;
                n->next = itr->next;
                itr->next = n;
            }
        }
    }
    void erase(T info)
    {
        for (lnode<T>* itr = head; itr != z; itr = itr->next)
        {
            if (itr->next->info == info)
            {
                lnode<T>* t = itr->next;
                itr->next = itr->next->next;
                itr->next->prev = itr->prev;
                delete t;
                return;
            }
        }
    }
    void pingPong()
    {
        for (lnode<T>* itr = head->next; itr != z; itr = itr->next)
        {
            std::cout<<itr->info<<" ";
            if (itr->next == z)
            {
                for (itr = itr->prev; itr != head; itr = itr->prev) 
                {
                    std::cout<<itr->info<<" ";
                    if (itr->prev == head)
                      return;
                }
            }
        }
        std::cout<<std::endl;
    }
};

}

#endif