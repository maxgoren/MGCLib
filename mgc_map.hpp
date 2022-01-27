#ifndef MGC_MAP_HPP
#define MGC_MAP_HPP
#include "mgc_node.hpp"
#include "mgc_redblack.hpp"

namespace mgc {

template <typename T, typename T2>
class Map : private RedBlack<T, T2>
{
    private:
    node<T,T2>* root;
    T2 nullItem;
    public:
    Map()
    {
        root = nullptr;
    }
    void insert(T key, T2 info)
    {
        root = this->insertR(root, key, info);
        root->color = black;
    }
    void erase(T key)
    {
        root = this->eraseR(root, key);
        root->color = black;
    }
    T2 find(T key)
    {
        node<T,T2>* x = root;
        while (x != nullptr)
        {
            if (key == x->key)
                return x->info;

            x = (key < x->info) ? x->left:x->right;
        }
    }
    int size()
    {
        return this->size();
    }
};

}

#endif