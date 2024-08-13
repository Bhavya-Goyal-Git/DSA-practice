#include <iostream>
using namespace std;

// Problem link: https://www.naukri.com/code360/problems/n-stacks-in-an-array_1164271?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio11thfeb&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio11thfeb&leftPanelTabValue=SUBMISSION

// Problem : Given the size of array 'S' and number of stacks 'N', design a data structure to implement N stacks in just one array of size S. push(x,m) pushes x in mth stack or returns false in overflow. pop(m) pops and returns from mth stack or returns -1 in underflow. Stacks are 1 indexed (1<=m)

// Approach: We will make a array arr of size S that stores the elements actually. Also, we need an array of tops of size N (number of stacks) this will store the index of top of each stack, this initially is all -1. We need another array called next of size S, this is doing work of chaining. (this stores at each index the index to previous element, or the next available free space in the arr). This is initialized with 1,2,3,...-1, as free space after 0 index is 1 after 1 is 2 and so on.. till after last is -1. Now, the 2 operations:
// Push operation : Firstly check overflow condition, ie if freespot is -1, return false. Else: Find the index where insertion can be done, index = freespot. Now insert the element at that spot, arr[index] = element. Now the freespot is filled, so update that via next, freespot = next[index], Now the next value of this index must point to previous value of top, so next[index] = top[m-1] (here m is stack number that is 1 indexed). Now update the top of this stack top[m-1] = index. Finally return true;
// Pop operation : Firstly check underflow that is top[m-1] == -1, return -1. Else: Do the reverse process of pushing the element. Firstly get the index to pop out, index = top[m-1]. Now update the top of this stack to previous value that is effective popping out, top[m-1] = next[index]. Within the next array, this index must now be a part of free-space-chain so join it using next[index] = freespot, ie the next of this index is the next available freespot. Now make this index a available freespot, freespot = index. Finally, return the popped element, return arr[index];

class NStack
{
public:
    int *arr;     // array that stores elements
    int *top;     // array storing top of each stack
    int *next;    // array that has links to next elements/free spaces
    int freespot; // stores the next free space available

    NStack(int N, int S)
    {
        this->arr = new int[S];
        this->next = new int[S];
        this->top = new int[N];
        this->freespot = 0;

        // initializing next with 1,2,3,...,-1
        for (int i = 0; i < S; i++)
        {
            (this->next)[i] = i + 1;
        }
        (this->next)[S - 1] = -1;

        // initializing top with -1,-1,-1...
        for (int i = 0; i < N; i++)
        {
            (this->top)[i] = -1;
        }
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        if (freespot == -1)
        {
            return false;
        }
        // find index where to insert
        int index = freespot;
        // insert the element there
        arr[index] = x;
        // update the next free spot
        freespot = next[index];
        // update next by linking to previous top of stack
        next[index] = top[m - 1];
        // update top of given stack
        top[m - 1] = index;
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        if (top[m - 1] == -1)
        {
            return -1;
        }
        // find the index to pop out
        int index = top[m - 1];
        // pop the element (point top back to previous in chain)
        top[m - 1] = next[index];
        // Register the element in free-space-chain
        next[index] = freespot;
        // Make this index as the current free spot
        freespot = index;
        // Return the popped value
        return arr[index];
    }
};