#include <iostream>
#include <vector>
using namespace std;

// Problem link: https://www.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1

// Problem : Given a binary matrix mat of size n * m, find out the maximum length of a side of a square sub-matrix with all 1s.

// Approach : First of all a very important result: if in a box we stand, and consider it top left corner of a square we want to form, now we can check, how length of a square can be made by the block to the right as top left corner of a square, block to down as top left corner, and block diagonally down right as top left corner of a square. Observe if these three block yeild the same result, a bigger square can be formed from the observing block, else: minimum of the three can be the best. We apply this result recursively to get the first solution to the problem
// We first check if i,j are out of bound then we return 0. Else, we make 3 calls, to the right block, down block and the diagonal block. Now, it can only be a square if it itself is a 1. If its a 0 we return 0, else we return 1 + min(right,down,diagonal). Because only that big of a square can be made. We keep updating maximum found after calculating this value. This can easily be turned into memoisation with 2d dp array.
// Now we go to tabluation method in which we start from n-1,m-1 index (as we go reverse in tabulation), and do the same logic, and return the ans. For space optimisation there are 2 availabilities. Observe that a row depends only on bottom row. So instead of entire dp array we maintain only 2 rows. So O(m). But we can improve further, if we allowed to manipulate input array. Then do calculation in that itself. It will make space complexity drop to O(1).

class Solution
{
public:
    // recursion
    int solve(vector<vector<int>> &mat, int i, int j, int &maxi)
    {
        if (i >= mat.size() || j >= mat[0].size())
            return 0;

        int right = solve(mat, i, j + 1, maxi);
        int diag = solve(mat, i + 1, j + 1, maxi);
        int down = solve(mat, i + 1, j, maxi);

        int ans = 0; // for the case if mat[i][j] is 0
        if (mat[i][j] == 1)
        {
            ans = 1 + min(right, min(diag, down));
            maxi = max(maxi, ans);
        }
        return ans;
    }
    // memoisation
    int solve2(vector<vector<int>> &mat, int i, int j, int &maxi, vector<vector<int>> &dp)
    {
        if (i >= mat.size() || j >= mat[0].size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        int right = solve2(mat, i, j + 1, maxi, dp);
        int diag = solve2(mat, i + 1, j + 1, maxi, dp);
        int down = solve2(mat, i + 1, j, maxi, dp);

        dp[i][j] = 0; // for the case if mat[i][j] is 0
        if (mat[i][j] == 1)
        {
            dp[i][j] = 1 + min(right, min(diag, down));
            maxi = max(maxi, dp[i][j]);
        }
        return dp[i][j];
    }
    // tabulation
    int solve3(vector<vector<int>> &mat, int n, int m)
    {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int maxi = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                int right = dp[i][j + 1];
                int diag = dp[i + 1][j + 1];
                int down = dp[i + 1][j];
                dp[i][j] = 0; // for the case if mat[i][j] is 0
                if (mat[i][j] == 1)
                {
                    dp[i][j] = 1 + min(right, min(diag, down));
                    maxi = max(maxi, dp[i][j]);
                }
            }
        }
        return maxi;
    }
    // reducing space complexity
    int solve4(vector<vector<int>> &mat, int n, int m)
    {
        int maxi = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                int right = j + 1 < m ? mat[i][j + 1] : 0;
                int diag = (i + 1 < n && j + 1 < m) ? mat[i + 1][j + 1] : 0;
                int down = i + 1 < n ? mat[i + 1][j] : 0;
                if (mat[i][j] == 1)
                {
                    mat[i][j] = 1 + min(right, min(diag, down));
                    maxi = max(maxi, mat[i][j]);
                }
            }
        }
        return maxi;
    }

    int maxSquare(int n, int m, vector<vector<int>> mat)
    {
        // int maxi = 0;
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // solve2(mat,0,0,maxi,dp);
        // return maxi;
        return solve4(mat, n, m);
    }
};