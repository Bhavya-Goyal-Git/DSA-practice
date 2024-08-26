#include <iostream>
#include <queue>
using namespace std;

// Problem Link : https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

// Problem : Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K. For ex if : N = 5, A[] = {-8, 2, 3, -6, 10}, K = 2
// Output : -8 0 -6 -6
// Explanation : First negative integer for each window of size k
// {-8, 2} = -8
// {2, 3} = 0 (does not contain a negative integer)
// {3, -6} = -6
// {-6, 10} = -6

// Approach : We first make a queue and a vector ans to be returned. Then we process a window of size K for the first time. In the processing, we just check if element is negative and if it is, we store its index in our queue. This queue stores index of all negative numbers as they occur in the current window. After the processing, we store the queue's front in the ans (ans.push(A[q.front])) if queue is non empty but store 0 if queue was empty. Now we begin processing from the kth element upto n-1 in the loop and at each element we check: firstly if the queue can be dequeued (first element needs to remove) this is donee by checking if i - q.front() >= K that is, queue's front does not lie in the window of size k, then pop it. Then we check if current element can be added to queue. If A[i] < 0 push i to the queue. At the end we do a similar insertion into ans the way we did before that : we store the queue's front in the ans (ans.push(A[q.front])) if queue is non empty but store 0 if queue was empty. This makes ans vector populate with first -ive integers in every window of size K. return ans.

// Note: it is possible to optimise the problem further into o(1) space. Approach and code for it is below the given code.

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K)
{
    queue<long long> q;
    vector<long long> ans;

    // processing first window of size K
    for (int i = 0; i < K; i++)
    {
        if (A[i] < 0)
        {
            q.push(i);
        }
    }
    if (q.empty())
    {
        ans.push_back(0);
    }
    else
    {
        ans.push_back(A[q.front()]);
    }
    // sliding the window 1 unit at a time
    for (int i = K; i < N; i++)
    {
        // removal if needed
        if (!q.empty() && i - q.front() >= K)
        {
            q.pop();
        }
        // addition if needed
        if (A[i] < 0)
        {
            q.push(i);
        }
        // pushing answer into vector
        if (q.empty())
        {
            ans.push_back(0);
        }
        else
        {
            ans.push_back(A[q.front()]);
        }
    }
    return ans;
}

// Approach 2 : This is optimized way, using O(n) [same] time but only O(1) space as compared to the O(k) in queue case. We maintain a variable FirstNegativeIndex initially 0, that contains the first negative element of current window. We begin processing from index i = k-1 for the first window and upto N-1. Now, at each window, we first increment this index.. to make sure it is in window (not gone above it) we use firstnegindex < i and we also need to check, if it is positive or within the current window ( not far behind by firstindex <= i-k) all these cases increment it. Then we check whether we got any value in it. if a[firstnegindex] < 0 then we set out first element number to that value, otherwise zero. Push back the value into ans vector and return at the end!!

vector<long long> printFirstNegativeIntegerOptimized(long long int A[], long long int N, long long int K)
{
    long long int firstNegIndex = 0;
    long long int firstNegNumber;
    vector<long long> ans;

    for (int i = K - 1; i < N; i++)
    {
        while (firstNegIndex < i && (firstNegIndex <= i - K || A[firstNegIndex] > 0))
        {
            firstNegIndex++;
        }
        if (A[firstNegIndex] < 0)
        {
            firstNegNumber = A[firstNegIndex];
        }
        else
        {
            firstNegNumber = 0;
        }
        ans.push_back(firstNegNumber);
    }
    return ans;
}