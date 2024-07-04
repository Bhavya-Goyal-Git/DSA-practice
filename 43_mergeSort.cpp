#include <iostream>
#include <vector>
using namespace std;

// Merge Sort.. Time complexity = O(nlog(n)), Space Complexity = O(n) [for copying array]
// Based on divide and conqurer approach
// We take and array and divide it into 2 parts, sort the 2 parts, then merge the 2 sorted parts. This is done recursively with the base case that start and end indices are same or array has just one element.
// Note: Approach to merge 2 sorted arrays can differ, in below code, it is optimised for using less space.. using the merge 2 sorted array problem solved earlier..

void merge(int arr[], int start, int end)
{
    int mid = start + (end - start) / 2;
    int secondArraylenght = end - mid;
    int *second = new int[secondArraylenght];
    for (int i = 0; i < secondArraylenght; i++)
    {
        second[i] = arr[mid + 1 + i];
    }
    int firstidx = mid;
    int secondidx = secondArraylenght - 1;
    int maininx = end;
    while (firstidx > start - 1 && secondidx > -1)
    {
        if (arr[firstidx] > second[secondidx])
        {
            arr[maininx--] = arr[firstidx--];
        }
        else
        {
            arr[maininx--] = second[secondidx--];
        }
    }
    while (secondidx > -1)
    {
        arr[maininx--] = second[secondidx--];
    }
    delete[] second;
}

void mergeSort(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = start + (end - start) / 2;
    // sort the left half
    mergeSort(arr, start, mid);
    // sort the right half
    mergeSort(arr, mid + 1, end);
    // merge the sorted halves
    merge(arr, start, end);
}

int main()
{

    int arr[] = {-145, 112, 81, 117, -23, -131, -60, 84, 172, 38, 76, 2, -138, -62, -20, 59, 138, -151, 21, 5, 175, 3, -102, 33, 29, -10, -11, -34, 195, 85, -9, 111, 33, -66, -39, 45, 130, -165, 106, 65, -169, 113, 166, 109, -11, 26, 49, 175, -73, 177, -64, 53, -18, -193, -92, -131, 46, -174, -150, 60, 4, 37, -62, -86, 168, -191, -35, -67, 14, 96, -77, -72, -38, -44, -51, -20, 151, -126, 31, -17, 85, -174, 28, -17, -181, -179, 71, 141, 58, -175, -59, 56, 149, 30, -104, -171, -40, -44, 122, 76, -2, 88, -33, -75, 49, 151, 89, -77, -34, -43, 98, 60, -2, -193, -130, -41, -106, -25, -70, 168, 39, 6, 129, -46, 136, -35, -193, 71, 39, 94, 88, -169, -26, -33, -160, 32, 113, 9, -168, 105, 98, 143, 83, 93, -139, -112, 55, -139, 159, -47, -52, 118, 93, 77, 160, 158, -187, 40, -93, -24, 158, 148};
    int count = 0;
    for (int c : arr)
    {
        count++;
    }
    mergeSort(arr, 0, count - 1);
    for (int c : arr)
    {
        cout << c << ", ";
    }
    return 0;
}