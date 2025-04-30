#include <iostream>
#include <set>

// Function to print all values in a std::set using a range-based for loop
void printSetValues(const std::set<int>& s) {
    for (int value : s) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    std::set<int> mySet = {10, 20, 30, 40, 50};
    std::cout << "Set values: ";
    printSetValues(mySet); // Output: 10 20 30 40 50
    return 0;
}