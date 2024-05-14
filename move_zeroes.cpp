#include <iostream>
#include <vector>
using namespace std;

// Problem link: https://leetcode.com/problems/move-zeroes/description/

// Problem : Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements. Note that you must do this in-place without making a copy of the array.

// Approach: Do quite opposite, move the non zero elements left. We use 2 pointers approach. initialize both to beginning and iterate the entire array using 2nd pointer. Whenever 2nd pointer comes across a non zero element, swap it with first pointer element and increment first pointer.

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int i = 0;
        int j = 0;
        for (j = 0; j < nums.size(); j++)
        {
            if (nums[j] != 0)
            {
                swap(nums[i++], nums[j]);
            }
        }
    }
};