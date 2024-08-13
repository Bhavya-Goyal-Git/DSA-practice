#include <iostream>
#include <stack>
using namespace std;

// Problem Link: https://www.naukri.com/code360/problems/sort-a-stack_985275?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio&leftPanelTabValue=PROBLEM

// Problem : Given a stack, sort it using recursion (top element must be greatest element)

// Approach : The recursive function ofcourse has the base case when stack is empty, we plainly return. Else, we take out the top element place it temporarily in recurive scope, pop from stack and make a recursive call. Now assuming a sorted stack is returned, we just have to place the element we extracted in its correct place. We off load this to another function insertAtPos, which inserts an element in a sorted stack at its right position. THis function is itself a recursive function checks if stack is empty or element we have to insert is greater or equal to the top element, if yes then inserts it, other wise does the same recursive logic of taking out top in a temp, popping it out and make a forward recursive call, push the element back for backtracking.

void insertAtPos(stack<int> &stack, int num)
{
    if (stack.empty() || num >= stack.top())
    {
        stack.push(num);
        return;
    }
    int current = stack.top();
    stack.pop();
    insertAtPos(stack, num);
    stack.push(current); // backtrack
}

void sortStack(stack<int> &stack)
{
    // Write your code here
    if (stack.empty())
    {
        return;
    }
    int current = stack.top();
    stack.pop();
    sortStack(stack);
    insertAtPos(stack, current); // backtrack
}