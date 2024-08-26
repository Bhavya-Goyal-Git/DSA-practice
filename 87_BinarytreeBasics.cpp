#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Structure for a node of binary tree
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

// Building a tree using DFS (depth first search)
Node *treebuilder(Node *n)
{
    cout << "\nEnter data for node : ";
    int number;
    cin >> number;
    if (number == -1)
    {
        return NULL;
    }
    n = new Node(number);
    cout << "\nEnter for left of " << n->data << endl;
    n->left = treebuilder(n->left);
    cout << "\nEnter for right of " << n->data << endl;
    n->right = treebuilder(n->right);
    return n;
}

// Traversing the tree level wise, also called Breadth First Search (bfs)
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

// level order traversal but in reverse, ie last level is printed first (left to right) then second last and so on upto root. We will need a stack along with queue.
void reverselevelOrderTraversal(Node *root)
{
    queue<Node *> q;
    stack<Node *> s;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        s.push(temp);

        // Note : Enqueuing right child first!!
        if (temp->right)
            q.push(temp->right);
        if (temp->left)
            q.push(temp->left);
    }

    while (!s.empty())
    {
        Node *temp = s.top();
        s.pop();
        cout << temp->data << " ";
    }
}

// Learning Tip : "In" means between, so L'N'R, "Pre" means before, so 'N'LR, "Post" means after, so LR'N'

// In order Traversal (L N R)
void inOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << endl;
    inOrderTraversal(root->right);
}

// Pre order Traversal (N L R)
void preOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << endl;
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// Post order Traversal (L R N)
void postOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << endl;
}

// building a tree in level order way
void levelordertreebuilder(Node *&root)
{
    queue<Node *> q;
    int data;
    cout << "Enter data for root : ";
    cin >> data;
    root = new Node(data);
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        int d;
        cout << "Enter data left of " << temp->data;
        cin >> d;
        if (d != -1)
        {
            temp->left = new Node(d);
            q.push(temp->left);
        }
        cout << "Enter data right of " << temp->data;
        cin >> d;
        if (d != -1)
        {
            temp->right = new Node(d);
            q.push(temp->right);
        }
    }
}

// Finding height of binary tree
int heightoftree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(heightoftree(root->left), heightoftree(root->right));
}

void givepath(Node *root, bool &hasfound, int level, int num, stack<pair<Node *, int>> &s)
{
    if (root == NULL || hasfound)
    {
        return;
    }
    if (root->data == num)
    {
        hasfound = true;
        s.push(make_pair(root, level));
        return;
    }
    s.push(make_pair(root, level));
    givepath(root->left, hasfound, level + 1, num, s);
    if (hasfound)
        return;
    givepath(root->right, hasfound, level + 1, num, s);
    if (hasfound)
        return;
    s.pop();
}

int main()
{
    Node *root;
    root = treebuilder(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // levelordertreebuilder(root);
    cout << "Level order traversal : " << endl;
    leverOrderTraversal(root);
    // cout << "\nReverse Level order traversal : " << endl;
    // reverselevelOrderTraversal(root);
    cout << "\nHeight of tree is : " << heightoftree(root) << endl;

    return 0;
}