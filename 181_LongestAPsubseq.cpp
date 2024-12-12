#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Problem link : https://www.geeksforgeeks.org/problems/longest-arithmetic-progression1019/1

// Problem : Given an array arr[] of sorted and distinct positive integers. The task is to find the length of the longest arithmetic progression in a given array.

// Approach : This DP problem is directly solved with tabulation approach, as it is easier to understand. IF the array has 2 or less elements, then length of AP is that number itself so we return this base case. Now we make a dp array. Here, it is a array of unordered maps. dp[i][j] represents that at ith index, what is length of AP with common difference 'j'. We could have made a 2d vector, as we know the largest common diff possible (last element - first element, as array is of sorted positive numbers). So we run a loop from index 1 (as index 0 will not have anything to compare in behind) and run a loop j from index 0 to i. At each step we calucate the common difference between the numbers. Then set a count to 1. If dp[j][diff] exists, it means until j, there exists the same AP before, so we set count to it. Then we store dp[i][diff] as count + 1. (observe that this value will be at minimum 2 and at most the size of given array). After this updation we compare it with a global maximum declared and update it if necessary. At the end, return the global maximum. Both space and time complexity are O(n2)

class Solution
{
public:
    int lengthOfLongestAP(vector<int> &arr)
    {
        int n = arr.size();
        if (n <= 2)
            return n;
        int ans = 0;
        unordered_map<int, int> dp[n];
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int count = 1;
                int d = arr[i] - arr[j];
                if (dp[j].count(d))
                {
                    count = dp[j][d];
                }
                dp[i][d] = 1 + count;
                ans = max(ans, dp[i][d]);
            }
        }
        return ans;
    }
};