#include <iostream>
#include <queue>
using namespace std;

// Problem : Given 2 BST, merge them and return the root of new merged BST. On the internet, this problem just asks to return a vector of int, that will be inorder of merged BST, but that is not chanllenging enough, so this is done locally.

// Approach : WE could have stored the inorder traversal of both given BST in a vector and then merged the 2 sorted arrays using known algo and then made a new bst from vector inorder given using the known algo of finding mid. Time complexity would be O(m+n) and space would be O(2m+2n) that is too much. We need to find a way to reuse the same nodes and prevent storing them, reducing space to O(h1+h2) [for recursion only].
// So we would have to play with pointers. Lets do it in few steps. First we have to obtain a straight order out of the bst's given.. rather than converting into inorder of vectors, we could flatten them into sorted LLs. To do that, we have used a new method here.. we recieve the root and the head reference (initially null) to the function. we return back if root is null (base case) else we first obtain LL from the right side (this is a simple recursive call with root->right, does not return anything). Then we make root's right as head. (this adds current node into head of LL) and then head = root. next we simply make a call with root->left. Remember again, it does not return anything. This function builds up a sorted LL out of BST by going right to left in recursive manner. Obtain the LL for both the trees given.
// Now we need to obtain 1 Linked list (sorted) out of the two we have. For that we apply the standard known algorithm that converts 2 sorted LLs into 1 sorted LL. This returns the head of new LL formed. (Remember this algo plays with pointers and does NOT create a new LL, but REARRANGES nodes as per need).
// Now we have a sorted LL. We need to convert that into a BST. We have a function that does that, but we need number of nodes in the LL for that to work. So obtain that first using a simple while loop.
// To convert the sorted LL into a BST, we make a recursive function that takes head of LL (as reference, as this will be updated), number of nodes in LL, and finally returns the root of formed BST. The base case is when head is null or number of nodes are <=0 then we simply return NULL. else: we firstly build the left subtree of a node. Make a temp pointer and make recursive call with head to that. After left tree is built, now we make a root pointer, and assign it the head. We make its left the above temp pointer and then remember to update head to head->right. Then we make a recursive call with head, by directly assigning it to root->right. At the end, remember to return root. This function builds a BST from LL using the bottom up approach.
// YAY, we have the root of merged BST! (bonus: its balanced too damn!!)

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
};

// ====================== UTILITY FUNCTIONS =============================
// function to insert 1 node into a bst
TreeNode *insertIntoBST(TreeNode *root, int data)
{
    if (root == NULL)
    {
        TreeNode *node = new TreeNode(data);
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
void buildBST(TreeNode *&root)
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
// function that prints a Linked List Given its head
void printLL(TreeNode *head)
{
    cout << "\n";
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->right;
    }
    cout << "\n";
}
void leverOrderTraversal(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
}
// ================= Actual Functions for Problem ===========================================

// takes a bst root and a head node for linked list, flattens the bst into sorted LL and makes head variable the head of sorted LL
void flattenBSTtoSortedLL(TreeNode *root, TreeNode *&head)
{
    if (root == NULL)
        return;
    flattenBSTtoSortedLL(root->right, head);
    root->right = head;
    head = root;
    flattenBSTtoSortedLL(root->left, head);
}

// merges 2 sorted LL into 1 sorted LL
TreeNode *mergeLLs(TreeNode *head1, TreeNode *head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    else if (head2 == NULL)
    {
        return head1;
    }
    if (head2->data < head1->data)
    {
        TreeNode *temp = head1;
        head1 = head2;
        head2 = temp;
    }
    TreeNode *headtoreturn = head1;
    TreeNode *next1 = head1->right;
    // Now head1 has smaller first member ensured
    while (next1 != NULL && head2 != NULL)
    {
        if (head2->data >= head1->data && head2->data <= next1->data)
        {
            head1->right = head2;
            TreeNode *temp = head2->right;
            head2->right = next1;
            head1 = head2;
            head2 = temp;
        }
        else
        {
            head1 = next1;
            next1 = next1->right;
        }
    }
    if (next1 == NULL && head2 != NULL)
    {
        head1->right = head2;
    }
    return headtoreturn;
}

// Returns number of nodes in a linked list
int countNodes(TreeNode *head)
{
    int count = 0;
    while (head != NULL)
    {
        head = head->right;
        count++;
    }
    return count;
}

// Takes a sorted LL and number of nodes in it, and turns into a BST
TreeNode *BSTfromSortedLL(TreeNode *&head, int n)
{
    if (n <= 0 || head == NULL)
    {
        return NULL;
    }
    TreeNode *left = BSTfromSortedLL(head, n / 2);
    TreeNode *root = head;
    root->left = left;
    head = head->right;
    root->right = BSTfromSortedLL(head, n - 1 - n / 2);
    return root;
}

// Main function to which 2 BST can be send for merging
TreeNode *mergeBST(TreeNode *root1, TreeNode *root2)
{
    // Step1 -> Flatten BST's into Sorted LLs
    TreeNode *head1 = NULL, *head2 = NULL;
    cout << "\nFLATTENING THE TREES INTO SORTED LLS";
    flattenBSTtoSortedLL(root1, head1);
    cout << "\nPrinting LL 1 : ";
    printLL(head1);
    flattenBSTtoSortedLL(root2, head2);
    cout << "\nPrinting LL 2 : ";
    printLL(head2);
    // Step2 -> Merge 2 sorted LLs to obtain 1 sorted LL
    cout << "\nMERGING TWO SORTED LLS : \n";
    TreeNode *head = mergeLLs(head1, head2);
    cout << "\nPrinting MERGED LL : ";
    printLL(head);
    // Step3 -> Obtain number of nodes in combined LL (we need this for step4)
    int n = countNodes(head);
    cout << "\nNUMBER OF NODES IN MERGED LIST : " << n << "\n";
    // Step4 -> Convert a sorted LL into a BST
    cout << "\nSENDING FOR LL TO BST METHOD!!\n";
    TreeNode *root = BSTfromSortedLL(head, n);
    return root;
}

int main()
{
    TreeNode *root1 = NULL;
    cout << "\nMAKING TREE 1\n";
    buildBST(root1);
    cout << "\nPrinting tree level order for tree 1 : \n";
    leverOrderTraversal(root1);
    TreeNode *root2 = NULL;
    cout << "\nMAKING TREE 2\n";
    buildBST(root2);
    cout << "\nPrinting tree level order for tree 2 : \n";
    leverOrderTraversal(root2);
    cout << "\nSENDING TREES FOR MERGING : \n";
    TreeNode *root = mergeBST(root1, root2);
    cout << "\nPrinting tree level order for MERGED RESULT : \n";
    leverOrderTraversal(root);
    return 0;
}