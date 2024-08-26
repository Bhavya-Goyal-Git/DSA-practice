#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <bits/stdc++.h>
using namespace std;

// Problem link : https://www.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1

// Problem : Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level, return a vector of integers that store data in this order as answer. IMPORTANT NOTE : If there are multiple nodes passing through a vertical line at the same level, then they should be printed as they appear in level order traversal of the tree.

// Approach : Suppose there is a large number line drawn over the binary tree, and root node is at 0,0 position. The x coordinate here denotes horizontal distance of a node from the central axis. If we see, all we have to do is insert elements into ans vector as per ascending order of these horizontal distances.. that is, first the nodes of left most distance, then next, and upto right most distance. Now, there is a problem: there are multiple nodes on a single horizontal distance.. so to do it, we have to associate each horizontal distance with a vector of data. Now, there is one more problem, what if more than 1 node is on same horizontal distance as well as same vertical level? It is given in the question that they must then be inserted in a level order way! But if we see leetcode implementation of this problem, they ask us to do different things, for which the given approach below, have to be twisted a little. Lets first deal with this easy one.
// What we are actually doing is, associating a horizontal dist with each node.. and traversing the tree in level order way then. At each node we append its data to a vector that stores data correspoding to that horizontal level. Since the traversal is level order, Data in that vector is already in top node to down node manner and data at same level in left to right manner, so we are saved from hassle. To do this: we make a map (note that map here is ordered collection whose iterator is sorted, this is necessary, as we have to take out values in left most (most negative) horizontal dist to most positive (right most) horizontal dist). To do level order traversal, we will need a queue, but this queue also need to store the horizontal dist. So instead, the queue is of type pair<Node *, int> where int is horizontal distance. And the map similarly, of type <int,vector<int>> that is mapping of horizontal distance to vector of nodes at that distance. Push the root into queue and run a loop until it is empty, at each step extract the node and horizontal distance, make a entry map[horizontal].push(data-of-node) and then push left of node with horizontal as current-1 and right as current+1 (if exists). At end of this loop, iterate through the map's vector's and insert elements into ans vector to be returned.

// given below the approach is a trickier version of problem

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Solution
{
public:
    // Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        map<int, vector<int>> m;    // horizontal dist, nodes
        queue<pair<Node *, int>> q; // node pointer, horizontal dist
        q.push(make_pair(root, 0));
        while (!q.empty())
        {
            pair<Node *, int> p = q.front();
            q.pop();
            Node *temp = p.first;
            int hd = p.second;
            m[hd].push_back(temp->data);
            if (temp->left)
                q.push(make_pair(temp->left, hd - 1));
            if (temp->right)
                q.push(make_pair(temp->right, hd + 1));
        }
        for (auto i : m)
        {
            for (auto j : i.second)
            {
                ans.push_back(j);
            }
        }
        return ans;
    }
};

// Here, the condition is, if multiple nodes are on same horizontal distance and same level, then the must be inserted in vector in SORTED WAY. Due to this, we now need to keep track of levels as well. The map now stores horizontal dist mapped to another map that stores level mapped to vector of data. THis is done because data has to be sorted level wise (if we sort overall, top level data could go below, and if we used a set, duplicate data could get lost). Similarly, queue also needs to store node, horizontal as well as level. Rest operations are same. Just at the end at time of insertion into answer vector, before traversing each vector level wise stored in the map, they have to be sorted. THen ans is returned!

class Solution2
{
public:
    // Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        map<int, map<int, vector<int>>> m;     // horizontal dist, level, nodes data
        queue<pair<Node *, pair<int, int>>> q; // node pointer, horizontal, level
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        q.push(make_pair(root, make_pair(0, 0)));
        while (!q.empty())
        {
            pair<Node *, pair<int, int>> p = q.front();
            q.pop();
            Node *temp = p.first;
            int hd = p.second.first;
            int lvl = p.second.second;
            m[hd][lvl].push_back(temp->data);
            if (temp->left)
                q.push(make_pair(temp->left, make_pair(hd - 1, lvl + 1)));
            if (temp->right)
                q.push(make_pair(temp->right, make_pair(hd + 1, lvl + 1)));
        }
        for (auto i : m)
        {
            for (auto j : i.second)
            {
                sort(j.second.begin(), j.second.end());
                for (auto k : j.second)
                {
                    ans.push_back(k);
                }
            }
        }
        return ans;
    }
};