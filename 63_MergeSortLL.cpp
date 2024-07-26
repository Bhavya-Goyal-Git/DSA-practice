#include <iostream>
using namespace std;

// Problem LInk : https://www.naukri.com/code360/problems/mergesort-linked-list_630514?leftPanelTab=0%3Fsource%3Dyoutube&campaign=YouTube_CodestudioLovebabbar5thfeb&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_CodestudioLovebabbar5thfeb&leftPanelTabValue=PROBLEM

// Problem : MergeSort a Linked list.

// Approach : This is a recursive algo. Base case is when LL has 0 or one element, then we return the head itself. Else: (1) Find mid of linked list using slow/fast. (2) Break the LL into 2 halves at the mid point (set firsthalf->next = NULL) and make recursive sort calls on both these halves (store result in node pointers) Now, we have 2 sorted lists that we have to merge.. Merge them using the merge 2 sorted LL Ques done before. Return the new head!

class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

node *merge(node *head1, node *head2)
{
    node *curr1, *curr2, *next1;
    if (head1->data <= head2->data)
    {
        curr1 = head1;
        curr2 = head2;
        next1 = head1->next;
    }
    else
    {
        curr1 = head2;
        curr2 = head1;
        next1 = head2->next;
    }
    node *newhead = curr1;
    while (next1 != NULL && curr2 != NULL)
    {
        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data))
        {
            node *next2 = curr2->next;
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
    return newhead;
}

node *mergeSort(node *head)
{
    // Write your code here.
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    // finding mid
    node *slow = head;
    node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    // breaking into 2
    node *otherhalf = slow->next;
    slow->next = NULL;
    // recursive calls
    node *firstsortedhalf = mergeSort(head);
    node *secondsortedhalf = mergeSort(otherhalf);
    // merge 2 sorted lists and return the head
    return merge(firstsortedhalf, secondsortedhalf);
}