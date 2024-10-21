#include <iostream>
#include <vector>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/maximum-sum-of-non-adjacent-elements_843261?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

// Problem : You are given an array/list of ‘N’ integers. You are supposed to return the maximum sum of the subsequence with the constraint that no two elements are adjacent in the given array/list.Note: A subsequence of an array/list is obtained by deleting some number of elements (can be zero) from the array/list, leaving the remaining elements in their original order.

// Approach : We form subarray sums deciding whether to include the current element or not. If we include it, we have to go next at index-2 because we cannot include index-1th element now. If we chose to exculde we can go to index-1. These steps are done from last to 0th index and answer is obtained recursively. Base case is when index==0 i.e. only 1 element in array then return itself, or when index<0 (exculsion call made to 0) then return 0.
// Above gives TLE and we go for dynamic. First we add memoisation and thats easy. Second we try bottom up tabulisation, for that dp[0] = num[0] and dp[1] = max(num[0],num[1]). Then we can iterate for i=2 to n-1 and return n-1th value. Then we do space optimisation in approach and observe that ith value only depends on i-1 and i-2th values.. So we replace the array with 2 vars and do the job.

// normal recursion
int solve(vector<int> &nums, int index)
{
    if (index < 0)
        return 0;
    if (index == 0)
        return nums[0];
    int incl = solve(nums, index - 2) + nums[index];
    int excl = solve(nums, index - 1);
    return max(incl, excl);
}

// with memoisation
int solve2(vector<int> &nums, int index, vector<int> &dp)
{
    if (index < 0)
        return 0;
    if (index == 0)
        return nums[0];
    if (dp[index] != -1)
        return dp[index];
    int incl = solve2(nums, index - 2, dp) + nums[index];
    int excl = solve2(nums, index - 1, dp);
    dp[index] = max(incl, excl);
    return dp[index];
}

// tabulation way
int solve3(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n);
    dp[0] = nums[0];
    if (n > 1)
        dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++)
    {
        int incl = dp[i - 2] + nums[i];
        int excl = dp[i - 1];
        dp[i] = max(incl, excl);
    }
    return dp[n - 1];
}

// space optimization
int solve4(vector<int> &nums)
{

    int n = nums.size();
    int prev1 = nums[0];
    if (n == 1)
        return prev1;
    int prev2 = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++)
    {
        int curr = max(prev1 + nums[i], prev2);
        prev1 = prev2;
        prev2 = curr;
    }
    return prev2;
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    // return solve(nums, nums.size()-1);

    // int n= nums.size();
    // vector<int> dp(n,-1);
    // return solve2(nums, n-1, dp);

    // return solve3(nums);
    return solve4(nums);
}