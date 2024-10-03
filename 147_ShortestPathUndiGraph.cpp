#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/shortest-path-in-an-unweighted-graph_981297?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

// Problem : Given a unweighted undirected graph, and a source and target value, return in form of a vector the shortest path from source to target.

// Approach : We have it simple as it is unweighted and undirected. If we look at how bfs works, it essentially goes through neighbours at distance 1 first, then 2 and so on.. So bfs already takes care of the fact, that a node is reached from a source in shortest steps, We just need to keep track of parent (which node added which node into queue). Once we have the parents ready, we can backtrack from the target in parents data structure until we reach the source. The path will be reverse of shortest path.
// We make a visited array as well as parent (int array). Then do normal bfs, while updating entries in parent array. Then after the bfs, parent array is populated and we can backtrack, we add entries into a vector. Remember to reverse it before returning as path we got while backtracking parent array is reverse of what we wanted.

vector<vector<int>> buildGraph(vector<pair<int, int>> &edges, int n, int m)
{
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[i].second].push_back(edges[i].first);
    }
    return adj;
}

void performBFS(vector<vector<int>> &adj, bool *visited, int *parent, int source, int target)
{
    queue<int> q;
    q.push(source);
    parent[source] = -1;
    visited[source] = true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                parent[neighbour] = node;
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
}

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{
    // build the adjacency list for graph
    vector<vector<int>> adj = buildGraph(edges, n, m);
    bool visited[n + 1] = {0};
    int parent[n + 1];
    // parent array ready karne ke liye bfs
    performBFS(adj, visited, parent, s, t);
    vector<int> ans;
    int current = t;
    while (current != -1)
    {
        ans.push_back(current);
        current = parent[current];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
