#ifndef MGC_SET_HPP
#define MGC_SET_HPP
#include "mgc_node.hpp"
#include "mgc_redblack.hpp"

namespace mgc {
    template <typename T>
class Set : private RedBlack<T, T> {
    private:
    node<T,T>* root;
    public:
    Set()
    {
        root = nullptr;
    }
    void insert(T key)
    {
        root = this->insertR(root, key, key);
        root->color = black;
    }
    void erase(T key)
    {
        root = this->eraseR(root, key);
        root->color = black;
    }
    T find(T key)
    {
        node<T,T>* x = root;
        while (x != nullptr)
        {
            if (x->key == key)
                return x->key;
            
            x = (key < x->key) ? x->left:x->right;
        }
    }
    int size()
    {
        return this->size();
    }
};
}

#endif