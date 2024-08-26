#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

// Problem Link : https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

// Problem : Given a binary tree, return how it will look from the top. Return your answer as a vector of integers left to right.

// Approach : Imagine a number line drawn over the binary tree. This question is very similar to vertical order traversal of the tree. Only change is that, in a single vertical order line, only the topmost element will be visible, and below will be hidden. So, similar to what we were storing horizontal distance to nodes data mapping, now we will only store a map for int to int (horizontal distance to topmost node data), And since we will we doing a level order traversal, when we insert into map first time for a horizontal value, it will be topmost of its kind, so no need to worry seperately, also this would be useful in checking (if a map entry already exists for a particular horizontal distance, do nothing!) [Note that a map is used whose iterator is sorted and we need this thing while doing final insertion in answer vector].
// So what we do is, make a queue<Node*,horizontal distance> and a map <horizontal dist, node data>. Push the root,0 into queue and run a loop until empty (level order traversal), at each step extract the node and horizontal dist from the queue pair. If there is no entry in the map corresponding to this horizontal, then add (this is checked using map.find(key) method which returns map.end() if key is not present) otherwise ignore. And then, as always add left and right of this node into queue with horizontals as current-1 and current+1 respectively (if exists). After the while loop, simply run a loop across the map (this will auto run in ascending order of keys, which is horizontal distance here), and append entry.second (node ka data) into answer vector and return it!

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        map<int, int> m;            // horizontal dist, node data
        queue<pair<Node *, int>> q; // node pointer, horizontal dist
        q.push(make_pair(root, 0));
        while (!q.empty())
        {
            pair<Node *, int> p = q.front();
            q.pop();
            Node *temp = p.first;
            int hd = p.second;
            if (m.find(hd) == m.end())
            {
                m[hd] = temp->data;
            }
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