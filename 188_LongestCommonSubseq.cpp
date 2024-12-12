#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Problem link: https://leetcode.com/problems/longest-common-subsequence/description/

// Problem : Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

// Approach : we run 2 indices, one across each string, if s1[i]==s2[j] then we have found 1 common we return 1 + f(i+1,j+1) else we have to now leave a letter, we could leave upper string f(i+1,j) or lower f(i,j+1), take max of both and return. Easy to memoise and tabulate and space optimise!

class Solution
{
public:
    int solve(string s1, string s2, int index1, int index2, vector<vector<int>> &dp)
    {
        if (index1 >= s1.size() || index2 >= s2.size())
            return 0;
        if (dp[index1][index2] != -1)
            return dp[index1][index2];
        if (s1[index1] == s2[index2])
            dp[index1][index2] = 1 + solve(s1, s2, index1 + 1, index2 + 1, dp);
        else
            dp[index1][index2] = max(solve(s1, s2, index1 + 1, index2, dp), solve(s1, s2, index1, index2 + 1, dp));
        return dp[index1][index2];
    }
    int solve2(string s1, string s2)
    {
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
        for (int index1 = s1.size() - 1; index1 >= 0; index1--)
        {
            for (int index2 = s2.size() - 1; index2 >= 0; index2--)
            {
                if (s1[index1] == s2[index2])
                    dp[index1][index2] = 1 + dp[index1 + 1][index2 + 1];
                else
                    dp[index1][index2] = max(dp[index1 + 1][index2], dp[index1][index2 + 1]);
            }
        }
        return dp[0][0];
    }
    int solve3(string s1, string s2)
    {
        vector<int> curr(s2.size() + 1, 0);
        vector<int> next(s2.size() + 1, 0);
        for (int index1 = s1.size() - 1; index1 >= 0; index1--)
        {
            for (int index2 = s2.size() - 1; index2 >= 0; index2--)
            {
                if (s1[index1] == s2[index2])
                    curr[index2] = 1 + next[index2 + 1];
                else
                    curr[index2] = max(next[index2], curr[index2 + 1]);
            }
            next = curr;
        }
        return next[0];
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        // vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
        // return solve(text1,text2,0,0,dp);
        // return solve2(text1,text2);
        if (text1.size() > text2.size())
            return solve3(text1, text2);
        return solve3(text2, text1);
    }
};