#include <iostream>
using namespace std;

// Problem link : https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1

// Problem : Given a binary tree, return whether its a max-heap or not.

// Approach : To verify if a given tree is heap, we need to verify 2 things, if tree is CBT (complete binary tree) and then it must follow max-order (every child node must be smaller than parent).
// To verify if its CBT, we need firstly number of nodes in a tree, we make a simple recursive function that does that. Now we make a recursive function that takes root node, an integer index, the total number of nodes we counted are in the tree. We know when heaps are indexed (0 here), left child is at 2i+1 and right at 2i+2, but if a node exists in the tree and its index is greater than or equal to number of nodes present, it indicates tree is not CBT. the function has base case root==null then true, else: node exists and we check index>=count if yes, return false. else make a call to left and right part with index updated to 2i+1 and 2i+2 resp.
// To verify its Max-order, we follow a simple limiting method, like one used to verify BST. we send root and INT_MAX to recursive function, at null we return true. We return is root is less than limit, and make left and right calls with limit updated to root->data.

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    // returns number of nodes in binary tree
    int countNodes(struct Node *root)
    {
        if (root == NULL)
            return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    // returns if tree is Complete Binary tree (CBT)
    bool isCBT(struct Node *root, int index, int total)
    {
        if (root == NULL)
            return true;
        if (index >= total)
            return false;
        return isCBT(root->left, 2 * index + 1, total) && isCBT(root->right, 2 * index + 2, total);
    }
    // returns if tree follows max-order i.e. each node is less than its parent
    bool isMaxOrder(struct Node *root, int limit)
    {
        if (root == NULL)
            return true;
        return (root->data < limit) && isMaxOrder(root->left, root->data) && isMaxOrder(root->right, root->data);
    }
    // actual function
    bool isHeap(struct Node *tree)
    {
        int index = 0;
        int totalNodes = countNodes(tree);
        return isCBT(tree, index, totalNodes) && isMaxOrder(tree, INT32_MAX);
    }
};