#include <iostream>
#include <vector>
#define INT_MIN INT32_MIN
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/cut-into-segments_1214651?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

// Problem : You are given an integer N denoting the length of the rod. You need to determine the maximum number of segments you can make of this rod provided that each segment should be of the length 'X', 'Y', or 'Z'. If not possible, return 0.

// Approach : Using recursion we will solve, for example if we have N=8 and lengths of 1,2,3 then ans can be max of f(8-1) + 1, f(8-2) + 1, f(8-3) + 1... Make the lower number, take max amount, add 1. Base case is when 0 is reached, return 0, if a negative is reached, meaning it can't be cut, return INT_MIN so that it remains below 0. We apply memoization to it, to arrive at O(n) solution. Then we apply tabulation to convert it into iterative thing. Here dp[i] will depend on dp[i-x], dp[i-y], and dp[i-z] {check if indices are valid before taking max, and remember to add 1}. At end we check if dp[n] is <0 return 0 else dp[n]. Space optimisation can't be done further as we dont know x,y,z prior and they change ques to ques.

// recursion + memoisation
int solve(int n, int x, int y, int z, vector<int> &dp)
{
    if (n < 0)
        return INT_MIN;
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int cutX = solve(n - x, x, y, z, dp) + 1;
    int cutY = solve(n - y, x, y, z, dp) + 1;
    int cutZ = solve(n - z, x, y, z, dp) + 1;
    dp[n] = max(cutX, max(cutY, cutZ));
    return dp[n];
}

// tabulation
int solve2(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, INT_MIN);
    dp[0] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        if (i - x >= 0)
            dp[i] = max(dp[i], dp[i - x] + 1);
        if (i - y >= 0)
            dp[i] = max(dp[i], dp[i - y] + 1);
        if (i - z >= 0)
            dp[i] = max(dp[i], dp[i - z] + 1);
    }
    if (dp[n] < 0)
        return 0;
    return dp[n];
}

int cutSegments(int n, int x, int y, int z)
{
    // vector<int> dp(n+1,-1);
    // int ans = solve(n,x,y,z,dp);
    // if(ans<=0) return 0;
    // return ans;
    return solve2(n, x, y, z);
}