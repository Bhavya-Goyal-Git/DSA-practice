#include <iostream>
#include <vector>
using namespace std;

// QuickSort : Space Complexity : O(1) and Time Complexity : O(nlog(n))
//  If array is already sorted, it leads to a worst case complexity of O(n2)

// Approach : we first decide a pivot element, (here we have used first element of array as pivot) then place the pivot at its appropriate position (all elements smaller than it at left of it and all greater than it at right of it), to do so we use a function (here, sahijagah) This fn can be designed in many ways, but for most efficiency, we have built it on foundations of Dutch national flag algorithm (sorts 0,1,2). Remember, this function also needs to return the index where pivot has been placed. After a pivot has been placed at its position, we apply recursive call to do similar for left and right parts of the pivot, with the base case when start>=end (list has 0 or 1 elements)

int sahijagah(int arr[], int start, int end)
{
    int first = start + 1;
    int myele = start;
    while (first <= end)
    {
        if (arr[first] < arr[myele])
        {
            swap(arr[first], arr[myele]);
            myele = first;
            first++;
        }
        else
        {
            swap(arr[first], arr[end]);
            end--;
        }
    }
    return myele;
}

void quickSort(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int pivotIndex = sahijagah(arr, start, end);
    quickSort(arr, start, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, end);
}

int main()
{
    int arr[] = {4, 1, 2, 3, 5, 6, 7, 8};
    quickSort(arr, 0, 7);
    for (int c : arr)
    {
        cout << c << " ";
    }
    return 0;
}