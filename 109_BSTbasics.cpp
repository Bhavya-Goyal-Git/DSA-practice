#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// IMPORTANT NOTES :
// Due to its behaviour, InOrder Traversal of a Binary search Tree (BST) is always in sorted order.
// Leftmost node will be MINIMUM value in the tree and Rightmost node will be MAXIMUM value in the tree.

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// level order traversal, just for viewing the tree
void leverOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
}

// function to insert 1 node into a bst
Node *insertIntoBST(Node *root, int data)
{
    if (root == NULL)
    {
        Node *node = new Node(data);
        return node;
    }
    if (data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    else
    {
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}

// function to build a BST, takes elements until we input -1
void buildBST(Node *&root)
{
    cout << "Enter data : " << "\n";
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

// function to search for an element inside BST O(log(n))
bool searchInBST(Node *root, int x)
{
    // RECURSIVE METHOD

    // if (root == NULL)
    //     return false;
    // if (root->data == x)
    //     return true;
    // if (x > root->data)
    //     return searchInBST(root->right, x);
    // else
    //     return searchInBST(root->left, x);

    // ITERATIVE METHOD
    Node *temp = root;
    while (temp != NULL)
    {
        if (temp->data == x)
            return true;
        else if (temp->data > x)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return false;
}

// Data of leftmost Node (minimum of tree)
int findMin(Node *root)
{
    Node *temp = root;
    int d;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}

// Data of rightmost Node (maximum of tree)
int findMax(Node *root)
{
    Node *temp = root;
    int d;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->data;
}

// deletes node with given key value from BST and returns the new root of tree.
// If node to delete has no children, simply delete it and return null
// If it has only 1 child (left/right) then store the child in temporary pointer and delete the node, then return the temporary pointer
// If node has 2 children, then we can replace this node with its inorder predecessor and then instead delete that node, or replace node with inorder successor and then instead delete it. Here, we are finding and deleting the inorder successor (which is same as finding the minimum element in the right subtree of a node), We replace the data, then recursively call the function to delete the newdata from root's right.
Node *deletefromBST(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        // handle deleting
        // 0 child case
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // single child cases
        else if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else
        { // both childs are not null
            int newkey = findMin(root->right);
            root->data = newkey;
            root->right = deletefromBST(root->right, newkey);
            return root;
        }
    }
    if (root->data < key)
    {
        root->right = deletefromBST(root->right, key);
    }
    else
    {
        root->left = deletefromBST(root->left, key);
    }
    return root;
}

int main()
{
    Node *root = NULL;
    buildBST(root);
    cout << "\nPrinting tree level order : \n";
    leverOrderTraversal(root);
    // cout << "\nDELETING A NODE\n";
    // root = deletefromBST(root, 2);
    // cout << "\nPrinting tree level order : \n";
    // leverOrderTraversal(root);
}