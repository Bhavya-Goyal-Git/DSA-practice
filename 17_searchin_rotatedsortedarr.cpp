#include <iostream>
#include <vector>
using namespace std;

// Problem Link : https://www.codingninjas.com/studio/problems/search-in-rotated-sorted-array_1082554?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&leftPanelTabValue=SUBMISSION

// Problem : Given is a rotated sorted array, its length n and a number k. search for k in the array and return its index. if not found, return -1.

// Approach: We find index of pivot element using a function first. Then we check if k>=arr[pivot index] and k<=arr[n-1], is yes implement binary search in later part ie pivot index to n-1 and if not, implement it fom 0 to pivot-index -1

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
int binarysearch(vector<int>& arr, int s, int e, int k)
{
    int low=s,high=e;
    int mid = low + (high-low)/2;
    while(low<=high)
    {
        if (arr[mid]==k)
        {
            return mid;
        }
        else if (arr[mid]>k)
        {
            high=mid-1;
        }
        else {
            low = mid+1;
        }
        mid = low + (high-low)/2;
    }
    return -1;
}


int search(vector<int>& arr, int n, int k)
{
    int pivot_index = findpivot(arr);
    if (k>=arr[pivot_index]&&k<=arr[n-1])
    return binarysearch(arr, pivot_index, n-1, k);
    else
    return binarysearch(arr, 0, pivot_index-1, k);

}
