// src se destination ka shortest path ka code using BFS
#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
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
    
    void shortestPathBFS(int src, int dest)
    {
        queue<int> q;
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;
        
        // initial steps for src
        q.push(src);
        visited[src] = true;
        parent[src] = -1;
        
        while(!q.empty())
        {
            int fNode = q.front();
            q.pop();
            
            for(auto nbr : adjList[fNode])
            {
                if(!visited[nbr.first])
                {
                    q.push(nbr.first);
                    visited[nbr.first] = true;
                    parent[nbr.first] = fNode;
                }
            }
        }
        
        // store path in ans, after traversing in the parent array
        vector<int> ans;
        int node = dest;
        while(node != -1)
        {
            ans.push_back(node);
            node = parent[node];
        }
        
        reverse(ans.begin(), ans.end());   // as we need src->dest and not dest->src
        
        cout << "Printing the shortest path using BFS:" << endl;
        for(int i = 0; i < ans.size()-1; i++)
        {
            cout << ans[i] << " -> ";
        }
        cout << ans.back() << endl;
    }
};

int main()
{
    // directed graph
    Graph g;

    g.addEdge(0,1,1,1);
    g.addEdge(1,2,1,1);
    g.addEdge(2,3,1,1);
    
    g.addEdge(3,4,1,1);
    g.addEdge(0,5,1,1);
    g.addEdge(5,4,1,1);
    
    g.addEdge(0,6,1,1);
    g.addEdge(6,7,1,1);
    g.addEdge(7,8,1,1);
    g.addEdge(8,4,1,1);
    
    // undirected graph
    // Graph g;

    // g.addEdge(0,1,1,0);
    // g.addEdge(1,2,1,0);
    // g.addEdge(2,3,1,0);
    
    // g.addEdge(3,4,1,0);
    // g.addEdge(0,5,1,0);
    // g.addEdge(5,4,1,0);
    
    // g.addEdge(0,6,1,0);
    // g.addEdge(6,7,1,0);
    // g.addEdge(7,8,1,0);
    // g.addEdge(8,4,1,0);

    cout << "Printing the adjacency list:" << endl;   
    g.printAdjacencyList();
    
    int src = 0;
    int dest = 4;
    
    g.shortestPathBFS(src, dest);

    return 0;
}