#include <iostream>
using namespace std;

// Problem Link : https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

// Problem : Given 2 linked list that are numbers (ex 3->2->1 represents 321).Add the 2 numbers and return the resulted linked list in same way. (3->4->5  + 4->5 = 3->9->0)

// Approach : As addition begins from ones digit, we reverse the given lists. Also initialize a carry integer to 0. At each step add the 3, take the last digit and insert it at head of a new list, Update the carry integer to sum/10 (all digits other than assigned last one). Continue until num1 and num2 both reach NULL and carry becomes 0. return the head of new list.

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
    Node *reverselist(Node *head)
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *forward;
        while (curr != NULL)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    void insertAtHead(Node *&head, int data)
    {
        Node *ptr = new Node(data);
        if (head == NULL)
        {
            head = ptr;
            return;
        }
        ptr->next = head;
        head = ptr;
    }

public:
    // Function to add two numbers represented by linked list.
    Node *addTwoLists(struct Node *num1, struct Node *num2)
    {
        num1 = reverselist(num1);
        num2 = reverselist(num2);
        int carry = 0;
        Node *newhead = NULL;
        while (num1 != NULL || num2 != NULL || carry != 0)
        {
            int val1 = 0, val2 = 0;

            if (num1 != NULL)
            {
                val1 = num1->data;
                num1 = num1->next;
            }
            if (num2 != NULL)
            {
                val2 = num2->data;
                num2 = num2->next;
            }

            int sum = val1 + val2 + carry;
            insertAtHead(newhead, sum % 10);
            carry = sum / 10;
        }
        return newhead;
    }
};
