// 🔴🔴LEETCODE 3235 -> Check If Rectangle Corner is Reachable🔴🔴
/*
You are given two positive integers xCorner and yCorner, and a 2D array circles, where circles[i] = [xi, yi, ri]
denotes a circle with center at (xi, yi) and radius ri.
There is a rectangle in the coordinate plane with its bottom left corner at the origin and top right corner at the
coordinate (xCorner, yCorner). You need to check whether there is a path from the bottom left corner to the top right
corner such that the entire path lies inside the rectangle, does not touch or lie inside any circle, and touches the
rectangle only at the two corners.
Return true if such a path exists, and false otherwise.

Example 1:
Input: xCorner = 3, yCorner = 4, circles = [[2,1,1]]
Output: true
Explanation:
The black curve shows a possible path between (0, 0) and (3, 4).

Example 2:
Input: xCorner = 3, yCorner = 3, circles = [[1,1,2]]
Output: false
Explanation:
No path exists from (0, 0) to (3, 3).

Example 3:
Input: xCorner = 3, yCorner = 3, circles = [[2,1,1],[1,2,1]]
Output: false
Explanation:
No path exists from (0, 0) to (3, 3).

Example 4:
Input: xCorner = 4, yCorner = 4, circles = [[5,5,1]]
Output: true

Constraints:
3 <= xCorner, yCorner <= 10^9
1 <= circles.length <= 1000
circles[i].length == 3
1 <= xi, yi, ri <= 10^9
*/
// ___________________________________________________________________________________________________________________

#include<iostream>
#include<vector>
#include<cmath>
#include<functional>
using namespace std;
typedef long long ll;

class Solution {
public:
    // Considering the center of every circle as a node starting from 0 to (n-1)
    // Considering the nth node as the origin (0,0)
    // Considering the n+1 node as the top-right corner (destination(xCorner, yCorner))
    // Now we'll make edges between these nodes using DSU (Disjoint set-union)
    bool canReachCorner(int xCorner, int yCorner, vector<vector<int>>& circles) {
        ll n = circles.size();
        vector<ll> parent(n+2, 0);

        // Inititalize DSU parent array
        for(ll i=0; i<n+2; i++)
        {
            parent[i] = i;
        }

        // Lambda function for finding the parent (with path compression)
        function<ll(ll)> find = [&](ll i)
        {
            if(parent[i] != i)
            {
                parent[i] = find(parent[i]);
            }
            return parent[i];
        };

        // Process each circle
        for(ll i=0; i<n; i++)
        {
            ll x = circles[i][0];
            ll y = circles[i][1];
            ll r = circles[i][2];

            // Check if the circle touches or intersects the origin(0,0)
            if(x * x + y * y <= r * r)
            {
                return false;
            }

            // Check if the circle touches or intersects the destination (xCorner, yCorner)
            // Refer: https://www.geeksforgeeks.org/check-two-given-circles-touch-intersect/
            if((x - xCorner) * (x - xCorner) + (y - yCorner) * (y - yCorner) <= r * r)
            {
                return false;
            }

            if(x <= r && y <= yCorner || (y + r >= yCorner && x <= xCorner)) //Checks if circle touches left/top boundary of rect
            {
                parent[find(n)] = find(i);     // if condition is satisfied, therefore it touches
                // so circle i is connected to origin node n(now this circle is part of the group of circles connected to origin)
            }
            if(y <= r && x <= xCorner || (x + r >= xCorner && y <= yCorner)) //Checks if circle touches bottom/right boundary of rect
            {
                parent[find(n+1)] = find(i);     // if condition is satisfied, therefore it touches
                // so circle i is connected to destination node n(now this circle is part of group of circles connected to dest.)
            }
        }

        // If both nodes (source and destination) are their own parents (not connected to a circle component a clear path exists)
        // If one of them is connected to a circle component and one of them is not then a path may still be found
        // if n and n+1 are not their own parents, we check for overlaps between circles as shown in next for loop below (n and
        // n+1 are constrained by circles), to determine whether a path is feasible the algorithm must verify if the source
        // and destination belong to diff. connected components. If they do, no blocking is there and a path exists. 
        if(find(n) == n || find(n+1) == n + 1)
        {
            return true;
        }

        // Check for overlaps between circles
        // The nested loop iterates over every pair of circles (i,j). The condition if(find(i) != find(j)) ensures we only process
        // circles that are not already in the same connected component. It calls the checkOverlap function to check if the 2
        // circles intersect. If the circles intersect, it merges their components in the DSU structure by setting
        // parent[find(i)] = find(j)
        // find(i): Gets the root of the set containing circle i
        // find(j): Gets the root of the set containing circle j
        // parent[find(i)] = find(j): Updates the root of i's set to point to the root of j's set. This effectively merges the
        // two sets, marking that i and j (or their sets) are now connected.
        for(ll i = 0; i < n; i++)
        {
            for(ll j = 0; j < i; j++)
            {
                if(find(i) != find(j))
                {
                    // Check if 2 circles intersect
                    if(checkOverlap(circles[i], circles[j], xCorner, yCorner))
                    {
                        parent[find(i)] = find(j);
                    }
                }
            }
        }

        // if this below condition is true then n and n+1 belong to different connected components. It means path between n and n+1
        // is possible because the source and destination are not directly blocked by the same group of overlapping circles 
        if(find(n) != find(n+1))
        {
            return true;
        }
        return false;
    }

