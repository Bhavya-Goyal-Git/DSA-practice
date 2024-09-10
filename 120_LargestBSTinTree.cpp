#include <iostream>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/largest-bst-subtree_893103?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

// Problem : Given a binary tree, return the size (number of nodes) in the largest BST present in the tree.

// Approach : Given the question, it is right to think that we need to process the tree from downwards, else we won't be able to do it in O(n) time. We also have to identify whether it's a BST and also take care of the size variable. For the size, we make a int variable and pass it as reference to the solve function, we will update it as and when we discover a BST. Now, to identify a bst, at each node we have to know certain information... like is left subtree and right subtree BST too? what are minimums and maximums values of left and right subtrees (to compare the current data and help declare whether it is a bst or not), and also the sizes of left and right subtrees. There are 4 informations, must be passed on from each node above. We therefore make a custom class 'subtree data' which stores these 4 data-points mini,maxi,size,isBST. We make a recursive function that returns an instance of this class.
// The base case of function is when root is null, and we return an instance where mini is INT_MAX and maxi is INT_MINI (notice, this is to make conditions at leaf nodes favourable), isBst is true and size is 0. Then we make recursive calls to root->left and root->right and store the instances returned in variables called left and right. Now we make another instance 'current' to return up and have to populate its 4 variables. current.size will simply be left.size + right.size + 1. and current.mini is minimum of left.mini and root->data, similarly current.maxi is maximum of right.maxi, root->data. Now we have to make sure is current a BST for that, left.isBST && right.isBST along with the fact that left.maxi < root->data < right.mini (a node in bst must be greater than maximum of left subtree and lesser than minimum of right subtree).. we && these conditions for checking current.isBSt. Now, we check if this has evaluated to true. if current.isBST, we update the size variable passed as reference to max(size,current.size). After all this, return current;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
};

class subtreeData
{
public:
    int mini, maxi, size;
    bool isBST;
};

subtreeData solve(TreeNode *root, int &size)
{
    if (root == NULL)
    {
        subtreeData d;
        d.isBST = true;
        d.maxi = INT32_MIN;
        d.mini = INT32_MAX;
        d.size = 0;
        return d;
    }
    subtreeData left = solve(root->left, size);
    subtreeData right = solve(root->right, size);

    subtreeData current;
    current.maxi = max(right.maxi, root->data);
    current.mini = min(left.mini, root->data);
    current.size = left.size + right.size + 1;
    current.isBST = left.isBST && right.isBST && (root->data > left.maxi) && (root->data < right.mini);

    if (current.isBST)
        size = max(size, current.size);

    return current;
}
int largestBST(TreeNode *root)
{
    int size = 0;
    subtreeData data = solve(root, size);
    return size;
}