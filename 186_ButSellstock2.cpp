#include <iostream>
#include <vector>
using namespace std;

// Problem link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

// Problem :You are given an integer array prices where prices[i] is the price of a given stock on the ith day. On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day. Find and return the maximum profit you can achieve.

// Approach : We iterate through the array in recursion, at each step we have 2 choices, either we ignore that day, or we buy/sell that day.. buying can be only when we can and selling only after buying. i.e. 2 simultaneous buy or sells can't be there. So we make 2 variables index and canbuy (bool) and at each step make ignore call and a buy/sell call (based on value of canbuy which is initially sent true).. we return max of the calls. THis approach can be easily memoised and tabulated.
// Better Greedy way: We observe the if we can sell immideately, we should, it won't matter in long run, so simply run a loop accross element index 1 to last... if prices[i]>prices[i-1] simply add the value p[i]-p[i-1] to the ans. return ans at end. Warning: This only works for this variation of problem, not buysellStocks variation 3,4 or 5.

class Solution
{
public:
    int solve(vector<int> &prices, int index, bool canbuy, vector<vector<int>> &dp)
    {
        if (index >= prices.size())
            return 0;
        if (dp[index][canbuy] != -1)
            return dp[index][canbuy];
        // ignore case
        int exclude = solve(prices, index + 1, canbuy, dp);
        // buy or sell case
        int include;
        if (canbuy)
        {
            include = -prices[index] + solve(prices, index + 1, false, dp);
        }
        else
        {
            include = prices[index] + solve(prices, index + 1, true, dp);
        }
        dp[index][canbuy] = max(include, exclude);
        return dp[index][canbuy];
    }
    int solve2(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));
        for (int index = prices.size() - 1; index >= 0; index--)
        {
            for (int canbuy = 0; canbuy <= 1; canbuy++)
            {
                int exclude = dp[index + 1][canbuy];
                // buy or sell case
                int include;
                if (canbuy)
                    include = -prices[index] + dp[index + 1][false];
                else
                    include = prices[index] + dp[index + 1][true];
                dp[index][canbuy] = max(include, exclude);
            }
        }
        return dp[0][true];
    }
    int solve3(vector<int> &prices)
    {
        vector<int> curr(2, 0);
        vector<int> next(2, 0);
        for (int index = prices.size() - 1; index >= 0; index--)
        {
            for (int canbuy = 0; canbuy <= 1; canbuy++)
            {
                int exclude = next[canbuy];
                // buy or sell case
                int include;
                if (canbuy)
                    include = -prices[index] + next[false];
                else
                    include = prices[index] + next[true];
                curr[canbuy] = max(include, exclude);
            }
            next = curr;
        }
        return next[true];
    }
    int maxProfit(vector<int> &prices)
    {
        // vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        // return solve(prices,0,true,dp);
        return solve3(prices);
    }
};

class Solution2
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxprofit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > prices[i - 1])
                maxprofit += prices[i] - prices[i - 1];
        }
        return maxprofit;
    }
};