#include <iostream>
using namespace std;

// HEAP is a non linear Data structure. It is a Complete Binary Tree (A tree in which each level has to be fully filled before moving to next level and insertion in a level always begins from left end similar to level order traveral) with special heap properties. It can be of 2 types, max heap and min heap.
// In our implementation of heap, we are represting it using an array. If we assign numbers from 1 to the root and so on as per level order way to the tree, the order we obtain can be stored in an array with assigned numbers as indices (yes the 0 index is to set empty). A benifit of this numbering is that for any index 'i' (or for any node) ,its left child is present at 2*i th index and right child at 2*i +1 th index. Also, similarly, the parent of any node is present at i/2 th index.
// Note that if 0 based indexing is done, left child is at 2i+1 and right at 2i+2 and parent at (i-1)/2
// The last most unfilled index shall then represent the position of insertion.
// To implement it with an array, we will also need a size variable, that tracks current number of elements in heap. At time of insertion, we first increment this and then add element in array at this position.

// INSERTION ALGO : after element is placed at end of array, we repetitively calculate its parent index (i/2) and compare the element with its parent.. this loop runs until index > 1 because if index turns 1, it is root of heap. if element is greater than parent, we swap them and make index = parent (parent is index).. else, we break out of the loop.

// Given a array of n elements, representing a heap, Leaf nodes always occupy indices from n/2+1 to n (1 based indexing) and from n/2 to n-1 (in 0 based indexing)

// Heapifying is the process of taking the given index and placing the node at it, at its correct position in the subtree the element is associated with.

class maxHeap
{
    int arr[100];
    int size;

public:
    maxHeap()
    {
        this->size = 0;
        (this->arr)[0] = -1;
    }
    void insert(int data)
    {
        // insert at last index
        (this->arr)[++size] = data;
        int index = size; // find out where insertion has been done
        // make swaps until element reaches correct position
        while (index > 1)
        {
            int parentIndex = index / 2;
            if (arr[index] > arr[parentIndex])
            {
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            else
            {
                return;
            }
        }
    }
    void printHeap()
    {
        cout << "\nPrinting Heap : \n";
        for (int i = 1; i <= size; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }

    void remove()
    {
        if (size == 0)
        {
            cout << "\nEMPTY HEAP, DELETION NOT POSSIBLE!\n";
            return;
        }
        // swap the last and first element
        arr[1] = arr[size];
        // remove the last element
        size--;
        // heapify the heap
        int index = 1;
        while (index < size)
        {
            int leftChildIndex = 2 * index;
            int rightChildIndex = 2 * index + 1;
            int maxIndex = index;
            if (leftChildIndex <= size && arr[leftChildIndex] > arr[maxIndex])
            {
                maxIndex = leftChildIndex;
            }
            if (rightChildIndex <= size && arr[rightChildIndex] > arr[maxIndex])
            {
                maxIndex = rightChildIndex;
            }
            if (maxIndex != index)
            {
                swap(arr[index], arr[maxIndex]);
                index = maxIndex;
            }
            else
                return;
        }
    }
};

int main()
{
    maxHeap m;
    m.insert(70);
    m.insert(50);
    m.insert(60);
    m.insert(30);
    m.insert(20);
    m.insert(55);
    m.insert(40);
    m.printHeap();
    m.remove();
    m.printHeap();
    m.remove();
    m.printHeap();
    m.remove();
    m.printHeap();
    m.remove();
    m.printHeap();
    m.remove();
    m.printHeap();
    m.remove();
    m.printHeap();
    m.remove();
    m.printHeap();

    return 0;
}