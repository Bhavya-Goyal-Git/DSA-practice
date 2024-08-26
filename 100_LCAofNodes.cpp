#include <iostream>
using namespace std;

// Problem link : https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1

// Problem : Given a binary tree with all unique data, and 2 integers which may be the nodes, return the node that is least common ancestor to the 2 given nodes! (LCA: It is the first common ancestor of both the nodes n1 and n2 from bottom of tree.)

// Approach : The trick is to make a recursive dfs function. We have to return the node whose left chain contains one of the element and right chain contains the other. That node will be the Lca. To do this, we make the plain old base case of returning Null on encountering Null. Then, we check if current node is actually one of nodes we are searching for, if yes we return this node. Now comes general part for a node. We make a recursive call to leftSubtree and store the value returned in a Node *, similarly make one to rightSubTree and store in another Node *. Based on value of these pointers, there arise 4 cases :
// 1) Both of pointers are not NUll, i.e. both nodes have been found! then the current node on which we are is the answer, we return Root!
// 2) Left one is null but right is not null, this means this node is just someone in the chain of original answer, we do not disturn and propogate right above. That is, return RightAns.
// 3) Left is not null, but right is. Similar to previous case, we propagate left above. Return leftAns.
// 4) Both are null, which means this node is useless. We return NULL above!

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

class Solution
{
public:
    // Function to return the lowest common ancestor in a Binary Tree.
    Node *lca(Node *root, int n1, int n2)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root->data == n1 || root->data == n2)
        {
            return root;
        }
        Node *lAns = lca(root->left, n1, n2);
        Node *rAns = lca(root->right, n1, n2);
        if (lAns != NULL && rAns != NULL)
        {
            return root;
        }
        else if (lAns == NULL && rAns != NULL)
        {
            return rAns;
        }
        else if (lAns != NULL && rAns == NULL)
        {
            return lAns;
        }
        else
        {
            return NULL;
        }
    }
};