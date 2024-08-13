#include <iostream>
#include <stack>
using namespace std;

// Problem Link : https://www.naukri.com/code360/problems/minimum-cost-to-make-string-valid_1115770?leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio&leftPanelTabValue=PROBLEM

// Problem : Given a string only of {,} Return the minimum number of brackets that must be reversed in direction to make the expression valid. for ex, Minimum operations to make ‘STR’ =  “{{“ valid is 1.

// Approach : First of all, if input expression has odd number of length, that means brackets can never be balanced and we return -1 straight away. Now, We create a stack and traverse the expression, if its a { we push into stack, however if its } then we check if its equivalent { is at stack top, if yes pop it else we push } onto the stack as well. What this process will leave us with is a stack that contains only the invalid part of our expression. Now we have to find a way to count minimum no. of fixes required to balance it. We do this by popping out from the stack (initialize a count to 0 for indexing and a variable ans to return the answer.) At every even index (count starts 0 remember) a } must be present, if not we increment our answer variable, similarly on every odd index a { must be present, if not we increment our answer variable. Remember to pop from stack and increment count at end of each iteration. At end, when stack is empty, return value of ans.

int findMinimumCost(string str)
{
    if (str.length() & 1)
    {
        return -1;
    }
    stack<char> mystack;
    for (char c : str)
    {
        if (c == '{')
        {
            mystack.push(c);
        }
        else
        {
            if (mystack.empty() || mystack.top() != '{')
            {
                mystack.push(c);
            }
            else
            {
                mystack.pop();
            }
        }
    }
    int count = 0;
    int ans = 0;
    while (!mystack.empty())
    {
        char c = mystack.top();
        if (count & 1)
        {
            ans += (c == '}') ? 1 : 0;
        }
        else
        {
            ans += (c == '{') ? 1 : 0;
        }
        mystack.pop();
        count++;
    }
    return ans;
}