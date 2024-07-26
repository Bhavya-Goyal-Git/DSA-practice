#include <iostream>
using namespace std;

// Problem Link : https://www.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

// Problem : Given a linked list of integers, return true if it is a palindrome. Do in O(1) space.

// Approach : We first reach the middle element of linked list (use slow/fast approach with fast as head->next). Then we reverse the list ahead of middle element. Then compare list from beginning with reversed list from the mid->next. Before returning true, we can remove the destruction we did by reversing the list ahead of mid again.

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
private:
    Node *findmid(Node *head)
    {
        Node *slow = head;
        Node *fast = head->next;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    Node *reverselist(Node *head)
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *nxt;
        while (curr != NULL)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }

public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        // Edge cases
        if (head == NULL || head->next == NULL)
        {
            return true;
        }
        // finding middle of linked list
        Node *middle = findmid(head);
        // reversing the list ahead of middle
        Node *temp = middle->next;
        middle->next = reverselist(temp);
        // Now compare list from start to list from middle
        Node *head1 = head;
        temp = middle->next;
        while (temp != NULL)
        {
            if (head1->data != temp->data)
            {
                return false;
            }
            head1 = head1->next;
            temp = temp->next;
        }
        // Optional (Reversing the change in input list)
        middle->next = reverselist(middle->next);
        return true;
    }
};
