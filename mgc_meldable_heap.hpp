#ifndef MGC_MELDABLE_HEAP_HPP
#define MGC_MELDABLE_HEAP_HPP
/* 
* Randomized Meldable heap
* Creates min ordered heap
* which can be merged in O(log n)
* (c) MIT License Max Goren, maxgoren@gmail.com 8/2022
*/
namespace mgc {
template <typename T>
class PQ {
    private:
        struct node {
            node *l, *r, *p;
            T info;
            node(T info_) {
                info = info_; l = r = p = nullptr;
            }
        };
        node* root;
        int n;
        node* merge(node* a, node* b) {
            if (a == nullptr) return b;
            if (b == nullptr) return a;
            if (b->info < a->info) return merge(b, a);
            if (rand() % 2 == 0) {
                a->l = merge(a->l, b);
                a->l->p = a;
            } else {
                a->r = merge(a->r, b);
                a->r->p = a;
            }
            return a;
        }
    public:
        PQ()
        {
            root = nullptr;
            n = 0;
        }
        void push(T info)
        {
            node* t = new node(info);
            root = merge(t, root);
            n++;
        }
        T top()
        {
            return root->info;
        }
        void pop()
        {
            node* t = root;
            root = merge(root->l, root->r);
            if (root != nullptr) root->p = nullptr;
            n--;
            delete t;
        }
        bool empty() const {
            return root == nullptr;
        }
        int size() const {
            return n;
        }
};
}
#endif