#include <iostream>
#include <climits>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/validate-bst_799483?leftPanelTab=0&leftPanelTabValue=PROBLEM

// Problem : Given a binary tree, return whether its a BST (binary search tree) or not.

// Approach : We can use the fact that inorder traversal of BST is sorted in nature. Get the inorder and return whether its sorted or not. But this requires O(n) for inorder and some overhead for checking if its sorted or not. We can think of another approach as follows: validate whether a given node lies within a defined range. For example, the root node can be anything from -inf to +inf, but root's left can only be from -inf to root->data and similarly, root's right can only be from root->data to +inf.. Every node is recieving a max, min from parent in which it must lie. Left should have same minimum but max should be root itself and right should have same maximum but minimum should be root itself. On this approach we design a recursive function, to which we send INT_MIn and INT_MAx as -inf and +inf for the root's range.

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
};
bool isBST(TreeNode *root, int mini, int maxi)
{
    if (root == NULL)
    {
        return true;
    }
    return (root->data >= mini) && (root->data <= maxi) && isBST(root->left, mini, root->data) && isBST(root->right, root->data, maxi);
}
bool validateBST(TreeNode *root)
{
    return isBST(root, INT_MIN, INT_MAX);
}