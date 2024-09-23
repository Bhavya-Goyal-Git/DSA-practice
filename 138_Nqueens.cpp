#include <iostream>
#include <vector>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/the-n-queens-puzzle_981286?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

// Problem : The N Queens puzzle is the problem of placing N chess queens on an N * N chessboard such that no two queens attack each other. Given an integer N, return all distinct solutions as vector of vector of int, where each vector is placement of queens in the board.

// Approach : we require a board(n*n) where we will solve this problem, all initialized with 0, and another vector<vector<int>> ans which we will return. We make a recursive function that tries all possible positions and give us the ans. Notice that only 1 queen can be there in a col or in a row. The naive approach is to fill 1 position in 1st column and then make a recursive call with 2nd column, at each column, try to place the queen in each row of that column, and place it where it is possible, then make call to next column, if there is a possible placement, we reach there recursively and column to be filled will exceed the limit of board, and at that point we can store the board into ans vector.
// The recursive function hence has the base case when col exceeds size, it stores board into ans vector. Then the function tries to place queen on each row of given column, it uses the function isSafe() to check whether queen can be placed at the position. This function checks only to the left, top-left diagonal and bottom-left diagonal. This is because right and right diagonals are yet to be filled so no use checking there, and since we are placing the queens column by column, in no way we could place 2 queens in the same column, so no need to check within the same column. If its safe to place the queen, we mark it on the board and make a recursive call to next column. After the call, we remove the placed queen by setting board's value back to 0 for backtracking.
// Time comp : O(n!)
// Further optimisation : When we are searching is placement isSafe? we are using linear time. We can use a hashmap to store whether a row/diagonal is already occupied or not. Row can be done directly by index, top left diagonal by subtraction of indices and bottom left diagonal by addition of indices, as they remain constant in given direction of diagonal. This will make isSafe work in O(1), but requires 3 hashMaps of sizes O(n)

void storeBoard(vector<vector<int>> &board, vector<vector<int>> &ans)
{
    vector<int> temp;
    for (vector<int> a : board)
    {
        for (int j : a)
        {
            temp.push_back(j);
        }
    }
    ans.push_back(temp);
}

bool isSafe(vector<vector<int>> &board, int row, int col, int n)
{
    int x = row;
    int y = col;
    // checking to the left (same row)
    while (y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        y--;
    }
    y = col;
    // checking top-left diagonal
    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        x--;
        y--;
    }
    x = row;
    y = col;
    // checking bottom-left diagonal
    while (x < n && y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        x++;
        y--;
    }
    return true;
}

void solve(vector<vector<int>> &board, vector<vector<int>> &ans, int col, int size)
{
    if (col >= size)
    {
        // store current status of board into ans if all columns have been filled
        storeBoard(board, ans);
        return;
    }
    for (int row = 0; row < size; row++)
    {
        if (isSafe(board, row, col, size))
        {
            board[row][col] = 1;              // rakh do raani
            solve(board, ans, col + 1, size); // agli column ke liye call karo
            board[row][col] = 0;              // hata lo waaps (backtracking)
        }
    }
}

vector<vector<int>> nQueens(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;
    solve(board, ans, 0, n);
    return ans;
}

int main()
{

    int num;
    cout << "Enter the size of chess board(single number) : ";
    cin >> num;
    cout << "\n";
    vector<vector<int>> v = nQueens(num);
    cout << "Total possible placements : " << v.size() << ", Here are they : \n\n";
    for (vector<int> a : v)
    {
        int count = 0;
        for (int j : a)
        {
            cout << j << ", ";
            count++;
            if (count % num == 0)
            {
                cout << "\n";
            }
        }
        cout << "\n\n";
    }
    cout << "Total possible placements : " << v.size();
    return 0;
}