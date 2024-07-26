#include <iostream>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/middle-of-linked-list_973250?source=youtube&campaign=Lovebabbarcodestudio_24thJan&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio_24thJan&leftPanelTabValue=SUBMISSION

// Problem: Given the head of a linked list, return the pointer to its middle node. If the number of nodes are even, the middle node is the one farther away from the head.

// Approach : We make 2 pointer, a slow one and a fast one, both initialized to head at the beginning. The fast pointer takes 2 step ahead at once (fast = fast->next->next) while the slow pointer takes 1 step per iteration ie (slow = slow->next). Due to this, when fast pointer reaches the end (==NULL in even case and fast->next == Null in odd case), the slow pointer will be at the mid. We return the slow pointer.

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

Node *findMiddle(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
