#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

class Graph
{
    public:
    unordered_map<int, list<int>> adjList;
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

    // Recursion Based Traversal
    void dfs(int src, unordered_map<int, bool>& visited)
    {
       cout << src << " ";
       visited[src] = true;

       for(auto neighbour: adjList[src])
       {
            if(!visited[neighbour])
            {
                dfs(neighbour, visited);
            } 
       }
    }
};

// For DFS:
// Time Complexity: O(V + E)
// Space Complexity: O(V)

int main()
{
    Graph g;
    // n -> number of nodes in the graph (0,1,2,3,4,5,6,7)
    int n = 8;

    g.addEdge(0, 1, 0);     // src, dest, undirected
    g.addEdge(1, 2, 0);     // src, dest, undirected
    g.addEdge(1, 3, 0);     // src, dest, undirected
    g.addEdge(3, 5, 0);     // src, dest, undirected
    g.addEdge(3, 7, 0);     // src, dest, undirected
    g.addEdge(7, 6, 0);     // src, dest, undirected
    g.addEdge(7, 4, 0);     // src, dest, undirected

    cout << "Printing the adjacency list:" << endl;   
    g.printAdjacencyList();

    cout << endl;

    unordered_map<int, bool> visited;       // map hai node check karne ke liye ki visited hai ki nahi, track rakhna zaruri hai jisske ek node ek hi baar traverse ho
    
    // run a loop for all nodes
    cout << "Printing the Depth-First Search:" << endl;
    for(int i=0; i<n; i++)
    {
        if(!visited[i])                    // i har ek node pe ja rha hai
        {
            g.dfs(i, visited);
        }
    }

    return 0;
}