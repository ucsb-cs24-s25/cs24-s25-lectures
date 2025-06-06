// In class solution to leetcode problem longest consecutive sequence
// https://leetcode.com/problems/longest-consecutive-sequence/description/
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
 int lcs(unordered_map<int, int>& M, int key) {
        if (M.count(key) == 0) return 0;
        if (M[key] > 1) return M[key];

        M[key] = 1 + lcs(M, key + 1);
        return M[key];
    }

    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_map<int, int> seqMap;
        for (int num : nums) {
            seqMap[num] = 1; // placeholder to mark presence
        }

        int maxLen = 0;
        for (auto& [num, _] : seqMap) {
            maxLen = max(maxLen, lcs(seqMap, num));
        }

        return maxLen;
        // Sam running time as unordered_set
    }
    // Improve this inefficient approach that uses a hashtable
    int longestConsecutive_v3(const std::vector<int>& nums) {
        std::unordered_set<int> s(nums.begin(), nums.end()); // O(n) on average, worst case O(n^2)
        int maxLen = 0;
        for (int num : s) {
            if (!s.contains(num - 1)){     // O(1) average case            
                int seqLen = 1;
                int current = num;
                // Check for consecutive numbers after current
                while (s.count(current + 1)) { 
                    current++;
                    seqLen++;
                }
                maxLen = std::max(maxLen, seqLen);
            }
        }
        // Even though there is a nested loop, overall, there are constant time checks done per key
        // so O(n) over all iterations of the loop. That's because we only compute the LCS for the 
        // keys that are at the start of a sequence and skip over all the others.
        
        return maxLen;
        //Overall T(n) = O(n) (average); T(n)= O(n^2), worst case
    }

    int longestConsecutive_v2(vector<int>& nums) {
        if(nums.empty()) return 0;
        set<int> s(nums.begin(), nums.end()); // O(nlogn)
        int maxlen  = 0;
        int seqlen = 1;
        for (auto num : s){ // O(n)
            if(s.find(num + 1) != s.end()){ // O(logn)
                seqlen++;
            }else{
                maxlen = max(maxlen, seqlen);
                seqlen = 1;
            }
        }
        // Overall for loop: O(nlogn)
        // T(n) = O(nlogn) + (nlogn) = O(nlogn)
        maxlen = max(maxlen, seqlen);
        return maxlen;
        
    }
    int longestConsecutive_v1(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(), nums.end()); // O(nlogn)
        int maxlen  = 0;
        int seqlen = 1;
        for (int i = 0; i < nums.size() - 1; i++){ // O(n)
            if(nums[i] == nums[i + 1]){
                continue;
            }
            else if(nums[i] + 1 == nums[i + 1]){
                seqlen++;
            }else{
                maxlen = max(maxlen, seqlen);
                seqlen = 1;
            }
        }
        maxlen = max(maxlen, seqlen);
        return maxlen;
        //Overall, T(n) = O(nlogn) + O(n) = O(nlogn)
    }
};