    // Helper function to check if 2 circles overlap or intersect
    bool checkOverlap(vector<int>circle1, vector<int>circle2, ll X, ll Y)
    {
        ll x1 = circle1[0];
        ll y1 = circle1[1];
        ll r1 = circle1[2];
        ll x2 = circle2[0];
        ll y2 = circle2[1];
        ll r2 = circle2[2];

        // Calculate the squared distance between the centres of the circle as the formula is (x2-x1)^2 + (y2-y1)^2 = d^2
        // d^2 <= (r1-r2)^2
        long double dSquared = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        long double d = sqrt(dSquared);

        // Check if circles are non-overlapping or completely inside each other
        // dSquared <= (r1 - r2)^2 This means one circle is fully contained inside the other.
        // dSquared > (r1 + r2)^2 This means the circles are completely separated.
        if(dSquared <= (r1 - r2) * (r1 - r2) || dSquared > (r1 + r2) * (r1 + r2))
        {
            return false;
        }

        // Calculate intersection points (for further checks)
        // The distance 𝑙 is the projection of the line joining the centers of the two circles onto the line of intersection
        // between the two circles.
        // The distance ℎ represents the perpendicular distance from the center of circle 1 (or circle 2) to the line joining the
        // two intersection points of the circles.
        // These values allow us to compute the actual coordinates of the intersection points.
        long double l = (r1 * r1 - r2 * r2 + dSquared) / (2 * d);
        long double h = sqrt(r1 * r1 - l * l);

        // Calculate intersection point coordinates
        // These are the coordinates of the 2 points ((x1,y1) and (x2,y2)) where the circles intersect
        // X and Y are xCorner and yCorner respectively
        long double intersectX1 = l / d * (x2 - x1) + h / d * (y2 - y1) + x1;
        long double intersectY1 = l / d * (y2 - y1) - h / d * (x2 - x1) + y1;
        long double intersectX2 = l / d * (x2 - x1) - h / d * (y2 - y1) + x1;
        long double intersectY2 = l / d * (y2 - y1) + h / d * (x2 - x1) + y1;

        // Check if the intersection point lies within the boundaries
        // The code checks if either of the two intersection points lies within the boundaries defined by X and Y
        // The || (OR) condition is used to ensure that either of the points could lie inside the rectangle to have a valid
        // intersection (part of connected path, boundary etc.) Only if the overlapping is inside the rectangle, the
        // circles could contribute somehow to obstruct the path etc. 
        return ((0 <= intersectX1 && intersectX1 <= X &&
                0 <= intersectY1 && intersectY1 <= Y) ||
                (0 <= intersectX2 && intersectX2 <= X &&
                0 <= intersectY2 && intersectY2 <= Y));
        // So basically this checkOverlap function returns true if 2 circles intersect with some portion of them being inside the
        // rectangle
    }
};

