#include <iostream>
using namespace std;

// Problem link : https://www.geeksforgeeks.org/problems/flatten-bst-to-sorted-list--111950/0

// Problem : You are given a Binary Search Tree (BST) with n nodes, each node has a distinct value assigned to it. The goal is to flatten the tree such that, the left child of each element points to nothing (NULL), and the right child points to the next element in the sorted list of elements of the BST. You must accomplish this without using any extra storage, except for recursive calls, which are allowed. (O(h) space and O(n) time)

// Approach : We can simply store the inorder of bst in a vector and then iterate over it to solve the problem. But that takes O(n) extra space for the vector. To do in O(h), we need to connect the nodes somehow while recursion only. To do so, we make a dummy node with -1 data. (pointer to a new node to be exact) and we also make another pointer 'prev' to this dummy node. prev = dummy. We are making a recursive function that takes our root, and this prev by reference and does the inorder traversal, while in the N stage for each node, we asssign prev->left to Null and prev->right to current node. and then update prev = current node for further process before making recursive call to right. After this function, dummy pointer points to a dummy node, next to which is head of required linked list and prev pointer points to last element of the list. We make prev's left and right null and then point it to head of LL i.e. at dummy->right, Then we delete dummy node and return prev.

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
private:
    void buildLL(Node *root, Node *&prev)
    {
        if (root == NULL)
            return;
        buildLL(root->left, prev);
        prev->left = NULL;
        prev->right = root;
        prev = root;
        buildLL(root->right, prev);
    }

public:
    Node *flattenBST(Node *root)
    {
        Node *dummy = new Node(-1);
        Node *prev = dummy;
        buildLL(root, prev);
        prev->left = NULL;
        prev->right = NULL;
        prev = dummy->right;
        dummy->right = NULL;
        delete dummy;
        return prev;
    }
};