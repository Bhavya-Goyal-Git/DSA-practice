#include <iostream>
#include <stack>
using namespace std;

// Problem Link : https://www.naukri.com/code360/problems/redundant-brackets_975473?leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio&leftPanelTabValue=PROBLEM

// Problem : Given a string expression, return true/false if the expression contains needless or redundant brackets for ex ((a+b)), (c) are needless brackets.

// Approach : This is similar to parenthesis matching. The only new logic is that, a pair of brackets are redundant or needless in an expression if no new operation is performed within them. Ie an operator must be present between two brackers (apart from variable) to make them needy. Now how we solve it: We make a stack, and traverse the expression, we will push the character into stack if its a opening bracket '(' or any operator + - * / And if the traeversal character is a close bracket, then we check: if the top of stack has the opening bracket, means no operator was present between the brackets, and we return true, else we pop out all the elements (operators in the stack) until we reach its counter half and then pop it too, as this pair had operators b/w it it was a needy pair. At the end of for loop, we return false as no pair was caught.

bool findRedundantBrackets(string &s)
{
    stack<char> mystack;
    for (char c : s)
    {
        if (c == '(' || c == '+' || c == '-' || c == '*' || c == '/')
        {
            mystack.push(c);
        }
        else if (c == ')')
        {
            if (mystack.top() == '(')
            {
                return true;
            }
            else
            {
                while (mystack.top() != '(')
                {
                    mystack.pop();
                }
                mystack.pop();
            }
        }
    }
    return false;
}