int main() {
    Solution solution;
    int xCorner, yCorner, n;
    cout << "Enter the x-coordinate of the top-right corner: " << endl;
    cin >> xCorner;
    cout << "Enter the y-coordinate of the top-right corner: " << endl;
    cin >> yCorner;
    cout << "Enter the number of circles: " << endl;
    cin >> n;
    vector<vector<int>> circles(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        cout << "Enter the x-coordinate of circle " << i + 1 << ": ";
        cin >> circles[i][0];
        cout << "Enter the y-coordinate of circle " << i + 1 << ": ";
        cin >> circles[i][1];
        cout << "Enter the radius of circle " << i + 1 << ": " << endl;
        cin >> circles[i][2];
    }
    bool result = solution.canReachCorner(xCorner, yCorner, circles);
    if (result) {
        cout << "It is possible to reach the corner." << endl;
    } else {
        cout << "It is not possible to reach the corner." << endl;
    }
    return 0;
}

// TC:
// parent array: O(N)
// processing each circle: O(N)
// Nested loop for circle overlaps: O(N^2)
// Path compression in DSU: amortized O(α(N)) where α(N) is the inverse Ackermann function which grows extremely slow,
// almost constant for practical N.
// Therefore, overall Time complexity: O(N^2)*O(α(N)) = O(N^2) approx.

// SC:
// Storage for parent and circles array: O(N) each
// Depth of recursive calls in lambda function is O(logN)
// Therefore, overall time complexity is: O(N)


// ____________________________________________________________________________________________________________

/*
// ⭐⭐DSU (Disjoint Set Union)⭐⭐
#include<iostream>
#include<vector>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent, size;
    public:
        DisjointSet(int n)
        {
            rank.resize(n+1, 0);  // n+1 will work for both 1-based and 0-based indexing
            parent.resize(n+1);
            size.resize(n+1);
            for(int i=0; i<=n; i++)
            {
                parent[i] = i;
                size[i] = 1;
            }
        }
        int findUltimateParent(int node)
        {
            if(node == parent[node])
                return node;
            return parent[node] = findUltimateParent(parent[node]);
        }

        void unionByRank(int u, int v)
        {
            int ultimateUparent = findUltimateParent(u);
            int ultimateVparent = findUltimateParent(v);
            if(ultimateUparent == ultimateVparent) return;
            if(rank[ultimateUparent] < rank[ultimateVparent])
            {
                parent[ultimateUparent] = ultimateVparent;
            }
            else if(rank[ultimateVparent] < rank[ultimateUparent])
            {
                parent[ultimateVparent] = ultimateUparent;
            }
            else
            {
                parent[ultimateVparent] = ultimateUparent;
                rank[ultimateUparent]++;
            }
        }

        void unionBySize(int u, int v)
        {
            int ultimateUparent = findUltimateParent(u);
            int ultimateVparent = findUltimateParent(v);
            if(ultimateUparent == ultimateVparent) return;
            if(size[ultimateUparent] < size[ultimateVparent])
            {
                parent[ultimateUparent] = ultimateVparent;
                size[ultimateVparent] += size[ultimateUparent];
            }
            else
            {
                parent[ultimateVparent] = ultimateUparent;
                size[ultimateUparent] += size[ultimateVparent];
            }
        }
};

int main()
{
    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    // check if 3 and 7 belong to the same component
    if(ds.findUltimateParent(3) == ds.findUltimateParent(7))
    {
        cout << "same" << endl;
    }
    else cout << "Not same" << endl;

    // After connecting, we check again
    ds.unionByRank(3,7);
    if(ds.findUltimateParent(3) == ds.findUltimateParent(7))
    {
        cout << "same" << endl;
    }
    else cout << "Not same" << endl;
    return 0;
}

// int main()
// {
//     DisjointSet ds(7);
//     ds.unionBySize(1,2);
//     ds.unionBySize(2,3);
//     ds.unionBySize(4,5);
//     ds.unionBySize(6,7);
//     ds.unionBySize(5,6);
//     // check if 3 and 7 belong to the same component
//     if(ds.findUltimateParent(3) == ds.findUltimateParent(7))
//     {
//         cout << "same" << endl;
//     }
//     else cout << "Not same" << endl;

//     // After connecting, we check again
//     ds.unionBySize(3,7);
//     if(ds.findUltimateParent(3) == ds.findUltimateParent(7))
//     {
//         cout << "same" << endl;
//     }
//     else cout << "Not same" << endl;
//     return 0;
// }

// If the larger rank component is connected to the smaller rank component, then the time taken by the nodes to travel
// will be comparatively more than if smaller rank component is connected to the larger rank component (for all nodes
// on avg).
*/