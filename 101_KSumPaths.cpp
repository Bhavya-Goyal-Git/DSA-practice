#include <iostream>
#include <unordered_map>
using namespace std;

// Problem link : https://www.geeksforgeeks.org/problems/k-sum-paths/1

// Problem : Given a binary tree and an integer k, the task is to count the number of paths in the tree such that the sum of the nodes in each path equals k. A path can start from any node and end at any node and must be downward only.

// Approach : After we have traversed lets say, some path, and have that path with us, we need to find subarrays in it with given sum k. A way this could be done is, store the node currentlt being visited in a vector, then make left and right recursive calls. Then at end of calls, check the vector from behind if element sum is k. This would ensure all paths are checked from the back. But but but.. in worst case this also could reach O(n2) .. but we have to achieve O(n), for that we would need a hashmap!
// O(n) method: we make variables : count - number of pairs found, passed as reference, currentSum (long long) - Stores the current Sum of the path we have followed, and a unorderedMap <long long to int> that stores the sum of path and its frequency (neagtives and zeros are also there, so this is needed). We make a recursive fuction with base case of null. At each step, we first increase the currentSum by root->data. Then we check if it has made to k. (currentsum ==k) if yes, we increase the count. Now we check if (currentSum-k) is in the hashMap. [Effectively this checks if this path we followed can be broken into 2 smaller paths of length currentSum-k and k, then sum of k one can be used by us!]. If the entry is present, we increment count by its frequency i.e. count+=map(currentSUm-k). Now we will add the entry of currentSum into our map i.e. map[currentSum]++ (note that it already begins by 0). THen we make left and right recursive calls. Then after the calls, we have to backtrack the entry in hashmap of currentSUm. so we do map[currentSum]--. The count variable after end of recursive process has our answer.

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
    void solve(Node *root, int k, int &count, long long currentsum, unordered_map<long long, int> &m)
    {
        if (root == NULL)
        {
            return;
        }
        currentsum += root->data;
        if (currentsum == k)
        {
            count++;
        }
        if (m.find(currentsum - k) != m.end())
        {
            count += m[currentsum - k];
        }
        m[currentsum]++;
        solve(root->left, k, count, currentsum, m);
        solve(root->right, k, count, currentsum, m);
        m[currentsum]--; // backtracking
    }
    int sumK(Node *root, int k)
    {
        int count = 0;
        unordered_map<long long, int> m;
        solve(root, k, count, 0, m);
        return count;
    }
};