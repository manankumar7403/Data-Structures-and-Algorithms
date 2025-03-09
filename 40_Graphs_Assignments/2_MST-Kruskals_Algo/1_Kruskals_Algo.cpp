// 🔴🔴 Refer this YT video Coding Ninjas: https://www.youtube.com/watch?v=6j-vHQMXXiA 🔴🔴
// ⭐⭐ Refer GFG and understand their code as well(there is no optimization) -> the one implemented below is optimized ⭐⭐
// https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/

/*
In Kruskal’s algorithm, sort all edges of the given graph in increasing order. Then it keeps on adding new edges and
nodes in the MST if the newly added edge does not form a cycle. It picks the minimum weighted edge at first and the
maximum weighted edge at last. Thus we can say that it makes a locally optimal choice in each step in order to find the
optimal solution. Hence this is a Greedy Algorithm.

Steps:
1) Sort all the edges in non-decreasing order of their weight. 
2) Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. If the cycle is not formed,
include this edge. Else, discard it. 
3) Repeat step#2 until there are (V-1) edges in the spanning tree.
*/

#include <iostream>
#include <algorithm>
using namespace std;

class Edge{
public:
    int source;
    int dest;
    int weight;

};

bool compare(Edge e1, Edge e2)
{
    return e1.weight < e2.weight;       // returns true (sorts in increasing order) if e1.weight < e2.weight
}

int findParent(int v, int *parent)        // return type int kyuki ek vertex ka parent return karna hai, input me vertex aur parent array mil rha hai jisme me hume uska parent figure out karna hai
{
    if(parent[v] == v)                    // matlab v hi topmost parent hai (suppose index 2 par value 2, index 5 par value 5 etc.)
    {
        return v;
    }
    return findParent(parent[v], parent);   // agar index aur index par padi value unequal hai toh hum us value(node) ka parent dhundenge
}

void kruskals(Edge * input, int n, int E)
{
    // Sort the input array - ascending order based on weights
    sort(input, input + E, compare);

    Edge * output = new Edge[n-1];        // as the final MST requires total n-1 edges

    int * parent = new int[n];            // kyuki har vertice ka parent store karna hai isliye n size liya hai
    for(int i=0; i<n; i++)
    {
        parent[i] = i;                   // kyuki shuru me har vertice apna khud ka parent hai
    }

    // ab bas n-1 edges ko ek ek karke pick karna hai aur apne output array me add karna hai
    int count = 0;    // currently MST me kite edges ko add kar diya hai
    int i = 0;        // currently konsi edge pe kaam kar rhe hai

    while(count != n-1)                // jab tak n-1 edges par kaam nahi kar lete
    {
        Edge currentEdge = input[i];   // sabse chota weight wala edge utha liya

        // ab check karna hai ki currentEdge MST me add kar sakte hai ya cycle ban jayegi - union find algorithm
        // Need to figure out the parent of the source and the destination parent of the Edge
        int sourceParent = findParent(currentEdge.source, parent);
        int destParent = findParent(currentEdge.dest, parent);

        if(sourceParent != destParent)       // agar source aur dest ka parent different hai toh MST me add kar sakte hai
        {
            // i ki jagah count liya kyuki i represent ki hum input ke konse index par lie kar rahe hai
            // it might happen ki humne kuch edges ko skip kar diya ho - kyuki unki wajah se cycle introduce ho rahi thi
            // so hum count lenge kyuki count toh yahi maintain kar rha hai ki output me kitne edges ja chuke hai
            output[count] = currentEdge;
            count++;
            parent[sourceParent] = destParent;      // ab jo 2 nodes ko connect karna hai unme se kisi ek ko parent banana hoga(source ka parent dest ko bana diya) aur ek ko child
        }
        i++;     // irrespective edge ko MST me daala ya exclude(coz of cycle) kiya, i inc karna hoga to move to the next edge
    }

    // Printing the MST
    int total_weight = 0;
    cout << "Minimum Spanning Tree using Kruskal's Algo is:" << endl;
    for(int i=0; i<n-1; i++)     // n-1 because in the final MST we only want n-1 edges and n vertices
    {
        if(output[i].source < output[i].dest)
        {
            cout << output[i].source << " " << output[i].dest << " " << output[i].weight << endl;
            total_weight += output[i].weight;
        }
        else
        {
            cout << output[i].dest << " " << output[i].source << " " << output[i].weight << endl;
            total_weight += output[i].weight;
        }
    }

    cout << endl;
    cout << "Minimum cost of Spanning tree using Kruskal's algorithm is: " << total_weight << endl;
}

int main()
{
    int n, E;
    cout << "Enter the number of nodes:" << endl;
    cin >> n;
    cout << "Enter the number of edges:" << endl;
    cin >> E;

    // We will create an array of type edge which should be of Size E(size E to store E number of edges)
    Edge * input = new Edge[E];

    cout << "Enter the edges(src dest) and weight:" << endl;
    for(int i=0; i < E; i++)
    {
        int src, des, wt;
        cin >> src >> des >> wt;
        input[i].source = src;                    // input array of type Edge ke ith index ki baat ho rhi hai
        input[i].dest = des;                     // input array of type Edge ke ith index ki baat ho rhi hai
        input[i].weight = wt;                    // input array of type Edge ke ith index ki baat ho rhi hai
    }

    kruskals(input, n, E);

    return 0;
}

/*
Time Complexity: O(E * logE) or O(E * logV) 

Sorting of edges takes O(E * logE) time. 
After sorting, we iterate through all edges and apply the find-union algorithm. The find and union operations can take at
most O(logV) time.
So overall complexity is O(E * logE + E * logV) time. 
The value of E can be at most O(V^2), so O(logV) and O(logE) are the same.
Therefore, the overall time complexity is O(E * logE) or O(E*logV)

Auxiliary Space: O(V + E), where V is the number of vertices and E is the number of edges in the graph.

*/