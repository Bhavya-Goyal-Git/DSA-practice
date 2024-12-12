#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Problem link : https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/description/

// Problem : Given an integer array arr and an integer difference, return the length of the longest subsequence in arr which is an arithmetic sequence such that the difference between adjacent elements in the subsequence equals difference.

// Approach : This question can be solved using 2 ways, using similar approach as Longest Increasing subsequence (LIS) with a restriction or similar to last question with just 1 loop. We will do the last one because its complexity will be O(n). With a loop we traverse the array, maintain a unordered map and a global maximum ans. At the element, we find element-difference, i.e. the previous element according to AP that should have been in the array. Then we find if this element is in array using the map. We initialize a count to 0. If that element existed we make count that value. Then store that map[current value] = count + 1. I.e. for this number, the Ap with given difference ending here is this much. After this, we update the global maximum. Return the global max after the loop.

class Solution
{
public:
    int longestSubsequence(vector<int> &arr, int difference)
    {
        unordered_map<int, int> m; // entry type: element,vaha tak ka largest AP len
        int ans = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            int prevElem = arr[i] - difference;
            int currlen = 0;
            if (m.count(prevElem))
                currlen = m[prevElem];
            m[arr[i]] = currlen + 1;
            ans = max(ans, m[arr[i]]);
        }
        return ans;
    }
};