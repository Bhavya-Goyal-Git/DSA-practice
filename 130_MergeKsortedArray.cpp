#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/merge-k-sorted-arrays_975379?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

// Problem : You have been given ‘K’ different arrays, which are sorted individually (in ascending order). You need to merge all the given arrays such that the output array should be sorted in ascending order.

// Approach : We could just combine all arrays into one, and sort it. It would've a complexity of O(nk log(nk)) which is pretty bad. And it also just ignores the fact that arrays given are sorted.
// How about we design a min-heap, push the first elements of all arrays into it. Then when we pop out, we have minimum element, push into the answer vector and then we can add to the heap, the next element of that array, from which the element was that just popped out. To achieve this, we need more information about the data in the heap, we need not only its value, but also which array it belonged to and which position in that array.
// To achieve this, we make a min-heap of custom data type. We make a data-type node which stores actual data, and a row and column number indicating position in arrays. Note that creating min-heap of this custom datatype also requires us to make a custom comparator, with certain pre-defined rules.
// Now the algo is simple, firstly traverse only 1st elements of k given arrays and add corresponding node entry into the heap. Then make a answer vector to return. Now run a loop till the heap is non empty, at each iteration, pop out a entry out of heap (it will be minimum as per comparator), push the data of it into ans vector and then check (using row and column entries) whether there is next item in the array, if yes, make corresponding node and push into the heap. After this, remember to delete the popped out node, free up space in memory. After end of loop, return ans vector.

#include <bits/stdc++.h>
class node
{
public:
    int data, row, column;
    node(int d, int r, int c)
    {
        data = d;
        row = r;
        column = c;
    }
};

struct Compare
{
    bool operator()(node *node1, node *node2)
    {
        return node1->data > node2->data;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    priority_queue<node *, vector<node *>, Compare> pq;
    // pushing first element of all k arrays into the heap
    for (int i = 0; i < k; i++)
    {
        node *n = new node(kArrays[i][0], i, 0);
        pq.push(n);
    }
    vector<int> ans;
    while (!pq.empty())
    {
        node *temp = pq.top();
        pq.pop();
        ans.push_back(temp->data);
        if (temp->column + 1 < kArrays[temp->row].size())
        {
            node *n = new node(kArrays[temp->row][temp->column + 1], temp->row, temp->column + 1);
            pq.push(n);
        }
        delete temp;
    }
    return ans;
}