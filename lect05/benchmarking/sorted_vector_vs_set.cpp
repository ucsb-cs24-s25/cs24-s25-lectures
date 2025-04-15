#include <iostream>  // For input/output (e.g., cout)
#include <vector>    // For std::vector to store data
#include <set>       // For std::set to store sorted, unique elements
#include <random>    // For random number generation
#include <algorithm> // For std::sort and std::binary_search
#include <cstdlib>   // For std::atoi to convert command-line argument to integer

using namespace std;
using namespace std::chrono;

// Step 1: Helper function to generate a vector of random numbers
// This creates a vector of N random integers between 0 and max_val for demonstration
// We use a large range (0 to 1,000,000) to ensure the std::set can grow with unique elements
vector<int> generate_random_data(int N, int max_val = 500) {
    random_device rd;                           // Seed for random number generation
    mt19937 gen(rd());                          // Mersenne Twister random number generator
    uniform_int_distribution<> dis(0, max_val); // Uniform distribution for integers in [0, max_val]

    vector<int> data(N);                       
    for (int &x : data) x = dis(gen);           // Fill the vector with random numbers
    return data;
}

// Step 2: Main function to compare std::set and sorted vector for dynamic updates
// The number of elements to insert dynamically will be provided as a command-line argument
int main(int argc, char* argv[]) {
    // Step 2.1: Parse the command-line argument for the number of elements to insert
    // Example usage: ./program 1000 (to insert 1000 elements)
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <number_of_elements_to_insert>\n";
        cout << "Example: " << argv[0] << " 1000\n";
        return 1;  // Exit with error if the argument is not provided
    }
    // Convert the command-line argument (a string) to an integer
    int num_elements_to_insert = atoi(argv[1]);
    if (num_elements_to_insert <= 0) {
        cout << "Please provide a positive number of elements to insert.\n";
        return 1;  // Exit with error if the number is not positive
    }

    // Step 2.2: Generate initial data (10 random integers between 0 and 1,000,000)
    // This is the starting data for both the std::set and sorted vector
    // Using a large range ensures the std::set can grow with unique elements
    vector<int> initial_data = generate_random_data(10);
    cout << "Initial data (unsorted, may have duplicates):\n";
    for (int x : initial_data) {
        cout << x << " ";
    }
    cout << "\n\n";

    // Step 2.3: Create a std::set and a sorted vector from the initial data
    // std::set automatically sorts and removes duplicates
    set<int> data_set(initial_data.begin(), initial_data.end());

    // Sorted vector needs to be explicitly sorted
    vector<int> sorted_vec(initial_data);
    sort(sorted_vec.begin(), sorted_vec.end());  // Sort the vector initially

    // Print both to show they are sorted
    cout << "Initial std::set (sorted, no duplicates):\n";
    for (int x : data_set) {
        cout << x << " ";
    }
    cout << "\n";

    cout << "Initial sorted vector (sorted, may have duplicates):\n";
    for (int x : sorted_vec) {
        cout << x << " ";
    }
    cout << "\n\n";

    // Step 2.4: Generate new elements to insert dynamically
    cout << "Generating " << num_elements_to_insert << " new elements to insert dynamically...\n";
    vector<int> new_elements = generate_random_data(num_elements_to_insert);

    // Step 2.5: Dynamic insertions into the std::set
    // std::set maintains its sorted order automatically 

    for (int x : new_elements) {
        data_set.insert(x);  
        // Time complexity of each insert: 
    }
  
    // Step 2.6: Dynamic insertions into the sorted vector
    // Sorted vector requires re-sorting after each insertion, which is O(N log N)
 
    for (int x : new_elements) {
        sorted_vec.push_back(x);// Time complexity to append:
        sort(sorted_vec.begin(), sorted_vec.end());  
        // Time complexity  to re-sort after each insertion:
    }
 
    // Step 2.7: Print the final sizes to show they are comparable
    cout << "Final size of std::set: " << data_set.size() << "\n";
    cout << "Final size of sorted vector: " << sorted_vec.size() << "\n\n";

    // Step 2.8: Verify both data structures still work for lookups
    // Pick a random element from new_elements to find
    int key_to_find = new_elements[0];

    // Find in std::set (O(log N))
    auto it_set = data_set.find(key_to_find);
    if (it_set != data_set.end()) {
        cout << "Found key " << key_to_find << " in std::set\n";
    } else {
        cout << "Key " << key_to_find << " not found in std::set\n";
    }

    // Find in sorted vector using std::binary_search (O(log N))
    bool found_vec = binary_search(sorted_vec.begin(), sorted_vec.end(), key_to_find);
    if (found_vec) {
        cout << "Found key " << key_to_find << " in sorted vector\n";
    } else {
        cout << "Key " << key_to_find << " not found in sorted vector\n";
    }

    return 0;
}