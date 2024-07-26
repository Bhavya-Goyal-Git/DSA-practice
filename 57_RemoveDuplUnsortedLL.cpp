#include <iostream>
#include <unordered_set>
using namespace std;

// Problem : Given a UNsorted Linked List, Remove all duplicates.

// Approach : We make a unordered set to remember what elements have been visited. Remember to add data of head node into the set to begin it. We start a temp pointer from beginning upto last node (temp->next!=NULL) and try to insert each element in it, if false is returned that means data already seen, then store next value in seprate pointer(to free it) and point current to ->next->next (removing from chain) then free the removed one. Else, data was different and added to the set, keep going forward and do (temp=temp->next).

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
    // Write your code here
    Node *temp = head;
    unordered_set<int> myset;
    myset.insert(temp->data);
    while (temp->next != NULL)
    {
        if (!myset.insert(temp->next->data).second)
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