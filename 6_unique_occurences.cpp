#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// Problem link : 
// https://leetcode.com/problems/unique-number-of-occurrences/submissions/1173060507/

// Problem : Given an array in which elements appear different number of times. If frequency of occuerence of every element is different, return true else return false

// Approach :
// we create a hashmap storing occurences of every element. Later, we try to store the occurences i.e. hashmap.second value into an unordered set. Failing to do so indicates the occurence already exists and we return a false else we return true

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> Hashmap;
        for (auto x:arr)
        {
            Hashmap[x]++;
        }
        unordered_set<int> Freq;
        for (auto x: Hashmap)
        {
            if(!Freq.insert(x.second).second)
            //The second parameter returned by insert function is status of insertion
            return false;
        }
        return true;
    }
};