#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/dijkstra-s-shortest-path_920469?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

// Problem : Given is a undirected weighted graph, all weights are positive. Find shortest paths from given source to all nodes, Return as a vector of int. (Djikstra's algo)

// Approach : Djikstra's algo works like a burning problem, like we set fire to the source node, and instead of thinking of weights as distances, they rather are time for fire from this node to spread to another. We are to assign each node then the time, when it will catch fire.. So naive way is to first burn the source (0 time) and then assign all nodes connected with source a time (equal to weights from source) that is expected time to burn. Now we get the minimum time of all of them, it will burn next.. then we do same to its neighbour nodes and so on, until entire graph is on fire!!
// Now to implement such a thing, we will need a set data structure, For we need at one time, the minimum distance currently (next node to burn). {This suggests it could be made with a min-heap but,} We also will need sometimes to remove certain entries, for example distance to node 1 was 7, but a process changed it to 4, we not only update the value in distances(ans Vector), but also in set for further processing. And since we are creating a set (not unordered), it auto stores data in ascending order, we need ascending order of distances, so we will store pairs in such way that 1st is distance and 2nd is node's value, then the first element *(set.begin()) will represent the min distance currently.
// Actual implementation: First build the graph, then a ans vector intially all infinity (INT_MAX) and then a set, initially insert(0,source) in it (distance to source node is 0). Then begin the processing until set is non-empty: Take out the first value and remember to erase it from the set. (This is current minimum dist possible to burn) Then go to its neighbour nodes, and see if (distance to current + distance from current to neighbour i.e. the edge weight) is less than (current distance of neighbour), if yes, first of all check if neighbour had a entry in set, if yes erase that first. After that, update the neighbours distance now to the value we compared with. Now, insert a new entry in the set, with updated distance and value of neighbour node. After the while loop, return the ans vector!

vector<vector<pair<int, int>>> buildGraph(vector<vector<int>> &vec, int vertices, int edges)
{
    vector<vector<pair<int, int>>> adj(vertices);
    for (int i = 0; i < edges; i++)
    {
        adj[vec[i][0]].push_back(make_pair(vec[i][1], vec[i][2]));
        adj[vec[i][1]].push_back(make_pair(vec[i][0], vec[i][2]));
    }
    return adj;
}

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    vector<vector<pair<int, int>>> adj = buildGraph(vec, vertices, edges);
    set<pair<int, int>> s; // distance of node, node number
    // set auto-stores in ascending order, we want order as per min-distance
    vector<int> ans(vertices, INT32_MAX); // distances, initially all inf
    ans[source] = 0;
    s.insert(make_pair(0, source));
    while (!s.empty())
    {
        pair<int, int> p = *(s.begin());
        s.erase(p);
        // got the top element
        for (pair<int, int> neighbour : adj[p.second])
        {
            if (p.first + neighbour.second < ans[neighbour.first])
            {
                if (s.find(make_pair(ans[neighbour.first], neighbour.first)) != s.end())
                {
                    s.erase(make_pair(ans[neighbour.first], neighbour.first));
                }
                ans[neighbour.first] = p.first + neighbour.second;
                s.insert(make_pair(ans[neighbour.first], neighbour.first));
            }
        }
    }
    return ans;
}