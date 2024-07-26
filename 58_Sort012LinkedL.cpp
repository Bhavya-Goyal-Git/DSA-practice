#include <iostream>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/sort-linked-list-of-0s-1s-2s_1071937?leftPanelTab=0%3Fsource%3Dyoutube&campaign=YouTube_Lovebabbar31stJan2021&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_Lovebabbar31stJan2021&leftPanelTabValue=SUBMISSION

// Problem: Given a linked list of 0s 1s and 2s, return the list by sorting it. (return the new head)

// Approach: We could have traversed the list once to count number of 1s 0s 2s and then replaced them by traversing once again. However, we are doing without data replacements. (actual node should shift). To do so, we create 3 dummy linked lists (zerohead, onehead, twohead) all with head node data as -1. We also initialize tail pointers (zerotail onetail twotail to same heads) so that insertion is O(1). What we are doing is, traversing the original list, and inserting 1 or 0 or 2 in the specified linked list at the tail, until we reach null. Now we have 3 linked lists comprising of 0s 1s and 2s respectively. Now we have to do one small check id onehead's next is not NULL. this is beceause we have to point zerotail's next to onehead's next and it must not be null. Other wise we directly connect zerotail->next to twohead->next. (Note that null condition didn't have to be checked for zero and two heads as they will work as per logic!). Assign onetails' next to twohead's next (works even if onehead or two head is empty). Now that all stuff is connected. Point original head to zerohead, and increment by one unit (remember zerohead is actually dummy(-1)). Then we make all dummy pointers null and delete them from memory. Finally, return our head!

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

Node *sortList(Node *head)
{
    // Write your code here.
    Node *zerohead = new Node(-1);
    Node *onehead = new Node(-1);
    Node *twohead = new Node(-1);
    Node *zerotail = zerohead;
    Node *onetail = onehead;
    Node *twotail = twohead;
    Node *temp = head;
    while (temp != NULL)
    {
        Node *forward = temp->next;
        if (temp->data == 0)
        {
            zerotail->next = temp;
            zerotail = temp;
        }
        else if (temp->data == 1)
        {
            onetail->next = temp;
            onetail = temp;
        }
        else
        {
            twotail->next = temp;
            twotail = temp;
        }
        temp->next = NULL;
        temp = forward;
    }
    if (onehead->next != NULL)
    {
        zerotail->next = onehead->next;
    }
    else
    {
        zerotail->next = twohead->next;
    }
    onetail->next = twohead->next;
    head = zerohead;
    head = head->next;
    zerohead->next = NULL;
    onehead->next = NULL;
    twohead->next = NULL;
    delete zerohead;
    delete onehead;
    delete twohead;
    return head;
}