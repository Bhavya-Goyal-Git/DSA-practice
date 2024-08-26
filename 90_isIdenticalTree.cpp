#include <iostream>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/identical-trees_799364?leftPanelTabValue=SUBMISSION

// Problem : Given 2 binary trees, return whether they are identical or not!

// Approach : we make a recursive function. The base case is when either of node becomes null, then the data can't be compared. we simply compare the nodes itself, because if both are null it evaluates to true else false. Or normally, we return (data1 == data2) && recursive call for left subtree && recursive call for right subtree.

template <typename T>

class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

bool identicalTrees(BinaryTreeNode<int> *root1, BinaryTreeNode<int> *root2)
{
    if (root1 == NULL || root2 == NULL)
    {
        return root1 == root2;
    }
    return (root1->data == root2->data) && identicalTrees(root1->left, root2->left) && identicalTrees(root1->right, root2->right);
}