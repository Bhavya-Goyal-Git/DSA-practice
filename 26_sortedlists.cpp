#include <iostream>
#include <vector>
using namespace std;

// problem link : https://leetcode.com/problems/merge-sorted-array/description/

// problem : You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively. Merge nums1 and nums2 into a single array sorted in non-decreasing order.

// The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

// Caution: m and n could be 0 too

// Approach: We use 2 pointer approach for merging sorted arrays. Here we have to do it in place, so we take 3 pointers, i = at end of list 1, j = at end of list 2, k = at end of elongated list 1 (total list). and begin comparison from the end. compare i and jth positions unless j>=0 (not i>0 as when i is not 0 the list may be sorted) compare elements and place the larger one at kth position. decrement used pointers.

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while (j >= 0)
        {
            if (i >= 0 && nums1[i] > nums2[j])
            {
                nums1[k--] = nums1[i--];
            }
            else
            {
                nums1[k--] = nums2[j--];
            }
        }
    }
};