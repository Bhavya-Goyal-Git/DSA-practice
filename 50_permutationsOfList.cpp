#include <iostream>
#include <vector>
using namespace std;

// Problem link : https://leetcode.com/problems/permutations/description/

// Problem : Given is a vector of integers, we have to return a vector of vectors that has all possible permutations of given vector. for ex. [1,2,3] -> { [1,2,3] [1,3,2] [2,1,3] [2,3,1] [3,1,2] [3,2,1] }

// Approach : We could have gone for constructing a new output just like every other question, but in permutaion of an object, we aren't creating anything new, just rearranging. therefore, this is a approach that avoids unnecessary overheads. we create a recursive function that takes input vector, a integer index, and the vector of vectors passed as reference to be pushedback into at the base case. Base Case: simply, when index goes out of bounds ie  >=input.size() we push back input (Yes input) into our ans and return. Normal case: We run a loop from current value of index until the end of input vector. At each iteration, we swap the index location arr[index] with a new value arr[i]. then we make a recursive call to with this input and index+1. Remember when we arrive back we must recorrect the input to be sent for further iterations, so the swap statement is repeated once more just after the recursive call (this is called backtracking).

class Solution
{
private:
    void solve(vector<int> nums, int index, vector<vector<int>> &ans)
    {
        if (index >= nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); i++)
        {
            swap(nums[i], nums[index]);
            solve(nums, index + 1, ans);
            swap(nums[i], nums[index]); // backtracking
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        int index = 0;
        vector<vector<int>> ans;
        solve(nums, index, ans);
        return ans;
    }
};