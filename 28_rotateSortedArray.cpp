#include <iostream>
#include <vector>
using namespace std;

// Problem link: https://leetcode.com/problems/rotate-array/description/

// Problem: Given a sorted array and a positive integer k, rotate the array by k units. for example, [1,2,3,4,5] and k=2 becomes [4,5,1,2,3]

// Approach: First thing we do is get k in range 0 to size of array to prevent casualitites, ny doing k%size. Now we have many approaches. First can be using A new array and doing cyclic assignment arr[(i+k)%num]=arr2[i]. But we have an approach with spaceComplexity of O[1]. we reverse the entire array. [5,4,3,2,1]. Then reverse first k elements [4,5,3,2,1]. Then reverse remaining n-k elements [4,5,1,2,3]. There is one more approach based on cyclic dependencies, we can explore it later..

class Solution
{
public:
    void rotor(vector<int> &nums, int startIdx, int endIdx)
    {
        while (startIdx <= endIdx)
        {
            swap(nums[startIdx++], nums[endIdx--]);
        }
    }
    void rotate(vector<int> &nums, int k)
    {

        k = k % nums.size(); // for k to remain between 0 to n

        // reversing entire array
        rotor(nums, 0, nums.size() - 1);

        // reversing first k elements
        rotor(nums, 0, k - 1);

        // reversing last (n-k) elements
        rotor(nums, k, nums.size() - 1);
    }
};