#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem link : https://leetcode.com/problems/russian-doll-envelopes/description/

// Problem : You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope. One envelope can fit into another if and only if both the width and height of one envelope are strivtly greater than the other envelope's width and height. Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

// Approach : This question is based on LIS length pattern (the previous question). To ensure widths and heights are placed into each other nicely, we have to sort the given array first. As per increasing order of widths, and if widths are equal then decreasing order of heights. This will require a custom comparator for sort fn. This step is very crucial for next process. By sorting the widths in ascending order we have ensured to pick smaller then larger first. But equal widths? That is reason we have placed heights within equal widths in descending way.
// All we have to do after sorting, is to find the length of LIS in the array of heights only. (do not take care of widths). Now we see why descending order arrangement was good. Within each width only one would be picked by LIS algorithm. This way, the length of LIS will give us the required ans, that is max number of envelopes that can be russian dolled.

bool comparator(const vector<int> &a, const vector<int> &b)
{
    if (a[0] == b[0])
        return a[1] > b[1]; // descending
    else
        return a[0] < b[0]; // ascending
}

class Solution
{
public:
    int findLengthofLIS(vector<vector<int>> &envelopes, int n)
    {
        if (n == 0)
            return 0;
        vector<int> tails;
        tails.push_back(envelopes[0][1]);
        for (int i = 1; i < n; i++)
        {
            if (envelopes[i][1] > tails.back())
            {
                tails.push_back(envelopes[i][1]);
            }
            else
            {
                // lower bound replace
                int index = lower_bound(tails.begin(), tails.end(), envelopes[i][1]) - tails.begin();
                tails[index] = envelopes[i][1];
            }
        }
        return tails.size();
    }
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        sort(envelopes.begin(), envelopes.end(), comparator);
        int ans = findLengthofLIS(envelopes, envelopes.size());
        return ans;
    }
};
