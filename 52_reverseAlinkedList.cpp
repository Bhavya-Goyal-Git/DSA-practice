#include <iostream>
using namespace std;

// Problem Link : https://www.naukri.com/code360/problems/reverse-the-singly-linked-list_799897?source=youtube&campaign=Lovebabbarcodestudio_24thJan&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio_24thJan&leftPanelTabValue=PROBLEM

// Problem : Given a linked list's head, reverse the list in O(n) time and O(1) space

// Approach: ITERATIVE: We make 2 pointers, a previous (initialized to null) and a current (initialized to head) We traverse the list until current becomes null. at each step, we first store the curr->next into another pointer forward to prevent loss of list. Then we point our current to previous (effectively reversing) and then update prev to current and current to forward for next iterations. Note: remember to handle cases of no nodes or 1 node seperately.

// Approach: RECURSIVE [Space O(n)] : The base case is to check if head is null or head's next is null ie list is empty or 1 node, then we simply return the head. Otherwise, we firstly make a recursive call to this function with parameter as (head->next) and store the value returned as newHead, (assuming this fn reverses a linked list and returns its newhead). After it, we make head->next->next = head  i.e. we make the next node point to current node. Then we make the current node point to null, i.e. head->next = null. But we return the newHead returned to us previously. Note that these 2 approaches are working like this because we have to return the new head pointer of the reversed list as the ans.

// Node structure
template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// iterative
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *curr = head;
    LinkedListNode<int> *forward;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

// recursive
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    LinkedListNode<int> *newHead = reverseLinkedList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}