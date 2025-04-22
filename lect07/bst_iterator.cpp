// bst.cpp
#include <iostream>
#include "bst_iterator.h"
using namespace std;

bst::iterator bst::begin(){
    iterator it(getmin(root), this);
    return it; 
}

bst::iterator bst::end(){
    return iterator(nullptr, this);
}

bst::Node* bst::getmin(Node* r) const{
    if(!r) return nullptr;
    while(r && r->left){
        r= r->left;
    }
    return r;
}

bst::Node* bst::successor(Node* r)const{
    if(!r) return nullptr;
    Node* result = nullptr;
    if(r->right){
        result = getmin(r->right);
    }else{
        Node* p = r->parent;
        while(p && r == p->right){
            r = p;
            p = p->parent;
        }
        result = p;
    }
    return result;
}


void bst::linearize(Node *r, vector<int>& result) const{
    if(!r) return;
    //cout << r->data << " ";
    result.push_back(r->data);
    linearize(r->left, result);
    linearize(r->right, result);

}
vector<int> bst::linearize() const{
    vector<int> result;
    // Call helper function
    linearize(root, result);
    return result;
}

void bst::insert(int value, Node *r) {
    
}

// Helper recursive function
void bst::printInorder(Node *r) const{
    if (!r)
        return;
    printInorder(r->left);
    cout << r->data << " ";
    printInorder(r->right);
}

// Helper getHeight recursive
int bst::getHeight(Node *r) const{
    if (!r)
        return -1;
    int hleft = getHeight(r->left);
    int hright = getHeight(r->right);
    return max(hleft, hright) + 1;
}

bool bst::find(int value) const{
    return false;
}

void bst::printInorder() const{
   printInorder(root);
}

void bst::insert(int value){
    
}

void bst::clear(){
    return;
}

void bst::erase(int value){
    return;
}

int bst::getHeight() const{
    return getHeight(root); // call helper
}
//create a small bst with keys 42, 32, 12
/*   42
    /  \
   32   45
  /
12
*/
bst* create_small_bst(){
    bst* new_bst = new bst();
    new_bst->root = new bst::Node(42);
    new_bst->root->left = new bst::Node(32,new_bst->root);
    bst::Node* tmp = new_bst->root->left;
    tmp->left = new bst::Node(12, tmp);
    new_bst->root->right = new bst::Node(45, new_bst->root);
    return new_bst;
}
