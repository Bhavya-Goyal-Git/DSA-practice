#include <iostream>
#include <vector>
#include <algorithm>
#define INT_MIN INT32_MIN
using namespace std;

// Problem link : https://leetcode.com/problems/maximum-height-by-stacking-cuboids/submissions/1440472189/

// Problem : Given n cuboids where the dimensions of the ith cuboid is cuboids[i] = [widthi, lengthi, heighti] (0-indexed). Choose a subset of cuboids and place them on each other. You can place cuboid i on cuboid j if widthi <= widthj and lengthi <= lengthj and heighti <= heightj. You can rearrange any cuboid's dimensions by rotating it to put it on another cuboid. Return the maximum height of the stacked cuboids.

// Approach : Since we want maximum heights and rotation is possible, we sort each cuboid given, to get the longest dimension on the end, this will be height. Then we sort the entire cuboids array as per width (or the 0th index) or the base area (width * length) This sorting is done to get the array in an order on which DP can be then applied easily. If we observe carefully, all we now need is a longest increasing subsequence of this array. See that we don't need length of lis, but lis itself. So, we can't use the binary search approach and best we can do is space optimised tabulation approach. All we have to change is, the way prev and currIndex are compared, (as now they have 3 dimensions), and the answer we have to store is value of 3rd index, that is height, to maximise. Rest approach remains same.

class Solution
{
    bool isless(vector<int> &prev, vector<int> &curr)
    {
        return prev[0] <= curr[0] && prev[1] <= curr[1] && prev[2] <= curr[2];
    }
    int solve(vector<vector<int>> &arr, int n)
    {
        vector<int> curr(n + 1, 0);
        vector<int> next(n + 1, 0);
        for (int index = n - 1; index >= 0; index--)
        {
            for (int prevIndex = index - 1; prevIndex >= -1; prevIndex--)
            {
                int include = INT_MIN;
                if (prevIndex == -1 || isless(arr[prevIndex], arr[index]))
                {
                    include = arr[index][2] + next[index + 1];
                }
                int exclude = next[prevIndex + 1];
                curr[prevIndex + 1] = max(include, exclude);
            }
            next = curr;
        }
        return next[0];
    }

public:
    int maxHeight(vector<vector<int>> &cuboids)
    {
        for (vector<int> &a : cuboids)
        {
            sort(a.begin(), a.end());
        }
        sort(cuboids.begin(), cuboids.end());
        // Now find LIS
        return solve(cuboids, cuboids.size());
    }
};