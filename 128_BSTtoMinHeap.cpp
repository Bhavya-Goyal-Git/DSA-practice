#include <iostream>
#include <vector>
using namespace std;

// Problem : Given a Binary Search Tree (BST), which is also a complete binary tree (CBT), convert it to a min-heap, also, for any node, all values in left subtree must be smaller than all values in right subtree.

// Approach: If the second condition was not present, we could easily play swap game (heapifying), but due to 2nd condition, We have to make sure for every node: N<L, N<R, and L<R.. on combining : N<L<R.. which is same as preorder. Therefore, we obtain the sorted order of bst using inorder Traversal and save in a vector. Then we insert these elements into bst by doing preorder.

struct Node
{
    int data;
    Node *left, *right;
};

void getInorder(Node *root, vector<int> &traversal)
{
    if (root == NULL)
        return;
    getInorder(root->left, traversal);
    traversal.push_back(root->data);
    getInorder(root->right, traversal);
}

void placeInorder(Node *root, vector<int> &traversal, int &index)
{
    if (root == NULL)
        return;
    root->data = traversal[index++];
    placeInorder(root->left, traversal, index);
    placeInorder(root->right, traversal, index);
}

Node *BSTtoMinHeap(Node *root)
{
    vector<int> inorder;
    // getting inorder traversal of bst
    getInorder(root, inorder);
    // placing inorder elements in preorder traversal
    int index = 0;
    placeInorder(root, inorder, index);
    return root;
}