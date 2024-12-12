#include <iostream>
#include <vector>
using namespace std;

// Problem link : https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/description/

// Problem : You are given two integer arrays of the same length nums1 and nums2. In one operation, you are allowed to swap nums1[i] with nums2[i].
// For example, if nums1 = [1,2,3,8], and nums2 = [5,6,7,4], you can swap the element at i = 3 to obtain nums1 = [1,2,3,4] and nums2 = [5,6,7,8]. Return the minimum number of needed operations to make nums1 and nums2 strictly increasing. The test cases are generated so that the given input always makes it possible.

// Approach : We run a index from 0 to last and at each step make 2 calls, with swap and without swap, at the end take the minimum of 2, note that swap may/may not be necessary so there are additional conditions prior to making recursive calls. We return 0 if index goes out of size. We also send a variable called swapped (true or false) which tells us if previous values were swapped or not. We do this because during swapping call, we dont want to actually change the arrays, just take notes. So after base case, we now need the previous values of both the arrays. If index was 0, if use -1 as previouses else nums[index-1] for both the arrays. Then we check value of swapped, if it was true, then we have to just swap the values of prev1 and prev2 to reflect it into our change.. now we can make decide further calls without worry. If current indices are greater than prevs of respective arrays, we can make a non swap call. store it in a ans, initialized to a large value at beginning. If current indices of both arrays are greater than prevs of opposite arrays, we can make a swap call. In this call, remember to add 1 for the swapping, and call with swapped variable set to true. We take minimum of the answers and return it. Adding memoisation, tabulation and space optimisation is easy. Time complexity is O(n) and space is O(1)

class Solution
{
public:
    int solve(vector<int> &nums1, vector<int> &nums2, int index, bool swapped, vector<vector<int>> &dp)
    {
        if (index >= nums1.size())
            return 0;
        if (dp[index][swapped] != -1)
            return dp[index][swapped];

        int prev1 = index > 0 ? nums1[index - 1] : -1;
        int prev2 = index > 0 ? nums2[index - 1] : -1;

        if (swapped) // getting correct previouses
            swap(prev1, prev2);

        int ans = 100001; // max ans can be 10^5

        // can we work with no swapping?
        if (nums1[index] > prev1 && nums2[index] > prev2)
            ans = solve(nums1, nums2, index + 1, false, dp);
        // can we work with swapping?
        if (nums1[index] > prev2 && nums2[index] > prev1)
            ans = min(ans, 1 + solve(nums1, nums2, index + 1, true, dp));

        return dp[index][swapped] = ans;
    }
    int solve2(vector<int> &nums1, vector<int> &nums2)
    {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(2, 0));
        for (int index = nums1.size() - 1; index >= 0; index--)
        {
            for (int swapped = 1; swapped >= 0; swapped--)
            {
                int prev1 = index > 0 ? nums1[index - 1] : -1;
                int prev2 = index > 0 ? nums2[index - 1] : -1;

                if (swapped) // getting correct previouses
                    swap(prev1, prev2);

                int ans = 100001; // max ans can be 10^5

                // can we work with no swapping?
                if (nums1[index] > prev1 && nums2[index] > prev2)
                    ans = dp[index + 1][0];
                // can we work with swapping?
                if (nums1[index] > prev2 && nums2[index] > prev1)
                    ans = min(ans, 1 + dp[index + 1][1]);
                dp[index][swapped] = ans;
            }
        }
        return dp[0][0];
    }
    int solve3(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> next(2, 0);
        vector<int> curr(2, 0);
        for (int index = nums1.size() - 1; index >= 0; index--)
        {
            for (int swapped = 1; swapped >= 0; swapped--)
            {
                int prev1 = index > 0 ? nums1[index - 1] : -1;
                int prev2 = index > 0 ? nums2[index - 1] : -1;

                if (swapped) // getting correct previouses
                    swap(prev1, prev2);

                int ans = 100001; // max ans can be 10^5

                // can we work with no swapping?
                if (nums1[index] > prev1 && nums2[index] > prev2)
                    ans = next[0];
                // can we work with swapping?
                if (nums1[index] > prev2 && nums2[index] > prev1)
                    ans = min(ans, 1 + next[1]);
                curr[swapped] = ans;
            }
            next = curr;
        }
        return next[0];
    }
    int minSwap(vector<int> &nums1, vector<int> &nums2)
    {
        // vector<vector<int>> dp(nums1.size(),vector<int>(2,-1));
        return solve3(nums1, nums2);
    }
};