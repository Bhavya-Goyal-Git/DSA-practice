#include <iostream>
#include <vector>
#define INT_MAX INT32_MAX
using namespace std;

// Problem link : https://www.geeksforgeeks.org/problems/get-minimum-squares0538/1

// Problem : Given a number n, find how many minimum perfect squares are required to sum upto n. For example, n=100 then only 1 perfect square (10) is required to make it, ans is 1. If n=6 then minimum (1^2 + 1^2 + 2^2) are required to make it, so ans is three.

// Approach : The problem is similar to coin problem, here the range will be numbers upto sqrt(n). So we can design a recursive function. For a number n, make a temp variable initially int_max, as we are going for the minimum. Then loop across all perfect squares upto n, and make a recursive call to f(n-i*i). Remember to add 1 to the call to get how many such calls (numbers) will be required. Take minimum in each iteration, then return the temp variable as answer. The base case is when n=0, and no perfect square is required to make 0, so return 0. Apply memoization and then tabulation to improve the complexities.

class Solution
{
public:
    int solve(int n, vector<int> &dp)
    {
        if (n == 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        dp[n] = INT_MAX;
        for (int i = 1; i * i <= n; i++)
        {
            dp[n] = min(dp[n], solve(n - i * i, dp) + 1); // +1 is important here
        }
        return dp[n];
    }
    int solve2(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j * j <= i; j++)
            {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
    int MinSquares(int n)
    {
        // vector<int> dp(n+1,-1);
        // return solve(n,dp);
        return solve2(n);
    }
};