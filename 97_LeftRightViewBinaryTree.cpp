#include <iostream>
#include <vector>
using namespace std;

// Problem link : https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1

// Problem : Given a binary tree, return a vector of int, how it will look if looked at from the left side. Second: return how it will look from right side.

// Approach : See, these could have easily been done by doing level order traversal, and simply storing the first node of a level (for left view) and last node of a level (for right view) but requires a additional queue data structure. We can do it with recursive traversal too.. We send our root node, a integer called level, and the ans vector to the recursive function.
// For left view: For this, we have to store the first node of each level, now how do we identify this? The vector.size() function is used cleverly here. If level == vector.size() that means it is our first time seeing that level, then Node->data is pushed into the vector. Then recursive calls are made, first to Node->left with level+1 and then to Node->right (THIS ORDER IS IMPORTANT HERE!!) The order insures the fact that the first node seen at a level is the left most one possible!
// For right view: Everything is same, just the fact that we need to store last node of each level.. But if we rethink, it is also the first node of that level just from the right side. So the entire function can remain same, just recursive call is first made to Node->right and then to Node->left, this ensures that when level==vector.size() evaluates to true, the Node doing so is the rightmost one possible for that level in the tree. And our view is achieved!

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void solve(Node *root, int level, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (level == ans.size())
    {
        ans.push_back(root->data);
    }
    solve(root->left, level + 1, ans);
    solve(root->right, level + 1, ans);
}
// Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int> ans;
    int level = 0;
    solve(root, level, ans);
    return ans;
}

// Should return  right view of tree
class Solution
{
public:
    void solve(Node *root, int level, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        if (level == ans.size())
        {
            ans.push_back(root->data);
        }
        solve(root->right, level + 1, ans);
        solve(root->left, level + 1, ans);
    }
    // Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
        vector<int> ans;
        int level = 0;
        solve(root, level, ans);
        return ans;
    }
};