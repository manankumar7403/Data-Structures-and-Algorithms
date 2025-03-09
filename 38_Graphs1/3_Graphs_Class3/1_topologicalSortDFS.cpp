/*
⭐⭐ Topological Sort could be implemented by:
1) DFS
2) BFS

Pre-requisite of applying a topological sort is that the Graph should be Directed Acyclic Graph.
*/

// ✅✅ DFS implementation ✅✅

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <stack>
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

    void topSortDFS(int src, unordered_map<int, bool> &visited2, stack<int>& ans)
    {
        visited2[src] = true;

        for (auto neighbour : adjList[src])
        {
            if (!visited2[neighbour])
            {
                topSortDFS(neighbour, visited2, ans);
            }
        }

        // while returning, store the node in stack
        ans.push(src);
    }
};

// For DFS:
// Time Complexity: O(V + E)
// Space Complexity: O(V)

int main()
{
    Graph g;
    int n = 8;         // number of nodes

    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,4,1);
    g.addEdge(3,5,1);
    g.addEdge(4,6,1);
    g.addEdge(5,6,1);
    g.addEdge(6,7,1);

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

    cout << endl << endl;

    unordered_map<int, bool> visited2;
    stack<int> ans;
    for(int i=0; i<n; i++)
    {
        if(!visited2[i])
        {
            g.topSortDFS(i, visited2, ans);
        }
    }

    cout << "Printing Topological Sort using DFS:" << endl;
    while(!ans.empty())
    {
        cout << ans.top() << " ";
        ans.pop();
    }

    return 0;
}