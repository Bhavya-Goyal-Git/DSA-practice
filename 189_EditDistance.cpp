#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Problem link : https://leetcode.com/problems/edit-distance/

// Problem : Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2. You have the following three operations permitted on a word: Insert a character, Delete a character, Replace a character

// Approach : We run 2 indices across the strings. Base case is when either of indices run out, then minimum editing required is equal to no. of char left in the other string. Normal case, we have s1[i]==s2[j] then no editing req, we make call to f(i+1,j+1) else we add 1 to the minimum of 3 cases, insert f(i,j+1) or delete f(i+1,j) or replace f(i+1,j+1).. This can be memoised and tabulated easily. During space optimisation, remember to set last row and columns appropriately, Also we have to seprately handle the case when one of strings is empty, then the ans is simply the length of the other.

class Solution
{
public:
    int solve(string &s1, string &s2, int index1, int index2, vector<vector<int>> &dp)
    {
        if (index1 >= s1.size())
            return s2.size() - index2;
        if (index2 >= s2.size())
            return s1.size() - index1;
        if (dp[index1][index2] != -1)
            return dp[index1][index2];
        if (s1[index1] == s2[index2])
            dp[index1][index2] = solve(s1, s2, index1 + 1, index2 + 1, dp);
        else
            dp[index1][index2] = 1 + min(solve(s1, s2, index1 + 1, index2 + 1, dp), min(solve(s1, s2, index1 + 1, index2, dp), solve(s1, s2, index1, index2 + 1, dp)));
        return dp[index1][index2];
    }
    int solve2(string &s1, string &s2)
    {
        int n1 = s1.size();
        int n2 = s2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = 0; i <= n2; i++)
        {
            dp[n1][i] = n2 - i;
        }
        for (int i = 0; i <= n1; i++)
        {
            dp[i][n2] = n1 - i;
        }
        for (int index1 = n1 - 1; index1 >= 0; index1--)
        {
            for (int index2 = n2 - 1; index2 >= 0; index2--)
            {
                if (s1[index1] == s2[index2])
                    dp[index1][index2] = dp[index1 + 1][index2 + 1];
                else
                    dp[index1][index2] = 1 + min(dp[index1 + 1][index2 + 1], min(dp[index1 + 1][index2], dp[index1][index2 + 1]));
            }
        }
        return dp[0][0];
    }
    int solve3(string &s1, string &s2)
    {
        int n1 = s1.size();
        int n2 = s2.size();
        vector<int> curr(n2 + 1, 0);
        vector<int> next(n2 + 1, 0);
        for (int i = 0; i <= n2; i++)
        {
            next[i] = n2 - i;
        }
        for (int index1 = n1 - 1; index1 >= 0; index1--)
        {
            curr[n2] = n1 - index1;
            for (int index2 = n2 - 1; index2 >= 0; index2--)
            {
                if (s1[index1] == s2[index2])
                    curr[index2] = next[index2 + 1];
                else
                    curr[index2] = 1 + min(next[index2 + 1], min(next[index2], curr[index2 + 1]));
            }
            next = curr;
        }
        return next[0];
    }
    int minDistance(string word1, string word2)
    {
        // vector<vector<int>> dp(word1.size(),vector<int>(word2.size(),-1));
        // return solve(word1,word2,0,0,dp);
        if (word1.size() == 0 || word2.size() == 0)
            return max(word1.size(), word2.size());
        if (word1.size() > word2.size())
            return solve3(word1, word2);
        return solve3(word2, word1);
    }
};