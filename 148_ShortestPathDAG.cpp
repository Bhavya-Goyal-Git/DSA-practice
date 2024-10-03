#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/shortest-path-in-dag_8381897?leftPanelTabValue=PROBLEM

// Problem : Given a weighted-Directed-Acyclic Graph, (negative weights may be there too), Find the shortest path from node 0 to every other node. Return it as vector of int. If a node is unreachable from node 0, make its distance -1.

// Approach : Bellarman ford's algo, works with negative weights and gives all path-lengths from one node to every other. It also works with cyclic graphs and can even detect negative cycles (cycle around which sum of weights is negative). However its time comp is O(VE).. when we already know that our graph is acyclic, we don't need such strong measure..
// Here is special algo for DAG's, for all shortest paths from a single vertex, that has time comp of O(V+E), it works with negative weights but does not work with cycles of any kind. Since we know given graph is acyclic we go for this algo.
// This algo relies on the fact that for a DAG, a topological ordering will exist, and if we relax edges (weights) as per the ordering, we can calculate shortest paths in a single pass (linear order of topo sort) So, first of all, build the DAG and get its topo sort into a stack (DFS method) using visited array etc. When we have the topo sort we can start the processing. We make an answer array marking all distances to inf (int_max here) and only the source distance 0 (node from itself). Then we process the stack, get the popped out top, check if its distance is not infinity, if not, then try relaxing its edges.. that is go to its neighbours and ask if (distance to this node) + (weight of edge from this to neighbour) is less than the current value of (distance to neighbour), if yes, update the (distance to neighbour).. In this way, edges will be relaxed in topological order. After the stack is empty make the INT_MAX values in the vector as -1, as per asked by the question.

vector<vector<pair<int, int>>> buildWeightedGraph(int n, int m, vector<vector<int>> &edges)
{
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++)
    {
        adj[edges[i][0]].push_back(make_pair(edges[i][1], edges[i][2]));
        // is vertex se                     is vertex par, is weight ki
    }
    return adj;
}

void getTopoSort(int vertex, vector<vector<pair<int, int>>> &adj, stack<int> &s, bool *visited)
{
    visited[vertex] = true;
    for (pair<int, int> p : adj[vertex])
    {
        if (!visited[p.first])
        {
            getTopoSort(p.first, adj, s, visited);
        }
    }
    s.push(vertex);
}

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    // construct weighted adjacency matrix
    vector<vector<pair<int, int>>> adj = buildWeightedGraph(n, m, edges);
    // getting topological sort of DAG using DFS
    bool visited[n] = {0};
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            getTopoSort(i, adj, s, visited);
        }
    }
    // Stack Now has the topo sort with top element as beginning of it
    vector<int> ans(n, INT32_MAX);
    ans[0] = 0;
    // relaxing edges in topological order
    while (!s.empty())
    {
        int i = s.top();
        s.pop();
        if (ans[i] != INT32_MAX)
        {
            for (pair<int, int> p : adj[i])
            {
                if (ans[i] + p.second < ans[p.first])
                {
                    ans[p.first] = ans[i] + p.second;
                }
            }
        }
    }
    // making non-reachables as -1
    for (int i = 0; i < n; i++)
    {
        if (ans[i] == INT32_MAX)
        {
            ans[i] = -1;
        }
    }
    return ans;
}