#include <iostream>
#include <vector>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

// Problem : Given edges as vector of pairs and number of nodes (Directed graph banane ki saamagri), Return 1 if graph is cyclic or return 0. Graph may be disconnected.

// Approach : In a directed graph we can't use the parent method used for undirected graphs. Because here, a cycle of length 2 can exist. Also, we may reach a node that is pre-visited, not a parent, yet not cyclic region (as node has only indegree not out degree), Here we are using DFS to do something else then.
// Along with visited array that keeps track whether node is already visited or not, we make another array DfsVisited, this marks the node in current recursive stack (jo stack mei hongi true hongi). When doing dfs now, if we encounter a node that is visited as well as dfsVisited (abhi chain mei hai), then we declare a cycle. Else, if unvisited we make a recursive call and store ans etc.

vector<vector<int>> buildGraph(vector<pair<int, int>> &edges, int n, int m)
{
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
        adj[edges[i].first].push_back(edges[i].second);
    // be careful while building, this is a directed graph
    return adj;
}

bool isCyclicDFS(int node, bool *visited, bool *dfsVisited, vector<vector<int>> &adj)
{
    visited[node] = true;
    dfsVisited[node] = true;
    for (int neighbour : adj[node])
    {
        if (visited[neighbour] && dfsVisited[neighbour])
            return true;
        else if (!visited[neighbour])
        {
            bool test = isCyclicDFS(neighbour, visited, dfsVisited, adj);
            if (test)
                return true;
        }
    }
    dfsVisited[node] = false; // backtracking
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    // building the graph
    vector<vector<int>> adj = buildGraph(edges, n, edges.size());
    bool visited[n + 1] = {0};    // for nodes visited or not
    bool dfsVisited[n + 1] = {0}; // for is the node in current chain of dfs
    for (int i = 1; i < n + 1; i++)
    {
        if (!visited[i])
        {
            bool test = isCyclicDFS(i, visited, dfsVisited, adj);
            if (test)
                return 1;
        }
    }
    return 0;
}