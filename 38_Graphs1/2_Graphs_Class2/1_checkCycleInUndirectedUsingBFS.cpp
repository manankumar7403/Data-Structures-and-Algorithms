// 🔴🔴🔴🔴 Check if there is a cycle in an undirected graph using BFS
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

    // Queue Based Traversal (similar to level order)
    void bfs(int src, unordered_map<int, bool>& visited)
    {
        queue<int> q;

        q.push(src);
        visited[src] = true;

        while(!q.empty())
        {
            int frontNode = q.front();
            q.pop();
            cout << frontNode << " ";

            // insert neighbours
            for(auto neighbour: adjList[frontNode])
            {
                if(!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }

    bool checkCyclicUsingBFS(int src, unordered_map<int, bool>& visited2)
    {
        queue<int> q;
        unordered_map<int, int> parent;

        q.push(src);
        visited2[src] = true;
        parent[src] = -1;

        while(!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            // insert neighbours
            for(auto neighbour: adjList[frontNode])
            {
                if(!visited2[neighbour])
                {
                    q.push(neighbour);
                    visited2[neighbour] = true;
                    parent[neighbour] = frontNode;
                }
                else
                {
                    // already visited
                    if(visited2[neighbour] && neighbour != parent[frontNode]) // already visited hai aur jis node se aaye the (neighbour) vo parent nahi hai
                    {
                        // cycle is present
                        return true;
                    }
                }
            }
        }
        return false;  // cycle is not present
    }
};

// For BFS:
// Time Complexity: O(V + E)
// Space Complexity: O(V)

int main()
{
    Graph g;

    // cycle absent
    int n = 5;  // num of nodes
    g.addEdge(0, 1, 0);     // src, dest, undirected
    g.addEdge(1, 3, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(2, 4, 0);

    // cycle present
    // int n = 4;  // num of nodes
    // g.addEdge(0, 1, 0);     // src, dest, undirected
    // g.addEdge(1, 2, 0);
    // g.addEdge(2, 3, 0);
    // g.addEdge(3, 0, 0);

    cout << "Printing the adjacency list:" << endl;   
    g.printAdjacencyList();

    cout << endl;

    unordered_map<int, bool> visited;       // map hai node check karne ke liye ki visited hai ki nahi, track rakhna zaruri hai jisske ek node ek hi baar traverse ho
    
    // run a loop for all nodes
    cout << "Printing the Breadth-First Search:" << endl;
    for(int i=0; i<n; i++)
    {
        if(!visited[i])                    // i har ek node pe ja rha hai
        {
            g.bfs(i, visited);
        }
    }

    unordered_map<int, bool> visited2;

    bool ans = false;
    for(int i=0; i<n; i++)
    {
        if(!visited2[i])                    // i har ek node pe ja rha hai
        {
            ans = g.checkCyclicUsingBFS(i, visited2);
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