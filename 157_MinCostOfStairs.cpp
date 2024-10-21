#include <iostream>
#include <vector>
using namespace std;

// Problem link : https://leetcode.com/problems/min-cost-climbing-stairs/description/

// Problem : You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps. You can either start from the step with index 0, or the step with index 1. Return the minimum cost to reach the top of the floor. Note: at least 2 stairs will be there

// Approach : First of all we find a recusive way, The cost of climbing to nth stair can be from n-1 th stair or n-2th stair, Remember to add cost of n-1th and n-2th in their respective calls, also remember cost is spent when we use a stair and not just come onto it, i.e. cost of nth stair is not given and hence is not added. To find the min cost, we develop the recurrence relation that cost of a stair is cost of using it + min of (cost of n-1 th, cost of n-2th).. These calls have to be made for n-1th stair and n-2th stair, and their minimum taken (outside of function, in main) and returned. But this gives TLE, so we apply dynamic programming.
// First thing is memoization: we create a vector and ]before recusive calls check if it has solution already.. Also, store result of calls into vector first, before returning.. This makes O(n) time but space is O(2n).
// Secondly we try tabulation, converting function to iterative form. We make array within the function, assign base values (0 and 1) to cost[0] and cost[1] and iterate for i=2 i=n-1 th stair. The answer is minimum of value of n-1 th and n-2 th stair.
// Third is space optimisation, As we see we only need to keep track of previous 2 values for a value calculation, so we run the same loop as in bottom up approach, just with 2 variables prev1 and prev2, which at the end of loop hold results of f(n-1) and f(n-2) and hence their minimum is the ans. This way time is reduced to O(n) and space to O(n-1)

class Solution
{
public:
    // recursive solution
    int solve(int nStairs, vector<int> &cost)
    {
        if (nStairs <= 1)
            return cost[nStairs];
        return cost[nStairs] + min(solve(nStairs - 1, cost), solve(nStairs - 2, cost));
    }

    // recursion with memoization (top-down)
    int solve2(int nStairs, vector<int> &cost, vector<int> &dp)
    {
        if (nStairs == 0 || nStairs == 1)
            return cost[nStairs];
        if (dp[nStairs] != -1)
            return dp[nStairs];
        dp[nStairs] = cost[nStairs] + min(solve2(nStairs - 1, cost, dp), solve2(nStairs - 2, cost, dp));
        return dp[nStairs];
    }

    // Tabulation (bottom-up)
    int solve3(int nStairs, vector<int> &cost)
    {
        vector<int> dp(nStairs + 1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < nStairs; i++)
        {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        return min(dp[nStairs - 1], dp[nStairs - 2]);
    }

    // Optimising Space Comp
    int solve4(int nStairs, vector<int> &cost)
    {
        int prev1 = cost[0];
        int prev2 = cost[1];
        for (int i = 2; i < nStairs; i++)
        {
            int curr = cost[i] + min(prev1, prev2);
            prev1 = prev2;
            prev2 = curr;
        }
        return min(prev1, prev2);
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        int nStairs = cost.size();
        // int ans = min(solve(nStairs-1,cost),solve(nStairs-2,cost));
        // return ans;

        // vector<int> dp(nStairs+1,-1);
        // int ans = min(solve2(nStairs-1,cost,dp),solve2(nStairs-2,cost,dp));
        // return ans;

        return solve4(nStairs, cost);
    }
};