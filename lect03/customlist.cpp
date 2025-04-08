//customlist.cpp
#include <iostream>
using namespace std;
// In this activity, you’ll work with a simple CustomList class 
// and compare it to the C++ Standard Library’s std::list. 
// Use the code below to guide your answers.
struct Node {
    string value;  // Song titles as strings
    Node* next;
};

class CustomList {
public:
    Node* head;
    CustomList() : head(nullptr) {}
    void add(string val) {
        Node* newNode = new Node{val, nullptr};
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
};
// (4 mins) Coding Task: Complete the createPlaylist function to:
// 1. Create a CustomList playlist.
// 2. Add the songs "Bad," "Beat It," and "Thriller" (in that order) 
// 3. Print all songs in the playlist by traversing the list (e.g., using cout).
// Hint: You’ll need to loop through the nodes starting from head.

// (2 mins) Discussion Task: Imagine a friend wants to use CustomList for their music app. 
// List two reasons why std::list might be a better choice, considering:
// Ease of use (e.g., built-in features, syntax).
// Efficiency (e.g., performance of operations).
// Safety (e.g., avoiding data corruption).

void createPlaylist(){
   
  






















}

int main(){
    createPlayList();
    return 0;
}