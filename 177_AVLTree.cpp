#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data, height;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        height = 1;
        left = NULL;
        right = NULL;
    }
};

int getHeight(Node *root)
{
    if (root == NULL)
        return 0;
    else
        return root->height;
}

// RR CASE
Node *leftRotation(Node *root)
{
    Node *child = root->right;
    Node *childLeft = child->left;
    child->left = root;
    root->right = childLeft;
    // rebalance heights
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));
    // return new root
    return child;
}

// LL CASE
Node *rightRotation(Node *root)
{
    Node *child = root->left;
    Node *childRight = child->right;
    child->right = root;
    root->left = childRight;
    // rebalance heights
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));
    // return new root
    return child;
}

Node *InsertInAVL(Node *root, int key)
{
    if (root == NULL)
        return new Node(key);
    if (root->data > key)
        root->left = InsertInAVL(root->left, key);
    else if (root->data < key)
        root->right = InsertInAVL(root->right, key);
    // ignoring equality case.. or we can write else return root;

    // reestablish heights
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    // check balance
    int balance = getHeight(root->left) - getHeight(root->right);
    if (balance > 1 && key < root->left->data)
    {
        // left left case
        return rightRotation(root);
    }
    else if (balance > 1 && key > root->left->data)
    {
        // left right case
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }
    else if (balance < -1 && key > root->right->data)
    {
        // right right case
        return leftRotation(root);
    }
    else if (balance < -1 && key < root->right->data)
    {
        // right left case
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }
    return root; // balance was intact
}

int getMin(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}

int getBalance(Node *root)
{
    return getHeight(root->left) - getHeight(root->right);
}

Node *deleteFromAVL(Node *root, int key)
{
    if (root->data > key)
    {
        root->left = deleteFromAVL(root->left, key);
    }
    else if (root->data < key)
    {
        root->right = deleteFromAVL(root->right, key);
    }
    else // element found, now deleting
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            Node *ll = root->left;
            root->left = NULL;
            delete root;
            return ll;
        }
        else if (root->right != NULL && root->left == NULL)
        {
            Node *rr = root->right;
            root->right = NULL;
            delete root;
            return rr;
        }
        else
        {
            int rightminimum = getMin(root->right);
            root->data = rightminimum;
            root->right = deleteFromAVL(root->right, rightminimum);
            // not returning root here, cause now its a path node and must be checked for balancing
        }
    }
    // reestablish heights
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    // check balance
    int balance = getBalance(root);
    if (balance > 1)
    {
        if (getBalance(root->left) < 0) // left right case
            root->left = leftRotation(root->left);
        // left left case or 2nd part of left right case
        return rightRotation(root);
    }
    else if (balance < -1)
    {
        if (getBalance(root->right) > 0) // right left case
            root->right = rightRotation(root->right);
        // right right case or 2nd part of right left case
        return leftRotation(root);
    }
    return root; // balance was intact
}

void getPreOrder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    getPreOrder(root->left);
    getPreOrder(root->right);
}
void getInOrder(Node *root)
{
    if (root == NULL)
        return;
    getInOrder(root->left);
    cout << root->data << " ";
    getInOrder(root->right);
}

void getLevelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (q.size() > 0)
    {
        int qlen = q.size();
        for (int i = 0; i < qlen; i++)
        {
            Node *temp = q.front();
            q.pop();
            cout << temp->data << " ";
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
        cout << "\n";
    }
}

int main()
{
    Node *root = NULL;
    int arr[] = {
        5, 3, 6, 2, 4, 7, 1};
    for (auto i : arr)
    {
        root = InsertInAVL(root, i);
    }
    getLevelOrder(root);
    // getPreOrder(root);
    // root = deleteFromAVL(root, 40);
    // cout << "After deleting \n\n";
    // getPreOrder(root);
}