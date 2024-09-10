#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/preorder-traversal-to-bst_893111?leftPanelTab=0&leftPanelTabValue=PROBLEM

// Problem : Given the preorder traversal of a BST, (inform of vector of int), construct back the BST and return the pointer to root node.

// Approach : We can sort the preorder and that will get us the inorder. And we know how to construct a tree with 2 orders provided. However complexity will be O(nlog(n)) due to sort. Better approach is to do a preorder traversal ourselves and construct the tree at the go.
// This will require a recursive function, taking the vector of int, a index (int) variable tracking what index we are at (passed by reference therefore), a left limit 'i', a right limit 'j' (help to build bst using the range method) and we also have included a length variable (length of vector rather than a call to vector.size() at each recursive call). At each step, we match the base cases that if index has gone out of bounds of length or element at index is out of range of i and j we return NULL.. else, we create node with vector[index] as data and increment the index variable. Then make recursive calls to left and right by using appropriate limits of left and right. (in left call, max limit will change to root->data and in right call, min limit will change to root->data). At end of calls, return root.

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

BinaryTreeNode<int> *treefromPreOrder(vector<int> &preorder, int &index, int length, int i, int j)
{
    if (index >= length || preorder[index] < i || preorder[index] > j)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(preorder[index]);
    index++;
    root->left = treefromPreOrder(preorder, index, length, i, root->data);
    root->right = treefromPreOrder(preorder, index, length, root->data, j);
    return root;
}

BinaryTreeNode<int> *preorderToBST(vector<int> &preorder)
{
    int index = 0;
    return treefromPreOrder(preorder, index, preorder.size(), INT_MIN, INT_MAX);
}