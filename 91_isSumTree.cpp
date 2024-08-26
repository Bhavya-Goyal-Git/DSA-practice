#include <iostream>
using namespace std;

// Problem link : https://www.geeksforgeeks.org/problems/sum-tree/1

// Problem : Given a binary tree, return whether it is a sum tree or not. A sum tree is a tree in which data of each node is equal to sum of data's of its left subTree and right subTree. Note that empty tree is also sum tree. Also note that given condition will not be checked for leaf nodes.

// Approach : We need 2 kind of data at each node, whether each node is sumtree (for that we require sum of its left and right subtrees) and whether its subtrees were sumtrees themselves or not? So, we make a recurive function that returns a pair<bool,int>. The base case is when root is null, then we return true,0 as per the question, another base case is when it is a leaf node, in that case we return true, data-of-that-node. In normal cases, we first calc recursively, the values for left and right parts. Then calculate whether this node is subtree or not by comparing root->data to sum of left+right. Then we make a answer pair to return. First value is (isLeftSumTree) && (isRightSumTree) && (isThisNodeSumTree (just calculated)) and second one is sum of this tree that is (sumleft) + (sumright) + (root->data). Return ans.

struct Node
{
    int data;
    Node *left, *right;
};

class Solution
{
private:
    pair<bool, int> Sumtreefast(Node *root)
    {
        if (root == NULL)
        {
            pair<bool, int> p = {true, 0};
            return p;
        }
        if (root->left == NULL && root->right == NULL)
        {
            pair<bool, int> p;
            p.first = true;
            p.second = root->data;
            return p;
        }
        pair<bool, int> left = Sumtreefast(root->left);
        pair<bool, int> right = Sumtreefast(root->right);
        pair<bool, int> ans;
        bool myans = (left.second + right.second == root->data);
        ans.first = left.first && right.first && myans;
        ans.second = left.second + right.second + root->data;
        return ans;
    }

public:
    bool isSumTree(Node *root)
    {
        // Your code here
        return Sumtreefast(root).first;
    }
};