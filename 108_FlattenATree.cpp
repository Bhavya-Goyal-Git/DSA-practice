#include <iostream>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/flatten-binary-tree-to-linked-list_1112615?leftPanelTabValue=PROBLEM

// Problem : You are given a binary tree consisting of 'n' nodes. Convert the given binary tree into a linked list where the linked list nodes follow the same order as the pre-order traversal of the given binary tree. Use the right pointer of the binary tree as the "next" pointer for the linked list and set the left pointer to NULL. Use these nodes only. Do not create extra nodes. Do it in O(1) space, i.e. no recursion and no other data structures

// Approach : As we need to do it INPLACE and also in O(1) space [no recursion or stack/queue], we cannot go with any travesal techniques for the tree. We have morris traversal for O(1) traversing a tree, we will modify it a little to do our task. We see in morris traversal, we make the rightmost element of left subtree point at the root again. But here, we will make it point at root->right. This will make the tree slowly flatten into a linked list.
// Algorithm : As in morris traversal, we make a current pointer initially at the root node. Then we run a loop unless current is null, inside the loop we check if current->left is not null (if its null there is no need for flatenning this part and we can directly do current = current->right), if there exists current->left, then we find the rightmost in this subtree similar to morris traversal.. that is, make a temp pointer to current->left then do temp = temp->right while temp->right is not null (we can remove that temp->right != current condition used in morris as we wont fall back to same element here) After reaching this element, we do temp->right = current->right [made the link needed for linked list] then, current->right = current->left [current->right was linked where it belonged, now we can fix the chain by making the left chain into the right one] and then current->left = NULL (making the left chain free). After this step, we need to move to the next node, which now will be in current->right, this is already written out of the 'if' block.

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T dat)
    {
        this->data = dat;
        left = NULL;
        right = NULL;
    }
};

void flattenBinaryTree(TreeNode<int> *root)
{
    TreeNode<int> *current = root;
    while (current != NULL)
    {
        if (current->left != NULL)
        {
            TreeNode<int> *rightmost = current->left;
            while (rightmost->right != NULL)
            {
                rightmost = rightmost->right;
            }
            rightmost->right = current->right;
            current->right = current->left;
            current->left = NULL;
        }
        current = current->right;
    }
}