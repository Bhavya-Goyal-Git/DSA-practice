#include <iostream>
#include <vector>
using namespace std;

// Problem link : https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

// Problem : Given a binary tree, traverse it in Boundary mode, that is, the left nodes first then all the leaf nodes and then all the right nodes in reverse order (forming a boundary along the end of tree). Push back data of this kind of traversal into a vector and return the vector!

// Approach : We break down the thing into 3 functions, one for left part, one for leafs, one for right. These functions are recursive and take a node pointer and the ans vector (with reference). First of all we push the root node into ans vector in the main function, then make a call to left Traversal with this vector and root->left. This function has base cases of null, and leaf nodes at which it simply returns. else, first store data of node into ans vector, then, if left is valid for the node make recurive call to root->left else call to root->right. (note that else here is necessary!) Now, After left make calls to leafs (seprate for left leaves and right leaves). This function simply ignores null base case, and when reaches the leaf, appends into ans and returns. Otherwise, a normal dfs, calling both left and right pointers to traverse one by one. Then at last we have right traversal function that too, in reverse. We normally pass root->right to it. It also has base case to ignore null, leaf node cases. Else, if root->right is valid traverse that, else traverse root->left (note that else here is necessary!) After the traversal calls we have append (to achieve reverse effect), append data of node to ans. At end of all this, in the main function, return the ans vector!

struct Node
{
    int data;
    Node *left, *right;
};

class Solution
{
public:
    void traverseLeft(Node *root, vector<int> &ans)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
        {
            return;
        }
        ans.push_back(root->data);
        if (root->left)
            traverseLeft(root->left, ans);
        else
            traverseLeft(root->right, ans);
    }

    void traverseLeafs(Node *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->data);
            return;
        }
        traverseLeafs(root->left, ans);
        traverseLeafs(root->right, ans);
    }

    void traverseRight(Node *root, vector<int> &ans)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
        {
            return;
        }
        if (root->right)
            traverseRight(root->right, ans);
        else
            traverseRight(root->left, ans);

        ans.push_back(root->data);
    }

    vector<int> boundary(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        ans.push_back(root->data);
        // traverse lefts
        traverseLeft(root->left, ans);
        // traverse leafs
        traverseLeafs(root->left, ans);
        traverseLeafs(root->right, ans);
        // traverse right in reverse
        traverseRight(root->right, ans);

        return ans;
    }
};