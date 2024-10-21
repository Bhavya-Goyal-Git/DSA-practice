#include <iostream>
#include <vector>
#define INT_MAX INT32_MAX
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/minimum-coins_2180776?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

// Problem : Ninja is willing to take some time off from his training and planning a year-long tour. You are given a DAYS array consisting of ‘N’ days when Ninjas will be traveling during the year. Each Day is an integer between 1 to 365 (both inclusive). Train tickets are sold in three different ways:
//  A 1-day pass is sold for 'COST'[0] coins,
//  A 7-day pass is sold for 'COST'[1] coins, and
//  A 30-day  pass is sold for 'COST'[2] coins.
//  The passes allow for many days of consecutive travel. Your task is to help the Ninja to find the minimum number of coins required to complete his tour. For example,If Ninja gets a 7-day pass on day 2, then he can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.

// Approach : We try to solve recursively first. let a index=0 running across days vector. at each day we decide which pass to buy and then update index respectively and make next call as per that. when index goes out of bounds of days we return 0. So base case is index>=n return 0. Else we have 3 choices. If we choose 1 day pass then cost is cost[0] + f(index+1). If we choose 7 day pass, then we first have to calculate the index upto which we can go now, lets say i=index then i can go as far as i<n and day[i]<day[index]+7. So increment i and get that value. then cost of this way will be cost[1] + f(i). Similarly, cost of 30 day pass will be cost[2] + f(i) {i calculated as per 30}. Then at end of 3 options, we return the minimum of 3.
// We do basic memoisation to improve time complexity.
// Then we do tabulation. Here it is different. Normal index is running from 0 to n. But in tabulation we run things in reverse. So base set is dp[n]=0 and then we run from n-1 to 0 index and dp[0] shall be our answer. In this function there is no need of index variable as that is the thing we are running variable of loop across. It reduces the space complexity further by avoiding recursion.

// recursive
int solve(int n, vector<int> &days, vector<int> &cost, int index)
{
    if (index >= n)
        return 0;

    // choosing 1 day pass
    int option1 = cost[0] + solve(n, days, cost, index + 1);

    // choosing 7 day pass
    int i = index;
    while (i < n && days[i] < days[index] + 7)
        i++;
    int option2 = cost[1] + solve(n, days, cost, i);

    // choosing 30 day pass
    i = index;
    while (i < n && days[i] < days[index] + 30)
        i++;
    int option3 = cost[2] + solve(n, days, cost, i);

    return min(option1, min(option2, option3)); // returning minimum coins
}

// memoized
int solve2(int n, vector<int> &days, vector<int> &cost, int index, vector<int> &dp)
{
    if (index >= n)
        return 0;
    if (dp[index] != -1)
        return dp[index];

    // choosing 1 day pass
    int option1 = cost[0] + solve2(n, days, cost, index + 1, dp);

    // choosing 7 day pass
    int i = index;
    while (i < n && days[i] < days[index] + 7)
        i++;
    int option2 = cost[1] + solve2(n, days, cost, i, dp);

    // choosing 30 day pass
    i = index;
    while (i < n && days[i] < days[index] + 30)
        i++;
    int option3 = cost[2] + solve2(n, days, cost, i, dp);

    dp[index] = min(option1, min(option2, option3));
    return dp[index]; // returning minimum coins
}
// tabulation
int solve3(int n, vector<int> &days, vector<int> &cost)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;
    for (int k = n - 1; k >= 0; k--)
    {
        int option1 = cost[0] + dp[k + 1];
        int i = k;
        while (i < n && days[i] < days[k] + 7)
            i++;
        int option2 = cost[1] + dp[i];
        i = k;
        while (i < n && days[i] < days[k] + 30)
            i++;
        int option3 = cost[2] + dp[i];
        dp[k] = min(option1, min(option2, option3));
    }
    return dp[0];
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // vector<int> dp(n+1,-1);
    // return solve2(n, days, cost,0,dp);
    return solve3(n, days, cost);
}