#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/minimum-spanning-tree_631769?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

// Problem : You are given an undirected, connected and weighted graph G(V, E), consisting of V number of vertices (numbered from 0 to V-1) and E number of edges. Find the total weight of the Minimum Spanning Tree (MST) using Kruskal's algorithm.

// Approach : The naive algorithm is to process the edges in ascending order. Take a edge, see if adding it does not create a cycle in our tree, then add it. Keep doing so, until all the vertices are added in the tree. Now, to implement this, we need a whole new data structure, to keep track of what all is connected together. This is called a disjoint set, it has 2 operations.. findParent() which returns the parent of a node in the set & Union set, which given 2 nodes, joins the 2 disjoint sets containing the 2 nodes.. First we will see how to implement this data structure and then use it to apply kruskal's.
// To define a Disjoint set, we need 2 things, a vector called parent (size is same as number of vertices), and initially every node is parent of itself. So parent[i] = i. And another vector called rank (same size as number of vertices) and initially all 0. These are defined for a disjoint set to work and provide the 2 functions mentioned above in almost O(1) time.
// Find parent() function : if the parent of node is the node itself, we return the node.. else.. we return recursively the parent of parent[node].. This is simple. However, in this way the chain may get too long, and disjoint set wont maintain its time complexity. So there is a thing called path compression, we compress the path of a child to ultimate parent of that disjoint set, while finding the parent. To do so, just write: return parent[node] =findParent(parent[node],parent-array).. that is find the parent recursively and assign it to parent of node as well. In c++ the return value of a assignment statement is value assigned, so it is assigned as well as returned. (it sets the parent of all nodes in the chain to parent of the disjoint set)
// Union set() function: We are given 2 nodes here, first we need to find the disjoint set they belong to.. so we find the parents of these 2.. After that we have 3 options as per rank of parents found (we have to merge the disjoint sets and it can be done without ranks too, but ranks help us ensure that this data structure is efficient) so, we make the node with larger rank, parent of the one with smaller rank. Incase however, ranks are equal, we can make anyone the parent, and whichever node we make the parent, we increase its rank. (Only in equality case rank is increased)
// Kruskal's implementation: We need to sort given edges vector on basis of edge weights, and initialize a disjoint set. Now we traverse the edge vector.. We find the 2 nodes connected by the edge and check if they belong to same/different disjoint sets.. (this is done by finding parent), if parent is same, they already belong to same disjoint set and we ignore it (this represents the edge creates cycles) else, if parents are not same, we include the edge in mst (as per the question we add the edge's weight into a ans variable) and also combine the disjoint sets i.e. union(vertex1, vertex2), So that they become one single component now. In this way, MST is obtained. The time comp is mainly due to sorting, O(E logE).

bool comparator(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

void makeDisjointSet(vector<int> &parent, vector<int> &rank, int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(int node, vector<int> &parent)
{
    if (parent[node] == node)
    {
        return node;
    }
    return parent[node] = findParent(parent[node], parent);
    // finds parent as well as does path compression
}

void UnionSet(int node1, int node2, vector<int> &parent, vector<int> &rank)
{
    // union by rank
    node1 = findParent(node1, parent);
    node2 = findParent(node2, parent);
    if (rank[node1] < rank[node2])
    {
        parent[node1] = node2;
    }
    else if (rank[node1] > rank[node2])
    {
        parent[node2] = node1;
    }
    else
    {
        parent[node1] = node2;
        rank[node2]++;
    }
}

int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
    // sorting the edges array, in order of weights of edges
    sort(edges.begin(), edges.end(), comparator);

    // making a disjoint set to proceed
    vector<int> parent(n);
    vector<int> rank(n);
    makeDisjointSet(parent, rank, n);

    int numEdges = edges.size();
    int weightOfMST = 0; // for answer

    for (int i = 0; i < numEdges; i++)
    {
        int p1 = findParent(edges[i][0], parent);
        int p2 = findParent(edges[i][1], parent);

        if (p1 != p2)
        {                                   // if sets are disjoint
            weightOfMST += edges[i][2];     // add the edge to mst
            UnionSet(p1, p2, parent, rank); // join the disjoint sets
        }
    }
    return weightOfMST;
}