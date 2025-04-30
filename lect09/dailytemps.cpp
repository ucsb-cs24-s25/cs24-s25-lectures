//dailytemps.cpp
//solution to leet code problem: https://leetcode.com/problems/daily-temperatures/
#include <vector>
#include <stack>
using namespace std;
class Solution {
    public:
        vector<int> dailyTemperatures_0(vector<int>& temperatures) {
            vector<int> result(temperatures.size(), 0);
            for (int i = 0; i < temperatures.size(); i++){ // n times
                for(int j = i + 1; j < temperatures.size(); j++){ // n - i - 1
                    if(temperatures[j] > temperatures[i]){
                        result[i] = j - i;
                        break;
                    }
                }
            } 
            // Running time =  O(n^2)
            // More careful analyis:
            // T(n) = (n - 1 + n - 2 + n - 3 ...+ 3 + 2 + 1 ) * c
            //      = (n-1)* n / 2 = n^2/2 - n/2
            // T(n) = O(n^2) (
            return result;     
        }
    
        vector<int> dailyTemperatures(vector<int>& temperatures) {
            int n  = temperatures.size(); // O(1)
            vector<int> result(n, 0); //O(n)
            stack<int> days;  // O(1)
            for (int i = n - 1; i >= 0 ; i--){  // n times
                // Since the while loop and number of pops is variable per iteration,
                // bound the total cost over all iterations  
                while(!days.empty() && temperatures[i] >= temperatures[days.top()]){ 
                    // while loop condition check is done as many times as the total number of pops + 
                    // + one additional time per iteration. So overall 2n checks = O(n)
                    days.pop(); // variable per iteration ; every value is pushed only once, so it can be poppped at most once
                                // overall complexity for pop is O(n)
                }
                if(!days.empty()) result[i] = days.top() - i;
    
                days.push(i); // O(1) per iterartion
                
            }
            return result;   
    
        }
    //Overall running time: O(n)
    //Auxilliary Space complexity:  O(n) 
            
    };