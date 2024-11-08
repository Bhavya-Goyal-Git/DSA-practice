#include <iostream>
#include <vector>
using namespace std;

// Problem link : https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/

// Problem : You have a convex n-sided polygon where each vertex has an integer value. You are given an integer array values where values[i] is the value of the ith vertex in clockwise order.
//  Polygon triangulation is a process where you divide a polygon into a set of triangles and the vertices of each triangle must also be vertices of the original polygon. Note that no other shapes other than triangles are allowed in the division. This process will result in n - 2 triangles.
//  You will triangulate the polygon. For each triangle, the weight of that triangle is the product of the values at its vertices. The total score of the triangulation is the sum of these weights over all n - 2 triangles. Return the minimum possible score that you can achieve with some triangulation of the polygon.

// Approach : For recursion we see that: if we take i=0 and j=n-1 (last) indices of the array, they will represent a edge in the polygon. With this edge as the base, we can choose now any of the i+1 to j-1 points to make a triangle. This triangle shall divide the shape into 2 shapes. One with points i to k and other with points k to j which can be solved recursively. We try different values of k and store the minimum one possible. So recursive way: Base case is when only 2 vertices we have (that is i+1==j) then no triangle can be formed, ans is 0. Else: we run a loop k, from i+1 to j-1, for each pair v[i]*v[j]*v[k] + f(i,k) + f(k,j) we take the minimum possible ans.
// Memoisation is easy, remember it is a 2d array we need as 2 things i,j are changing in function calls. Now we need tabulation. See that recursion runs with i=0 and j=n-1. And in tabulation we go reverse, so we run loop i from n-1 to 0 and j from i+2 to n-1. (if j<i or j=i or j=i+1 then answer will be 0, because no triangles can be formed in such cases). At the end return dp[0][n-1]. The time comp is O(n3) and space O(n2)

class Solution
{
public:
    // memoized
    int solve(vector<int> &v, int i, int j, vector<vector<int>> &dp)
    {
        if (i + 1 == j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        dp[i][j] = INT32_MAX;
        for (int k = i + 1; k <= j - 1; k++)
        {
            dp[i][j] = min(dp[i][j], v[i] * v[j] * v[k] + solve(v, i, k, dp) + solve(v, k, j, dp));
        }
        return dp[i][j];
    }
    // tabulation
    int solve2(vector<int> &v)
    {
        int n = v.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 2; j < n; j++)
            { // runs from i+2 as when i+1==j ans is 0
                dp[i][j] = INT32_MAX;
                for (int k = i + 1; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], v[i] * v[j] * v[k] + dp[i][k] + dp[k][j]);
                }
            }
        }
        return dp[0][n - 1];
    }
    int minScoreTriangulation(vector<int> &values)
    {
        // int n = values.size();
        // vector<vector<int>> dp(n,vector<int>(n,-1));
        // return solve(values,0,n-1,dp);
        return solve2(values);
    }
};