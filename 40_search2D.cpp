#include <iostream>
#include <vector>
using namespace std;

// Problem link: https://leetcode.com/problems/search-a-2d-matrix-ii/description/

// Problem: Given is a weirdly sorted 2D array (matrix) and a target to be found. How is it sorted : Each row is sorted in ascending order and each colum is sorted in ascending order too.
// For example :   [ 1, 4, 7,11,15]
//                 [ 2, 5, 8,12,19]
//                 [ 3, 6, 9,16,22]
//                 [10,13,14,17,24]
//                 [18,21,23,26,30]

// Approach: We have to do some exhaustive search in which we can reduce the search space fastly. for so, we initialize rowindex=0 and column index to (num of cols-1) and then we start at top right end of matrix.. then we see if element is equal to target, we return true.. else when element is less than target, we need a greater answer than can be found only below so we increment rowindex++. now if element is greater than target, we can find it only on lefter side, so we decrement the colIndex--. By this way, we keep removing rows and collumn from the matrix, making it smaller at each iteration. At max, it can take O(m+n) time as it can go m steps and n step left and down resp.

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        int rowIndex = 0;
        int colIndex = col - 1;
        while (rowIndex < row && colIndex >= 0)
        {
            int element = matrix[rowIndex][colIndex];
            if (element == target)
                return true;
            else if (element > target)
                colIndex--;
            else
                rowIndex++;
        }
        return false;
    }
};