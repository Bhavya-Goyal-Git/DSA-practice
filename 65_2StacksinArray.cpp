#include <iostream>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/two-stacks_983634?leftPanelTab=0%3Fsource%3Dyoutube&campaign=YouTube_CodestudioLovebabbar5thfeb&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_CodestudioLovebabbar5thfeb&leftPanelTabValue=PROBLEM

// Problem : Implement 2 stack Data structures using just one array. In case of push overflow, return nothing do nothing, in case of pop underflow, return -1. Total size of array is given in constructor

// Approach : We could give half half size to each stack, but this is not good memory wise. We implement it in such a way that first stack begins at -1 index and 2nd stack begins at size of array (from the last) [One from left size, one from right]. Rest operations are easy to write!

class TwoStack
{

public:
    int *arr;
    int top1, top2, size;
    // Initialize TwoStack.
    TwoStack(int s)
    {
        this->arr = new int[s];
        this->top1 = -1;
        this->top2 = s;
        this->size = s;
    }

    // Push in stack 1.
    void push1(int num)
    {
        if (this->top1 + 1 == this->top2)
        {
            return; // overflow
        }
        (this->top1)++;
        this->arr[this->top1] = num;
    }

    // Push in stack 2.
    void push2(int num)
    {
        if (this->top2 - 1 == this->top1)
        {
            return; // overflow
        }
        (this->top2)--;
        this->arr[this->top2] = num;
    }

    // Pop from stack 1 and return popped element.
    int pop1()
    {
        if (this->top1 == -1)
        {
            return -1;
        }
        return this->arr[(this->top1)--];
    }

    // Pop from stack 2 and return popped element.
    int pop2()
    {
        if (this->top2 == this->size)
        {
            return -1;
        }
        return this->arr[(this->top2)++];
    }
};
