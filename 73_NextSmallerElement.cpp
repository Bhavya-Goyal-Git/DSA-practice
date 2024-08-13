#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Problem Link: https://www.naukri.com/code360/problems/next-smaller-element_1112581?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio&leftPanelTabValue=PROBLEM

// Problem : You are given an array 'ARR' of integers of length N. Your task is to find the next smaller element for each of the array elements.
// Next Smaller Element for an array element is the first element to the right of that element which has a value strictly smaller than that element.
// If for any array element the next smaller element does not exist, you should print -1 for that array element.
// For Example: If the given array is [ 2, 3, 1], we need to return [1, 1, -1]. Because for  2, 1 is the Next Smaller element. For 3, 1 is the Next Smaller element and for 1, there is no next smaller element hence the answer for this element is -1.

// Approach : Normal brute force gives a time Complexity of O(n2). We use a stack here to simplify the process. First of all we create a ans vector of same size, to be returned and then a stack, Push the value -1 into the stack as all elements are greater than it and if nothing smaller than them is found, -1 has to be returned. Now very imp! we traverse the given array from back side. (Intutution is if current element is greater than stack's top then ans is stack's top and also push the element into the stack, and if current element is smaller than keep popping elements out of stack until you find something smaller, then keep that as the ans and push current element into the stack), But once we write this, we find the logic can be simplified: Just keep popping elements from the stack until the top is something smaller than current element. Then, mark it in ans vector and also push the current element into the stack. (in this way, stack effectively stores processed data reducing the Tc to O(n))

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n);
    stack<int> mystack;
    mystack.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (mystack.top() >= arr[i])
        {
            mystack.pop();
        }
        ans[i] = mystack.top();
        mystack.push(arr[i]);
    }
    return ans;
}