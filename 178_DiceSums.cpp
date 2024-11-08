#include <iostream>
#include <vector>
using namespace std;

// Problem link : https://www.geeksforgeeks.org/problems/dice-throw5349/1

// Problem : Given n dice each with m faces. Find the distinct number of ways to get sum x by throwing all the dice together.

// Approach : We write recursive approach first, base cases are important here. We are going from Nth dice to last and target given to 0. So, if target goes below zero it is bad. If target is 0 and we have dice remaining then bad. If dice are all used (=0) and target is not yet 0, then bad. All these return 0. ONly 1 case returns 1, that is when both target and dice are 0 at same time. Then, normal case is easy. We make a answer variable and run a loop across all face values. In recursive calls, dice number reduces by 1 and target reduces by (target - face-value-used) and return ans. The approach is easy to made into memoisation. THen we apply tabulation, now dice goes 1 to N and target 1 to given Target. (we did not take 0 of both as base case suggests that its all zero, except one case only, dp[0][0]=1 i.e. when both target and dice are 0). Then we run simple tabulation. Remember to do boundary check (indices must be >=0). At end we return dp[dice][target]. After all this we realise the f(dice) depends on f(dice-1) so we get rid of entire dp array and replace it with 2 arrays size of target. Remember to do prev[0]=1. Then run similarly and at end return prev[target]. This makes time complexity O(dice*target*faces) and space complexity O(target)

class Solution
{
public:
    long long solve(int dice, int faces, int target)
    {
        if (target < 0)
            return 0;
        if (target != 0 && dice == 0)
            return 0;
        if (target == 0 && dice != 0)
            return 0;
        if (target == 0 && dice == 0)
            return 1;

        long long ans = 0;
        for (int f = 1; f <= faces; f++)
        {
            ans += solve(dice - 1, faces, target - f);
        }
        return ans;
    }
    long long solve2(int dice, int faces, int target, vector<vector<long long>> &dp)
    {
        if (target < 0)
            return 0;
        if (target != 0 && dice == 0)
            return 0;
        if (target == 0 && dice != 0)
            return 0;
        if (target == 0 && dice == 0)
            return 1;
        if (dp[dice][target] != -1)
            return dp[dice][target];

        long long ans = 0;
        for (int f = 1; f <= faces; f++)
        {
            ans += solve2(dice - 1, faces, target - f, dp);
        }
        return dp[dice][target] = ans;
    }
    long long solve3(int dice, int faces, int target)
    {
        vector<vector<long long>> dp(dice + 1, vector<long long>(target + 1, 0));
        dp[0][0] = 1;
        for (int dicenum = 1; dicenum <= dice; dicenum++)
        {
            for (int tar = 1; tar <= target; tar++)
            {
                long long ans = 0;
                for (int f = 1; f <= faces; f++)
                {
                    if (tar - f >= 0)
                        ans += dp[dicenum - 1][tar - f];
                }
                dp[dicenum][tar] = ans;
            }
        }
        return dp[dice][target];
    }
    long long solve4(int dice, int faces, int target)
    {
        vector<long long> prev(target + 1, 0);
        vector<long long> curr(target + 1, 0);
        prev[0] = 1;
        for (int dicenum = 1; dicenum <= dice; dicenum++)
        {
            for (int tar = 1; tar <= target; tar++)
            {
                long long ans = 0;
                for (int f = 1; f <= faces; f++)
                {
                    if (tar - f >= 0)
                        ans += prev[tar - f];
                }
                curr[tar] = ans;
            }
            prev = curr;
        }
        return prev[target];
    }
    long long noOfWays(int m, int n, int x)
    {
        // vector<vector<long long>> dp(n+1,vector<long long>(x+1,-1));
        return solve4(n, m, x);
    }
};