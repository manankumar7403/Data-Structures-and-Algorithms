/*
🔴🔴🔴🔴
Graph is a Data Structure -> Contains Nodes (to store data) and Edges (to connect the nodes)

Graph is of 2 types:
1) Directed Graph (Unidirectional) -> One way to traverse between two nodes. (A->B)
2) Undirected Graph(Bidirectional) -> Two ways to traverse between two nodes. (A->B and B->A)

If the edges of directed graph has weights it is called weighted directed graph.
If the edges of undirected graph has weights it is called weighted undirected graph.

Degree is the number of edges from the node (in case of undirected graph).

In case of directed graph we have indegree and outdegree.
indegree is the number of edges coming at that particular node.
outdegree is the number of edges going from that particular node.

Cyclic graph is the graph that makes a complete cycle.
If it has direction and weight, it is called Weighted Cyclic Directed Graph.

If the graph is non-cyclic it is called acyclic.
If it has direction and weight it is called Weighted Acyclic Directed Graph.

⭐⭐⭐⭐ Graph Implementation ⭐⭐⭐⭐
Graph can be implemented in 2 ways:
1) Adjacency Matrix (2D-Array)
2) Adjacency List (Map and List / Map and Vector / Map and Set)

Check the slides for Graphs -> Class 1 for adjacency Matrix

Ab code me kaise implement karenge
i/p -> Edge ki List chahiye hogi
say
1) 0-1 (0 se 1 ek edge hai)
2) 1-0
3) 2-0
4) 0-2
5) 1-2
6) 2-1

Ab suppose 1) 0-1 liya toh u=0 and v=1 liya hai
adj[u][v] = 1

*/
// ____________________________________________________________________________________________________________
// ____________________________________________________________________________________________________________
// ____________________________________________________________________________________________________________

/*
// ✅✅ 1) Implementation of 1)Adjacency Matrix (2D-Array) ✅✅✅

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of nodes:" << endl;
    cin >> n;

    vector<vector<int>> adj(n, vector<int>(n, 0)); 

    int e;
    cout << "Enter the number of edges:" << endl;
    cin >> e;

    for(int i=0; i<e; i++)
    {
        int u, v;
        cout << "Enter edge " << i+1 << ": ";
        cin >> u >> v;

        // mark 1 for the edges
        adj[u][v] = 1;     // 1 ki jagah weight daal dena agar adjacency matrix use karke weighted graph bana rahe
    }

    // printing
    cout << "The adjacency matrix is:" << endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

TC -> O(n^2) or O(v^2)
SC -> O(n^2) or O(v^2)

*/

// _______________________________________________________________________________________________________________

/*
// ✅✅ 2) Implementation of 2)Adjacency List (Map and List / Map and Vector / Map and Set) ✅✅✅

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

class Graph
{
    public:
    unordered_map<int, list<int>> adjList;  // map ki TC O(logn) and unordered_map ki O(1) for insertion. List ki jagah vector bhi use kar sakte hai idhar
    // node, {neighbour nodes}

    void addEdge(int u, int v, bool direction) // source node, dest node, directed or undirected edge
    {
        // direction 0 -> undirected graph
        // direction 1 -> directed graph

        // ab chahe directed ho ya undirectd ho, u se v toh edge banti hi banti hai
        adjList[u].push_back(v);

        // par ab ye undirected hota toh u se v toh ho gya par v se u bhi karna padega
        if(direction == 0)   // undirected edge
        {
            adjList[v].push_back(u);
        }
    }

    void printAdjacencyList()
    {
        for(auto node: adjList)                          // node -> int type
        {
            cout << node.first << " -> ";
            for(auto neighbour: node.second)           // neighbour -> List Type
            {
                cout << neighbour << " ";
            }
            cout << endl;
        }
    }
};


// int main()
// {
//     Graph g;

//     // undirected edge input
//     g.addEdge(0,1,0);  // undirected edge
//     g.addEdge(1,2,0);  // undirected edge
//     g.addEdge(0,2,0);  // undirected edge

//     cout << "Printing the adjacency list:" << endl;   
//     g.printAdjacencyList();

//     return 0;
// }


int main()
{
    Graph g;

    // directed edge input
    g.addEdge(0,1,1);  // directed edge
    g.addEdge(1,2,1);  // directed edge
    g.addEdge(0,2,1);  // directed edge

    cout << "Printing the adjacency list:" << endl;   
    g.printAdjacencyList();

    return 0;
}

TC -> O(v+e)
SC -> O(v+e) avg case and O(v^2) worst case

*/
// ____________________________________________________________________________________________________________
/*

// ✅✅ Now implementing the graph with weights ✅✅

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

class Graph
{
    public:
    unordered_map<int, list<pair<int, int>>> adjList;  // node, {dest node, weight}

    void addEdge(int u, int v, int weight, bool direction) // source node, dest node, weight, directed or undirected edge
    {
        // direction 0 -> undirected graph
        // direction 1 -> directed graph

        // ab chahe directed ho ya undirectd ho, u se v toh edge banti hi banti hai
        adjList[u].push_back({v, weight});

        // par ab ye undirected hota toh u se v toh ho gya par v se u bhi karna padega
        if(direction == 0)   // undirected edge
        {
            adjList[v].push_back({u, weight});
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
};

int main()
{
    Graph g;

    // directed edge input
    g.addEdge(0,1,5,1);  // directed edge
    g.addEdge(1,2,8,1);  // directed edge
    g.addEdge(0,2,6,1);  // directed edge

    cout << "Printing the adjacency list:" << endl;   
    g.printAdjacencyList();

    return 0;
}

*/

// ____________________________________________________________________________________________________________
// ____________________________________________________________________________________________________________
// ____________________________________________________________________________________________________________

// ✅✅ Creating a normal graph with custom data type using template ✅✅

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;
template<typename T> 

class Graph
{
    public:
    unordered_map<T, list<T>> adjList;
    // node, {neighbour nodes}

    void addEdge(T u, T v, bool direction) // source node, dest node, directed or undirected edge
    {
        // direction 0 -> undirected graph
        // direction 1 -> directed graph

        // ab chahe directed ho ya undirectd ho, u se v toh edge banti hi banti hai
        adjList[u].push_back(v);

        // par ab ye undirected hota toh u se v toh ho gya par v se u bhi karna padega
        if(direction == 0)   // undirected edge
        {
            adjList[v].push_back(u);
        }
    }

    void printAdjacencyList()
    {
        for(auto node: adjList)                          // node -> int type
        {
            cout << node.first << " -> ";
            for(auto neighbour: node.second)           // neighbour -> List Type
            {
                cout << neighbour << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph<char> g;
    g.addEdge('a', 'b', 0);
    g.addEdge('b', 'c', 0);
    g.addEdge('a', 'c', 0);

    cout << "Printing the adjacency list:" << endl;   
    g.printAdjacencyList();

    return 0;
}