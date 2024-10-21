#include <iostream>
#include <vector>
#define INT_MAX INT32_MAX
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/minimum-elements_3843091?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

// Problem : Given a array containing denominations, and a target value, find the minimum number of coins required to make the target. (Infinite no of each denominations are available). If target cant be achieved return -1

// Approach : First of all, if you think about arranging numbers in descending order and then using remainder approach, that won't work, because it may be possible that even though a number can be subtracted from the money, but it is not in ans. (After subtracting it, we dont have smaller coins to make required value, making answer wrong).. Therefore we look at the long recursive approach:
// Suppose we are making 7, then we run a loop across available denominations, suppose they are 1,2,4 then ways in which 7 can be made are make(6) in minimum +1 or make(5) in minimum + 1 or make(3) in minimum +1... i.e. we try making smaller denominations looping through all available. Base case is when money is 0, we return 0.. however, in cases where answer is not possible, money value will drop to below zero, and in such cases we return INT_MAX. We declare a minimum variable (initially intmax) then run a for loop across dominations and calculate ans for lower values currentMoney-dominations[i], if ans is valid (!=intMax) then update the minimum as ans+1 (1 to include that coin).. return mini at end. In main fn check if returned value is not IntMax in which return -1 else ans.
// Above solution has exponential time comp, we try Dynamic progg. First memoisation. We make a array dp in main fn and initialize with -1. In recursive fn, store value of mini into dp[money] prior to returning, and after base cases firstly check if dp[money] !=-1, then return dp[money]. This reduces time complexity to O(nx) {n is number of denominations, x is money req} but space comp is O(2x) due to recursion and dp array.
// Now we try bottom up approach (tabulisation). Make dp array in the function now, and initialize with INT_MAX. As we know from base cases, make dp[0]=0. Now we are to fill up values from 1 to money in the dp array.. so run a loop from i=1 to i=money. As we see from recursion, we have to run a loop across each denomination for each money to get an ans. So run a inner loop j, for all denominations.. Now, how is dp[i] dependent on previous dp entries? it is minimum of previous entries as per denominations available +1 for example: dp[7] and denominations = {2,5} then dp[7] will be minimum of dp[2] + 1 and dp[5] + 1. (provided back entries are not intmax themselves and a coin bigger than 7 does not exists otherwise index will become negative). So inside the j loop, we have dp[i] = minimum of (dp[i], 1 + dp[ i - denominations[j] ]). (Prior to it, please check that i-deno[j] must be >=0 and dp[1-deno[j]] must not be INT_MAX). This fills up the dp array, and we have dp[money] as the answer at end. (-1 if its intMax). Time comp is O(nx) and space is O(x). Further space reduction is not possible as dp[i] is dependent on many previous values (non constant for all).

// recursion normal
int solve(vector<int> &num, int money)
{
    if (money == 0)
        return 0;

    if (money < 0)
        return INT_MAX;

    int mini = INT_MAX;
    for (int i = 0; i < num.size(); i++)
    {
        int ans = solve(num, money - num[i]);
        if (ans != INT_MAX)
            mini = min(mini, ans + 1);
    }
    return mini;
}

// recursion with memoisation
int solve2(vector<int> &num, int money, vector<int> &dp)
{
    if (money == 0)
        return 0;

    if (money < 0)
        return INT_MAX;

    if (dp[money] != -1)
        return dp[money];

    int mini = INT_MAX;
    for (int i = 0; i < num.size(); i++)
    {
        int ans = solve2(num, money - num[i], dp);
        if (ans != INT_MAX)
            mini = min(mini, ans + 1);
    }
    dp[money] = mini;
    return mini;
}

// Tabulation bottom up approach
int solve3(vector<int> &num, int money)
{
    vector<int> dp(money + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i < money + 1; i++)
    {
        for (int j = 0; j < num.size(); j++)
        {
            if (i - num[j] >= 0 && dp[i - num[j]] != INT_MAX)
                dp[i] = min(dp[i], 1 + dp[i - num[j]]);
        }
    }
    if (dp[money] == INT_MAX)
        return -1;
    return dp[money];
}

int minimumElements(vector<int> &num, int x)
{
    // int ans = solve(num,x);
    // if(ans==INT_MAX) return -1;
    // return ans;

    // vector<int> dp(x+1,-1);
    // int ans = solve2(num, x, dp);
    // if(ans==INT_MAX) return -1;
    // return ans;
    return solve3(num, x);
}