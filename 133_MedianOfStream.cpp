#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Problem Link : https://www.naukri.com/code360/problems/median-in-a-stream_975268?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

// Problem : Given that integers are read from a data stream. Your task is to find the median of the elements read so far. Return a vector of ints (median upto 1, upto 2, and so on upto n elements).

// Approach : Since it is a running stream, suppose we have a previous result, and if i bring a new element, i want answer as quick as possible. If i were to sort it everytime, complexity would go (n2 log(n)). Therefore we think of another way to reduce that to O(n log(n)).
// We suppose the array to be sorted, then given a median (mid-value), the left and right parts can be thought of as a max-heap and a min-heap respectively. Naive approach is to just be able to sort the incoming element into 1 out of 2 parts either greater than median or lesser than it, and then get required median value.
// We make a variable median (passed as ref), a min-heap and a max-heap. These heaps will divide the array (processed until now) into 2 halves. If there are even elements both heaps will have equal, say (n,n) elements. If odd, there may be (n-1,n) or (n,n-1) elements. Note that difference between sizes of heaps therefore is atmost 1, and if by any chance it is growing over that, we need to prevent it. So we make a function with these parameters and make a call with each element of incoming stream. We firstly check size comparison of both heaps and then proceed :
// if sizes are equal, then push the element where it belongs as per >median or <median and update median to heap.top() of that heap, into which you pushed the element.
// if max-heap is bigger (n,n-1). (left one is bigger).. Then if element needs to be pushed into left one too (ele < median), then it creates a disbalance, so we first push top of left into right, making elements n-1,n and then push safely to left and update median to average of tops (as elements after pushing is n,n). ELSE, element needs to be pushed into right, we can do it safely. this makes sizes n,n and we can update median to average of the two tops.
// if min-heap is bigger (n-1,n) (right one is bigger).. This case is exact opposite to previous one.
// The value of median variable after each function call has the median of stream, uptil processed.

void getMedian(int element, priority_queue<int> &maxHeap, priority_queue<int, vector<int>, greater<int>> &minHeap, int &median)
{
    if (maxHeap.size() == minHeap.size())
    { // n and n
        if (element < median)
        {
            maxHeap.push(element);
            median = maxHeap.top();
        }
        else
        { // element > median
            minHeap.push(element);
            median = minHeap.top();
        }
    }
    else if (maxHeap.size() > minHeap.size())
    { // n and n-1
        if (element < median)
        { // size would disbalance
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            // now sizes are n-1 and n
            maxHeap.push(element); // now n and n
            median = (minHeap.top() + maxHeap.top()) / 2;
        }
        else
        {                          // element > median
            minHeap.push(element); // size after this is n and n
            median = (minHeap.top() + maxHeap.top()) / 2;
        }
    }
    else
    { // maxHeap.size() < minHeap.size() // n-1 and n
        if (element < median)
        {
            maxHeap.push(element); // size after this is n and n
            median = (minHeap.top() + maxHeap.top()) / 2;
        }
        else
        { // element > median
            maxHeap.push(minHeap.top());
            minHeap.pop();
            // now sizes are n and n-1
            minHeap.push(element); // now n and n
            median = (minHeap.top() + maxHeap.top()) / 2;
        }
    }
}

vector<int> findMedian(vector<int> &arr, int n)
{
    vector<int> ans;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int median = -1;
    for (int i = 0; i < n; i++)
    {
        getMedian(arr[i], maxHeap, minHeap, median);
        ans.push_back(median);
    }
    return ans;
}