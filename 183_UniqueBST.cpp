#include <iostream>
#include <vector>
using namespace std;

// Problem link : https://leetcode.com/problems/unique-binary-search-trees/description/

// Problem : Given n, number of nodes in a bst (numbered 1 to n), how many unique bst can be formed?

// Approach : If we take for example 3 nodes, then we have to consider each (1,2,3) as root nodes, then left and right of them remaining values solved recursively. Note that if left-subtree can be formed in p ways and right in q ways, then tree is formed using p*q ways. (choosing 1 type from both pC1 and qC1). Remember that n=0 ans is 1. Then we make an ans, and run a loop across nodes. get left and right answers and multiply them f(i-1) * f(n-i) and add to answer. return answer at end. This can be easily memoised and tabulated. Space is O(n) and time is O(n2).
// Special note: the series that is observed is famous series called Catalan number series. Its direct formula is available (2n)! / ((n+1)! * n!)

class Solution
{
public:
    int solve(int n, vector<int> &dp)
    {
        if (n == 0)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += solve(i - 1, dp) * solve(n - i, dp);
        }
        return dp[n] = ans;
    }
    int solve2(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int num = 1; num <= n; num++)
        {
            int ans = 0;
            for (int i = 1; i <= num; i++)
            {
                ans += dp[i - 1] * dp[num - i];
            }
            dp[num] = ans;
        }
        return dp[n];
    }
    int numTrees(int n)
    {
        // vector<int> dp(n+1,-1);
        return solve2(n);
    }
};