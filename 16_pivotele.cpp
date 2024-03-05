#include <iostream>
#include <vector>

using namespace std;

// Problem : Given is a rotated sorted array. Find index of pivot element (The elementt which was the beginning before sorted array was rotated) ex : [7,8,9,1,2,3,4] --> 3 (element 1)

// Approach : Binary Search. Check if arr[mid]>=arr[0], then it belongs to rotated greater part and we increment low to mid+1. else element is either pivot or on lower side. hence we decrement high to mid. loop runs until low < high. answer is the last occurence of low;

int findpivot(vector<int> &nums){
    int low =0, high = nums.size()-1;
    int mid = low + (high-low)/2;
    while(low<high){
        if (nums[mid] >= nums[0])
        low = mid+1;
        else
        high = mid;
        mid = low + (high-low)/2;
    }
    return low;
}