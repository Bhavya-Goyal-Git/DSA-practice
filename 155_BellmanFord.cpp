#include <iostream>
#include <vector>
using namespace std;

// Problem link : https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

// Problem : Given a weighted and directed graph of V vertices and E edges, Find the shortest distance of all the vertex's from the source vertex S. If a vertices can't be reach from the S then mark the distance as 10^8. The Graph contains negative weights and may be cyclic, Note: If the Graph contains a negative cycle then return an array consisting of only -1.

// Approach : We apply BellanMan Ford's algo for shortest path in a negative weighted graph, it can also detect presence of -ive cycles. The algo is very simple, if there are N vertices in the graph, then we need to relax all the edges in the graph N-1 times. that is, check if dist[neighbour] > dist[node] + weight of edge, then update the dist of neighbour, this has to be done for all edges (N-1)times, To check for presence of a -ve cycle, we run for 1 more time and detect if any change occurs in distances calculated, if yes, there is a -ve cycle. Time comp is O(V*E) which is pretty bad lol.
// Implementation: Mark all distances as Max value permitted and source node as zero. THen run relaxation n-1 times. Then once more to check for -ve cycles. Then return the respective answer

class Solution
{
public:
    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
    {
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        int e = edges.size();

        for (int i = 1; i <= V - 1; i++)
        {
            for (int j = 0; j < e; j++)
            {
                int u = edges[j][0];
                int v = edges[j][1];
                int weight = edges[j][2];

                if (dist[u] != 1e8 && dist[v] > dist[u] + weight)
                {
                    dist[v] = dist[u] + weight;
                }
            }
        }
        bool flagChange = false;
        for (int j = 0; j < e; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int weight = edges[j][2];

            if (dist[u] != 1e8 && dist[v] > dist[u] + weight)
            {
                flagChange = true;
                break;
                dist[v] = dist[u] + weight;
            }
        }
        if (flagChange)
            return {-1};
        return dist;
    }
};
