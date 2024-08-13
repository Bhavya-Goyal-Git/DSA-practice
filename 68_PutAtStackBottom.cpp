#include <iostream>
#include <stack>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio&leftPanelTabValue=SUBMISSION

// Problem : Given a stack and a number x, place x at the bottom of the stack.

// Approach: We use the recursive approach with stack. If the stack is empty, simply push the element and return. Else, store the top element into some temporary variable in scope and pop it from the stack and make a recursive call. After the call, push the temporary variable back into the stack for back tracking. This function too, leverages the fact that recursive calls are indeed a stack themselves.

void solve(stack<int> &myStack, int x)
{
    if (myStack.empty())
    {
        myStack.push(x);
        return;
    }
    int currentelement = myStack.top();
    myStack.pop();
    solve(myStack, x);
    myStack.push(currentelement);
}

stack<int> pushAtBottom(stack<int> &myStack, int x)
{
    solve(myStack, x);
    return myStack;
}