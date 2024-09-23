#include <iostream>
#include <vector>
using namespace std;

// Problem Link : https://www.naukri.com/code360/problems/sudoku-solver_699919?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

// Problem : You have been given a 9x9 2d integer matrix 'MAT' representing a Sudoku puzzle. The empty cells of the Sudoku are filled with zeros, and the rest of the cells are filled with integers from 1 to 9. Your task is to fill all the empty cells such that the final matrix represents a Sudoku solution.
// A Sudoku solution must satisfy all the following conditions-
// 1. Each of the digits 1-9 must occur exactly once in each row.
// 2. Each of the digits 1-9 must occur exactly once in each column.
// 3. Each of the digits 1-9 must occur exactly once in each of the 9, 3x3 sub-grids of the grid.
// You can also assume that there will be only one sudoku solution for the given matrix.

// Approach : We make a recursive function to solve the thing. The function has 2 for loops, for traversing the matrix, and it stops when there is a empty place (0) in it, If however, both loops run, and no empty place was there, we must return true, as the thing is solved. (it serves as base case). Now inside the loops, when a empty place is found, we run another loop trying to place numbers 1 to 9 there, it checks one by one using isSafe() function that checks placement is possible or not by going through row,col,3*3 matrix of that position. When it can be placed, we set the value in matrix, and make forward recursive call storing the value in a boolean variable, if that boolean is true, it means forward calls are successfull and we return true, else we backtrack and set that value back to 0. After both the for loops, we return false, because if a empty place was found and no value 1-9 can satisfy it, no solution is possible. As matrix is passed by ref, we don't need to return anything regarding it, auto filled.

bool isSafe(vector<vector<int>> &sudoku, int row, int col, int val)
{
    // checking row & col
    for (int x = 0; x < 9; x++)
    {
        if (sudoku[row][x] == val)
            return false;
        if (sudoku[x][col] == val)
            return false;
    }
    // checking 3*3 box
    int x = (row / 3) * 3;
    int y = (col / 3) * 3;
    for (int i = x; i < x + 3; i++)
    {
        for (int j = y; j < y + 3; j++)
        {
            if (sudoku[i][j] == val)
            {
                return false;
            }
        }
    }
    return true;
}

bool solve(vector<vector<int>> &sudoku)
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            if (sudoku[row][col] == 0)
            {
                // we have found a empty cell, try filling it
                for (int val = 1; val <= 9; val++)
                {
                    if (isSafe(sudoku, row, col, val))
                    {
                        sudoku[row][col] = val;
                        bool solveNext = solve(sudoku);
                        if (solveNext)
                        {
                            return true; // sabkuch bhar gya aage ka
                        }
                        else
                        {
                            sudoku[row][col] = 0; // backtracking
                        }
                    }
                }
                // sab kuch try karlia par empty place fill ni hui
                return false;
            }
        }
    }
    // if no empty cell in sudoku, return true
    return true;
}

void solveSudoku(vector<vector<int>> &sudoku)
{
    solve(sudoku);
}
