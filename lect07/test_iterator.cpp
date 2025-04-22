//test_iterator.h

#include <iostream>
#include <random>
#include <set>
#include "bst_iterator.h"
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


int main(){
    auto rnd_nums = generate_random_data(10);
    set<int> s(rnd_nums.begin(), rnd_nums.end());

    // What you write (shorthand for-loop):
    for(int x : s){
        cout << x << " ";
    }
    cout << endl;

    // What actually gets executed (expanded version):
    for(set<int>::iterator it = s.begin(); it !=s.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
  
    //create a small bst with keys 42, 32, 12
    /*   42
        /  \
      32   45
     /
    12
    */
    bst* mybst = create_small_bst();
    // mybst->printInorder();
    // cout << endl;
    bst::iterator it;
    // bst::iterator it = mybst->begin();
    // while(it != mybst->end()){
    //     cout << *it << " ";
    //      ++it;
    // }
    // cout << endl;


    for(auto e: *mybst){
        cout << e << " ";
    }
    cout<< endl;
    return 0;
}
