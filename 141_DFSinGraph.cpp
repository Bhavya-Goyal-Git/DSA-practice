#include <iostream>
#include <vector>
using namespace std;

// Problem link: https://www.naukri.com/code360/problems/dfs-traversal_630462?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

// Problem : Given number of vertices V, Edged E and all the edges in form of vector of vector(pairs), Perform the DFS of the graph. Graph may be disjoint, so it may have 1 or more dfs component, return the vector of vector of ints, each int vector representing one such component.

// Approach : We make a adjacency list using given edges first. Then we make a array of visited, and run a loop across it, if not visited, we apply recursive dfs to it. DFS function is a recursive with base case if visited is true we return, else we append to ans vector, mark it visited, then make recursive calls to the children (or adjacent nodes). Rest is assured by recursion.
// Had we used a stack in place of recursion, we would have to push into stack in descending order, so poping back were in ascending. Also, when pushing children nodes into stack, we would have to mark them visited true, and not at time of traversal as in BFS implementation in prev ques.

vector<vector<int>> buildGraph(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(V);
    for (int i = 0; i < E; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    return adj;
}

void dfs(vector<vector<int>> &adj, vector<int> &store, int node, bool *visited)
{
    if (visited[node] == true)
    {
        return;
    }
    store.push_back(node);
    visited[node] = true;
    for (int child : adj[node])
    {
        dfs(adj, store, child, visited);
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // making adjacency list from edges (making graph)
    vector<vector<int>> adj = buildGraph(V, E, edges);

    bool visited[V] = {0};
    vector<vector<int>> ans;
    // ye karna pad raha hai becoz graph may be disconnected
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            vector<int> temp;
            dfs(adj, temp, i, visited);
            ans.push_back(temp);
        }
    }
    return ans;
}