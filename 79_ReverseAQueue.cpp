#include <iostream>
#include <queue>
using namespace std;

// Problem link : https://www.geeksforgeeks.org/problems/queue-reversal/1

// Problem : Given a queue, reverse it.

// Approach : We pop out all the elements into a stack and then pop all of them back from stack and add into the queue, effectively reversing the order of elements. Here, recursive stack is used as a stack.

class Solution
{
private:
    void revqueue(queue<int> &q)
    {
        if (q.empty())
        {
            return;
        }
        int data = q.front();
        q.pop();
        revqueue(q);
        q.push(data);
    }

public:
    queue<int> rev(queue<int> q)
    {
        revqueue(q);
        return q;
    }
};