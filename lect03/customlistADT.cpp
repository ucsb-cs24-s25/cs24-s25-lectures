// customlistADT.cpp
// An abstract data type (ADT) is a data structure defined by its operations—what it does—not how it’s built.

#include <iostream>
using namespace std;
// CustomList: Second try
class CustomList {
public:
    CustomList() : head(nullptr), tail(nullptr) {}
    CustomList(std::initializer_list<string> init);
    ~CustomList(){}
    void push_back(const string& val);
    void push_front(const string& val){}
    void pop_back(){}
    void pop_front(){}
    void clear(){}
    friend ostream& operator<< (ostream& os, CustomList & playlist);
    bool empty() const{return false;}
private:
    struct Node {
        string value;
        Node* next;
    };
    Node* head;
    Node* tail;

};
ostream& operator<< (ostream& os, CustomList & playlist){
    CustomList::Node* curr = playlist.head;
    while(curr){
        os << curr->value <<  " |";
        curr = curr->next;
    }
    os << endl;
    return os;
}
void CustomList::push_back(const string& val){
    
    Node* new_node = new Node{val, nullptr};
    if(!head) head = tail = new_node;
    else{
        tail->next = new_node;
        tail = tail->next;
    }
    
 }
 CustomList::CustomList(std::initializer_list<string> init):head(nullptr), tail(nullptr){
    for(auto song: init){
        push_back(song);
    }

 }
// Lab02 is about implementing a linked list ADT
// (5 mins) Activity 2: Spot the upgrades to CustomList 
// Below is an improved CustomList resembling std::list. 
// Analyze and enhance it in two steps:
// 1. Annotate (3 mins): Add brief comments to each line, explaining its purpose 
//    or why it’s there.
//   Compare to the old CustomList (from Activity 1) and identify upgrades 
//   (e.g., cleaner interface, better efficiency, improved safety).
// 2. Extend (2 mins): Add one new method to the public section — write its declaration 
//    and a short note on its purpose. Jot down any questions about the code.

int main(int argc, char const *argv[])
{
    /* code */
    CustomList playlist {"Beat It", "Bad"};
    cout << playlist;
    return 0;
}
