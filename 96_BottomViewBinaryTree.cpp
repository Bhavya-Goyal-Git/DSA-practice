#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

// Problem link : https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

// Problem : Given a binary tree, return a vector of int, showing how the tree would look if seen from bottom. If there are multiple nodes at same horizontal distance and same level, the rightmost one as per level order traversal is to be considered.

// Approach : As in top view of tree, we stored data into map when it was first time seeing it, now if we go by similar approach, just keep updating data in the map every time something is seen. IN the end, what we will have in the map is bottom most node of each horizontal distance, as it is level order traversal, it will also take care of fact with there are multiple nodes at same level, distance from horizontal. At end just push the numbers from map to ans vector and return!

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Solution
{
public:
    vector<int> bottomView(Node *root)
    {
        map<int, int> m;            // horizontal dist, node value
        queue<pair<Node *, int>> q; // node pointer, horizontal
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        q.push(make_pair(root, 0));
        while (!q.empty())
        {
            pair<Node *, int> p = q.front();
            q.pop();
            Node *temp = p.first;
            int hd = p.second;
            m[hd] = temp->data;
            if (temp->left)
                q.push(make_pair(temp->left, hd - 1));
            if (temp->right)
                q.push(make_pair(temp->right, hd + 1));
        }
        for (auto i : m)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};