#include <iostream>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/diameter-of-the-binary-tree_920552?leftPanelTabValue=PROBLEM

// Problem : Given a binary tree, find its diameter. Diameter of a binary tree is the max length of path between any 2 nodes of the tree.

// Approach : Either the diameter could exist in left subpart of the current node, or the right part of current node, or through the current node (height of left tree + height of right tree + 1). For this calculation, at each node we need 3 things, height & diameter for left part, height and diameter for right part and diameter through current node. So, we make a function (recursive) that returns a pair of integers, first being diameter of that node and second height of that node. Base case returns 0,0 pair when node is null. Else: take left and right data by recursive calls. Now, calculate diameter through current node by height(left) + height(right) + 1. Then make an answer pair to return. The first value is current max diameter that will be max(current-node-dia-just-calculated, dia-left,dia-right) and second value will be height of this node, which is simply 1 + max(height-left, height-right). Return ans.

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// first part is diameter, second part is height
pair<int, int> diameterFast(TreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> p = {0, 0};
        return p;
    }
    pair<int, int> left = diameterFast(root->left);
    pair<int, int> right = diameterFast(root->right);
    pair<int, int> ans;

    int mydia = left.second + right.second + 1;

    ans.first = max(left.first, max(right.first, mydia));
    ans.second = 1 + max(left.second, right.second);
    return ans;
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
    return diameterFast(root).first - 1;
}