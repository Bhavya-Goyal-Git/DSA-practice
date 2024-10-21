#include <iostream>
#include <vector>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/count-ways-to-reach-nth-stairs_798650?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

// Problem : You have been given a number of stairs. Initially, you are at the 0th stair, and you need to reach the Nth stair. Each time, you can climb either one step or two steps. You are supposed to return the number of distinct ways you can climb from the 0th step to the Nth step. As output is big, return Output mod 10^9 + 7

// Approach : Classic recursion problem, it is, but throws time limit exceeded as complexity goes too high, We aim to optimize such problems using dynamic Programming.
// method 1: First we see that some function calls in recusive way are repititive, Overlapping, and if we store the function's value in some mapping, we could look into that before the computation, and if its available there return from it. This is called Top down approach that includes memoization with recursion. It alone reduces time comp to O(n) and space to O(2n)
// method 2: We are filling up the array in method 1 top to down, however it is much easy to think of it filling from bottom (base cases) up to our need, This converts recursive way into iterative way and rest remains same. This is bottom up method based on tabulisation, reduces space comp further to O(n)
// method 3: We observe in method 2, that in the function, calculation of a value needs only previous 2 results.. So why bother a array at all? Just make 2 pointers that keep track of the things and move them forward. This is space optimisation of bottom up method, reducing space comp to O(1)

#define MOD 1000000007

// approach 1: Top down method: Recursion with memoization
long long solve(int nStairs, vector<long long> &dp)
{
    if (dp[nStairs] != -1)
        return dp[nStairs];
    dp[nStairs] = solve(nStairs - 1, dp) + solve(nStairs - 2, dp);
    return dp[nStairs] % MOD;
}

// approach 2: Bottom Up Method: Tabulisation
long long solve2(int nStairs)
{
    vector<long long> dp(nStairs + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= nStairs; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }
    return dp[nStairs] % MOD;
}

// approach 3: Making bottom up approach space efficient
long long solve3(int nStairs)
{
    int prev1 = 1;
    int prev2 = 1;
    if (nStairs <= 1)
        return 1;
    for (int i = 2; i <= nStairs; i++)
    {
        long long c = (prev1 + prev2) % MOD;
        prev1 = prev2;
        prev2 = c;
    }
    return prev2 % MOD;
}

long long countDistinctWays(int nStairs)
{
    // vector<long long> dp(nStairs+1,-1);
    // dp[0] = 1;
    // dp[1] = 1;
    // return solve(nStairs,dp);

    return solve3(nStairs);
}