#include <iostream>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/lca-in-a-bst_981280?leftPanelTab=0&leftPanelTabValue=PROBLEM

// Problem : Given a BST and 2 nodes in it, find the least common ancestor of the 2 nodes. Return the node hence found or return null.

// Approach : We already know how to find lca of a binary tree, but it is O(n) in time. Here, we can take advantage of structure of BST. We know that LCA of nodes means, one of node will be its left and another one to its right, such node shall be LCA of nodes. In a bst, lefts are smaller and rights are bigger. We can simply check at a node if it lies in range of given 2 nodes. If yes, it is lca, else , if its smaller, look into right, else if its bigger look into left. If loop turns null, then return null. This is simple iterative way, O(h) time and O(1) space.

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

TreeNode *findLCA(TreeNode *root, int k1, int k2)
{
    TreeNode *temp = root;
    while (temp != NULL)
    {
        if (temp->data >= k1 && temp->data <= k2)
        {
            return temp;
        }
        else if (temp->data < k1)
        {
            temp = temp->right;
        }
        else
        { // temp->data > k2
            temp = temp->left;
        }
    }
    return NULL;
}
TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    TreeNode *ans = findLCA(root, min(P->data, Q->data), max(P->data, Q->data));
    return ans;
}