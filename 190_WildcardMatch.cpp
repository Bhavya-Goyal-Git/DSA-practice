#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Problem link : https://leetcode.com/problems/wildcard-matching/

// Problem : Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where: '?' Matches any single character. '*' Matches any sequence of characters (including the empty sequence). The matching should cover the entire input string (not partial).

// Approach : We traverse the string and pattern from back side.. base case is when both string and pattern are exhausted together (i<0 and j<0) then return true.. else if only pattern is exhausted but string is still there, return false (i>=0, j<0).. else if string is exhausted and pattern isn't then there is a special case here, if remaining pattern is just stars *,** etc.. then it is true, so we run a loop across remaining pattern (0 to jth index) and if pattern[k]!='*' we return false, else entire loop is traversed which means it is *** only then we return true... Now regular cases: if character matches or pattern is '?' we match them and move to next indices i.e. f(i-1,j-1) else if pattern is a *, then there can be 2 cases: either we replace the * with empty string, in that case, f(i,j-1) or we replace it with the above character, in that case f(i-1,j). WE or || the result in this case and return.. else we return false...
// This can be memoised easily, then for tabulation, we observe that we need to store with i,j go below 0 i.e. -1. So we convert the problem to 1-indexed and then treat dp of 0th row and 0th colum as edge cases. Carefully fill the first row. Then in loop remember to compare s[i-1] and p[j-1] as i and j are 1 indexed now.. Similarly, we have space optimisation, we only need 2 arrays size of pattern, in this, the first array will behave as first row and will be filled like we did earlier, rest is same. Time comp is O(nm) and space is O(2m) (n is size of string and m is size of pattern)

class Solution
{
public:
    bool solve(string &s, string &p, int i, int j, vector<vector<int>> &dp)
    {
        if (i < 0 && j < 0)
            return true;
        if (i >= 0 && j < 0)
            return false;
        if (i < 0 && j >= 0)
        {
            for (int k = 0; k <= j; k++)
            {
                if (p[k] != '*')
                    return false;
            }
            return true;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == p[j] || p[j] == '?')
            dp[i][j] = solve(s, p, i - 1, j - 1, dp);
        else if (p[j] == '*')
            dp[i][j] = (solve(s, p, i, j - 1, dp) || solve(s, p, i - 1, j, dp));
        else
            dp[i][j] = false;
        return dp[i][j];
    }
    bool solve2(string &s, string &p)
    {
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, 0));
        dp[0][0] = true;
        for (int k = 1; k <= p.size(); k++)
        {
            if (p[k - 1] == '*')
                dp[0][k] = true;
            else
                break;
        }
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= p.size(); j++)
            {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*')
                    dp[i][j] = (dp[i][j - 1] || dp[i - 1][j]);
                else
                    dp[i][j] = false;
            }
        }
        return dp[s.size()][p.size()];
    }
    bool solve3(string &s, string &p)
    {
        vector<int> prev(p.size() + 1, 0);
        vector<int> curr(p.size() + 1, 0);
        prev[0] = true;
        for (int k = 1; k <= p.size(); k++)
        {
            if (p[k - 1] == '*')
                prev[k] = true;
            else
                break;
        }
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= p.size(); j++)
            {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    curr[j] = prev[j - 1];
                else if (p[j - 1] == '*')
                    curr[j] = (curr[j - 1] || prev[j]);
                else
                    curr[j] = false;
            }
            prev = curr;
        }
        return prev[p.size()];
    }
    bool isMatch(string s, string p)
    {
        // vector<vector<int>> dp(s.size(),vector<int>(p.size(),-1));
        // return solve(s,p,s.size()-1,p.size()-1,dp);
        return solve3(s, p);
    }
};