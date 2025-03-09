// 🔴🔴🔴🔴 Check if there is a cycle in a directed graph using DFS
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

    bool checkCyclicDirectedGraphUsingDFS(int src, unordered_map<int, bool>& visited2,
    unordered_map<int, bool> dfsVisited)
    {
        visited2[src] = true;
        dfsVisited[src] = true;

        for(auto neighbour : adjList[src])
        {
            if(!visited2[neighbour])
            {
                bool aageKaAns = checkCyclicDirectedGraphUsingDFS(neighbour, visited2, dfsVisited);
                if(aageKaAns == true)
                {
                    return true;
                }
            }
            else if(visited2[neighbour] == true && dfsVisited[neighbour] == true)
            {
                return true;
            }
        }
        
        // ⭐⭐ yaha hi galti hoti hai ⭐⭐
        dfsVisited[src] = false;
        return false;
    }
};


// For DFS:
// Time Complexity: O(V + E)
// Space Complexity: O(V)

int main()
{
    Graph g;
    
    // cycle absent
    int n = 5;  // num of nodes
    g.addEdge(0, 1, 1);     // src, dest, directed
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);

    // cycle present
    // int n = 5;  // num of nodes
    // g.addEdge(0, 1, 1);     // src, dest, directed
    // g.addEdge(1, 2, 1);
    // g.addEdge(2, 3, 1);
    // g.addEdge(3, 4, 1);
    // g.addEdge(4, 0, 1);

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

    unordered_map<int, bool> visited2;
    unordered_map<int, bool> dfsVisited;

    bool ans = false;
    for(int i=0; i<n; i++)
    {
        if(!visited2[i])                    // i har ek node pe ja rha hai
        {
            ans = g.checkCyclicDirectedGraphUsingDFS(i, visited2, dfsVisited);
            if(ans == true)
            {
                break;
            }
        }
    }

    cout << endl << endl;

    if(ans == true)
    {
        cout << "Cycle is present!" << endl;
    }
    else
    {
        cout << "Cycle is not present!" << endl;
    }

    return 0;
}