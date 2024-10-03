#include <iostream>
#include <vector>
using namespace std;

// Problem link : https://www.geeksforgeeks.org/problems/articulation-point-1/1

// Problem : Given an undirected connected graph with V vertices and adjacency list adj. You are required to find all the articulation points, i.e. those vertices removing which, disconnects the graph into 2 or more components.

// Approach : This is very similar to tarjan's algo for bridges. Just some minor changes, we have to maintain same arrays, disc for discovery time, low for lowest time, visited for dfs, and a int timer. We also make a array isArticulationPoint, boolean and when we detect a point we make it true in it. We could have used a vector directly, but in the algo it is possible that we may declare a vertex articulation point more than once, so we just make it true in the array and later extract all that is true into a vector as answer. The algo is: We do normal tarjan's algo, however condition for point is low[neighbour]>=disc[node], (equals case was not in edges), this is becuase a neighbour need to be connected to someone prior to this node for its path to sustain. Also, this condition fails for root node (with which we begin dfs) so we include parent!=-1 into the condition.. Now what if root node is actually a articulation? we make a variable child=0 in the dfs call prior to visiting neighbours, and evertime a non-visited neighbour comes up we increment child. After all the negihbours, this value actually contains number of disconnected childs of the root node, and if its more than 1, it is a articulation point.. so if parent==-1 and child>1 then it is articulation point (this condition is check after visiting all neighbours). This way we get all the points marked true in the array, extract into vector and return!

class Solution
{
public:
    void dfs(int node, int parent, int low[], int disc[], int &timer, bool visited[],
             vector<int> adj[], bool ans[])
    {
        visited[node] = true;
        low[node] = timer;
        disc[node] = timer;
        timer++;
        int child = 0;
        for (int neighbour : adj[node])
        {
            if (neighbour == parent)
                continue;
            if (!visited[neighbour])
            {
                child++;
                dfs(neighbour, node, low, disc, timer, visited, adj, ans);
                low[node] = min(low[node], low[neighbour]);
                if (low[neighbour] >= disc[node] && parent != -1)
                {
                    ans[node] = true;
                }
            }
            else
            {
                // back or cyclic edge
                low[node] = min(low[node], disc[neighbour]);
            }
        }
        if (parent == -1 && child > 1)
        {
            ans[node] = true;
        }
    }
    vector<int> articulationPoints(int v, vector<int> adj[])
    {
        int low[v];
        int disc[v];
        bool visited[v] = {0};
        int timer = 1;
        bool ans[v] = {0};

        dfs(0, -1, low, disc, timer, visited, adj, ans);

        vector<int> a;
        for (int i = 0; i < v; i++)
        {
            if (ans[i])
            {
                a.push_back(i);
            }
        }
        if (a.size() == 0)
            return {-1};
        return a;
    }
};