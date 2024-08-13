#include <iostream>
#include <stack>
using namespace std;

// Problem Link : https://www.naukri.com/code360/problems/reverse-stack-using-recursion_631875?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio&leftPanelTabValue=PROBLEM

// Problem : Given a stack, reverse it using recursion.

// Approach : Well we have the base case when stack is empty, then we return as it is. Else, we take the top element place it in current scope and make a recursive call. (Now, assuming the recursive call has given us a reversed stack uptil this point) Now the element we have in scope must go at the bottom of this returned stack. So we make a call to another function that takes a stack and a element and inserts it at the bottom. Effectively, this recursion first empties the stack into recursive calls and while backtracking inserts every element to the bottom of returning stack, thereby reversing it.

void insertAtBottom(stack<int> &stack, int num)
{
    if (stack.empty())
    {
        stack.push(num);
        return;
    }
    int current = stack.top();
    stack.pop();
    insertAtBottom(stack, num);
    stack.push(current); // backtrack
}

void reverseStack(stack<int> &stack)
{
    if (stack.empty())
    {
        return;
    }
    int num = stack.top();
    stack.pop();
    reverseStack(stack);
    insertAtBottom(stack, num); // backtrack
}