#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Problem : Given a queue of even length, return a interleaved queue. For example 1,2,3,4,5,6,7,8 return 1,5,2,6,3,7,4,8 (break into halves and combine). You only can use a stack as auxilary space.

// Approach : Since we have to use a stack, we need to fill the stack in a way that elements can be popped out from it in ordered way. So first we pop out half of the queue into a stack. Now this will return elements in reverse order. Push this reversed order back into queue. Now we sent half elements of queue back so that this reversed order is again at front. Now pop half of queue back into stack, this half is now reversed again and when it will be popped from stack it will be straight. Now do the interleaving. pop one from stack and one from queue and insert into the queue.

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    int n = q.size();
    stack<int> s;
    // push half of q into stack
    for (int i = 0; i < n / 2; i++)
    {
        s.push(q.front());
        q.pop();
    }
    // empty the stack back to queue
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    // cycle first half of queue to back again
    for (int i = 0; i < n / 2; i++)
    {
        q.push(q.front());
        q.pop();
    }
    // empty the first half queue into stack again
    for (int i = 0; i < n / 2; i++)
    {
        s.push(q.front());
        q.pop();
    }
    // now do the interleaving
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
    // print the queue
    while (!q.empty())
    {
        cout << q.front() << " -> ";
        q.pop();
    }
    cout << "NULL" << endl;
    return 0;
}
