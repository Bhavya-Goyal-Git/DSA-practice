#include <iostream>
#include <vector>
using namespace std;

// Problem link : https://leetcode.com/problems/subsets/description/

// Problem: Given a set (vector) of integers, return its power set (set of all subsets). (vector of vectors)

// Approach: We make a recursive function. first arguement is the input vector, second is a vector we would be constructing (initially empty), third is a index variable, and finally fourth is the ans vector of vectors (VERY IMP: pass ans as a reference otherwise progress will be lost). What we are doing: at every step, we make 2 recursive call, first when element at current index is not included in subsets and second when it is included. To do the non included one, we just incement value of index and pass the same parameters. to do the included call, we push_back nums[index] to our output vector and then pass the same parameters (aufcourse with increment of index). This will lead to formation of all subsets at the base case. The output vector we were constructing, at the base case would be a possible value of subset. (Base case is when index has gone out of bounds or simply >=nums.size()) Therefore, at the base case, we push_back this output vector into our ans (vector of vectors) prior to returning.

class Solution
{
private:
    void solve(vector<int> &nums, vector<int> output, int index, vector<vector<int>> &ans)
    {
        if (index >= nums.size())
        {
            ans.push_back(output);
            return;
        }
        // exclude case
        solve(nums, output, index + 1, ans);
        // include case
        output.push_back(nums[index]);
        solve(nums, output, index + 1, ans);
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        solve(nums, output, index, ans);
        return ans;
    }
};