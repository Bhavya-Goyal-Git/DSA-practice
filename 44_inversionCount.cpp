#include <iostream>
#include <vector>
using namespace std;

// Problem: Given an array, we need to find inversion pairs. Inversion pairs are such that for 2 indices i,j : i<j and arr[i]>arr[j]. That is, left value must be greater.

// Approach: Its easy to think of using a nested for loop, that will have complexity of O(n2). We can do it better by integrating it with merge sort. Just a little change in merge aproach. (Please use a complete temporary array method so that this works). Initialize a count to 0. We have initialized first pointer to start of array and second to mid+1 (they mark starting of 2 sorted arrays resp.) In a temporary array, we keep adding the lesser value. Inside this loop, if arr[right]<arr[left] we have found a pair.. but as the left array is sorted, all such left values will form a pair. therefore we increment count with (mid-left+1). This includes all the pairs. we return this count to original fn. original fn has its own count incremented at each step and then returned!

int merge(int arr[], int start, int end)
{
    int mid = start + (end - start) / 2;
    int *temparray = new int[end - start + 1];
    int left = start;
    int right = mid + 1;
    int mainidx = 0;
    int count = 0;
    while (left <= mid && right <= end)
    {
        if (arr[left] <= arr[right])
        {
            temparray[mainidx++] = arr[left++];
        }
        else
        {
            count += (mid - left + 1);
            temparray[mainidx++] = arr[right++];
        }
    }
    while (left <= mid)
    {
        temparray[mainidx++] = arr[left++];
    }
    while (right <= end)
    {
        temparray[mainidx++] = arr[right++];
    }
    for (int i = start; i <= end; i++)
    {
        arr[i] = temparray[i - start];
    }
    delete[] temparray;
    return count;
}

int mergeSort(int arr[], int start, int end)
{
    int count = 0;
    if (start >= end)
    {
        return count;
    }
    int mid = start + (end - start) / 2;
    // sort left half
    count += mergeSort(arr, start, mid);
    // sort right half
    count += mergeSort(arr, mid + 1, end);
    // merge the results
    count += merge(arr, start, end);
    return count;
}

int main()
{
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    cout << mergeSort(arr, 0, 9);
    return 0;
}