#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem link : https://leetcode.com/problems/reducing-dishes/

// Problem : A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time. Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].
// Return the maximum sum of like-time coefficient that the chef can obtain after preparing some amount of dishes. Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

// Approach : Observe that if dishes can be prepared in any order, we would want to prepare the worst rated dishes first, in order to promote best rated dishes to a larger value of time, to get more cofficient. To do this, we sort the given array first. Then we see, problem is reduced to inclusion/exclusion problem like knapsack one. 2 variables are index, time and can undergo 2d dp. The recursion is simple, 2 calls: include current dish, exclude current dish and return the max. Memoisation is easy. Tabluation works in reverse. Then for space optimisation we see that we don't need entire dp array but just 2 rows. done and dusted!

class Solution
{
public:
    // recursive
    int solve(vector<int> &satisfaction, int index, int time)
    {
        if (index >= satisfaction.size())
            return 0;
        int include = satisfaction[index] * time + solve(satisfaction, index + 1, time + 1);
        int exclude = solve(satisfaction, index + 1, time);
        return max(include, exclude);
    }
    // memoised
    int solve2(vector<int> &satisfaction, int index, int time, vector<vector<int>> &dp)
    {
        if (index >= satisfaction.size())
            return 0;
        if (dp[index][time] != -1)
            return dp[index][time];
        int include = satisfaction[index] * (time + 1) + solve2(satisfaction, index + 1, time + 1, dp);
        int exclude = solve2(satisfaction, index + 1, time, dp);
        dp[index][time] = max(include, exclude);
        return dp[index][time];
    }
    // tabulation
    int solve3(vector<int> &satisfaction)
    {
        int n = satisfaction.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int index = n - 1; index >= 0; index--)
        {
            for (int time = n - 1; time >= 0; time--)
            {
                int include = satisfaction[index] * (time + 1) + dp[index + 1][time + 1];
                ;
                int exclude = dp[index + 1][time];
                dp[index][time] = max(include, exclude);
            }
        }
        return dp[0][0];
    }
    // space optimisation
    int solve4(vector<int> &satisfaction)
    {
        int n = satisfaction.size();
        vector<int> curr(n + 1, 0);
        vector<int> next(n + 1, 0);
        for (int index = n - 1; index >= 0; index--)
        {
            for (int time = n - 1; time >= 0; time--)
            {
                int include = satisfaction[index] * (time + 1) + next[time + 1];
                ;
                int exclude = next[time];
                curr[time] = max(include, exclude);
            }
            next = curr;
        }
        return next[0];
    }
    int maxSatisfaction(vector<int> &satisfaction)
    {
        sort(satisfaction.begin(), satisfaction.end());

        // return solve(satisfaction,0,1);

        // int n = satisfaction.size();
        // vector<vector<int>> dp(n,vector<int>(n,-1));
        // return solve2(satisfaction,0,0,dp);

        return solve4(satisfaction);
    }
};