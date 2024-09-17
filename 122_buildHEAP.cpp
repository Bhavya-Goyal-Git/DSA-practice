#include <iostream>
#include <vector>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/build-min-heap_1171167?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

// Problem : Given an array, Heapify it to make it represent a Min-Heap. (This is similar to building a heap from given array). Note that input array is 0 indexed.

// Approach : We know in a 0 index array representing a heap, leaf nodes lie between n/2 to n-1 index, where n is size of the array. We dont process these. We begin processing from n/2 -1 th index and process will index>=0 (remember to include 0). We are processing from backwards, because it makes the algo O(n) surprisingly..
// We run a loop as per given above and call a function 'heapify' that heapifies the given index (places it at correct place in its associated subtree). This function calculates left child index and right child index for a node and compares the smaller one out of them, then swaps the value and updates value of index to continue for next iteration, if none is smaller we return, else the loop runs while index is < size-1 [if index = size-1 then index has become the last element of heap and we cannot go any further]

void heapify(vector<int> &arr, int size, int index)
{
    while (index < size - 1)
    {
        int minIndex = index;
        int leftChildIndex = 2 * index + 1;
        int rightChildIndex = 2 * index + 2;

        if (leftChildIndex < size && arr[leftChildIndex] < arr[minIndex])
        {
            minIndex = leftChildIndex;
        }
        if (rightChildIndex < size && arr[rightChildIndex] < arr[minIndex])
        {
            minIndex = rightChildIndex;
        }

        if (minIndex != index)
        {
            swap(arr[minIndex], arr[index]);
            index = minIndex;
        }
        else
        {
            return;
        }
    }
}

vector<int> buildMinHeap(vector<int> &arr)
{
    int size = arr.size();
    // begin processing from backwards, dont process leaf nodes..
    for (int i = size / 2; i >= 0; i--)
    {
        heapify(arr, size, i);
    }
    return arr;
}
