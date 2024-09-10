#include <iostream>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/_893049?leftPanelTabValue=PROBLEM

// Problem : Given a BST (binary search tree), Find the inorder Predecessor and inorder Successor of the given key in the tree. (element that occurs just previous and just after the given key when a inorder traversal is done)

// Approach : Please note that inorder traversal of a bst is always in sorted order and we can use this fact! Method 1 : Simply store the inorder traversal of tree in a array, then find the key inside that array and return a value before and after that kay. (time -> o(n) space-> o(2n))
// Method 2: Why store so much data, just perform the inorder traversal, (LNR) and the first time we encounter a node greater than key, is the successor. And the last time, we encounter a node less than our key, is the predecessor. {therefore, while traversing, always update predecessor if node is smaller, but only update successor once, i.e., when a larger node is first encountered} (time-> O(n) space->O(n))
// These methods use recursion and on top of that, Have to still traverse the entire tree, to find the nodes.. Note that inorder is sorted and therefore, predecessor of element is the node whose data is just smaller than it and successor is the node whose data is just larger than it. And data in a bst can be easily searched due to its structure. We will use this fact to get ans in O(h) time {h is height of tree which most probably is log n} and O(1) space.
// Algo : Lets say we are finding successor of key, i.e. we have to find the element just greater than the key. We declare a variable succ and initialize with -1. We make a temp pointer to root node and run a while loop unless temp is null. During this iteration, if the node we are at, is greater than the key, then the node may be the successor of our key, so we update succ variable with temp->value, but now, it may be possible that a value, lesser than this one, but greater than key exists, to find that, we update temp = temp->left {smaller than current}. Else, during iteration, we found something less than key, then we need a greater value, so we simply do temp = temp->right. After the while loop, succ variable contains the successor of key. Similar algo can be applied to find the predecessor.

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
};

int findPre(TreeNode *root, int key)
{
    int pre = -1;
    TreeNode *temp = root;
    while (temp != NULL)
    {
        if (temp->data < key)
        {
            pre = temp->data;
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }
    return pre;
}
int findSuc(TreeNode *root, int key)
{
    int suc = -1;
    TreeNode *temp = root;
    while (temp != NULL)
    {
        if (temp->data > key)
        {
            suc = temp->data;
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    return suc;
}

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    pair<int, int> p;
    p.first = findPre(root, key);
    p.second = findSuc(root, key);
    return p;
}