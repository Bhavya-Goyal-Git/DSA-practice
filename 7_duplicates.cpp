#include <iostream>
using namespace std;

// Problem link : https://www.codingninjas.com/studio/problems/duplicate-in-array_893397?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1&leftPanelTabValue=SUBMISSION

// Problem : An array of n elements given. Numbers from 1 to n-1 appear atleast once. One number appears twice, find it.

//Approach :  XOR all array elements together with 0 to n-1 numbers. All numbers will become twice and cancel each other, however repeating element becomes thrice and sustains.

int duplicates(int arr[], int size)
{
    int result=0;
    for(int i=0;i<size;i++)
    {
        result = result^arr[i]^i;
    }
    return result;
}
