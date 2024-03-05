#include <iostream>
#include <vector>

using namespace std;

// Problem link : https://leetcode.com/problems/find-pivot-index/description/

// Problem : Finding index of pivot element of an array. pivot element is such that sum of all elements before it is equal to sum of all elements after it. note that it can be 0th or last element too. if there is no such element return -1

// Approach : store current left sum, initially 0 and current right sum, initially sum of entire array. then traverse the array, firstly remove current element from sum upto right term. then check if left and right sums are equal, if yes return i. else add current element to left sum and continue iterating. if not found return -1;

class Solution {
public:

    int pivotIndex(vector<int>& nums) {
      int lsum=0;
      int rsum = accumulate(nums.begin(),nums.end(),0);
      for (int i =0;i<nums.size();i++)
      {
          rsum -= nums[i];
          if (lsum==rsum){
              return i;
          }
          lsum+= nums[i];
      }
      return -1;
    }
};