/*
✅🔴⭐
Dijkstra's algorithm is considered a greedy approach because, at each step, it selects the vertex with the smallest known
distance and explores its neighbors. The algorithm makes locally optimal choices by prioritizing the shortest paths to the
current set of vertices. However, it doesn't guarantee a globally optimal solution in all cases.

Which specific cases does it fail?
Dijkstra's algorithm may not provide a globally optimal solution when it encounters graphs with negative-weight edges.
If there are negative edges, the algorithm might fail to correctly determine the shortest paths. In such cases, other
algorithms like Bellman-Ford are more suitable since they can handle graphs with negative-weight edges, albeit at a higher
computational cost.
Its based on Principle of Relaxation

🔴🔴 Bellman-Ford algorithm will fail if the graph contains any negative edge cycle. 🔴🔴

// Dijkstra's and Bellman-Ford are boh single-source shortest path algorithms
// UNLIKE Floyd-Warshall which is multi-source shortest path algorithm

Bellman Ford Algorithm
Need to do relaxation N-1 times where N is the number of nodes
Relaxation: dist[u] + wt < dist[v]

Suppose A -> B = -1 (Agar B par shortest answer update hona hai vo starting me hi ho gaya toh B ki jitni bhi edges hongi
unka shortest dist bhi ussi pass me update ho jayega)
B -> E
B -> C
B -> D

Now the opposite case
B -> E
B -> C
B -> D
A -> B (ab B ki shortest distance wali updation huyi par B se outgoing jo edges(E, C, D) hai unka next pass me hoga)

Worst Case
Toh aise hi agar dependent nodes pehle update kar rhe hai aur source node baad me update kar rhe hai toh chances hai ki
sabka smallest distance update hone me N-1 iterations lagenge.

Agar N-1 passes ke baad ek baar aur loop chalaya aur fir bhi distance update ho rha hai matlab we are stuck in an infinite
negative edge cyclic or sub-cyclic graph.

Bellman-Ford Algorithm
1) (N-1) times relaxation on all edges
2) to find/detect negative cycle -> run relaxation step 1 more time and if the distance gets updated, then there is a
negative cycle present.
✅🔴⭐
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
    
    void bellmanFordAlgo(int src, int n)
    {
        // assuming directed weighted graph
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // n-1 relaxation step
        for(int i=0; i<n-1; i++)
        {
            // for all edges
            for(auto t: adjList)
            {
                for(auto nbr: t.second)
                {
                    int u = t.first;
                    int v = nbr.first;
                    int wt = nbr.second;
                    if(dist[u] != INT_MAX && dist[u] + wt < dist[v])
                    {
                        dist[v] = dist[u] + wt;
                    }
                }
            }
        }

        // Time Complexity of Bellman-Ford:
        // i=0->n-1 for all nodes (vertices) -> O(V)
        // for (auto t: adjList) {for (auto nbr: t.second)} for all edges -> O(V*E)
        // Space Complexity -> O(V)

        // TC for disconnected graph -> O(E*(V^2))
        // SC for disconnected graph -> O(V)

        // To check for negative cycle
        bool negativeCycle = false;

        for (auto t : adjList)
        {
            for (auto nbr : t.second)
            {
                int u = t.first;
                int v = nbr.first;
                int wt = nbr.second;
                if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
                {
                    negativeCycle = true;
                    break;
                }
            }
        }

        if(negativeCycle == true)
        {
            cout << "-ve cycle is present!" << endl;
        }
        else
        {
            cout << "-ve cycle is absent!" << endl;
        }

        cout << "Printing dist array: " << endl;
        for(auto i : dist)
        {
            cout << i << " ";
        }
    }
};

int main()
{
    int n = 5; // number of nodes

    // directed graph
    Graph g;
    g.addEdge(0,1,-1,1);
    g.addEdge(0,2,4,1);
    g.addEdge(1,2,3,1);
    
    g.addEdge(1,3,2,1);
    g.addEdge(1,4,2,1);
    g.addEdge(3,1,1,1);
    
    g.addEdge(3,2,5,1);
    g.addEdge(4,3,-3,1);

    cout << "Printing the adjacency list:" << endl;   
    g.printAdjacencyList();

    cout << endl;

    g.bellmanFordAlgo(0, n);               // 0 is the source, n is the number of nodes

    return 0;
}

