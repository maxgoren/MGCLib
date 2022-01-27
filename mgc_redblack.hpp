#ifndef MGC_REDBLACK_HPP
#define MGC_REDBLACK_HPP
#include "mgc_node.hpp"
#include <iostream>

namespace mgc {

template <typename T, typename T2>
class RedBlack {
    public:
    int N;
    node<T,T2>* colorFlip(node<T,T2>* h)
    {
        h->color = !h->color;
        h->right->color = !h->right->color;
        h->left->color = !h->left->color;
        return h;
    }
    node<T,T2>* rotL(node<T,T2>* h)
    {
        node<T,T2>* x = h->right;
        h->right = x->left;
        x->left = h;
        x->color = h->color;
        h->color = red;
        return x;
    }
    node<T,T2>* rotR(node<T,T2>* h)
    {
        node<T,T2>* x = h->left;
        h->left = x->right;
        x->right = h;
        x->color= h->color;
        h->color = red;
        return x;
    }
    node<T,T2>* moveRedLeft(node<T,T2>* h)
    {
        h = colorFlip(h);
        if (isRed(h->right->left))
        {
            h->right = rotR(h->right);
            h = rotL(h);
            h = colorFlip(h);
        }
        return h;
    }
    node<T,T2>* moveRedRight(node<T,T2>* h)
    {
        h = colorFlip(h);
        if (isRed(h->left->left))
        {
            h = rotR(h);
            h = colorFlip(h);
        }
        return h;
    }
    node<T,T2>* deleteMin(node<T,T2>* h)
    {
        if (h->left == nullptr) return nullptr;
        if (!isRed(h->left) && !isRed(h->left->left))
            h = moveRedLeft(h);
        h->left = deleteMin(h->left);
        return fixUp(h);
    }
    node<T,T2>* eraseR(node<T,T2>* h, T key)
    {
        if (key < h->key)
        {
            if (!isRed(h->left) && !isRed(h->left->left))
                h = moveRedLeft(h);
            h->left = eraseR(h->left, key);
        } else {
            if (isRed(h->left))
                h = rotR(h);
            if (key == h->key && (h->right == nullptr))
                return nullptr;
            if (!isRed(h->right) && !isRed(h->right->left))
                h = moveRedRight(h);
            if (key == h->key)
            {    
                h->info = h->right->info;
                h->key = h->right->key;
                h->right = deleteMin(h->right);
            } else {
                h->right = eraseR(h->right, key);
            }
        }
        return fixUp(h);
    }
    bool isRed(node<T,T2>* h)
    {
        if (h == nullptr) return false;
        return (h->color == red);
    }
    node<T,T2>* fixUp(node<T,T2>* h)
    {
        if (isRed(h->right) && !isRed(h->left))
            h = rotL(h);
        if (isRed(h->left) && isRed(h->left->left))
            h = rotR(h);
        if (isRed(h->left) && isRed(h->right))
            h = colorFlip(h);
        return h;
    }
    node<T,T2>* insertR(node<T,T2>* h, T key, T2 info)
    {
        if (h == nullptr)
        {
            h = new node<T,T2>(key, info);
            return h;
        }

        //cant have multiple values with same key
        //stores most recent key/value for item entered
        if (key == h->key)
        {
            h->info = info;
            return h;
        }

        if (key < h->key) h->left = insertR(h->left, key, info);
        else h->right = insertR(h->right, key, info);
        
        h = fixUp(h);
        
        return h;
    }

    void walk(node<T,T2>* h)
    {
        if (h == nullptr) return;
        std::cout<<h->key;
        if (isRed(h)) std::cout<<" red.\n";
        else std::cout<<" black.\n";
        walk(h->left);
        walk(h->right);
    }
    node<T,T2>* root;
    RedBlack()
    {
        root = nullptr;
    }
    void insert(T key, T2 info)
    {
        root = insertR(root, key, info);
        root->color = black;
        N++;
    }
    void erase(T key)
    {
        root = eraseR(root, key);
        root->color = black;
        N--;
    }
    void show()
    {
        walk(root);
    }
    int size()
    {
        return N;
    }
};

}

#endif