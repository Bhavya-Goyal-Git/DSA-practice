#include <iostream>
using namespace std;

// Problem Link : https://www.naukri.com/code360/problems/flatten-a-linked-list_1112655?source=youtube&campaign=YouTube_CodestudioLovebabbar5thfeb&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_CodestudioLovebabbar5thfeb&leftPanelTabValue=PROBLEM

// Problem : You are given a linked list containing 'n' 'head' nodes, where every node in the linked list contains two pointers:
// (1) ‘next’ which points to the next node in the list
// (2) ‘child’ pointer to a linked list where the current node is the head.
// Each of these child linked lists is in sorted order and connected by 'child' pointer. Your task is to flatten this linked such that all nodes appear in a single layer or level in a 'sorted order'.The returned linked list should be in a sorted order. All the elements in this returned linked list are connected by 'child' pointers and 'next' pointers point to null.

// Approach : This is to be done recursively, with the base case that LL has only 1 head node or none remaining, in that case we return the head itself. Else, we break the temp->next link. [Store it in a forward pointer and then make it null to prevent data loss] After that we make recursive call on that forward pointer assuming it returns a head of sorted linked list connected just via child pointers. Now we have 2 linked lists, one with temp and one with forward, so we sent them for a merge two sorted lists function and hence return the newhead. [Remember that these lists are connected with child pointers not next pointers, so use ->child only in merge logic!]

class Node
{
public:
    int data;
    Node *next;
    Node *child;
    Node() : data(0), next(nullptr), child(nullptr) {};
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
};

Node *merge(Node *head1, Node *head2)
{
    Node *curr1, *curr2, *next1;
    if (head1->data <= head2->data)
    {
        curr1 = head1;
        curr2 = head2;
        next1 = head1->child;
    }
    else
    {
        curr1 = head2;
        curr2 = head1;
        next1 = head2->child;
    }
    Node *newhead = curr1;
    while (next1 != NULL && curr2 != NULL)
    {
        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data))
        {
            Node *next2 = curr2->child;
            curr1->child = curr2;
            curr2->child = next1;
            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            curr1 = next1;
            next1 = next1->child;
        }
    }
    if (next1 == NULL && curr2 != NULL)
    {
        curr1->child = curr2;
    }
    return newhead;
}
Node *flattenLinkedList(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *temp = head;
    Node *forward = temp->next;
    temp->next = NULL;
    forward = flattenLinkedList(forward);
    return merge(temp, forward);
}