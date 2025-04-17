// bst.cpp
#include <iostream>
#include <random>
#include <set>
using namespace std;

vector<int> generate_random_data(int N, int max_val = 100){
    random_device rd;                           // Seed for random number generation
    mt19937 gen(rd());                          // Mersenne Twister random number generator
    uniform_int_distribution<> dis(1, max_val); // Uniform distribution for integers in [1, max_val]

    vector<int> data(N); // Create a vector of size N
    for (int &x : data)
        x = dis(gen); // Fill the vector with random numbers
    return data;
}

// bst is an Abstract Data Type
class bst{
public:
    // initialization routine: constructor
    bst() : root(nullptr) {}
    // accessors or getter
    bool find(int value) const; // searches for a value
    void printInorder() const;
    vector<int> linearize() const; //NEW!
    int getHeight() const; // returns the height of the tree

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
};

vector<int> bst::linearize() const{
    vector<int> result;
    // Call helper function
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
    new_bst->root->left = new bst::Node(32,new_bst->root->left);
    bst::Node* tmp = new_bst->root->left;
    tmp->left = new bst::Node(12, tmp);
    new_bst->root->right = new bst::Node(45, new_bst->root);
    return new_bst;
}
int main(){
    bst* mybst = create_small_bst();
    mybst->printInorder();
    cout << endl;
    cout << "Height = "<< mybst->getHeight() << endl;
    return 0;
}