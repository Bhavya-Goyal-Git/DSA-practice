#include <iostream>
#include <vector>
using namespace std;

// Problem link : https://leetcode.com/problems/minimum-sideway-jumps/

// Problem : There is a 3 lane road of length n that consists of n + 1 points labeled from 0 to n. A frog starts at point 0 in the second lane and wants to jump to point n. However, there could be obstacles along the way.
//  You are given an array obstacles of length n + 1 where each obstacles[i] (ranging from 0 to 3) describes an obstacle on the lane obstacles[i] at point i. If obstacles[i] == 0, there are no obstacles at point i. There will be at most one obstacle in the 3 lanes at each point.
//  For example, if obstacles[2] == 1, then there is an obstacle on lane 1 at point 2.
//  The frog can only travel from point i to point i + 1 on the same lane if there is not an obstacle on the lane at point i + 1. To avoid obstacles, the frog can also perform a side jump to jump to another lane (even if they are not adjacent) at the same point if there is no obstacle on the new lane. For example, the frog can jump from lane 3 to lane 1.
//  Return the minimum number of side jumps the frog needs to reach any lane at point n starting from lane 2 at point 0. Note: There will be no obstacles on points 0 and n.

// Approach : First of all we discuss plain recursion. It is given that we start at lane 2, position 0 and have to reach position n-1, any lane. The function takes currentlane, currentposition as arguements. Base case is when currentpos = n-1, we return 0. else we have 2 choices: if in the current lane, there is no obstacle forward, then we travel 1 position forward in current lane. i.e. if obstacle[currentpos+1] != currentlane, recursive call f(currentlane,currentpos+1). But, if there is a obstacle ahead in the currentlane, then we have to jump sideways. For that, we use a for loop, with lane=1 to 3. We check lane must not be equal to currnetlane and obstacle[currentpos] must not be equal to lane (Jaha jump kar rahe hai vo obstacle nahi hona chahiye, aur jaha khade hai vahi par jump nhi karna hai vapas) Then many answers are possible, we initialize a ans=int_max. Take minimum of recursive calls to 1 + f(laneOfLoop,currentpos). Remember to add 1 here, this 1 is for the side jump we had to make. return ans after the loop.
// Memoisation over recusion is easy, we observe that lane,position are changing so, 2d dp array. Lanes are 3 only, but to simplify indexing, we make a array of size 4*(no of positions). Then add dp appay to each call.
// Tabulation is a bit tricky. observe that in recursion we are trying to get from position (2,0) to (anylane,n-1) and in bottom up, we go reverse. Analyzing the base case we see, dp[all lanes][last pos] = 0. Then since n-1 position is filled, we run a loop for currentpos from n-2 to 0. And currentlane from 1 to 3. Inside the loop logic is similar. However, in the else case, when infront is a obstacle, we try getting value from another lanes of same position, it may be possible that we are in 1st lane, some position and infront is a obstacle to we try to find a value below, but below values are yet not filled! So instead of depending on dp[lane][currentpos], we change it to dp[lane][currentpos+1] and it works! After this processing, we have some values at dp[all lanes][0]. We need to reach in minimum steps from 2,0. So ans could be dp[2][0] or 1 + dp[1][0] or 1+dp[3][0] (2nd lane se direct ya fir second se first pe jaake ya third pe jaake, 1 extra is for that jump). Minimum of 3 is the ans to return.
// Space optimisation: observe that f(currentlane,currentpos) is only dependent on f(anylane,currentpos+1), so we can reduce it to just 2 arrays of size 4 (representing lanes). Do the same thing as in tabulation. Wherever is dp[something][currpos] replace with curr[something] and replace dp[something][currpos+1] with next[something]. At the end return min of next[2] or 1+next[1] or 1+next[3]. This makes O(n) time and O(1) space.

#define INT_MAX INT32_MAX

