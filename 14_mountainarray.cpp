#include <iostream>
#include <vector>
using namespace std;

// Problem link : https://leetcode.com/problems/peak-index-in-a-mountain-array/

// Problem : Given a mountain array (atleast length 3), ie arr[1]<arr[2]...< arr[i-1] < arr[i] > arr[i+1]....>arr[n-1] find the index of peak element that is, i.

// Approach : Binary search. note that we run only until low < high. when arr[mid]<arr[mid+1], we are on left slope hence increment low to mid +1, else we can be at peak or right slope, therefore update high to mid and not mid-1. The last observed value of low is req answer.

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low=0,high=arr.size()-1;
        int mid = low + (high-low)/2;
        while(low<high)
        {
            if (arr[mid]<arr[mid+1])
            {
                low = mid+1;
            }
            else
            {
                high=mid;
            }

            mid = low + (high-low)/2;
        }
        return low;
    }
};