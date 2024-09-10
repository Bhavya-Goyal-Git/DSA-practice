#include <iostream>
#include <stack>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/bst-iterator_1112601?leftPanelTabValue=PROBLEM

// Problem : Given a binary search tree (bst), Design a bst iterator class. The class constructor shall recieve the root node of bst. The iterator must be in sorted order (As per inorder traversal). Impelemet the next() and hasnext() function of the class. Do the operations in apx O(1) time and O(h) space.

// Approach : We could store the inorder of a bst in some vector etc and then return appropriately. But for that, space will be O(n). We could find inorder successor of each element one after other, but for that the time of operations will be O(h). To implement an iterator therefore, wew use a stack datastructure.
// We make a stack of Node pointers. And we make a utility function, pushAll. This function takes a node pointer and then pushes it and all the left's it can go from it, into the stack. Because this is how inorder works, full to left, then node, then right (and after a right, again to full left of that, if exists). So in the constructor, we just call this pushAll function over the root provided to us. Now, for the next() function, we pop out the top from stack. We have to return its data, but before that one small thing, we make a call to pushAll with node->right. Because after this node, its right's leftest must be there in inorder, that is what pushAll does. And then return node->data. Now for the hasNext() function we simply return false when stack is empty... that is return !stack.empty(). This leads to design of sorted iterator for a bst, with O(h) space and appx O(1) operations complexity.

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class BSTiterator
{
private:
    stack<TreeNode<int> *> iter;
    // utility function :
    void pushAll(TreeNode<int> *node)
    {
        while (node != NULL)
        {
            iter.push(node);
            node = node->left;
        }
    }

public:
    BSTiterator(TreeNode<int> *root)
    {
        pushAll(root);
    }

    int next()
    {
        TreeNode<int> *temp = iter.top();
        iter.pop();
        pushAll(temp->right);
        return temp->data;
    }

    bool hasNext()
    {
        return !iter.empty();
    }
};