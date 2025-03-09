// src se har node ka shortest path ka code using DFS
// agar src se destination ka path nikalna hai toh uske liye 'parent' use karna hoga 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>
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
    
    void topoSortDFS(int src, unordered_map<int, bool>& visited, stack<int>& topoOrder, vector<int>& res)
    {
        visited[src] = true;

        for(auto neighbour : adjList[src])
        {
            if(!visited[neighbour.first])
            {
                topoSortDFS(neighbour.first, visited, topoOrder, res);
            }
        }

        // while returning, store the node in stack
        topoOrder.push(src);

        //res is for for printing the Topological Sort (if we use stack it wiil become vacant but we need it for shortestPathDFS)
        res.push_back(src);
    }

    void shortestPathDFS(int dest, stack<int> topoOrder, int n)
    {
        vector<int> dist(n, INT_MAX);

        int src = topoOrder.top();
        topoOrder.pop();
        dist[src] = 0;

        for (auto neighbour : adjList[0])
        {
            if (dist[0] + neighbour.second < dist[neighbour.first])
            {
                dist[neighbour.first] = dist[0] + neighbour.second;
            }
        }

        while(!topoOrder.empty())
        {
            int topElement = topoOrder.top();
            topoOrder.pop();

            if(dist[topElement] != INT_MAX)
            {
                for(auto neighbour : adjList[topElement])
                {
                    if(dist[topElement] + neighbour.second < dist[neighbour.first])   // curr node + one of its edge weight < dist of the neighbour the edge is going to -> check jpg for logic
                    {
                        dist[neighbour.first] = dist[topElement] + neighbour.second;
                    }
                }
            }
        }

        cout << "Printing the distance from src to each node:" << endl;
        for(int i=0; i<n; i++)
        {
            cout << i << " -> " << dist[i] << endl;
        }
    }
    
};

int main()
{
    int n = 5; // number of nodes

    // directed graph
    Graph g;
    g.addEdge(0,1,5,1);
    g.addEdge(0,2,3,1);
    g.addEdge(2,1,2,1);
    
    g.addEdge(1,3,3,1);
    g.addEdge(2,3,5,1);
    g.addEdge(2,4,6,1);
    
    g.addEdge(4,3,1,1);

    cout << "Printing the adjacency list:" << endl;   
    g.printAdjacencyList();

    cout << endl;

    stack<int> topoOrder;

    unordered_map<int, bool> visited;

    vector<int> res;
    g.topoSortDFS(0, visited, topoOrder, res);         // src, visited, topoOrder
    cout << "Printing the Topological Sort:" << endl;
    reverse(res.begin(), res.end());
    for(auto i : res)
    {
        cout << i << " ";
    }

    cout << endl << endl;
    
    g.shortestPathDFS(3, topoOrder, n);          // dest, topoOrder

    return 0;
}