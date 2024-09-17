#include <iostream>
#include <vector>
using namespace std;

// Problem link : https://www.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1

// Problem : Given 2 arrays representing 2 max-heaps, return a single array representing a max-heap by merging the given 2 heaps.

// Approach : Just make a array containing elements of both given arrays. Heapify the made array. Done and dusted!! time -> O(m+n)

class Solution
{
public:
    void heapify(vector<int> &arr, int size, int index)
    {
        while (index < size - 1)
        {
            int maxIndex = index;
            int leftIndex = 2 * index + 1;
            int rightIndex = 2 * index + 2;
            if (leftIndex < size && arr[leftIndex] > arr[maxIndex])
                maxIndex = leftIndex;
            if (rightIndex < size && arr[rightIndex] > arr[maxIndex])
                maxIndex = rightIndex;

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

    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
    {
        vector<int> ans;
        for (int i : a)
            ans.push_back(i);
        for (int i : b)
            ans.push_back(i);

        int size = m + n;
        for (int i = size / 2; i >= 0; i--)
        {
            heapify(ans, size, i);
        }
        return ans;
    }
};