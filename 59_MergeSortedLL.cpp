#include <iostream>
using namespace std;

// Problem link: https://www.naukri.com/code360/problems/merge-two-sorted-linked-lists_800332?leftPanelTab=0%3Fsource%3Dyoutube&campaign=YouTube_Lovebabbar31stJan2021&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_Lovebabbar31stJan2021&leftPanelTabValue=SUBMISSION

// Problem : Given 2 sorted linked lists, merge them into one. Return the head of new LL formed.

// Approach : We are going to first decide the list the will be merged into, and the list that is going to be destroyed. We compare the first elements of both lists, whoever is smaller, will be merged into and other shall be destoyed (curr1 and curr2 resp). We make a pointer head1, same as curr1 to be returned at the last. Also make a pointer next1 (curr1->next) to make it easy to do comparisons. Now enter a while loop (until next1 or curr2 becomes NULL). We check if element at curr2 can be inserted between curr1 and next1, if yes, first we store next2 (curr2->next) to ensure no data loss. then insert it between curr1 and next1, and increment our curr1 pointer (make it curr2 simply), and give curr2 back to next2 (curr2 = next2). ELse, we simply increment both curr1 and next1. At the end, remember if 2nd list is exhausted, we dont have to do anything. but if first is exhausted and second is not then we simply do curr1->next = curr2. Return the previously assigned head1!

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        next = NULL;
        this->data = data;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

Node<int> *sortTwoLists(Node<int> *first, Node<int> *second)
{
    if (first == NULL)
    {
        return second;
    }
    if (second == NULL)
    {
        return first;
    }
    Node<int> *curr1;
    Node<int> *curr2;
    if (first->data <= second->data)
    {
        curr1 = first;
        curr2 = second;
    }
    else
    {
        curr1 = second;
        curr2 = first;
    }
    Node<int> *next1 = curr1->next;
    Node<int> *head1 = curr1;
    while ((next1 != NULL) && (curr2 != NULL))
    {
        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data))
        {
            Node<int> *next2 = curr2->next;
            curr1->next = curr2;
            curr2->next = next1;
            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            curr1 = next1;
            next1 = next1->next;
        }
    }
    if (next1 == NULL && curr2 != NULL)
    {
        curr1->next = curr2;
    }
    return head1;
}