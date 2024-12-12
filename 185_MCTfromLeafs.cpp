#include <iostream>
#include <map>
#include <vector>
#include <stack>
using namespace std;

// Problem link : https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/description/

// Problem : Given an array arr of positive integers, consider all binary trees such that: Each node has either 0 or 2 children; The values of arr correspond to the values of each leaf in an in-order traversal of the tree. The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively. Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. Note: A node is a leaf if and only if it has zero children.

// Approach : We can think of it as partitioning problem, partition the array at a position, left ones will go left of root element and right will go to right. IN such a partition, value of root will be max(all the lefts)*max(all the rights) and we have to then recursively add left and right sub problems. This partition can be done at many indices from 0 to n-2 position (n is size of array, note we cannot partition at n-1 because then the right partition shall have no elements). So at each range, we try all the partitions and take minimum one possible. Now: observe that this requires max values of different ranges so we create a map[pair of int] to int that is max of ranges. Then in the recursive function: base case is when left>=right then, we are at leaf node, no partition can be done now, return 0. Else make ans=Intmax and run loop from left to right-1. max(all lefts)*max(all rights)+f(lefts)+f(rights) is the value for one possible partition. Take min of all such answers. Memoize it and then tabulate it, the approach is O(n3) time and O(n2) space.

// The DP's best approach is O(n3) however, there exists a greedy approach with O(n) time complexity using stack. The intution is: when we merge 2 nodes, say a and b, in the tree, to create a non leaf node, the smaller one, say a, is gone (larger, say b, stays) and cost of such an operation is a*b. We have to minimise this cost. And for any a, we have 2 choices for b, the left number or the right num. and remember we have to minimise the cost, so for a number a, min cost is a*min(left,right) and in doing so, a must disappear but rest stay as it is. We have to do this process until entire array is reduced to 1 number. Now, this could be done with a array and 2 for loops with lot of shifting. However if we observe this problem, like Finding the next greater element one in stacks, it becomes O(n). WE create a stack, and push INT_MAX in it, similar to next greater element problem, otherwise it can go empty and cause trouble. Then we loop accross the elements of the array. If an element is smaller than the previous, no problem, just push in stack. Otherwise... if this element we are addressing is bigger than the last, then we have found a pair (a,b,c) where a and b are already in stack and a>b and we have a 'c' such that c>b. So b is in a position to be merged. So we pop out b, and muliplty min of (a,c) to it and add that to the cost. (remember a is currently stack top and c is what we are accessing now). This process must be done in a while loop similar to next greater element so that all merging can be done. After the while loop, we push the current element (c in the example) into the stack. After processing all elements in the array, it is possible stack has elements, arranged in descending order. And as we know, merging has to be done for a smallest element with min(its left and right), in descending order it is simpler. While the stack length is >2 keep poping an element and multiply it with current top (don't pop it, its required for next calc). Do this until len>2 as when len is 2.. we actually have only ans node left, as one node is INT_MAX that we pushed into stack. after this, return ans. In O(n) steps we have got the answer.

class Solution
{
public:
    int solve(vector<int> &arr, int left, int right, map<pair<int, int>, int> &m, vector<vector<int>> &dp)
    {
        if (left == right)
            return 0;
        if (dp[left][right] != -1)
            return dp[left][right];
        int ans = INT32_MAX;
        for (int i = left; i < right; i++)
        {
            ans = min(ans, m[{left, i}] * m[{i + 1, right}] + solve(arr, left, i, m, dp) + solve(arr, i + 1, right, m, dp));
        }
        return dp[left][right] = ans;
    }
    int solve2(vector<int> &arr, map<pair<int, int>, int> &m)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int left = n - 1; left >= 0; left--)
        {
            for (int right = left + 1; right < n; right++)
            {
                int ans = INT32_MAX;
                for (int i = left; i < right; i++)
                {
                    ans = min(ans, m[{left, i}] * m[{i + 1, right}] + dp[left][i] + dp[i + 1][right]);
                }
                dp[left][right] = ans;
            }
        }
        return dp[0][n - 1];
    }
    int mctFromLeafValues(vector<int> &arr)
    {
        int n = arr.size();
        map<pair<int, int>, int> m; //(startIndex,endIndex)->Max in the range
        // vector<vector<int>> dp(n,vector<int>(n,-1));
        for (int i = 0; i < n; i++)
        {
            m[{i, i}] = arr[i];
            for (int j = i + 1; j < n; j++)
            {
                m[{i, j}] = max(m[{i, j - 1}], arr[j]);
            }
        }
        // return solve(arr,0,n-1,m,dp);
        return solve2(arr, m);
    }
};

// greedy approach O(n)
class Solution2
{
public:
    int mctFromLeafValues(vector<int> &arr)
    {
        int ans = 0;
        stack<int> st;
        st.push(INT32_MAX);
        for (int val : arr)
        {
            while (st.top() <= val)
            {
                int smallest = st.top();
                st.pop();
                ans += smallest * min(val, st.top());
            }
            st.push(val);
        }
        while (st.size() > 2)
        {
            int temp = st.top();
            st.pop();
            ans += st.top() * temp;
        }
        return ans;
    }
};