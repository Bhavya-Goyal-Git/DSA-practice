#include <iostream>
#include <stack>
#include <vector>
#include <climits>
#define MAX 1000
using namespace std;

// Problem Link : https://www.geeksforgeeks.org/problems/max-rectangle/1\

// Problem : Given a binary matrix M of size n X m. Find the maximum area of a rectangle formed only of 1s in the given matrix. For example : n = 4, m = 4
// M[][] = {{0 1 1 0},
//          {1 1 1 1},
//          {1 1 1 1},
//          {1 1 0 0}}
// Output: 8

// Approach : This question build upon largest rectangle area in a histogram problem, so thats a pre-requistie. What we do is, apply max rectangle area on the first row of given matrix and store it in a variable "area". Now, in next step we will add first 2 rows of the given matrix and it will sort of behave like a histogram problem (however, there is one thing to be considered while adding, for example we are adding into the 2nd row, above value must be added only if entry in this second row isn't 0, because if it is, then it wont make a rectangle.) So, effectively, we run a loop across the rows of this matrix from row index 1 (0 was already run) to n-1. At each iteration, we add above row's values to this row (with 0's condition in mind) and then send this newly formed histogram to our largestRectangleArea function. Keep comparing the new values being returned and storing the max of them into "area" variable. At the end, return this area.

class Solution
{
private:
    vector<int> smallernextint(int arr[], int n)
    {
        vector<int> ans(n);
        stack<int> mystack;
        mystack.push(-1);
        for (int i = n - 1; i >= 0; i--)
        {
            while (arr[mystack.top()] >= arr[i] && mystack.top() != -1)
            {
                mystack.pop();
            }
            ans[i] = mystack.top();
            mystack.push(i);
        }
        return ans;
    }
    vector<int> smallerprevint(int arr[], int n)
    {
        vector<int> ans(n);
        stack<int> mystack;
        mystack.push(-1);
        for (int i = 0; i < n; i++)
        {
            while (arr[mystack.top()] >= arr[i] && mystack.top() != -1)
            {
                mystack.pop();
            }
            ans[i] = mystack.top();
            mystack.push(i);
        }
        return ans;
    }
    int largestRectArea(int arr[], int n)
    {
        vector<int> nexts = smallernextint(arr, n);
        vector<int> prevs = smallerprevint(arr, n);
        int area = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (nexts[i] == -1)
                nexts[i] = n;
            int newarea = arr[i] * (nexts[i] - prevs[i] - 1);
            area = max(area, newarea);
        }
        return area;
    }

public:
    int maxArea(int M[MAX][MAX], int n, int m)
    {
        int area = largestRectArea(M[0], m);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (M[i][j] != 0)
                {
                    M[i][j] += M[i - 1][j];
                }
            }
            int newarea = largestRectArea(M[i], m);
            area = max(area, newarea);
        }
        return area;
    }
};