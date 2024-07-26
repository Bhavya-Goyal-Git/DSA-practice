#include <iostream>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/interview-shuriken-42-detect-and-remove-loop_241049?leftPanelTab=0%3Fsource%3Dyoutube&campaign=YouTube_codestudio_lovebabbar28thjan&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_codestudio_lovebabbar28thjan&leftPanelTabValue=SUBMISSION

// Problem: Given a linked list's head, find out if it has any loops, if yes, detect the loop and remove it. This is actually a combination of 3 questions, 1st: Detecting if there is a loop in linked list, 2nd: Find the node which is the start of the loop in the linked list, 3rd: Remove the loop from linked list i.e. make it linear

// Approach : First of all, to detect if there is a cycle in the LL, we use Floyd's cycle detection algorithm. For that we make a slow and a fast pointer, increment slow once and fast twice per iteration. loop runs until fast is not null. if at any point fast==slow, this means loop is present. Currently pointers are at meeting point of the loop. (or else if fast became null, there is no loop in LL). Secondly, now we are finding the node that is beginning of the loop. To do this we make our slow = head again and keep fast at the meeting place. then we increment both one step at a time until fast=slow. This can be shown mathematically, that they meet at starting point of the loop. Last thing is to remove the loop from LL. we take a temporary pointer from starting node and increment it until its next becomes the starting node itself, then simply do temp->next=NULL.

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

Node *removeLoop(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    // detecting if there is a loop
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        if (slow == fast)
        {
            break; // cycle present
        }
    }
    if (fast == NULL)
    {
        return head; // cycle absent
    }
    // now we have detected a cycle and are at meeting point. Lets reach the loop start node
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    Node *temp = slow;
    while (temp->next != slow)
    {
        temp = temp->next;
    }
    // now temp is at 1 block prior to loop start, we can make it null.
    temp->next = NULL;
    return head;
}