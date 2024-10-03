#include <iostream>
#include <vector>
using namespace std;

// If we convert a graph into a tree such that for n-nodes there are n-1 edges and every node is reachable from every node, it is called spanning tree. (Remember, tree is nothing but a connected acyclic-graph). There can be many spanning trees for a graph. The graph with minimum sum of all weights (edge weights) is called the MST (minimum spanning tree)

// Problem link : https://www.naukri.com/code360/problems/prim-s-mst_1095633?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

// Problem : Given a undirected graph, finds its MST using Prim's Algorithm

// Approach : The idea of Prim's algo is to firstly add a source into the tree, then we see all edges going out of the tree we have made and take the minimum one, and add it to the tree. Then repeat, until all nodes are in the tree.
// To implement it, we will need 3 arrays. key->int array having distance of a node from its parent, it is initially all infinity (INT_MAX), parent->int array stores parent of each node initially all -1, isInMST-> bool array which tells which nodes currently are in mst. Then we set source node, here 1, by setting key[1] = 0 and parent[1] = -1.
// Now we begin our processing (in each iteration, 1 node is added into mst so we do same number of iterations as there are nodes in the graph), inside the loop, we firstly need to get minimum value and its index from the key vector whose isInMST is false. (this represents minimum outgoing node from tree as it is currently not in mst and we find min of such). After we have the node (index value we just got), we add it into mst (isMST[node]=true), now we traverse its neighbours, and check if neighbour is not yet in mst and its key[neighbour] is greater than neighbour's distance from current node.. if yes, then update key[neighbour] to distance from current node and also make neighbour's parent the current node. (This step is actually registering all the outgoing nodes from our current tree into the key vector so that next time it is checked, min outgoing can be found). After the processing, we can now construct the ans data structure. We have to represent edges in it.. which are of form parent[i],i with dist= key[i], just remember to begin with i=2, because as 1 was source node its parent is -1 and 0 wasn't in the ques.
// The approach given below uses O(EV + V^2) time (v for calculation of minimum and v times), but it can be improved using a priority queue to get the minimum in logV units and time then will be O((E+V)log V) that is approximately O(E logV)

vector<vector<pair<int, int>>> buildGraph(vector<pair<pair<int, int>, int>> &vec, int vertices, int edges)
{
    vector<vector<pair<int, int>>> adj(vertices + 1);
    for (int i = 0; i < edges; i++)
    {
        adj[vec[i].first.first].push_back(make_pair(vec[i].first.second, vec[i].second));
        adj[vec[i].first.second].push_back(make_pair(vec[i].first.first, vec[i].second));
    }
    return adj;
}

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // build the graph
    vector<vector<pair<int, int>>> adj = buildGraph(g, n, m);
    bool isInMST[n + 1] = {0};
    vector<int> parent(n + 1, -1);
    vector<int> key(n + 1, INT32_MAX);
    // setting 1 as source node
    key[1] = 0;
    parent[1] = -1;

    for (int j = 1; j < n + 1; j++)
    {
        // getting minimum edge going out of the tree
        int mini = INT32_MAX;
        int node;
        for (int i = 1; i < n + 1; i++)
        {
            if (!isInMST[i] && key[i] < mini)
            {
                node = i;
                mini = key[i];
            }
        }
        // adding the node into mst
        isInMST[node] = true;
        // updating its adjacents for next iteration
        for (pair<int, int> neighbour : adj[node])
        {
            if (!isInMST[neighbour.first] && neighbour.second < key[neighbour.first])
            {
                key[neighbour.first] = neighbour.second;
                parent[neighbour.first] = node;
            }
        }
    }
    vector<pair<pair<int, int>, int>> ans;
    for (int i = 2; i < n + 1; i++)
    {
        ans.push_back({{parent[i], i}, key[i]});
    }
    return ans;
}