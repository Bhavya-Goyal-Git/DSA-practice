#include <iostream>
using namespace std;

// Problem link : https://www.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1

// Problem : Given a binary tree with a value associated with each node, we need to choose a subset of these nodes such that sum of chosen nodes is maximum under a constraint that no two chosen node in subset should be directly connected that is, if we have taken a node in our sum then we can’t take its any children or parents in consideration and vice versa.

// Approach :

struct Node
{
    int data;
    struct Node *left, *right;
};

class Solution
{
public:
    // p.first is max sum including current element
    // p.second is max sum excluding current element
    pair<int, int> solve(Node *root)
    {
        if (root == NULL)
        {
            pair<int, int> p = {0, 0};
            return p;
        }
        pair<int, int> lft = solve(root->left);
        pair<int, int> rgt = solve(root->right);
        pair<int, int> ans;
        // if we include current element, we have to exclude both its child
        ans.first = root->data + lft.second + rgt.second;
        // if we exclude current element, we can choose to include/exclude child based on whats maxx
        ans.second = max(lft.first, lft.second) + max(rgt.first, rgt.second);
        return ans;
    }
    // Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root)
    {
        pair<int, int> ans = solve(root);
        return max(ans.first, ans.second); // whether sum is max by including root or excluding it
    }
};