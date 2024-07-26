#include <iostream>
using namespace std;

// Problem Link : https://www.naukri.com/code360/problems/reverse-list-in-k-groups_983644?leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbar_codestudio_26thjan&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar_codestudio_26thjan&leftPanelTabValue=SUBMISSION

// Problem : Given the head of a linked list, reverse it in groups of k (given number) and return the new head of altered list. Note: if k is 3 and in the last subgroup only 2 elements are present, do not reverse that group, leave it as it is. For example, if the linked list is 1->2->3->4->5, and 'k' is 3, we have to reverse the first three elements, and leave the last two elements unchanged. Thus, the final linked list being 3->2->1->4->5.

// Approach : We do it recursively. Our approach is to make a function that takes a LL, reverses it and returns the new head. The base case is when head is null or head's next is null. Then we return the head itself (remember the function's return type is Node*) Now, firstly we make a temp pointer to current head and increment a count variable to k. if it reaches k, that means out subgroup has enough elements to be reversed (at the last subgroup, this would fail if less elements are present and then we simply return the recieved head. (this is in the else block)). Now, we reverse the current subgroup by counting back from k and using normal reversing technique. Note that after this process, the pointer prev is pointing at the node which should become the new head, and the older head is pointing at the last node of currently reversed group. To connect this to more reversed subgroups we make assign (last node's next) i.e. head->next = recursiveCall(curr,k). At the end we return pointer prev, as it is the newhead.

class Node
{
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

Node *kReverse(Node *head, int k)
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }
    int count = 0;
    Node *temp = head;
    while (count < k && temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    if (count == k)
    {
        Node *prev = NULL, *curr = head, *forward;
        while (count != 0 && curr != NULL)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            count--;
        }
        head->next = kReverse(curr, k);
        return prev;
    }
    else
    {
        return head;
    }
}