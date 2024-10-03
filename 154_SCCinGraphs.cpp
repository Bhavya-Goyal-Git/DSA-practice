#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/count-strongly-connected-components-kosaraju-s-algorithm_1171151?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

// Problem : You are given an unweighted directed graph having 'V' vertices and 'E' edges. Your task is to count the number of strongly connected components (SCCs) present in the graph. A directed graph is said to be strongly connected if every vertex is reachable from every other vertex. The strongly connected components of a graph are the subgraphs which are themselves strongly connected.
// In simple words, a section of graph in which every vertex is reachable from every other in that section, is called a strongly connected component. We have to count number of these in the graph.

// Approach : We have KosaRaju's Algorithm for this thing. Firstly we shall describe the algo a little and then implementations. Imagine if we normally dfs travel a graph that is connected.. then we make come across that (SCC 1)->(SCC 2)->(SCC 3) and so on.. 1 to 3 is reachable due to only the link between them.. however if we reverse those links.. (SCC 1)<-(SCC 2)<-(SCC 3) then if we apply dfs, then it stops at scc1, then we need to restart and so on, and we get the scc's. Now we are wondering how to reverse these edges that connect scc's together! Reverse the entire graph, every edge. SCC will remain SCC even after reversing and these components will get disconnected. Now we face a problem, after dfs of 1 scc, how do we know the node where to begin scc again? For that, before doing the reversal, we topo sort the graph (I know graph is cyclic and this sounds vague, but we arent actually topo sorting the graph's individual nodes, but topo sorting the SCC's, if a SCC were a node, the topo sort would look like that), then we do reversal and then dfs as per values of the stack (topo sort dfs returns a stack)
// Implementation: Build the graph and apply dfs topo sort, this will fill the stack up with topo sort of SCC's. Now reverse the graph (or build a new reversed one) and remember to clear out the visited array too. After that, keep popping out of stack and apply normal dfs from the node if not visited. When we detect a unvisited node in the stack, that is beginning of a SCC, so increment a counter. Return the counter at the end!

vector<vector<int>> buildGraph(vector<vector<int>> &edges, int v, int e, bool rev)
{
    vector<vector<int>> adj(v);
    if (rev)
    {
        for (int i = 0; i < e; i++)
        {
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        return adj;
    }
    for (int i = 0; i < e; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    return adj;
}

void getTopoSortSCC(int node, bool *visited, vector<vector<int>> &adj, stack<int> &s)
{
    visited[node] = true;
    for (int neighbour : adj[node])
    {
        if (!visited[neighbour])
            getTopoSortSCC(neighbour, visited, adj, s);
    }
    s.push(node);
}

void SccDFS(int node, bool *visited, vector<vector<int>> &adj)
{
    visited[node] = true;
    for (int neighbour : adj[node])
    {
        if (!visited[neighbour])
            SccDFS(neighbour, visited, adj);
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    vector<vector<int>> adj = buildGraph(edges, v, edges.size(), false);

    // Step 1 : Get topo sort of SCC's
    bool visited[v] = {0};
    stack<int> s;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            getTopoSortSCC(i, visited, adj, s);
        }
    }

    // Step 2: Reverse the graph or build a reverse graph
    vector<vector<int>> revAdj = buildGraph(edges, v, edges.size(), true);
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }

    // Step 3: Apply dfs to scc's now, as per their topo sort
    int sccCount = 0;
    while (!s.empty())
    {
        int node = s.top();
        s.pop();
        if (!visited[node])
        {
            sccCount++;
            SccDFS(node, visited, revAdj);
        }
    }
    return sccCount;
}