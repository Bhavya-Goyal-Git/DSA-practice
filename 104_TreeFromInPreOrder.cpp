#include <iostream>
using namespace std;

// Problem link : https://www.geeksforgeeks.org/problems/construct-tree-1/1

// Problem : Given are 2 arrays, that represents the inorder and preorder traversal of some binary tree. The number of nodes in tree is n, hence the size of arrays too. You have to construct the tree of which these traversals were, and return its root.

// Approach : Please note that given any 2 traversals of a binary tree, a unique tree can be determined out of the information! Given the preorder traversal, we can surely say that the first element of this traversal will be root of our tree. We are going to solve this recursively, we will overselves do a preorder traversal of the tree to make the tree. This function will need : both the arrays of pre and in order traversal, the size of arrays 'n', inOrderStart and inOrderEnd -> 2 int indices acting as pointers to the inOrder array, preOrderIndex -> int index acting as a pointer to PreOrder array.. we could use a preOrderEnd, but that's not necessary!, rather we have passes the preOrderIndex thing by reference, so it does not loose value even on recursive backs. Lets look at the algorithm now:
// the first element in preOrder will give us our root, lets say we make a node with this element.. Now as per inorder traversal, the elements to left to this element in InOrder traversal will be to left of this and elements to the right of this element in Inorder traversal will be to right of this (as inorder is LNR) therefore, we make a function the returns us the position of this element in Inorder traversal, then when we make for left of this root node we just made, we can be assured that its inorder will now be in range inorderStart to position-1 and right of node's from position+1 to inorderEnd. This makes the algo recursive. Base cases are when preorderIndex gets out of range or inorderStart > inorderEnd (go beyond range), they return null.
// Currently, our algorithm searches for a element in Inorder Array between the given bound, making it O(n2) , we can store all elements given in inOrder array as a map of <element,index> to speed up search, making it O(1). But this optimisation fails for duplicates. If we have to optimise as well as use duplicates, we can make the mapping of int to queue of indices and then would have to pop from queue everytime a search is conducted.

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Solution
{
public:
    // function to find position of element in the InOrderTraversal array
    int findpos(int arr[], int start, int end, int key)
    {
        for (int i = start; i <= end; i++)
        {
            if (arr[i] == key)
                return i;
        }
        return -1;
    }
    // recursive function to solve the problem
    Node *solve(int in[], int inStart, int inEnd, int pre[], int &preIndex, int n)
    {
        if (preIndex >= n || inStart > inEnd)
        {
            return NULL;
        }
        // make a new node with pre[preIndex] as data, and update preIndex to +1 for next recursion
        Node *root = new Node();
        root->data = pre[preIndex];
        preIndex++; // note that making this passed by ref was necessary

        int positionInInorder = findpos(in, inStart, inEnd, root->data); // finding position in inorder

        root->left = solve(in, inStart, positionInInorder - 1, pre, preIndex, n);
        root->right = solve(in, positionInInorder + 1, inEnd, pre, preIndex, n);

        return root;
    }
    Node *buildTree(int in[], int pre[], int n)
    {
        int preOrderStart = 0;
        Node *ans = solve(in, 0, n - 1, pre, preOrderStart, n);
    }
};