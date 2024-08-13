#include <iostream>
#include <stack>
#include <vector>
#include <climits>
using namespace std;

// Problem link : https://leetcode.com/problems/largest-rectangle-in-histogram/description/

// Problem : Given a array that represents lengths of bars in a histogram, return the area of largest rectangle that can be formed within the histogram. Assume that width of each bar is 1.

// Approach : On the bruteforce method, this takes O(n2) complexity. To reduce it to O(n) we can use the approach of NextSmallerElement ques(previously done). Effectively what we want is to check how far can i extend each bar on both sides, and ans is-> until the index of nextSmallerElement and the index of previousSmallerElement (till we hit bars of smaller sizes on both ends.) So what we do is, make 2 arrays first using the same stack based approach to find next&previous smaller indices for each element in given array. Note that ques did earlier, we returned elements themselves but here we have to return their indices, so stack will collect indices, therefore comparisons will be done with arr[stack.top()] and to prevent arr[-1], that has to be checked too. Two seprate function will do our job and now we have 2 arrays containing previousSmallerIndex and nextSmallerIndex of each element. Note that nextSmallerIndex = -1 indicates that we can extend the bar fully, so we inturn replace that -1 with n (size of given array). Now we traverse the given array, calculating max areas for each bar.. length is already given and width is simply (next[i] - prev[i] -1), keep comparing to a area variable and storing the max. Return the area.

class Solution
{
private:
    vector<int> nextsmallindex(vector<int> &arr, int n)
    {
        vector<int> ans(n);
        stack<int> mystack;
        mystack.push(-1);
        for (int i = n - 1; i >= 0; i--)
        {
            while (mystack.top() != -1 && arr[mystack.top()] >= arr[i])
            {
                mystack.pop();
            }
            ans[i] = mystack.top();
            mystack.push(i);
        }
        return ans;
    }
    vector<int> previoussmallindex(vector<int> &arr, int n)
    {
        vector<int> ans(n);
        stack<int> mystack;
        mystack.push(-1);
        for (int i = 0; i < n; i++)
        {
            while (mystack.top() != -1 && arr[mystack.top()] >= arr[i])
            {
                mystack.pop();
            }
            ans[i] = mystack.top();
            mystack.push(i);
        }
        return ans;
    }

public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> nexts = nextsmallindex(heights, n);
        vector<int> prevs = previoussmallindex(heights, n);
        int area = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (nexts[i] == -1)
                nexts[i] = n;
            int newarea = heights[i] * (nexts[i] - prevs[i] - 1);
            area = max(area, newarea);
        }
        return area;
    }
};