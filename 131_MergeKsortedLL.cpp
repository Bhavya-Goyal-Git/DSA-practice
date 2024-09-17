#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/merge-k-sorted-lists_992772?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

// Problem : Given an array of 'k' sorted linked list heads, merge the sorted linked lists into 1 sorted LL and return its head.

// Approach : Similar to sorting k sorted arrays, we do this one with a min-heap. However we dont need custom data type in here, we can directly create a comparator on node of a linked list based on data variable in it. This works good because once we pop an element we can get next element in same linked list by using next pointer, rest algorithm remains same.

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

struct Compare
{
    bool operator()(Node *left, Node *right)
    {
        return left->data > right->data;
    }
};

Node *mergeKLists(vector<Node *> &listArray)
{
    priority_queue<Node *, vector<Node *>, Compare> pq;
    for (Node *i : listArray)
    {
        pq.push(i);
    }
    Node *newhead = new Node(-1);
    Node *temp = newhead;
    while (!pq.empty())
    {
        Node *top = pq.top();
        pq.pop();
        if (top->next != NULL)
            pq.push(top->next);
        temp->next = top;
        temp = top;
    }
    temp->next = NULL;
    temp = newhead->next;
    newhead->next = NULL;
    delete newhead;
    return temp;
}