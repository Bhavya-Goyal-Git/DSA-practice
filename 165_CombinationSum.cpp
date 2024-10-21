#include <iostream>
#include <vector>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/number-of-ways_3755252?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

// Problem : You are given an array of distinct integers and you have to tell how many different ways of selecting the elements from the array are there such that the sum of chosen elements is equal to the given target number tar. Note: if way1 =[1,2,3,4] and way2= [4,3,2,1] then both ways are different. For Example:
// If N = 3 and tar = 5 and array elements are [1,2,5] then the possible ways of making sum = 5 are:
// (1,1,1,1,1), (1,1,1,2), (1,2,1,1), (2,1,1,1), (1,1,2,1), (2,2,1), (1,2,2), (2,1,2), (5)
// Hence the output will be 9.

// Approach : Normal recursion is possible. We try making 5 with 1, then we have a sub problem, make 4 with given numbers and so on.. target keeps on reducing but number remains same. This is similar to coin problem. So at each function call, we first check if target is 0 (it is made) then return 1 (number of ways) and if target is <0 then it could not reach so return 0. Else, make a ans variable (num of ways) and loop through all nums gives and make a call for each f(tar-num[i]) and add to ans variable. Return the ans.
// The approach takes exponential time, so we apply simple memoization.
// To further reduce the space comp, we make it to tabulation.
// No further optimisation can be done as f(i) depends on almost all entries lower than i.

int solve(vector<int> &num, int tar)
{
    if (tar == 0)
        return 1;
    if (tar < 0)
        return 0;

    int ans = 0;
    for (int x : num)
    {
        ans += solve(num, tar - x);
    }
    return ans;
}
int solve2(vector<int> &num, int tar, vector<int> &dp)
{
    if (tar == 0)
        return 1;
    if (tar < 0)
        return 0;
    if (dp[tar] != -1)
        return dp[tar];

    dp[tar] = 0;
    for (int x : num)
    {
        dp[tar] += solve2(num, tar - x, dp);
    }
    return dp[tar];
}

int solve3(vector<int> &num, int tar)
{
    vector<int> dp(tar + 1);
    dp[0] = 1;
    for (int i = 1; i <= tar; i++)
    {
        dp[i] = 0;
        for (int x : num)
        {
            if (i - x >= 0)
                dp[i] += dp[i - x];
        }
    }
    return dp[tar];
}

int findWays(vector<int> &num, int tar)
{
    // vector<int> dp(tar+1,-1);
    return solve3(num, tar);
}