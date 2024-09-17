#include <iostream>
#include <queue>
using namespace std;

// Problem link : https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

// Problem : Given a integer array (unsorted) and a integer k, return the kth smallest element in the array.

// Approach : Simplest approach is to sort the array in place, and return the (k-1)th index. That takes O(1) space but O(n logn) time due to sorting. We hope to bring time down, at sacrifice of a little space.
// We make a max-heap (priority queue) of size k. We fill it up with first k elements of the array. Now we go through rest elements in the array, and we encounter an element smaller than heap.top(), we pop out from heap, and push this element into the heap. After these traversals, we have a max-heap of k smallest elements in our array. And where will we kth smallest element then? right! at the top of this heap. we return heap.top(). This approach requires extra space of O(k) for the heap, but reduces time complexity to O(n log(k))

class Solution
{
public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k)
    {
        priority_queue<int> pq;
        int n = arr.size();

        for (int i = 0; i < k; i++)
        {
            pq.push(arr[i]);
        }
        for (int i = k; i < n; i++)
        {
            if (arr[i] < pq.top())
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        return pq.top();
    }
};

// Even better approach here: Heapify the given array into a min-heap, then perform k-1 deletions (removals from top) and then simply return the first element. This takes O(1) space and O(k log(n)) time that is much much better than nlog(k)