//playlist.cpp
#include <iostream>
#include <list>
using namespace std;
ostream& operator<<(ostream& os, const std::list<string>& playlist){
    for(auto song : playlist){
        os << song << " | ";
    }
    os << endl;

}
int main(int argc, char const *argv[])
{
    std::list<string> playlist= {"Beat It", "Bad", "Thriller"};
    playlist.push_front("Smooth Criminal");
    playlist.push_back("Heal the world");
    playlist.reverse();
    cout << playlist; // overloaded the << operator for printing a list. 
                      // Last line is a function call: operator<<(cout, playlist);
                      // Need to write a function with a matching signature!
    cout << playlist << playlist;
    return 0;
}


