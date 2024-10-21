#include <iostream>
#include <vector>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/count-derangements_873861?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

// Problem : Given a number n, find number of derrangements of n items possible.

// Recurrence Proof : https://www.youtube.com/watch?v=duWHhbISG4A

// Approach : Once we know the recurrence relation, it is simple to write recusive appraoch and convert it to memoisation and then into tabulation and further optimise the space by getting rid of array altogether.

#define MOD 1000000007

// recursion + memoisation
long long int solve(int n, vector<long long int> &dp)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    dp[n] = (n - 1) * (solve(n - 1, dp) + solve(n - 2, dp)) % MOD;
    return dp[n];
}

// tabulation
long long int solve2(int n)
{
    vector<long long int> dp(n + 1);
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]) % MOD;
    }
    return dp[n];
}

// Space optimisation
long long int solve3(int n)
{
    long long int prev1 = 0;
    if (n == 1)
        return prev1;
    long long int prev2 = 1;
    for (int i = 3; i <= n; i++)
    {
        long long int curr = (i - 1) * (prev2 + prev1) % MOD;
        prev1 = prev2;
        prev2 = curr;
    }
    return prev2;
}

long long int countDerangements(int n)
{
    // vector<long long int> dp(n+1,-1);
    return solve3(n);
}