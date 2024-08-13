#include <iostream>
#include <stack>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/delete-middle-element-from-stack_985246?leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio&leftPanelTabValue=PROBLEM

// Problem : Given a stack, delete its middle elememnt (Size N is given)

// Approach: We calculate the index of element to be deleted and it is N/2 (mid) [This approach uses a counter with 0 initial value (0 indexed) hence N/2 works if we choose a 1 indexed counter we would have to do N/2 + 1]. Now we just have to pop out elements from our stack, and to not lose their track and order, we push them into another stack. When the counter equals mid, we just pop it out and break the loop. Now we pop elements from the utility stack back into the original stack. The trick here is to use the recursion calls as utility stack holding the top element at each recursive call and adding it back as a part of backtracing, this effectively works similiar to using another utility stack.

void solve(stack<int> &inputStack, int count, int mid)
{
    if (count == mid)
    {
        inputStack.pop();
        return;
    }
    int currentelement = inputStack.top();
    inputStack.pop();
    solve(inputStack, count + 1, mid);
    inputStack.push(currentelement);
}

void deleteMiddle(stack<int> &inputStack, int N)
{
    return solve(inputStack, 0, N / 2);
}