#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Problem : Same problem as previous, Topological sort a given DiaGraph.

// Approach : This is another way to topo sort. This uses BFS, and this algo is known as Kahn's algorithm. We will need visited and another array of int, indegree. When we build the graph, we also build indegree array. It stores indegree of each node. Then we make a call to bfs function.
// First of all we push all nodes with 0 indegree into a queue. Then we start normal bfs using while loop, pop out front and add it to answer vector, but at the time of pushing neighbours into the queue, we first of all decrease the indegree of them (as current node is removed), and then if indegree has become zero, we push them into the queue. At last we return the ans vector.

vector<int> buildGraphandIndegree(vector<vector<int>> &edges, int n, int m, vector<vector<int>> &adj)
{
    vector<int> indegree(n, 0);
    for (int i = 0; i < m; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        indegree[edges[i][1]]++;
    }
    return indegree;
}

vector<int> topoSortBFS(vector<vector<int>> &adj, bool *visited, vector<int> &indegree, int v)
{
    queue<int> q;
    vector<int> ans;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (int neighbour : adj[node])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }
    return ans;
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    // building a directed graph's adjacency list and getting indegrees
    vector<vector<int>> adj(v);
    vector<int> indegree = buildGraphandIndegree(edges, v, e, adj);
    bool visited[v] = {0};
    vector<int> ans = topoSortBFS(adj, visited, indegree, v);
    return ans;
}