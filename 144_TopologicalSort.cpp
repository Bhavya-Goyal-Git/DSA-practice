#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// NOTE: TOPOLOGICAL sorting exists only for Directed Acyclic Graphs (DiaGraphs)

// Problem link : https://www.naukri.com/code360/problems/topological-sort_982938?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

// Problem : A Directed Acyclic Graph (DAG) is a directed graph that contains no cycles. Topological Sorting of DAG is a linear ordering of vertices such that for every directed edge from vertex 'u' to vertex 'v', vertex 'u' comes before 'v' in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.
// Given a DAG consisting of 'V' vertices and 'E' edges, you need to find out any topological sorting of this DAG. Return an array of size 'V' representing the topological sort of the vertices of the given DAG.

// Approach : We firstly build the adjacency list from given details. Then we make the visited boolean array and we will need a stack we build that. Then we run a loop across visited array as usual and make a call to dfs-method, that updates the stack we created. After the loop, we pop all elements out of the stack and push them into a ans vector to return.
// Dfs-method : this is normal dfs, just at end after the neighbour for-loop, we push the node into the stack (passed by ref). Due to this, node accessed at the last call is pushed to bottom of the stack. Hence using a stack helps us track the fact that all children of a node are pushed below it in the stack. Also, popping out of stack after the for loop (and not within it) is essential.

vector<vector<int>> buildGraph(vector<vector<int>> &edges, int n, int m)
{
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    return adj;
}

void topoSortDFS(int node, bool *visited, vector<vector<int>> &adj, stack<int> &st)
{
    visited[node] = true;
    for (int neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            topoSortDFS(neighbour, visited, adj, st);
        }
    }
    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    // building a directed graph's adjacency list
    vector<vector<int>> adj = buildGraph(edges, v, e);

    bool visited[v] = {0};
    stack<int> st;
    vector<int> ans;

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            topoSortDFS(i, visited, adj, st);
        }
    }
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}