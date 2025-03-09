/*
Floyd-Warshall
This algorithm is highly efficient and can handle graphs with both positive and negative edge weights, making it a
versatile tool for solving a wide range of network and connectivity problems.

The Floyd Warshall Algorithm is an all pair shortest path algorithm unlike Dijkstra and Bellman Ford which are
single source shortest path algorithms. This algorithm works for both the directed and undirected weighted graphs.
But, it does not work for the graphs with negative cycles (where the sum of the edges in a cycle is negative).
It follows Dynamic Programming approach to check every possible path going via every possible node in order to calculate
shortest distance between every pair of nodes.

Why Floyd-Warshall Algorithm better for Dense Graphs and not for Sparse Graphs?
Dense Graph: A graph in which the number of edges are significantly much higher than the number of vertices.
Sparse Graph: A graph in which the number of edges are very much low.

No matter how many edges are there in the graph the Floyd Warshall Algorithm runs for O(V^3) times therefore it is best
suited for Dense graphs. In the case of sparse graphs, Johnson’s Algorithm is more suitable.
*/

// ______________________________________________________________________________________________________________

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <set>
using namespace std;

class Graph
{
    public:
    unordered_map<int, list<pair<int, int> > > adjList;

    void addEdge(int u, int v, int wt, bool direction) // source node, dest node, weight, directed or undirected edge
    {
        // direction 0 -> undirected graph
        // direction 1 -> directed graph

        // ab chahe directed ho ya undirectd ho, u se v toh edge banti hi banti hai
        adjList[u].push_back({v, wt});

        // par ab ye undirected hota toh u se v toh ho gya par v se u bhi karna padega
        if(direction == 0)   // undirected edge
        {
            adjList[v].push_back({u, wt});
        }
    }

    void printAdjacencyList()
    {
        for(auto node: adjList)                          // node -> int type
        {
            cout << node.first << " -> ";
            for(auto neighbour: node.second)           // neighbour -> List Type
            {
                cout << "(" << neighbour.first << "," << neighbour.second << "), ";
            }
            cout << endl;
        }
    }
    
    void floydWarshall(int n)
    {
        vector<vector<int> >dist(n, vector<int>(n, 1e9));   // as we are adding in distance sometimes but we can't add in INT_MAX, so write a number according to the constraints given
        // Diagonals par 0 mark kardo
        for(int i=0; i<n; i++)
        {
            dist[i][i] = 0;
        }
        
        // graph ke according distance insert kar diya
        for(auto t: adjList)
        {
            for(auto nbr: t.second)
            {
                int u = t.first;
                int v = nbr.first;
                int wt = nbr.second;
                dist[u][v] = wt;
            }
        }

        // ✨✨ DP LOGIC ✨✨ 
        for(int helper=0; helper<n; helper++)
        {
            for(int src=0; src<n; src++)
            {
                for(int dest=0; dest<n; dest++)
                {
                    dist[src][dest] = min(dist[src][dest], dist[src][helper] + dist[helper][dest]);
                }
            }
        }

        cout << "Printing the distance array: " << endl;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cout << dist[i][j] << ", ";
            }
            cout << endl;
        }
    }

    /*
    Complexity Analysis:
    Time Complexity: O(V^3), where V is the number of vertices in the graph and we run three nested loops each of size V
    Auxiliary Space: O(V^2), to create a 2-D matrix in order to store the shortest distance for each pair of nodes.
    */
};

int main()
{
    int n = 4; // number of nodes

    // directed graph
    Graph g;
    g.addEdge(0,1,3,1);
    g.addEdge(0,3,5,1);
    g.addEdge(1,0,2,1);
    
    g.addEdge(1,3,4,1);
    g.addEdge(2,1,1,1);
    g.addEdge(3,2,2,1);

    cout << "Printing the adjacency list:" << endl;   
    g.printAdjacencyList();

    cout << endl;

    g.floydWarshall(n);               // n is the number of nodes

    return 0;
}

