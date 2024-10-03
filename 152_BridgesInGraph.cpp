#include <iostream>
#include <vector>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/bridges-in-graph_893026?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

// Problem : Given an undirected graph of V vertices and E edges. Your task is to find all the bridges in the given undirected graph. A bridge in any graph is defined as an edge which, when removed, makes the graph disconnected (or more precisely, increases the number of connected components in the graph).

// Approach : This question can be solved using modified dfs, using Tarjan's algorithm. In the algorithm, we traverse the graph dfs wise and after traversing children of a node, see whether the edge could have been a graph. To proceed: we maintain a timer variable (passed by ref) initially 1. We maintain 2 arrays, low and disc (lowest time and discovery time), along with visited array required for dfs. We also need to keep track of parent of a node, but in dfs that is a simple integer. Now the algo is as follows.. On visiting a node, we firstly mark it visited and then set its lowest as well as discovery time to current value of timer and increment timer variable. Now we traverse the neighbours of this node, simply ignore the parent node. Now 2 cases arise, when neighbour is already visited and when its not. If already visited, it means this is a cyclic edge, and we update the low[node] to min(low[node],disc[neighbour]).. Else, if node was unvisited, we visit it (make recursive call), after the call, update low of current node (as adjacent have been updated) as low[node] = min(low[node],low[neighbour]).. After doing this, we can verify if it was a bridge edge.. if(low[neighbour] > dis[node]) then its a bridge, lowest time to reach a node is greater than discovery of parent node that means it must be a bridge edge. We push such edge into ans vector. As this is dfs with modification, time comp is O(V+E)

vector<vector<int>> buildGraph(vector<vector<int>> &edges, int v, int e)
{
    vector<vector<int>> adj(v);
    for (int i = 0; i < e; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    return adj;
}

void dfs(int node, int parent, int low[], int disc[], int &timer, bool visited[], vector<vector<int>> &adj, vector<vector<int>> &ans)
{
    visited[node] = true;
    low[node] = timer;
    disc[node] = timer;
    timer++;
    for (int neighbour : adj[node])
    {
        if (neighbour == parent)
            continue;
        if (!visited[neighbour])
        {
            dfs(neighbour, node, low, disc, timer, visited, adj, ans);
            low[node] = min(low[node], low[neighbour]);
            if (low[neighbour] > disc[node])
            {
                ans.push_back({node, neighbour});
            }
        }
        else
        {
            // already visited neighbour i.e. this is a back edge
            low[node] = min(low[node], disc[neighbour]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
    // building undirected graph
    vector<vector<int>> adj = buildGraph(edges, v, e);

    bool visited[v] = {0};
    int low[v];
    int disc[v];
    int timer = 1;
    vector<vector<int>> ans;
    dfs(0, -1, low, disc, timer, visited, adj, ans);
    return ans;
}