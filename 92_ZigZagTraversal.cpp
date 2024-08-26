#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Problem link : https://www.geeksforgeeks.org/problems/zigzag-tree-traversal/1

// Problem : Given a binary tree, traverse it in zig zag order, return a vector that has data in order of this traversal. I.e. traverse the first level left to right, second level right to left, third again left to right and so on..

// Approach : Karna level order traversal hee hai, bas computer ka bewakoof banana h. Use a queue to do simple level order traversal, and a result vector to return. Make a boolean variable leftToRight to decide order (initially true). Then add root to queue and start as usual a while loop until q is non empty, at each stage get size of current level using q.size and make a new vector of this size to store data of this level. Now, run a for loop until this size.. Normally traverse the queue elements, as if a level order traversal, just check at time of insertion in the ans vector whether leftToRight is true or not, if yes insert at normal i index otherwise at size-i-1 (from the back) index. This will simply reverse the storage, although level order traversal is going on. Remember to store the left and right child of this node in the queue. After the for loop, we have to add these values in the results vector, simply add all values of ans vector into results vector.. Before exiting the while loop, we have to flip value of leftToRight variable, do that. At the end return results vector!

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    // Function to store the zig zag order traversal of tree in a list.
    vector<int> zigZagTraversal(Node *root)
    {
        vector<int> result;
        if (root == NULL)
        {
            return result;
        }
        queue<Node *> q;
        q.push(root);
        bool leftToRight = true;
        while (!q.empty())
        {
            int size = q.size();   // number of elements in a level
            vector<int> ans(size); // stores ordering of 1 level
            for (int i = 0; i < size; i++)
            {
                Node *temp = q.front();
                q.pop();
                int index = leftToRight ? i : size - i - 1;
                ans[index] = temp->data;
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            for (auto i : ans)
            {
                result.push_back(i);
            }
            leftToRight = !leftToRight;
        }
        return result;
    }
};