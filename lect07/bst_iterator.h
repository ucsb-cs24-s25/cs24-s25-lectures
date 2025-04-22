//bst_iterator.h
#include <iostream>
using namespace std;
// bst is an Abstract Data Type
# ifndef bst_iterator_h
# define bst_iterator_h

class bst{
public:
    // initialization routine: constructor
    bst() : root(nullptr) {}
    // accessors or getter
    bool find(int value) const; // searches for a value
    void printInorder() const;
    int getHeight() const; // returns the height of the tree
    vector<int> linearize() const; // NEW!

    // mutators or setter
    void insert(int value);
    void clear();
    void erase(int value);
    friend bst* create_small_bst();

private:
    struct Node{
        int data;
        Node *parent;
        Node *left;
        Node *right;
        Node(int d, Node* p = nullptr) : data(d), parent(p){
            left = right = nullptr;
        }
    };
    Node *root;
    int getHeight(Node *r) const;
    void printInorder(Node *r) const;
    void insert(int value, Node *r);
    void linearize(Node *r, vector<int>& result) const;
    Node* successor(Node* r) const;
    Node* getmin(Node* r) const;
};
class bst::iterator{
    public:
        iterator(bst::Node* p = nullptr, bst* ptree = nullptr): curr(p), tree(ptree){}
        int operator*(){
            return curr->data;
        }
        iterator& operator++(){
            curr = tree->successor(curr);
            return *this;
        }
        bool operator!=(&iterator rhs){
            return curr != rhs.curr;
        }
    private:
        bst::Node* curr;
        bst* tree;
};
bst* create_small_bst();
#endif
