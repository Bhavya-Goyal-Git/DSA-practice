#include <iostream>
#include <vector>
using namespace std;

// Problem link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

// Problem :You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k. Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times. Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

// Approach : We have the same conditions as previous version, just one more, that is number of transactions, so we make it a 3d DP. can be easily memoised and tabulated.

class Solution
{
public:
    int solve3(vector<int> &prices, int k)
    {
        vector<vector<int>> next(2, vector<int>(k + 1, 0));
        vector<vector<int>> curr(2, vector<int>(k + 1, 0));
        for (int index = prices.size() - 1; index >= 0; index--)
        {
            for (int canbuy = 1; canbuy >= 0; canbuy--)
            {
                for (int limit = 1; limit <= k; limit++)
                {
                    int exclude = next[canbuy][limit];
                    int include;
                    if (canbuy)
                        include = -prices[index] + next[false][limit];
                    else
                        include = prices[index] + next[true][limit - 1];
                    ;
                    curr[canbuy][limit] = max(include, exclude);
                }
            }
            next = curr;
        }
        return next[true][k];
    }
    int maxProfit(int k, vector<int> &prices)
    {
        // vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));
        // return solve(prices,0,true,k,dp);
        return solve3(prices, k);
    }
};