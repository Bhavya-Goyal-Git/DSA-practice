#include <iostream>
#include <stack>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/two-sum-in-a-bst_1062631?leftPanelTab=0&leftPanelTabValue=PROBLEM

// Problem : Given a binary search tree, (BST), and a integer target, find out whether sum of any 2 nodes in the bst is equal to target or not. Return true/false. Try implementing in O(n) time and O(h) space.

// Approach : Most easy way would have been to store the Inorder in a vector and then apply 2 pointer approach on the vector similar to 2sum problem in a array (as inorder is sorted). But this takes O(n) space.
// Remember we designed a sorted iterator for bst, with O(h) space and O(1) operations in previous question.. We can alter it a little to also get a reverse iterator (decreasing order). We define this class and pass our root to it. Make 2 iterators, one ascending sorted and one descending sorted. Now we can apply the 2 pointer logic on these iterators. Assign i and j to iterators ascending and descending's next resp. and run while i<j. Remember, while updating, do i = ascending.next() etc. and not i++. This gives a O(h) space solution.

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

class BSTiterator
{
private:
    stack<BinaryTreeNode<int> *> iter;
    bool isReverse;
    // utility function
    void pushAll(BinaryTreeNode<int> *node)
    {
        if (isReverse)
        {
            while (node != NULL)
            {
                iter.push(node);
                node = node->right;
            }
        }
        else
        {
            while (node != NULL)
            {
                iter.push(node);
                node = node->left;
            }
        }
    }

public:
    BSTiterator(BinaryTreeNode<int> *root, bool rev)
    {
        isReverse = rev;
        pushAll(root);
    }
    int next()
    {
        BinaryTreeNode<int> *temp = iter.top();
        iter.pop();
        if (isReverse)
        {
            pushAll(temp->left);
        }
        else
        {
            pushAll(temp->right);
        }
        return temp->data;
    }
    bool hasnext()
    {
        return !iter.empty();
    }
};
bool twoSumInBST(BinaryTreeNode<int> *root, int target)
{
    if (root == NULL)
    {
        return false;
    }
    BSTiterator ascend(root, false);
    BSTiterator descend(root, true);
    int i = ascend.next();
    int j = descend.next();
    while (i < j)
    {
        if (i + j == target)
        {
            return true;
        }
        else if (i + j < target)
        {
            i = ascend.next();
        }
        else
        {
            j = descend.next();
        }
    }
    return false;
}