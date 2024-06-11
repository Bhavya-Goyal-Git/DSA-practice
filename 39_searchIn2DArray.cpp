#include <iostream>
#include <vector>
using namespace std;

// Problem link: https://leetcode.com/problems/search-a-2d-matrix/description/

// Problem: Given is a sorted 2D array in which each row is sorted in increasing order and the first element of next row is larger than last element of previous row.. and a target is to be found. Find it in O(log(m*n)).

// Approach: We doing binary search on 2d array. How? Think of 2d array as a 1d array running from index 0 to (n*m-1) [number of elements - 1]. Apply normal binary search then. Just when we calculate mid, we need to turn this single index back into a row and col index. this is done simply as : row index = mid/ no. of col and col index = mid % no. of colums..

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int numCol = matrix[0].size();
        int left = 0;
        int right = matrix.size() * numCol - 1;
        int mid = left + (right - left) / 2;
        while (left <= right)
        {
            if (matrix[mid / numCol][mid % numCol] == target)
            {
                return true;
            }
            else if (matrix[mid / numCol][mid % numCol] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
            mid = left + (right - left) / 2;
        }
        return false;
    }
};