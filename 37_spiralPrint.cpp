#include <iostream>
#include <vector>
using namespace std;

// Problem link : https://leetcode.com/problems/spiral-matrix/description/

// Problem: Given a 2D array..(matrix) traverse it in a spiral form. for ex :
// [   [1,2,3]
//     [4,5,6]                   1 -> 2 -> 3 -> 6 -> 9 -> 8 -> 7 -> 4 -> 5
//     [7,8,9]      ]

// Approach: take 4 numbers, top bottom left and right, initialized to 0, (number of rows -1), 0, (number of cols -1) respectively. traverse the array until top<=bottom and left<=right. print first row, and then increment top. print last colum and decrement right. print last row in reverse and decrement bottom, print first columm in reverse and increment left.

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        int top = 0, left = 0;
        int bottom = matrix.size() - 1;
        int right = matrix[0].size() - 1;
        while (top <= bottom && left <= right)
        {
            for (int i = left; i <= right; i++)
            {
                ans.push_back(matrix[top][i]);
            }
            top++;
            if (left <= right && top <= bottom)
            {
                for (int i = top; i <= bottom; i++)
                {
                    ans.push_back(matrix[i][right]);
                }
                right--;
            }
            if (left <= right && top <= bottom)
            {
                for (int i = right; i >= left; i--)
                {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if (left <= right && top <= bottom)
            {
                for (int i = bottom; i >= top; i--)
                {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};