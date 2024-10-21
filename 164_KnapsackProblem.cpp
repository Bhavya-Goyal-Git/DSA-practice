#include <iostream>
#include <vector>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/0-1-knapsack_920542?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

// Problem : Given n, number of items in a house. Given is also 2 arrays weight and value. Weight[i] represents weight of ith item in house and Value[i] represents value of ith item. Also given a MaxWeight, the largest a knapsack of theif can carry. We have to find max value a thief can steal, given the capacity (maxWeight) of his knapsack. Return the max value that can be stolen.

// Approach : First we try recursion. It is same as calculating all subsets of items possible and at the end update the max value. But we will go in reverse direction, ie index n-1 to 0, so that base case becomes index=0. When index is 0, we can include item if capacity >= weight[0] otherwise not. So we return value[0] when capacity allows else return 0. If index is not 0, then regular case, we can either include the item or exclude it. But inclusion is only possible if capacity allows. So, we make 2 recursive calls as follows: include = value[index] + f(index-1,capacity-weight[index]) & exclude = f(index-1,capacity). As we require max value, we take max of these and return it. This takes exponential time and large space.
// Memoizing : here we observe in recursion that 2 values are changing, capacity as well as index. So its a 2d DP question. Hence dp array will have 2 dimensions. rows representing index (0 t0 n-1) and collumns representing capacity (0 to maxWeight). We apply simple memoization and complexity changes to O(n*W) and space comp is O(n*W + recursive)
// Tabulation: We observe the base case is for 0th row, in 0th row if weight[0] <= capacity, entry must be value[0] else 0. We initialize the array with 0s so fill only value[0] in those dp[0][i] where i>=weight[0]. Then we start 2 loops outer runs for index and inner for capacity. Conversion is easy, just remember that inside the loop, capacity is no longer a constant but a looping variable, here w. This reduces space to O(nW)
// Space opt: We observe that f(index,capacity) depends on f(index-1, Any random capacity), so we can reduce 1 dimension. I mean, we do not require the entire 2d array, just 2 arrays prev and curr both size of (capacity+1) at the end of each inner loop, prev=curr (copies all entries). And we can return curr[maxWeight] at the end. This reduces space comp to O(2*W)
// Further space opt: Can we do this with just 1 array? observe that f(index,cap) depends on f(index-1, capacity equal to or less than cap). So across running left to right, only left values are used in the loop. But in a single run, if we modify arr[3] and later arr[7] requires arr[3] it will give wrong value. But What if, we process from right to left. No ambiguity can arise. So we make only 1 array and do updation in itself only. This reduces the space comp to O(W) and time stays at O(nW)

// recursive
int solve(vector<int> &weight, vector<int> &value, int index, int capacity)
{

    if (index == 0)
    { // base case
        if (weight[0] <= capacity)
            return value[0];
        else
            return 0;
    }

    int include = 0;
    if (weight[index] <= capacity)
        include = value[index] + solve(weight, value, index - 1, capacity - weight[index]);
    int exclude = solve(weight, value, index - 1, capacity);
    return max(include, exclude);
}

// recursive + memoization
int solve2(vector<int> &weight, vector<int> &value, int index, int capacity, vector<vector<int>> &dp)
{

    if (index == 0)
    { // base case
        if (weight[0] <= capacity)
            return value[0];
        else
            return 0;
    }
    if (dp[index][capacity] != -1)
        return dp[index][capacity];

    int include = 0;
    if (weight[index] <= capacity)
        include = value[index] + solve2(weight, value, index - 1, capacity - weight[index], dp);
    int exclude = solve2(weight, value, index - 1, capacity, dp);
    dp[index][capacity] = max(include, exclude);
    return dp[index][capacity];
}

// tabulation
int solve3(vector<int> &weight, vector<int> &value, int n, int capacity)
{
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));
    // base case is 0th row (index 0)
    for (int w = weight[0]; w <= capacity; w++)
    {
        dp[0][w] = value[0];
    }
    for (int index = 1; index < n; index++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            int include = 0;
            if (weight[index] <= w)
                include = value[index] + dp[index - 1][w - weight[index]];
            int exclude = dp[index - 1][w];
            dp[index][w] = max(include, exclude);
        }
    }
    return dp[n - 1][capacity];
}

// space opt
int solve4(vector<int> &weight, vector<int> &value, int n, int capacity)
{
    // vector<vector<int>> dp(n,vector<int>(capacity+1,0));
    vector<int> prev(capacity + 1, 0);
    vector<int> curr(capacity + 1, 0);
    // base case is 0th row (index 0)
    for (int w = weight[0]; w <= capacity; w++)
    {
        prev[w] = value[0];
    }
    if (n == 1)
        return prev[capacity];

    for (int index = 1; index < n; index++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            int include = 0;
            if (weight[index] <= w)
                include = value[index] + prev[w - weight[index]];
            int exclude = prev[w];
            curr[w] = max(include, exclude);
        }
        prev = curr;
    }
    return curr[capacity];
}

// more space opt
int solve5(vector<int> &weight, vector<int> &value, int n, int capacity)
{
    // vector<vector<int>> dp(n,vector<int>(capacity+1,0));
    vector<int> prev(capacity + 1, 0);
    // base case is 0th row (index 0)
    for (int w = weight[0]; w <= capacity; w++)
    {
        prev[w] = value[0];
    }
    if (n == 1)
        return prev[capacity];

    for (int index = 1; index < n; index++)
    {
        for (int w = capacity; w >= 0; w--)
        {
            int include = 0;
            if (weight[index] <= w)
                include = value[index] + prev[w - weight[index]];
            int exclude = prev[w];
            prev[w] = max(include, exclude);
        }
    }
    return prev[capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // return solve(weight,value,n-1,maxWeight);
    // vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
    // return solve2(weight, value, n-1, maxWeight, dp);
    return solve5(weight, value, n, maxWeight);
}