//bst.cpp
#include <iostream>
using namespace std;

// bst is an Abstract Data Type
class bst{
 public:
    //initialization routine: constructor
    bst():root(nullptr){}
    // accessors or getter
    bool find(int value) const; //searches for a value
    void printInorder() const; 
    int getHeight() const; // returns the height of the tree

    // mutators or setter
    void insert(int value);
    void clear();
    void erase(int value);
    friend bst* create_small_bst();

 private:
    struct Node{
        int data;
        Node* parent;
        Node* left;
        Node* right;
        Node (int d): data(d){
            parent = left = right = nullptr;
        }
    };
    Node* root;
    int getHeight(Node* r) const;
    void printInorder(Node* r) const;
};
// Helper recursive function
void bst::printInorder(Node* r) const{
    if(!r) return;
    printInorder(r->left);
    cout << r->data << " ";
    printInorder(r->right);
}

// Helper getHeight recursive
int bst::getHeight(Node* r) const{
    if(!r) return -1;
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
    return;
}
void bst::clear(){
    return;
}
void bst::erase(int value){
    return;
}
int bst::getHeight() const{
    return getHeight(root); //call helper
} 

//create a small bst with keys 42, 32, 12
bst* create_small_bst(){
    bst* new_bst = new bst();
    new_bst->root = new bst::Node(42);
    new_bst->root->left = new bst::Node(32);
    new_bst->root->left->parent = new_bst->root;
    bst::Node* tmp = new_bst->root->left;
    tmp->left = new bst::Node(12);
    tmp->left->parent = tmp;
    return new_bst;
}

int main() {
    bst* mybst = create_small_bst();
    mybst->printInorder();
    cout << endl;
    cout << "Height = "<< mybst->getHeight() << endl;
    return 0;
}