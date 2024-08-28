#include <iostream>
#include <vector>
using namespace std;

// Problem link : https://www.geeksforgeeks.org/problems/inorder-traversal-iterative/1

// Problem : Given a binary tree, do a inorder traversal without using recursion or any data structure like stack/queue, and return the sequence of nodes hence obtained as a array. Also try doing the same for preorder traversal.

// Approach : The given problem is called Morris traversal and is used to traverse the tree using O(n) time but in O(1) space. This algorithm uses the concept of threaded tree, that is leaf nodes having pointers back to roots (not everywhere tho). During the iterations, we create the threaded trees and keep on removing them, leaving our original tree unaltered.
// Algorithm : We make a pointer current that initially points to root element. Run a while loop until current is not NULL, this pointer traverses the tree for us. Now, if current's left is NULL, then as per inorder we can now include the root, so firstly append the current->data into ans vector and then simply update current to current->right. Else (i.e. current had a left), now the thing is, we must find a way to come back to current's position after traversal of this entire subtree, so we have to make a link from rightmost node in this tree back to current. So we first make a temp pointer to current->left and now while(temp->right != NULL && temp->right != Current) we make temp = temp->right. Here, temp->right is not null is understandable, temp->right != current is checked because when this linked has been formed once, and we reach older position of current again sometime, then this loop may keep running forever. this condition helps to stop it and also break the threaded chain we created. Here's how: after this while loop, the temp is standing at the rightmost pointer of subtree, now there are 2 cases, if temp->right == NULL (while loop ended due to 1st condition i.e. it has been visited for 1st time) then we make our link.. i.e. temp->right = current. Now it is safe to move current so we make current = current->left. Else: (while loop ended due to 2nd condition and we are visiting it for second time) then we break the link temp->right = NULL, since current is at root now, we append it in our ans vector, and after that we can say that left subtree has been traversed fully, so we make current = current->right. after the while loop, return the ans.
// Changes to make this preorder : We are appending the root when we traverse it for the second time in the inorder code, however preorder follows NLR, so we append the node just before going to the left inside the code. So, when temp->right = NULL, when we go current = current->left, just prior to that, we will append the current to our ans vector.

struct Node
{
    int data;
    Node *left;
    Node *right;
};
class Solution
{
public:
    // morris traversal for inorder
    vector<int> inOrder(Node *root)
    {
        vector<int> ans;
        Node *current = root;
        while (current != NULL)
        {
            if (current->left == NULL)
            {
                ans.push_back(current->data);
                current = current->right;
            }
            else
            { // if current has a left
                Node *rightmost = current->left;
                while (rightmost->right != NULL && rightmost->right != current)
                {
                    rightmost = rightmost->right;
                }
                if (rightmost->right == NULL)
                {
                    rightmost->right = current;
                    current = current->left;
                }
                else
                { // rightmost->right was current itself
                    rightmost->right = NULL;
                    ans.push_back(current->data);
                    current = current->right;
                }
            }
        }
        return ans;
    }
    // morris traversal for pre order
    vector<int> preOrder(Node *root)
    {
        vector<int> ans;
        Node *current = root;
        while (current != NULL)
        {
            if (current->left == NULL)
            {
                ans.push_back(current->data);
                current = current->right;
            }
            else
            { // if current has a left
                Node *rightmost = current->left;
                while (rightmost->right != NULL && rightmost->right != current)
                {
                    rightmost = rightmost->right;
                }
                if (rightmost->right == NULL)
                {
                    rightmost->right = current;
                    ans.push_back(current->data);
                    current = current->left;
                }
                else
                { // rightmost->right was current itself
                    rightmost->right = NULL;
                    current = current->right;
                }
            }
        }
        return ans;
    }
};