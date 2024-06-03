#include <iostream>
#include <vector>
using namespace std;

// Problem Link : https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/submissions/1276039059/

// Problem : Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false. There may be duplicates in the original array.

// Approach: we check number of pairs in which the previous [i-1] element is greater than [i] element. Note that one pair will also be have ti=o check if last element is bigger than the first [n-1]>[0] for purely sorted but not rotated array cases. If number of such pair is 1 or 0(when all elements in array are equal it gives 0), then true if not, then false

class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int count = 0;
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] > nums[i])
                count++;
        }
        if (nums[n - 1] > nums[0])
            count++;

        return count <= 1;
    }
};