class Solution
{
public:
    // recursive
    int solve(vector<int> &obstacles, int currlane, int currpos)
    {
        if (currpos == obstacles.size() - 1)
            return 0;
        if (obstacles[currpos + 1] != currlane)
        { // aage same lane par obstacle nahi hai to chalo
            return solve(obstacles, currlane, currpos + 1);
        }
        else
        { // varna jump dekho kaha lage, minimum mile
            int ans = INT_MAX;
            for (int lane = 1; lane <= 3; lane++)
            {
                if (lane != currlane && obstacles[currpos] != lane)
                    ans = min(ans, 1 + solve(obstacles, lane, currpos)); // remember to add 1
            }
            return ans;
        }
    }
    // memoized
    int solve2(vector<int> &obstacles, int currlane, int currpos, vector<vector<int>> &dp)
    {
        if (currpos == obstacles.size() - 1)
            return 0;
        if (dp[currlane][currpos] != -1)
            return dp[currlane][currpos];
        int ans = INT_MAX;
        if (obstacles[currpos + 1] != currlane)
        {
            ans = solve2(obstacles, currlane, currpos + 1, dp);
        }
        else
        {
            for (int lane = 1; lane <= 3; lane++)
            {
                if (lane != currlane && obstacles[currpos] != lane)
                    ans = min(ans, 1 + solve2(obstacles, lane, currpos, dp));
            }
        }
        dp[currlane][currpos] = ans;
        return dp[currlane][currpos];
    }
    // tabulated
    int solve3(vector<int> &obstacles)
    {
        int n = obstacles.size();
        vector<vector<int>> dp(4, vector<int>(n, 700000)); // could be int_max
        dp[0][n - 1] = 0;
        dp[1][n - 1] = 0; // zero values for the last position
        dp[2][n - 1] = 0;
        dp[3][n - 1] = 0;
        for (int currpos = n - 2; currpos >= 0; currpos--)
        {
            for (int currlane = 1; currlane <= 3; currlane++)
            {
                // agar aage nahi tha obstacle toh:
                if (obstacles[currpos + 1] != currlane)
                {
                    dp[currlane][currpos] = dp[currlane][currpos + 1];
                }
                // agar tha toh:
                else
                {
                    for (int lane = 1; lane <= 3; lane++)
                    {
                        if (lane != currlane && obstacles[currpos] != lane)
                            dp[currlane][currpos] = min(dp[currlane][currpos], 1 + dp[lane][currpos + 1]);
                    }
                }
            }
        }
        return min(dp[2][0], min(1 + dp[1][0], 1 + dp[3][0]));
    }
    // space optimised
    int solve4(vector<int> &obstacles)
    {
        int n = obstacles.size();
        vector<int> next(4, 700000);
        vector<int> curr(4, 700000);
        next[0] = 0;
        next[1] = 0; // zero values for the last position
        next[2] = 0;
        next[3] = 0;
        for (int currpos = n - 2; currpos >= 0; currpos--)
        {
            for (int currlane = 1; currlane <= 3; currlane++)
            {
                int ans = INT_MAX;
                // agar aage nahi tha obstacle toh:
                if (obstacles[currpos + 1] != currlane)
                {
                    ans = next[currlane];
                }
                // agar tha toh:
                else
                {
                    for (int lane = 1; lane <= 3; lane++)
                    {
                        if (lane != currlane && obstacles[currpos] != lane)
                            ans = min(ans, 1 + next[lane]);
                    }
                }
                curr[currlane] = ans;
            }
            next = curr;
        }
        return min(next[2], min(1 + next[1], 1 + next[3]));
    }
    int minSideJumps(vector<int> &obstacles)
    {
        // return solve(obstacles,2,0);
        // vector<vector<int>> dp(4,vector<int>(obstacles.size(),-1));
        // return solve2(obstacles,2,0,dp);
        // return solve3(obstacles);
        return solve4(obstacles);
    }
};