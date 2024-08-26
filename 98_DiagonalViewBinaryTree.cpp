#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Problem link : https://www.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1

// Problem : Given a Binary Tree, print the diagonal traversal of the binary tree. Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line. If the diagonal element are present in two different subtress then left subtree diagonal element should be taken first and then right subtree.

// Approach : For a diagonal, we have to travel only in right direction from a node until it reaches end and then begin the next diagonal. This diagonal could begin from the left of root node but in between also possibly could contain the left node of any one node in previously travelled diagonal. THis is as per the question. So what we do is, We make a queue. IN the beginning just store the root node. Run the loop until queue is empty, Inside the loop, Take out the node from queue and store in a temp. Run another loop on this temp until it becomes NULL (we are driving this to the right side as much possible) So at each step, first store its data in answer vector, then push its left into the queue as it will constitute the next diagonal and then make temp = temp->right. These 2 nested loops do the job of diagonal traversing the binary tree. Return ans at the end!

struct Node
{
    int data;
    Node *left, *right;
};

vector<int> diagonal(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        while (temp != NULL)
        {
            ans.push_back(temp->data);
            if (temp->left)
                q.push(temp->left);
            temp = temp->right;
        }
    }
    return ans;
}