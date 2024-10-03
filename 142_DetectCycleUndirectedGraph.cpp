#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/cycle-detection-in-undirected-graph_1062670?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

// Problem : Given edges, no of vertices, no of edges, (i.e. Graph banane ki saamagri), for a (maybe)disjoint, undirected graph, return "Yes" if its cyclic and "No" otherwise.

// Approach : Build the graph (adjacency list). Make a visited array helpful for traversing and also for checking if graph got disjoint components. Run a loop across this visited array which is initially all false. If node is unvisited, apply BFS/DFS from that node. If true is returned, return Yes. after the for loop, it means true was never detected, so return No.
// BFS/DFS logic to detect cycle : We are doing normal bfs dfs, just we are also maintain parent of nodes. If ever while traversing we find that we are trying to visit an already visited node, which is not the parent of currentNode, then a cycle is present. To maintain parents in bfs, we have to use a map, however in dfs, cause it goes in depths first and is recursive, parent can be a simple interger similar to node.

vector<vector<int>> buildGraph(vector<vector<int>> &edges, int n, int m)
{
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    return adj;
}

bool isCyclicBFS(int node, bool *visited, vector<vector<int>> &adj)
{
    unordered_map<int, int> childToParent;
    childToParent[node] = -1;
    queue<int> q;
    visited[node] = true;
    q.push(node);
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        for (int neighbour : adj[frontNode])
        {
            if (visited[neighbour] && neighbour != childToParent[frontNode])
            {
                // agar phele se visited hai, lekin parent nhi h
                return true; // cycle detected
            }
            else if (!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = true;
                childToParent[neighbour] = frontNode;
            }
        }
    }
    // bfs poora hogya aur kuch nahi mila
    return false;
}

bool isCyclicDFS(int node, int parent, bool *visited, vector<vector<int>> &adj)
{
    visited[node] = true;
    for (int neighbour : adj[node])
    {
        if (visited[neighbour] && neighbour != parent)
        {
            return true;
        }
        else if (!visited[neighbour])
        {
            bool test = isCyclicDFS(neighbour, node, visited, adj);
            if (test)
            {
                return true;
            }
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    // building adjacency matrix, indexes denoting node values
    // indexed with 1, 0th place empty
    vector<vector<int>> adj = buildGraph(edges, n, m);

    // visited array, indexed with 1, 0th place empty
    bool visited[n + 1] = {0};

    for (int i = 1; i < n + 1; i++)
    {
        if (!visited[i])
        {
            bool test = isCyclicBFS(i, visited, adj); // or
            // bool test = isCyclicDFS(i,-1,visited,adj);
            if (test)
            {
                return "Yes";
            }
        }
    }
    return "No";
}