#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Problem link : https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1

// Problem : Given a queue, and a integer k, reverse the first k elements of the queue. for example the queue -> [1,2,3,4,5] and k = 3, should give [3,2,1,4,5]

// Approach : We first add the first k elements into a stack by popping them out of queue and then insert them back into the queue by popping form stack, this reverses the first k elements but remaining elements of queue are now at front that is not wanted. So we take out the first element of queue and add it again (remove front add at end) for n-k times (n here is size of queue). This restores their position and we have our answer.

class Solution
{
public:
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k)
    {
        stack<int> s;
        for (int i = 0; i < k; i++)
        {
            s.push(q.front());
            q.pop();
        }
        while (!s.empty())
        {
            q.push(s.top());
            s.pop();
        }
        int n = q.size() - k;
        while (n--)
        {
            int d = q.front();
            q.pop();
            q.push(d);
        }
        return q;
    }
};