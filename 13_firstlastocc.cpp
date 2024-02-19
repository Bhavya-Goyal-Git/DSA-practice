#include <iostream>
#include <vector>
using namespace std;

// Problem link : https://www.codingninjas.com/studio/problems/first-and-last-position-of-an-element-in-sorted-array_1082549?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&leftPanelTabValue=PROBLEM

// Problem : Find the 1st index and last index of occurence of a given element in a sorted array

// Approach : We use bindary search. Finding left occurence : all inequality cases reamin same as binary search basics, however when out arr[mid]==value then we store that index and update end = mid-1, continuing search in left direction. Similarly, for right occurence, when arr[mid]==value, we store index and update low = mid + 1 to continue search in right direction.

#include <bits/stdc++.h> 

int firstocc(vector<int>& arr, int n, int k)
{
    int low=0,high=n-1,answer=-1;
    int mid = low + (high-low)/2;
    while(low<=high)
    {
        if (arr[mid]==k)
        {
            answer=mid;
            high = mid-1;
        }
        else if (arr[mid]>k)
        {
            high=mid-1;
        }
        else {
            low = mid+1;
        }
        mid = low + (high-low)/2;
    }
    return answer;
}

int lastocc(vector<int>& arr, int n, int k)
{
    int low=0,high=n-1,answer=-1;
    int mid = low + (high-low)/2;
    while(low<=high)
    {
        if (arr[mid]==k)
        {
            answer=mid;
            low = mid+1;
        }
        else if (arr[mid]>k)
        {
            high=mid-1;
        }
        else {
            low = mid+1;
        }
        mid = low + (high-low)/2;
    }
    return answer;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair <int,int> p;
    p.first = firstocc(arr, n, k);
    p.second= lastocc(arr, n, k);
    return p;
}