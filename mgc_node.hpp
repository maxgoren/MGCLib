#ifndef NODE_HPP
#define NODE_HPP

const bool red = true;
const bool black = false;


///Node for Tree based structures
template <typename T, typename T2>
struct node {
        T key;
        T2 info;
        node* left;
        node* right;
        bool color;
        node(T _key, T2 _info) : key(_key), info(_info), left(nullptr), right (nullptr) { color = red; }
        node() { }
};


///Dobuly linked list structures,
template <typename T>
struct lnode {
        T info;
        lnode* next;
        lnode* prev;
        lnode(T _info) : info(_info), next(nullptr) { }
        lnode() { }
};


///singly linked list strucutres, (Queue, Stack, Forward_list)
template <typename T>
struct snode {
        T info;
        snode* next;
        snode(T _info) : info(_info), next(nullptr) { }
        snode(T _info, snode* _next) : info(_info), next(_next) { }
        snode() { }
};

///for use in pq heap
template <typename T, typename T2 = int>
struct pqnode {
        T info;
        T2 priority;
        pqnode(T _info, T2 _priority)
        {
                info = _info;
                priority = _priority;
        }
        pqnode()
        {

        }
        bool operator<(const pqnode& other) const {
                return (this->priority < other.priority);
        }
        bool operator>(const pqnode& other) const {
                return (this->priority > other.priority);
        }
        bool operator<=(const pqnode& other) const {
                return (this->priority <= other.priority);
        }
        bool operator>=(const pqnode& other) const {
                return (this->priority >= other.priority);
        }
        bool operator==(const pqnode& other) const {
                return (this->priority == other.priority);
        }
        bool operator!=(const pqnode& other) const {
                return !(this->priority == other.priority);
        }
};

#endif