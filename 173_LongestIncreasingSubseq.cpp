#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// Problem link : https://www.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1

// Problem : Given an array a[ ] of n integers, find the Length of the Longest Strictly Increasing Subsequence. A sequence of numbers is called "strictly increasing" when each term in the sequence is smaller than the term that comes after it. (subsequence means we can take or exclude any elements in the array, just that they must be in sequence as they are in the array)

// Approach : we try to do the problem recursively. We have to take care whether to include current index or not, and we will require the last (previous) index included in order to decide that. So we have 2 changing variables, index, prevIndex. index begins at 0 and prev at -1. if index>=size then return 0. Else we have to make 2 calls. A call to include current index, a call to exclude. but inclusion can only be done if previndex==-1 or arr[prev] < arr[index]. remember to add 1 to ensure inclusion. and in inclusion call, prev will become index in further call. And in exclusion call just increase index by 1. This is bad solution with exponential time.
// We apply memoisation over it. Remember that index goes 0 to n-1 and prevIndex goes -1 to n-1. So set size of dp array accordingly. Also, storage in dp array will be of form dp[index][previndex+1] because prevIndex=-1 will crash the indexing, so we store 1 ahead. This solution can be converted to tabulation and then space optimised to just 2 rows. Only remember that prevIndex+1 will be done wherever we acess the dp array. After doing all this, complexity is O(n2) time and O(2n) space. However this is not enough as there exists a clever O(nlogn) solution, using dp with binary search.
// We make a vector called tails. We push the first element into tails. Then we run a loop accross given array as follows: If given element is larger than tails' last element, then append it to tails, as it increases the subsequence length. Else: element is smaller, then find the index of a number within tails vector which is just larger than this element, and replace that number with this element. After end of this for loop, the size of tails vector is the length of LIS required. The process of finding just larger element in a sorted array (remember tails is sorted) can be done in logn time by binary search. We don't require to write it, C++ has built in func lower_bound() which takes .begin(), .end() and element whose lower bound needs to be found. It returns a pointer, so we subtract .begin() from it to get index integer and perform the replacement. NOW, why this works: This approach build up tails array such that last values of it are as minimum as possible. If a useless replacement is done (at begin etc) then that does not affect the answer as we want the length of LIS and not the LIS itself. The aim of this approach is to keep reducing the tail elements so possibility of increasing the subsequence is maximised, on the same hand, if subsitution is useless, it does not affect length of LIS, ie the answer. This approach is O(nlogn) time, O(n) space.

class Solution
{
public:
    // recursive
    int solve(int arr[], int n, int index, int prevIndex)
    {
        if (index >= n)
            return 0;
        int include = INT_MIN;
        if (prevIndex == -1 || arr[prevIndex] < arr[index])
        {
            include = 1 + solve(arr, n, index + 1, index);
        }
        int exclude = solve(arr, n, index + 1, prevIndex);
        return max(include, exclude);
    }
    // memoised
    int solve2(int arr[], int n, int index, int prevIndex, vector<vector<int>> &dp)
    {
        if (index >= n)
            return 0;
        if (dp[index][prevIndex + 1] != -1)
            return dp[index][prevIndex + 1];
        int include = INT_MIN;
        if (prevIndex == -1 || arr[prevIndex] < arr[index])
        {
            include = 1 + solve2(arr, n, index + 1, index, dp);
        }
        int exclude = solve2(arr, n, index + 1, prevIndex, dp);
        dp[index][prevIndex + 1] = max(include, exclude);
        return dp[index][prevIndex + 1];
    }
    // Tabulated
    int solve3(int arr[], int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int index = n - 1; index >= 0; index--)
        {
            for (int prevIndex = index - 1; prevIndex >= -1; prevIndex--)
            {
                int include = INT_MIN;
                if (prevIndex == -1 || arr[prevIndex] < arr[index])
                {
                    include = 1 + dp[index + 1][index + 1];
                    ;
                }
                int exclude = dp[index + 1][prevIndex + 1];
                dp[index][prevIndex + 1] = max(include, exclude);
            }
        }
        return dp[0][0];
    }
    // Space optimised
    int solve4(int arr[], int n)
    {
        vector<int> curr(n + 1, 0);
        vector<int> next(n + 1, 0);
        for (int index = n - 1; index >= 0; index--)
        {
            for (int prevIndex = index - 1; prevIndex >= -1; prevIndex--)
            {
                int include = INT_MIN;
                if (prevIndex == -1 || arr[prevIndex] < arr[index])
                {
                    include = 1 + next[index + 1];
                }
                int exclude = next[prevIndex + 1];
                curr[prevIndex + 1] = max(include, exclude);
            }
            next = curr;
        }
        return next[0];
    }
    // Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        //     vector<vector<int>> dp(n,vector<int>(n+1,-1));
        //   return solve2(a,n,0,-1,dp);
        return solve4(a, n);
    }
};

class Solution2
{
public:
    // Function to find length of longest increasing subsequence.
    int solveOptimal(int arr[], int n)
    {
        if (n == 0)
            return 0;
        vector<int> tails;
        tails.push_back(arr[0]);
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > tails.back())
            {
                tails.push_back(arr[i]);
            }
            else
            {
                // finding just bigger element using binary search
                int index = lower_bound(tails.begin(), tails.end(), arr[i]) - tails.begin();
                tails[index] = arr[i];
            }
        }
        return tails.size();
    }
    int longestSubsequence(int n, int a[])
    {
        return solveOptimal(a, n);
    }
};