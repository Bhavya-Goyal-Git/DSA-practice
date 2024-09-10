#include <iostream>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/find-k-th-smallest-element-in-bst_1069333?leftPanelTab=0&leftPanelTabValue=PROBLEM

// Problem : Given a BST, find the kth smallest value in the tree. If it does not exist, return -1.

// Approach : We use the fact that inorder traversal of BST is sorted. We traverse the tree using inorder traversal, And in the N part, process the node. We maintain a counter, initially 0, and increment it in the processing part, and check if it has reached k. If yes, we return the node's data. If we encounter null, we return -1. Also, after making the call to left, we can early exit, by check if value returned is not -1, then we can early return. This speeds up the process, and we dont have to complete the entire traversal.

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
};

int solve(TreeNode *root, int &i, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    // L
    int lft = solve(root->left, i, k);
    if (lft != -1)
    {
        return lft;
    }
    // N
    i++;
    if (i == k)
    {
        return root->data;
    }
    // R
    return solve(root->right, i, k);
}
int kthSmallest(TreeNode *root, int k)
{
    int ans = 0;
    int result = solve(root, ans, k);
    return result;
}