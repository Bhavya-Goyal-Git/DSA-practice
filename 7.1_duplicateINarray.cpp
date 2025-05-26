#include <iostream>
#include <vector>
using namespace std;

// Problem link : https://leetcode.com/problems/find-the-duplicate-number/description/

// Problem : Given an array of length N+1, only has elements [1,N], (it is bound to have atleast one duplicate), one number is repeated rest can occur only once. (repeated number can repeat many times). Dont modify the array and find the repeating number!

// Approach: It cannot be solved using XOr as we aren't sure what numbers will be there or not and repeating number can repeat many times. We could have done "making the element at nums[i] index negative and then if we discover it again it is dulpicate approach" but we are told not to touch the array. SO here's the solution: Tortoise hare approach- the one used for cycle detection.
//  We can think of the duplicate number as starting point of the cycle. Assign a slow and fast. slow goes to arr[slow] and fast to arr[arr[fast]], when they meet we have found a cycle. But we want to find the element not the cycle. TO find the cycle start, reset one of them to start i.e. arr[0] and now run them once step each. when they become equal, that is the answer.

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = nums[0], fast = nums[0];
        // do-while loop here is essential, without it, the loop won't even start to run as initially the pointers are equal!
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        fast = nums[0];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};