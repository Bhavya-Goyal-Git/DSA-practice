#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

// Problem link : https://www.geeksforgeeks.org/problems/huffman-encoding3345/1

// Problem : Given a string S of distinct character of size N and their corresponding frequency f[ ] i.e. character S[i] has f[i] frequency. Your task is to build the Huffman tree print all the huffman codes in preorder traversal of the tree. Note: While merging if two nodes have the same value, then the node which occurs at first will be taken on the left of Binary Tree and the other one to the right, otherwise Node with less value will be taken on the left of the subtree and other one to the right.

// Approach : We just have to make huffman tree using priority queue (min heap of frequencies) and then traverse it using preorder. Remember to set left and right pointers null, else it causes errors, and remember to declare cmp as class or struct, plain function will cause error!

class Node
{
public:
    int freq;
    Node *left = NULL, *right = NULL;
    Node(int f)
    {
        freq = f;
    }
};

class cmp
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->freq > b->freq;
    }
};

class Solution
{
public:
    static void preorder(Node *root, string temp, vector<string> &ans)
    {
        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(temp);
            return;
        }
        preorder(root->left, temp + '0', ans);
        preorder(root->right, temp + '1', ans);
    }
    vector<string> huffmanCodes(string S, vector<int> f, int N)
    {
        priority_queue<Node *, vector<Node *>, cmp> pq;
        for (int i = 0; i < N; i++)
        {
            pq.push(new Node(f[i]));
        }
        while (pq.size() > 1)
        {
            Node *l = pq.top();
            pq.pop();
            Node *r = pq.top();
            pq.pop();
            Node *newNode = new Node(l->freq + r->freq);
            newNode->left = l;
            newNode->right = r;
            pq.push(newNode);
        }
        Node *root = pq.top();
        vector<string> ans;
        string temp = "";
        preorder(root, temp, ans);
        return ans;
    }
};