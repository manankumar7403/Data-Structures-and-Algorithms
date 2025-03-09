/*
✅✅ Could be implemented using:
1) Set       -> implemented below
2) MinHeap   -> check LeetCode 1631
*/

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
    
    void shortestDistDijkstra(int src, int n)
    {
        vector<int> dist(n, INT_MAX);
        set<pair<int, int> > st;

        // initial steps
        dist[src] = 0;
        st.insert(make_pair(0, src));

        while(!st.empty())      // set ka top element indexing se nahi nikalta, iterators se niklata hai par auto keyword is also an option
        {
            // fetch the smallest or the first element from the set
            auto topElement = *(st.begin());  // st.begin() gives the iterator of the starting value of the set, need to dereference it so used *(st.begin())
            int nodeDistance = topElement.first;
            int node = topElement.second;

            // pop from the set
            st.erase(st.begin());

            // now traverse on the neighbours of the smallest element stored in topElement(nodeDistance) to get to the next nearest node
            for(auto nbr : adjList[node])
            {
                // check karo agar distance minimum hai aur update karne layak bhi ha ki nahi
                if(nodeDistance + nbr.second < dist[nbr.first])
                {
                    // mujhe distance update karna hai kyuki comparatively less distance mil gya
                    // 2 cases
                    // 1) ya toh jo distance update karna hai uski entry set me padi hui hai
                    // agar INT_MAX nahi hua toh koi na koi entry set me padi hogi
                    // 2) aur ya set me nahi padi hai
                    // Now I need to make sure that I update it in set as well as the distance vector

                    // finding entry in the set
                    auto result = st.find(make_pair(dist[nbr.first], nbr.first));
                    // if found, then remove
                    if(result != st.end())
                    {
                        st.erase(result);
                    }
                    // ab new entry insert karenge (yeh updation hai in set and distance array)
                    dist[nbr.first] = nodeDistance + nbr.second;
                    st.insert(make_pair(dist[nbr.first], nbr.first));
                }
            }
        }
        cout << "Printing the smallest distance from src to each node: " << endl;
        for(int i=0; i<n; i++)
        {
            cout << dist[i] << ", ";
        }
        cout << endl;
    }

    // ⭐ Jis bhi node ka distance min hoga us node se neighbour ko update kiya jaata hai that's why dijkstra's is a greedy based approach
    
    // TC -> Dijkstra's (ElogV)
};

int main()
{
    int n = 7; // number of nodes

    // undirected graph
    Graph g;
    g.addEdge(6,3,2,0);
    g.addEdge(6,1,14,0);
    g.addEdge(3,1,9,0);
    
    g.addEdge(3,2,10,0);
    g.addEdge(1,2,7,0);
    g.addEdge(2,4,15,0);
    
    g.addEdge(4,3,11,0);
    g.addEdge(6,5,9,0);
    g.addEdge(4,5,6,0);

    cout << "Printing the adjacency list:" << endl;   
    g.printAdjacencyList();

    cout << endl;

    g.shortestDistDijkstra(6, n);               // 6 is the source, n is the number of nodes

    return 0;
}