#include <iostream>
using namespace std;

// Problem Link : https://www.naukri.com/code360/problems/clone-a-linked-list-with-random-pointers_983604?leftPanelTabValue=PROBLEM

// Problem : You are given a linked list containing 'n' nodes, where every node in the linked list contains two pointers:
// (1) ‘next’ which points to the next node in the list
// (2) ‘random’ which points to a random node in the list or 'null'.
// Your task is to create a 'deep copy' of the given linked list and return its head.
// Try doing in O(n) time and O(1) space

// Approach : A simple approach with O(n) space could have been : TO make a new list with nexts intact and at each step store the mapping of {oldnode pointer: newnode pointer} in a unordered map. Then iterate the lists, and set every newnode->random to mapping[oldnode->random]. But we have to do in O(1) space, So we need to figure out how to store this new list in such a way that its elements can be accessed through old lists elements.
// So what we do instead is, make this new list with nexts intact. then set the next of all olds to corresponding new element and new element next to olds next. (These 2 steps are basically creaing a criss cross structure which when visualised it is just the original list doubled, i.e. each element is present twice.. so what we actually do is, double up our given list by inserting same data after each node)

// Now that list is doubled. We traverse it to set the random pointers. temp->next->random = temp->random->next is the statement which does it. I.e. newly created Node ka Random equals old node ka random ka next (effectively what newer random should be), however there is a catch, random of temp could be null, so before assigning, check that. At each step increment temp twice (we have to traverse the original list only)

// Now that pointers are set up, we must divide the mess into 2 parts, the original list back and the cloned list. We take 2 temp pointers, one to head and one to head->next (clonehead). At each step assign temp->next to clonetemp ->next and then temp to temp->next. Similarly, clonetemp->next to temp->next and clonetemp to clonetemp->next. this will work fine until both our temps are at last nodes of respective lists. Then assigning of clonetemp to temp->next will break. So it is enclosed in a if block. At end, lists are seprated and we return the head of cloned list i.e. clonehead!

class Node
{
public:
    int data;
    Node *next;
    Node *random;
    Node() : data(0), next(nullptr), random(nullptr) {};
    Node(int x) : data(x), next(nullptr), random(nullptr) {}
    Node(int x, Node *next, Node *random) : data(x), next(next), random(random) {}
};

Node *cloneLL(Node *head)
{
    // doubling our LL
    Node *temp = head;
    while (temp != NULL)
    {
        Node *newnode = new Node(temp->data);
        newnode->next = temp->next;
        temp->next = newnode;
        temp = newnode->next;
    }
    // Setting up random pointers
    temp = head;
    while (temp != NULL)
    {
        temp->next->random = temp->random ? temp->random->next : temp->random;
        temp = temp->next->next;
    }
    // Breaking this LL into 2 copies.
    temp = head;
    Node *clonehead = head->next;
    Node *clonetemp = clonehead;
    while (temp != NULL && clonetemp != NULL)
    {
        temp->next = clonetemp->next;
        temp = temp->next;
        if (temp != NULL)
        {
            clonetemp->next = temp->next;
        }
        clonetemp = clonetemp->next;
    }
    return clonehead;
}