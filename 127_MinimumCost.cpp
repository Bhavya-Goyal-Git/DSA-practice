#include <iostream>
#include <queue>
using namespace std;

// Problem link : https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

// Problem : Given an array arr containing the lengths of the different ropes, we need to connect these ropes to form one rope. The cost to connect two ropes is equal to sum of their lengths. The task is to connect the ropes with minimum cost. Return minimum cost required.

// Approach : Intuitively, we should add the pieces in increasing order. (piece added first will be repeatedly added). This seems to form a pattern, smallest element added n times then n-1 etc.. however ITS WRONG. In a case where 2 small units add upto a bigger number and atleast 2 other numbers smaller that it are present, then they must be paired together fisrt, and that messes up this pattern. So at any time, we have to add 2 minimum lengths present in array, add it to the cost and add the answer to array too.. this needs to go on until array has reduced to size 1 (rope is made).
// To get 2 minimums from a array is exhausting, to reduce time complexity to nlog(n), we here introduce a min-heap. Push all elements to it. Initialize a cost to 0. Then run a loop till size of heap is >1 (till rope is not connected), at each iteration, take 2 out of heap, add their addition to the cost, and push their addition into the heap again. Return the cost at the end.

class Solution
{
public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long> &arr)
    {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (long long i : arr)
        {
            pq.push(i);
        }
        long long cost = 0;
        while (pq.size() > 1)
        {
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            cost += a + b;
            pq.push(a + b);
        }
        return cost;
    }
};