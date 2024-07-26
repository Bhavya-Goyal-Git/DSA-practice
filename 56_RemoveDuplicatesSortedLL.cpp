#include <iostream>
using namespace std;

// Problem : Given a sorted Linked List, Remove all duplicates.

// Approach : We start a temp pointer from beginning upto last node (temp->next!=NULL) and check if data of current element is equal to data of next, if yes, store next in seprate pointer(to free it) and point current to ->next->next (removing from chain) then free the removed one. Else, if data is different, keep going forward. (temp=temp->next)

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

Node *removeDuplicates(Node *head)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->data == temp->data)
        {
            Node *tofree = temp->next;
            temp->next = temp->next->next;
            delete tofree;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}