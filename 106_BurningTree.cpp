#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

// Problem link : https://www.geeksforgeeks.org/problems/burning-tree/1

// Problem : Given a binary tree and a node data called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent. Note: The tree contains unique values.

// Approach : This is a burning problem, so it will use some form of Djiktra's algo. Here the data structure is a tree, not a graph and the tree does not have weighted edges, i.e. burning time to each node connected with a burning node is fixed, that is 1 second. To apply this algorithm, however we should have a 2 sided graph, where we can move from any node to any. Since in a tree node, buring it will next burn its both children and the parent, we already have pointers to both the children, but not to the parent node. So we have to construct a map<node * to node*> which provides us pointers from child to parent node. Also, in the question, target node is given as a mere number and not the actual pointer to that node, so we need that pointer too. For doing these 2 pre-requistie tasks before applying the actual algorithm, we make a functiom that does so. The function does level order traversal of the tree, and at each node checks if its data matches given target, if yes then store it in a ans variable.. then continue the level order.. just at time of pushing the child nodes into the queue, first make entries of them into the map.. that is map[node->left] = node (child to parent), and similar for right. Before entering into this loop, make sure to add map[root] = NUll into the map for root node. At the end, return the ans Node pointer that stores target node. Now we send this target node pointer and the map we created into the burnTree function that returns the real ans :
// The algorithm of Djiktra's needs to traverse the graph in bfs, and also maintain a set/map to avoid revisiting (reburning here) already visited (burnt) nodes. So we make a queue<node *> for bfs and a unordered_set<node*> to keep track of visited nodes. We push the target into queue and also mark it visited. Make a variable to store the time and initialize it to zero. Now we run the bfs by !q.empty(), all the children added at single step will burn at the same time, so we take current size of queue by q.size(), Make a boolean flag that will check whether any new entry was made into queue during an iteration of the for loop, because if not, we will not increase the time variable. Now run a for loop until that size. Inside this loop we pop out from queue and check for the three.. if node->left has a value and its not in visited, then push into queue and mark it visited. also make the flag true. Similarly do for right node and then for parent using the map we created. after the for loop, if any new entry has been made into the queue, we increment the time if(flag) time++; after the ending of while loop, return the time.

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
    // function that makes map of node to parent as well as return the target node
    Node *makemap(Node *root, int target, unordered_map<Node *, Node *> &nodetoParent)
    {
        queue<Node *> q;
        q.push(root);
        Node *ans;
        nodetoParent[root] = NULL;
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            if (temp->data == target)
            {
                ans = temp;
            }
            if (temp->left)
            {
                nodetoParent[temp->left] = temp;
                q.push(temp->left);
            }
            if (temp->right)
            {
                nodetoParent[temp->right] = temp;
                q.push(temp->right);
            }
        }
        return ans;
    }
    // function that returns minimum time to burn tree
    int burnTree(Node *target, unordered_map<Node *, Node *> &nodetoParent)
    {
        queue<Node *> q;
        unordered_set<Node *> visited;
        q.push(target);
        visited.insert(target);
        int timeans = 0;
        while (!q.empty())
        {
            int size = q.size();
            bool flag = false;
            for (int i = 0; i < size; i++)
            {
                Node *temp = q.front();
                q.pop();
                // check for left
                if (temp->left && (visited.find(temp->left) == visited.end()))
                {
                    flag = true;
                    visited.insert(temp->left);
                    q.push(temp->left);
                }
                // check for right
                if (temp->right && (visited.find(temp->right) == visited.end()))
                {
                    flag = true;
                    visited.insert(temp->right);
                    q.push(temp->right);
                }
                // check for parent
                if (nodetoParent[temp] && (visited.find(nodetoParent[temp]) == visited.end()))
                {
                    flag = true;
                    visited.insert(nodetoParent[temp]);
                    q.push(nodetoParent[temp]);
                }
            }
            if (flag)
            {
                timeans++;
            }
        }
        return timeans;
    }
    int minTime(Node *root, int target)
    {
        unordered_map<Node *, Node *> nodetoParent;
        Node *targetNode = makemap(root, target, nodetoParent);
        int ans = burnTree(targetNode, nodetoParent);
        return ans;
    }
};