#include <iostream>
#include <vector>
#include "../../../../../MinGW/lib/gcc/mingw32/6.3.0/include/c++/bits/algorithmfwd.h"
using namespace std;

// Problem link : https://leetcode.com/problems/rotate-image/description/

// Problem: Given a square matrix (2d Array), rotate the matrix 90deg clockwise. Do it in-place without using another matrix.

// Approach: First we take in-place transpose of given matrix. Then reverse contents of each row to obtain our answer.
//    [1,2,3]           [1,4,7]            [7,4,1]
//    [4,5,6]    --->   [2,5,8]    --->    [8,5,2]
//    [7,8,9]           [3,6,9]            [9,6,3]

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {

        // taking a in-place transpose

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reversing each row to get desired output

        for (int i = 0; i < matrix.size(); i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};