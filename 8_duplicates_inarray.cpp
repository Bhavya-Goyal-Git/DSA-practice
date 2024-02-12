#include <iostream>
#include <vector>
using namespace std;

// Problem Link : https://leetcode.com/problems/find-all-duplicates-in-an-array/

// Problem : Given an array of size n. Only elements from 1 to n can be found in array. Either the element appears once or at most twice. return all the elements that appear twice.

// Approach : Traverse the array. check if element present at (abs(value)) position is negative or positive. if positive, element is visited for first time, make the element at that position negative to mark it. if negative, the element has been visited before, and add the current number's absolute value to answer array

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> answer;
        for (auto x:nums){
            if (nums[abs(x)-1] < 0)
            {
                answer.push_back(abs(x));
            }
            else
            {
                nums[abs(x)-1] = -nums[abs(x)-1];
            }
        }
        return answer;
    }
};