#include <iostream>
#include <queue>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/k-th-largest-sum-contiguous-subarray_920398?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

// Problem : Given an array, and a integer k, return the kth largest subarray sum for the array. (A subarray is sequence of continious elements of an array, out of all such possible subarrays, each will be having some sum, return the kth largest of those sums)

// Approach : There is no shortcut to getting all subarray sums, for that we will have to use a double for loop. Bruteforce way is to store all such sums in a array, sort the array and return the (size-k)th index from the back. But this has O(n2 log(n)) time and O(n2) space comp. As order of n2 elements will be in sums array. We aim to reduce these using a heap.
// Note that for kth smallest value, we used a max-heap and here for kth largest value, we use a min-heap. We make a min heap and double for loop for the sums, at the time we have got a sum, we check if heap size is less than k, if yes normally push into heap the sum else: we check if current sum is larger than heap.top(), if yes then we pop one, and push this sum into the heap. After this traversal heap.top() contains the kth largest subarray sum.
// This works as we are storing the k-largest values into our heap, and its a min heap, so kth largest will be at the top. It reduces the space to O(k) and time to O(n2 log(k))

int getKthLargest(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (pq.size() < k)
            {
                pq.push(sum);
            }
            else
            {
                if (sum > pq.top())
                {
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }
    return pq.top();
}