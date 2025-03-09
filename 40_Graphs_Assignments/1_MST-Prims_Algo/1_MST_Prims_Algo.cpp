// 🔴🔴🔴🔴 Refer Love Babbar YT: https://www.youtube.com/watch?v=rnYBi9N_vw4 🔴🔴🔴🔴

/*
Like Kruskal’s algorithm, Prim’s algorithm is also a Greedy algorithm. This algorithm always starts with a single node and
moves through several adjacent nodes, in order to explore all of the connected edges along the way.
The algorithm starts with an empty spanning tree. The idea is to maintain two sets of vertices. The first set contains the
vertices already included in the MST, and the other set contains the vertices not yet included. At every step, it considers
all the edges that connect the two sets and picks the minimum weight edge from these edges. After picking the edge, it moves
the other endpoint of the edge to the set containing MST. 

A group of edges that connects two sets of vertices in a graph is called cut in graph theory. So, at every step of Prim’s
algorithm, find a cut, pick the minimum weight edge from the cut, and include this vertex in MST Set (the set that contains
already included vertices).
*/

// _______________________________________________________________________________________________________________

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;
// n -> num of nodes
// m -> num of edges
// vector<pair<pair<int, int>, int>> &g -> edge list with weights

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < g.size(); i++)
    {
        int u = g[i].first.first;  // taking out the src node
        int v = g[i].first.second; // taking out the dest node
        int w = g[i].second;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> key(n + 1);
    vector<bool> mst(n + 1);
    vector<int> parent(n + 1);

    for (int i = 0; i <= n; i++)
    {
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }

    // let's start the algo
    key[1] = 0;
    parent[1] = -1;
    for (int i = 1; i < n; i++) // for loop for all the edges
    {
        int mini = INT_MAX;
        int u;

        // find the minimum node
        for (int v = 1; v <= n; v++)
        {
            if (mst[v] == false && key[v] < mini)
            {
                u = v;
                mini = key[v];
            }
        }

        // mark minimum node as true
        mst[u] = true;

        // check its adjacent nodes
        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;
            if (mst[v] == false && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }
    vector<pair<pair<int, int>, int>> result;
    for (int i = 2; i <= n; i++)
    {
        result.push_back({{parent[i], i}, key[i]});
    }
    return result;
}

int main()
{
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the number of edges: ";
    cin >> m;

    vector<pair<pair<int, int>, int>> edges;

    cout << "Enter edges (source destination weight):\n";
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({{u, v}, w});
    }

    vector<pair<pair<int, int>, int>> mst = calculatePrimsMST(n, m, edges);

    cout << "\nMinimum Spanning Tree (MST) Edges:\n";
    for (auto edge : mst)
    {
        cout << "Edge: " << edge.first.first << " - " << edge.first.second << " | Weight: " << edge.second << "\n";
    }

    return 0;
}

// TC -> O(V^2)
// SC -> O(V)

// Time complexity could be further improved to O(E*log(E)) but space would become O(V^2)
// Refer Striver's or GFG implementation for optimization



/*
Advantages:
Prim’s algorithm is guaranteed to find the MST in a connected, weighted graph.
It has a time complexity of O(E log V) using a binary heap or Fibonacci heap, where E is the number of edges and V is the
number of vertices.
It is a relatively simple algorithm to understand and implement compared to some other MST algorithms.

Disadvantages:
Like Kruskal’s algorithm, Prim’s algorithm can be slow on dense graphs with many edges, as it requires iterating over all
edges at least once.
Prim’s algorithm relies on a priority queue, which can take up extra memory and slow down the algorithm on very large graphs.
The choice of starting node can affect the MST output, which may not be desirable in some applications

*/