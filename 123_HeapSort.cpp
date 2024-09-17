#include <iostream>
using namespace std;

// Given an integer array, sort it using heap sort.

// Heap Sort Algo O(n logn) : This algo works on the fact that the first element of max-heap is always the largest element. To simplify, if we are given a max-heap and we keep on removing elements from it, we will recieve them in descending order due to properties of heap, as when we remove, we place the last element in place of first one and then heapify the 0th index.. This algo is precisely that, with a little twist.
// We rather than kicking out the first index, swap it with last one, swap(arr[0],arr[last]) this places the largest element in the heap at end of array. Now we reduce the size of array by last--; Then we heapify the 0th position (from where we deleted the first index) and we send the reduced size to this method. This is done until reduced size becomes 0. The array is sorted in ascending order!
// In simple words : Delete first element (replace/swap it with last one), reduce size of heap, heapify the first position.. (do this until size of heap goes 0)

// takes a index to correct position in its subtree (heapifies it)
void heapify(int arr[], int size, int index)
{
    while (index < size - 1)
    {
        int maxIndex = index;
        int leftChildIndex = 2 * index + 1;
        int rightChildIndex = 2 * index + 2;
        if (leftChildIndex < size && arr[leftChildIndex] > arr[maxIndex])
        {
            maxIndex = leftChildIndex;
        }
        if (rightChildIndex < size && arr[rightChildIndex] > arr[maxIndex])
        {
            maxIndex = rightChildIndex;
        }
        if (maxIndex != index)
        {
            swap(arr[index], arr[maxIndex]);
            index = maxIndex;
        }
        else
        {
            return;
        }
    }
}

// heap sorts the given heapified array (max heap must be input), returns array sorted in ascending order
void heapSort(int arr[], int size)
{
    int lastIndex = size - 1;
    while (lastIndex > 0)
    {
        swap(arr[0], arr[lastIndex]);
        lastIndex--;
        heapify(arr, lastIndex + 1, 0);
    }
}

int main()
{
    int arr[100] = {35, -21, 24, -17, -6, -42, -46, 16, -16, -15, 27, 47, 22, -35, 34, 28, 35, -18, 3, -44, 18, 10, 32, -44, 34, -2, 14, -9, -29, 32, 50, 3, 39, 32, 38, -27, 36, -6, 50, -23, -12, 5, -50, 29, 36, -18, -25, -46, -17, 31, -30, -5, 16, -32, 47, 47, 47, -27, 35, -31, -38, 30, -36, -14, -42, -40, -15, -21, -8, -17, -50, -3, -2, -22, 38, -43, 30, -21, 4, 37, -49, 21, 16, 5, 44, 7, 22, -45, 14, 36, 13, 47, -29, 7, 1, -48, 11, 35, -10, 11};

    int n = 100; // size of array

    // we will first heapify the array into a max-heap (0 based indexing) this takes O(n)
    for (int i = n / 2; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // heap sort can now be applied, it applies only to heaps, so we had to heapify the array first.
    heapSort(arr, n);
    // printing result
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << "\n";
}