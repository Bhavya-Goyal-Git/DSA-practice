#include <iostream>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/is-height-balanced-binary-tree_975497?leftPanelTabValue=PROBLEM

// Problem : Given a binary tree, return whether its balanced or not.. in a balanced tree, the difference between height of left subpart and right subpart is at most 1.

// Approach : At every node, we need to know if nodes below it are balanced and if current node is balanced (leftHeight - rightHeight <=1) so, we make a function that returns a pair of bool,int, first being the status whether the node is balanced or not and second being the height of that node. The recursive function has base case when root node is null in that case we return true,0 (given in question that empty tree is balanced) else,  we calculate the status of balance of this node (absolute value of leftHeight - rightHeight <=1) and store it in a bool. Now, make a answer pair to return, the first part of it is balanced status which will be isLeftBalanced && isRightBalanced && currentBalanced. Second part will be height, that is 1 + max(leftHeight,rightHeight). Return ans.
// Note : we can further optimize adding a check after left part in recursive calls, to break chain of calls as soon as a false is obtained, but it is not necessary!

template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

pair<bool, int> isBalancedfast(TreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = {true, 0};
        return p;
    }
    pair<bool, int> ans;
    pair<bool, int> left = isBalancedfast(root->left);

    // if (!left.first)     //further optimization if needed
    // {
    //     ans.first = false;
    //     ans.second = 0;
    //     return ans;
    // }

    pair<bool, int> right = isBalancedfast(root->right);

    bool currentBalance = abs(left.second - right.second) <= 1;
    ans.first = left.first && right.first && currentBalance;
    ans.second = 1 + max(left.second, right.second);
    return ans;
}

bool isBalancedBT(TreeNode<int> *root)
{
    return isBalancedfast(root).first;
}