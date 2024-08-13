#include <iostream>
#include <stack>
using namespace std;

// Problem link: https://www.naukri.com/code360/problems/design-a-stack-that-supports-getmin-in-o-1-time-and-o-1-extra-space_842465?topList=love-babbar-dsa-sheet-problems%3Fsource%3Dyoutube&campaign=Codestudio_Lovebabbar&utm_source=youtube&utm_medium=affiliate&utm_campaign=Codestudio_Lovebabbar&leftPanelTabValue=SUBMISSION

// Problem : Design a special stack that has push, pop, top, and a special method getMin() that returns current minimum value, all in O(1) time and O(1) space. Use built in stack class only.

// Approach : We have to use just one variable called mini as we have to do in O(1) space. There has to be a way by which we can get older value of this mini from the current value. For it: In the push operation (if stack is empty just normally push and update the mini for first time), we firstly check if data to be inserted is less than mini, if not just push it normally. If it was smaller than mini, then we push 2*data - mini into that stack. Afterwards, update mini to that data. And in the pop operaion similarly, if data to be popped is greater than mini, just pop normally, else first update the mini to 2*mini - data and then return mini (if required as this was the actual data). Similar to pop, top operation will also change, if value is greater than mini, return it simply.. else return the value of mini. The function getMin() simply returns mini.
// Why this works: We are using the value of current element and mini to track the previous values. Lets say in a push operation, currently the minimum is 5 and we have to insert a value less than that, (say x) then what we are pushing is (2x - PreviousMini) which is even less than x itself and we update mini to x. At the time of pop, we detect that value is less than mini(x) and we do 2*mini - data. Remember mini was x and data is what we pushed (2x - PrevMinimum). So what we pop is 2(x) - (2x - PrevMinimum) which = PrevMinimum. (2x cancels off) And hence we update the minimum back. Similarly when top element is required, if its less than mini, that means mini is holding the actual value and we return it.

class SpecialStack
{

    stack<int> mystack;
    int mini;

public:
    void push(int data)
    {
        if (mystack.empty())
        {
            mystack.push(data);
            mini = data;
            return;
        }
        if (data < mini)
        {
            mystack.push(2 * data - mini);
            mini = data;
        }
        else
        {
            mystack.push(data);
        }
    }

    void pop()
    {
        if (mystack.empty())
        {
            return;
        }
        int val = mystack.top();
        mystack.pop();
        if (val < mini)
        {
            mini = 2 * mini - val;
        }
    }

    int top()
    {
        if (mystack.empty())
        {
            return -1;
        }
        int val = mystack.top();
        return val < mini ? mini : val;
    }

    int getMin()
    {
        return mini;
    }
};