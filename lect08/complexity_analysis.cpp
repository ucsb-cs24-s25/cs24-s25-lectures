#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

/* Problem: find all keys that appear in both the set and the vector,
   returning the result as a std::set containing the common keys. 
   Inputs: std::set containing N unique integer keys and 
   a std::vector containing M integer keys (not necessarily unique). 
   Output: set of all unique common keys 

   You are given two solutions:
   Solution 1: Iterate over the M keys in the vector and 
            use std::set::find to check if each key exists in the set.
        
   Solution 2: Iterate over the N keys in the set and use std::find on 
            the unsorted vector to check if each set key exists in the vector.

   Analyze the time complexity for each solution.
*/

// Solution 1: Iterate over vector and use std::set::find
std::set<int> findKeysInSetMethod1(const std::vector<int>& keysToFind, const std::set<int>& keySet) {
    std::set<int> foundKeys;
    for (int key : keysToFind) { // M times
        if (keySet.find(key) != keySet.end()) { // O(logN)
            foundKeys.insert(key); // O(1)
        }
    }
    return foundKeys;
}
// O(M log N)

// Solution 2: Iterate over set and use std::find on unsorted vector
std::set<int> findKeysInSetMethod2(const std::vector<int>& keysToFind, const std::set<int>& keySet) {
    std::set<int> foundKeys;
    for (int key : keySet) {
        if (std::find(keysToFind.begin(), keysToFind.end(), key) != keysToFind.end()) {
            foundKeys.insert(key);
        }
    }
    return foundKeys;
}
//O(NM)

// Function to print a set
void printSet(const std::set<int>& s) {
    std::cout << "{ ";
    for (int x : s) {
        std::cout << x << " ";
    }
    std::cout << "}" << std::endl;
}

int main() {
    // Example usage
    std::vector<int> keysToFind = {1, 3, 5, 7, 9};
    std::set<int> keySet = {2, 3, 4, 5, 6};

    std::cout << "Keys to find: ";
    printSet(std::set<int>(keysToFind.begin(), keysToFind.end()));
    std::cout << "Key set: ";
    printSet(keySet);

    // Test Solution 1
    std::cout << "Found keys (Method 1): ";
    std::set<int> result1 = findKeysInSetMethod1(keysToFind, keySet);
    printSet(result1);

    // Test Solution 2
    std::cout << "Found keys (Method 2): ";
    std::set<int> result2 = findKeysInSetMethod2(keysToFind, keySet);
    printSet(result2);

    return 0;
}