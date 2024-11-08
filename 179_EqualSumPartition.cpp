#include <iostream>
#include <vector>
using namespace std;

// Problem link : https://www.geeksforgeeks.org/problems/subset-sum-problem2014/1

// Problem : Given an array arr, return true/false whether it can be partitioned into 2 subsets with equal sums. The subsets may have any different number of elements, any order.

// Approach : We first of all calculate sum of entire array, if its an odd number, we straight away return false as we cannot seprate integer array with odd sum. Then we know our number is now divisible by 2. So, all we have to check is whether sum/2 can be formed using elements of array, if yes, all remaining elements would sum up to that too and we have got our partition. This was the only catch, otherwise this now reduces to plain inclusion, exclusion problem that can be solved easily, then memoised, tabulated and space optimised.

class Solution
{
public:
    bool solve(vector<int> &arr, int index, int target, vector<vector<int>> &dp)
    {
        if (index >= arr.size() || target < 0)
            return false;
        if (target == 0)
            return true;
        if (dp[index][target] != -1)
            return dp[index][target];

        bool include = solve(arr, index + 1, target - arr[index], dp);
        bool exclude = solve(arr, index + 1, target, dp);
        dp[index][target] = include || exclude;
        return dp[index][target];
    }
    bool solve2(vector<int> &arr, int target)
    {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 1;
        }
        for (int index = n - 1; index >= 0; index--)
        {
            for (int t = 1; t <= target; t++)
            {
                bool include = false;
                if (t - arr[index] >= 0)
                    include = dp[index + 1][t - arr[index]];
                bool exclude = dp[index + 1][t];
                dp[index][t] = include || exclude;
            }
        }
        return dp[0][target];
    }
    bool solve3(vector<int> &arr, int target)
    {
        int n = arr.size();
        vector<int> next(target + 1, 0);
        vector<int> curr(target + 1, 0);
        next[0] = curr[0] = 1;

        for (int index = n - 1; index >= 0; index--)
        {
            for (int t = 1; t <= target; t++)
            {
                // bool include = false;
                // if(t-arr[index]>=0)
                //     include = next[t-arr[index]];
                // bool exclude = next[t];
                // curr[t] = include || exclude;
                curr[t] = next[t] || (t - arr[index] >= 0 ? next[t - arr[index]] : false);
            }
            next = curr;
        }
        return next[target];
    }
    bool equalPartition(vector<int> arr)
    {
        int sum = 0;
        for (int a : arr)
            sum += a;
        if (sum & 1)
            return false; // sum was odd
        // vector<vector<int>> dp(arr.size(),vector<int>(sum/2 +1,-1));
        // return solve(arr,0,sum/2,dp);
        return solve3(arr, sum / 2);
    }
};