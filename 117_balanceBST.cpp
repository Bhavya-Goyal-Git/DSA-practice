#include <iostream>
#include <vector>
using namespace std;

// Problem link : https://www.geeksforgeeks.org/problems/normal-bst-to-balanced-bst/1

// Problem : Given a Binary Search Tree, modify the given BST such that it is balanced and has minimum possible height. Return the balanced BST.

// Approach : Traverse the given bst using Inorder and store the inorder traversal into a vector of node pointers. Note that this will be sorted automatically. Now make a recurive function that takes the start index, end index and the vector storing Inorder and generates a bst from it. This function has base case when start>end, and it returns NULL. else: it calculates mid of the array using start and end (this will become root, note that mid value choosing will lead to a balanced bst being made), take out the mid node from array and make left and right calls for it, with index ranges start to mid-1 and mid+1 to end respectively. This build a bst, balanced from the inorder given. Return the recieved node pointer.

struct Node
{
    int data;
    Node *left, *right;
};

class Solution
{
private:
    void getInOrder(Node *root, vector<Node *> &inOrder)
    {
        if (root == NULL)
            return;
        getInOrder(root->left, inOrder);
        inOrder.push_back(root);
        getInOrder(root->right, inOrder);
    }
    Node *buildBSTfromInorder(vector<Node *> &inOrder, int start, int end)
    {
        if (start > end)
            return NULL;
        int mid = start + (end - start) / 2;
        Node *root = inOrder[mid];
        root->left = buildBSTfromInorder(inOrder, start, mid - 1);
        root->right = buildBSTfromInorder(inOrder, mid + 1, end);
        return root;
    }

public:
    // Your are required to complete this function
    // function should return root of the modified BST
    Node *buildBalancedTree(Node *root)
    {
        vector<Node *> inOrder;
        getInOrder(root, inOrder);
        Node *n = buildBSTfromInorder(inOrder, 0, inOrder.size() - 1);
        return n;
    }
};