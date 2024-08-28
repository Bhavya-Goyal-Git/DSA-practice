#include <iostream>
#include <unordered_map>
using namespace std;

// Problem link : https://www.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1

// Problem : Given 2 arrays representing the inorder and post order traversal of some binary tree, construct the tree and return its root. Size of arrays is n (i.e. no of nodes in tree). Additionally, all the elements in the tree are unique!

// Approach : This question is same as previous one, constructing a tree from inorder and preorder traversal, here are some noticeable changes :
// 1. As the order is Post order, the root element in this case will be last index, so PostOrderIndex value has been set to n-1. Now this value will go down till 0, so in each recursive call we do PostIndex--. Similarly, the base case will also change to when postIndex < 0.
// 2. The postorder has LRN, and we are traversing this array from the end, so after getting the root node, we first are getting the right node. So, the first recursive call would be to right and then to the left. Also remember the fact that postIndex is passed by reference.
// 3. In this question it was given that tree has only unique elements, therefore we optimised the searching part in inorder array, by making it a map. This map is passed as reference in our recursive function for quick lookup. Makes the time complexity O(n).

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
public:
    void mapbuilder(unordered_map<int, int> &pmap, int in[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            pmap[in[i]] = i;
        }
    }
    Node *solve(int in[], int inStart, int inEnd, int post[], int &postIndex, unordered_map<int, int> &pmap)
    {
        if (postIndex < 0 || inStart > inEnd)
        {
            return NULL;
        }
        Node *root = new Node(post[postIndex]);
        postIndex--;

        int positionInInorder = pmap[root->data];

        root->right = solve(in, positionInInorder + 1, inEnd, post, postIndex, pmap);
        root->left = solve(in, inStart, positionInInorder - 1, post, postIndex, pmap);
        return root;
    }
    // Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int n, int in[], int post[])
    {
        int postOrderIndex = n - 1;
        unordered_map<int, int> pmap;
        mapbuilder(pmap, in, n);
        Node *ans = solve(in, 0, n - 1, post, postOrderIndex, pmap);
        return ans;
    }
};