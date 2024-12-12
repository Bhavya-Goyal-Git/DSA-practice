#include <iostream>
#include <vector>
using namespace std;

// Problem link : https://leetcode.com/problems/guess-number-higher-or-lower-ii/submissions/1450248141/

// Problem : We are playing the Guessing Game. The game will work as follows:
//  1. I pick a number between 1 and n.
//  2. You guess a number.
//  3. If you guess the right number, you win the game.
//  4. If you guess the wrong number, then I will tell you whether the number I picked is higher or lower, and you will continue guessing.
//  5. Every time you guess a wrong number x, you will pay x dollars. If you run out of money, you lose the game.
//  Given a particular n, return the minimum amount of money you need to guarantee a win regardless of what number I pick.

// Approach : We have to find minimum cost to gurantee that we guess the number. I.e. we actually have to guess the game strategy itself. We can start from any number 1 to n, and if we win the first try, no money spent, but if we are wrong, the guess money is spent and now it can be higher or lower (range changes) now, we have to get the max values of left and right range (to gurantee a guess). THis is a minimum of maximums type problem. So we make a recursive function with start, end parameters that represent range. Then if start>=end return 0. Now for this value, we run a loop accross the entire range (start to end) and take minimum of i + max( f(start,i-1) and f(i+1,end) ). Here i runs in loop of (start,end). We take minimum of all values as we have to minimise the cost (finding ideal strategy, which number do we pick first? to gurantee that minimum money is spent even in worst case) and taking max of left and right ranges to ensure we have enough money for the worst possible case. This can be memoised (2d dp as start, end both change) and then tabulated as start runs from n to 1 and end from start +1 to n. Rest is same. Time and space comp are O(n2)

class Solution
{
public:
    int solve(int start, int end, vector<vector<int>> &dp)
    {
        if (start >= end)
            return 0;
        if (dp[start][end] != -1)
            return dp[start][end];
        int ans = INT32_MAX;
        for (int i = start; i <= end; i++)
        {
            ans = min(ans, i + max(solve(start, i - 1, dp), solve(i + 1, end, dp)));
        }
        return dp[start][end] = ans;
    }
    int solve2(int n)
    {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int start = n; start >= 1; start--)
        {
            for (int end = start + 1; end <= n; end++)
            {
                int ans = INT32_MAX;
                for (int i = start; i <= end; i++)
                {
                    ans = min(ans, i + max(dp[start][i - 1], dp[i + 1][end]));
                }
                dp[start][end] = ans;
            }
        }
        return dp[1][n];
    }
    int getMoneyAmount(int n)
    {
        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // return solve(1,n,dp);
        return solve2(n);
    }
};