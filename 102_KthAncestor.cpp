#include <iostream>
using namespace std;

// Problem Link : https://www.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1

// Problem : Given a binary tree, a node (int), and a positive integer k. Your task is to complete the function kthAncestor(), the function should return the kth ancestor of the given node in the binary tree. If there does not exist any such ancestor then return -1.
// Note:
// 1. It is guaranteed that the node exists in the tree.
// 2. All the nodes of the tree have distinct values.

// Approach : This problem can be solved similar to the way we solved first common ancestor. By returning Null or the node containing the data, we can tackle ancestors. We make a recursive function with base case of null. (this function returns a node pointer to the kth ancestor!) Another base case is when root->data == n (n is the node whose ancestor has to be found). If yes, we return root. Now, first we make recursive calls to left and right trees and store the pointers obtained in leftAns and rightAns. (Note that only 1 out of these can be not null or both can be null.. both will never be not null together). If anyone out of these returned results is not Null, we decrement the value of K (number of ancestor).. then we check if k has turned 0 (if yes, then return root as root is our required ans) Else we return leftans or rightans (whatever was not null). This recursive function is called in main function. One check now has to be done (if ans == NULL or ans->data == n) [answer mila hee nahi yaa answer khud same node hee aagaya (possible when root node is being searched as k can not be 0 as per question, also possible when k during the recursive function 0 hee nahi ho paya, that is kth ancestor nahi exist karta, lekin baaaki karte hai) ] then return -1.. else return ans->data.

struct Node
{
    int data;
    struct Node *left, *right;
};

Node *solve(Node *root, int &k, int n)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n)
    {
        return root;
    }
    Node *leftAns = solve(root->left, k, n);
    Node *rightAns = solve(root->right, k, n);

    if (leftAns != NULL && rightAns == NULL)
    {
        k--;
        if (k == 0)
        {
            return root;
        }
        return leftAns;
    }
    else if (leftAns == NULL && rightAns != NULL)
    {
        k--;
        if (k == 0)
        {
            return root;
        }
        return rightAns;
    }
    return NULL;
}

int kthAncestor(Node *root, int k, int node)
{
    Node *ans = solve(root, k, node);
    if (ans == NULL || ans->data == node)
    {
        return -1;
    }
    return ans->data;
}