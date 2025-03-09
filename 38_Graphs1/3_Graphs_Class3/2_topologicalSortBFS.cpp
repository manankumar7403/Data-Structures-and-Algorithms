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

    // ✅⭐ This following inDegree method is also called Kahn's Algorithm ✅⭐
    void topSortBFS(int n, vector<int>& ans)
    {
        queue<int> q;
        unordered_map<int, int> inDegree;

        // calculate the indegree of every node
        for(auto i: adjList)
        {
            int src = i.first;
            for(auto nbr : i.second)
            {
                inDegree[nbr]++;
            }
        }

        // put all nodes in queue, which have inDegree = 0
        for(int i=0; i<n; i++)
        {
            if(inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        // BFS wala logic laga do
        while(!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            ans.push_back(frontNode);

            for(auto nbr : adjList[frontNode])
            {
                inDegree[nbr]--;

                // check for 0 again (if indegree is now 0)
                if(inDegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }
    }

};

// For BFS:
// Time Complexity: O(V + E)
// Space Complexity: O(V)

int main()
{
    // Cycle absent
    // Graph g;
    // int n = 8;         // number of nodes

    // g.addEdge(0,1,1);
    // g.addEdge(1,2,1);
    // g.addEdge(2,3,1);
    // g.addEdge(3,4,1);
    // g.addEdge(3,5,1);
    // g.addEdge(4,6,1);
    // g.addEdge(5,6,1);
    // g.addEdge(6,7,1);

    // Cycle Present
    Graph g;
    int n = 4;         // number of nodes

    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,1,1);


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

    cout << endl << endl;

    vector<int> ans;
    // we do not require visited here to keep the track as we are traversing the entire graph and pushing all the nodes in queue with inDegree=0 -> Line 85
    g.topSortBFS(n, ans);

    // Checking if the Topological Sort is valid or invalid
    if(ans.size() == n)
    {
        cout << "It is a valid Topological Sort!" << endl << endl;
    }
    else
    {
        cout << "Cycle Present or invalid Topological Sort!" << endl << endl;
        return 0;
    }

    cout << "Printing Topological Sort using BFS:" << endl;
    for(auto i: ans)
    {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}