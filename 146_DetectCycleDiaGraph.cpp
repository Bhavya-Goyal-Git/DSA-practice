#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

// Problem : Detect whether a cycle is there in given DiGraph

// Approach : We already did the problem using DFS in which we had to maintain another array dfsVisited to check if it lied in same line of recursion. Here is a approach using BFS, or Kahn's algo. The algo is for doing topological sort of DiGraph using Bfs, but we know topo sort only exists for a acyclic graph. Using this fact, we try finding topo sort of given graph, and if vertices in topo sort are less than the number of vertices, a cycle is detected. (because in BFS way of finding topo sort, indegree of certain nodes if cycle is present will never become 0 and they will not make it to topo sort)
// So, we do topo-sort bfs, that is using a indegree array and a queue and maintain a count of nodes in this. At end we compare the nodes, if equal to vertices, no cycles, else graph is cyclic

vector<vector<int>> buildGraph(vector<pair<int, int>> &edges, int n, int m)
{
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
        adj[edges[i].first].push_back(edges[i].second);
    return adj;
}

vector<int> getIndegree(vector<pair<int, int>> &edges, int n, int m)
{
    vector<int> v(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        v[edges[i].second]++;
    }
    return v;
}

int doTopoSortBFS(vector<vector<int>> &adj, vector<int> &indegree, int n)
{
    queue<int> q;
    int count = 0; // counts number of vertices in toposort
    for (int i = 1; i < n + 1; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        count++;
        for (int neighbour : adj[node])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }
    return count;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    // build diGraph
    vector<vector<int>> adj = buildGraph(edges, n, edges.size());
    vector<int> indegree = getIndegree(edges, n, edges.size());

    int count = doTopoSortBFS(adj, indegree, n);
    if (count != n)
        return true;
    return false;
}