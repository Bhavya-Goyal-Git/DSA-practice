#include <iostream>
#include <stack>
using namespace std;

// Problem Link : https://www.naukri.com/code360/problems/valid-parenthesis_795104?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio&leftPanelTabValue=SUBMISSION

// Problem : Given a string only of bracket characters, check whether it is a valid balanced parenthesis matching.

// Approach : We create a stack and then iterate the given expression. If its a opening bracket push into stack. Else it will be a closing bracket, first check if the stack is even checkable (if it is empty then return false at that instant) Now check the stack, the stack top must match the closing's opening. If this is the condition, we pop it from the stack, else we return false at that instant. Now entire expression is traversed, we return stack.empty() because stack should be empty after the process, if its not, then expression was invalid.

bool isValidParenthesis(string s)
{
    stack<char> mystack;
    for (char c : s)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            mystack.push(c);
        }
        else
        {
            if (mystack.empty())
            {
                return false;
            }
            else if ((c == ')' && mystack.top() == '(') || (c == '}' && mystack.top() == '{') ||
                     (c == ']' && mystack.top() == '['))
            {
                mystack.pop();
            }
            else
            {
                return false;
            }
        }
    }
    return mystack.empty();
}