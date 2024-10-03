#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Graph can be represented in 2 manners, a adjacency matrix which has O(n2) space comp, or a adjacency list {which can be a unordered_Map or (if the nodes are int or some way convertible to int) vector of list/vector or if no. of nodes already known, an array of vectors.} Adjacency list will have space comp of O(m+n) where m is no. of edges and n nodes.

// For unweighted Graphs --> BFS is best way to get shortest distances (parent backtracking), whether graph is directed/undirected or cyclic/acylic
// For weighted Graphs --> if weights are non-negative Djikstra's algo. (both cyclic/acyclic or directed/undirected)
// --> if there are negative weights : Bellar-man ford (both cyclic/acyclic and directed/undirected)
// --> if negative wieghts are there, but it is known graph is Directed, Acyclic : Algo using topological sort of the graph

// Given the adjacency list as a vector of vectors (index represents node value), and number of nodes n, prints the breadth first search of graph. BFS uses queue, time comp O(m+n)
void bfsTraversal(int n, vector<vector<int>> &adj)
{
    queue<int> q;
    bool visited[n] = {0};
    q.push(0);
    visited[0] = true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (int child : adj[node])
        {
            if (visited[child] == false)
            {
                q.push(child);
                visited[child] = true;
            }
        }
    }
}

int main()
{
    vector<vector<int>> v = {{1, 2, 3}, {5}, {4}, {}, {}, {}};
    int n = 6;
    bfsTraversal(n, v);
    return 0;
}