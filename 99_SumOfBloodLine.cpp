#include <iostream>
using namespace std;

// Problem link : https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

// Problem : Given a binary tree having n nodes. Find the sum of all nodes on the longest path from root to any leaf node. If two or more paths compete for the longest path, then the path having maximum sum of nodes will be considered.

// Approach : We iterate the tree recursively, with sum and level data at each node, and 2 current global maximums for level and sum value. (the globals would be passed by ref) When we reach a leaf node in the traversal, we add its value to the sum, and then compare the level reached to current_global_max one if it is greater, we update the globalLevel and globalSum, if it is same as of previous, we update the globalSum if new one is bigger (as per the question). This returns to us the max bloodline sum in the globalSum variable.

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    void solve(Node *root, int level, int sum, int &currentlvl, int &currentsum)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->left == NULL && root->right == NULL)
        {
            sum += root->data;
            if (level > currentlvl)
            {
                currentlvl = level;
                currentsum = sum;
            }
            else if (level == currentlvl)
            {
                currentsum = sum > currentsum ? sum : currentsum;
            }
        }
        solve(root->left, level + 1, sum + root->data, currentlvl, currentsum);
        solve(root->right, level + 1, sum + root->data, currentlvl, currentsum);
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        int lvl = 0;
        int sum = 0;
        solve(root, 0, 0, lvl, sum);
        return sum;
    }
};