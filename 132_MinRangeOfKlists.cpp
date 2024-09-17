#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Problem Link : https://www.naukri.com/code360/problems/smallest-range-from-k-sorted-list_1069356?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

// Problem : You are given K lists containing non-negative integers. Each list has a size N and is sorted in non-decreasing order. You need to find the minimum length of a range such that at least one element of each list must be included in that range. Return (endOfRange - beginOfRange +1)

// Approach : We have to make advantage of the fact that lists are in ascending order. We make a priority queue (min-heap) and work with that. But since its arrays, we will have to make a custom class which stores data along with row and column information, also we have to write a custom comparator structure for this custom class. Now we can create a min-heap of this custom class type. The naive idea is to firstly process the first elements of k arrays and get a min value and max value out of them, that will give us a range that can be the answer and we store it in ansStart and ansEnd variables. Now, to reduce the range (that is our task), we can either increase the min-value or decrease the max-value. We can't directly decrease max-value as lists are in ascending order and to decrease we would have to go left. So, we take the next item in the same row as the min-value and then recalculate the mins and maxs of these k values. then check if new range is smaller than previous, if yes update. Do it until any one list has exhausted and then break out of it.
// Here's how we will be doing it really, using the heap. We firstly process first elements of k arrays and push the corresponding node entries into the heap. During this process we also keep track of max and min values. Then initialize the ansStart and End variables with min and max resp. Now we begin the processing of heap, in a while loop. Firstly take out the top and assigns its data to mini value. Then check if the new range is smaller than older one, if yes update ansStart and ENd values. Then check if a new value can be added (is temp->col + 1 < n), if yes, add corresponding node into heap, and also update value of maxi. Else, break out of loop. After the loop, return (ansEnd - ansStart +1). Time comp: O(nk log(k))

class heapNode
{
public:
    int data, row, column;
    heapNode(int d, int r, int c)
    {
        data = d;
        row = r;
        column = c;
    }
};

struct compare
{
    bool operator()(heapNode *left, heapNode *right)
    {
        return left->data > right->data;
    }
};

int kSorted(vector<vector<int>> &a, int k, int n)
{
    priority_queue<heapNode *, vector<heapNode *>, compare> pq;
    int mini = INT_MAX;
    int maxi = INT_MIN;
    // pushing 1st entries into Pqueue
    for (int i = 0; i < k; i++)
    {
        pq.push(new heapNode(a[i][0], i, 0));
        mini = min(mini, a[i][0]);
        maxi = max(maxi, a[i][0]);
    }
    int ansStart = mini, ansEnd = maxi;
    while (!pq.empty())
    {
        heapNode *temp = pq.top();
        pq.pop();
        mini = temp->data;
        if (maxi - mini < ansEnd - ansStart)
        {
            ansStart = mini;
            ansEnd = maxi;
        }
        if (temp->column + 1 < n)
        {
            maxi = max(maxi, a[temp->row][temp->column + 1]);
            pq.push(new heapNode(a[temp->row][temp->column + 1], temp->row, temp->column + 1));
        }
        else
        {
            break;
        }
    }
    return ansEnd - ansStart + 1;
}