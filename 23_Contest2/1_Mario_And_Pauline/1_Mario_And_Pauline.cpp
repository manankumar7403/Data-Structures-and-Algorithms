// GFG
/*
Mario wants to meet Pauline. Mario is standing at source point (x1 , y1) and Pauline is standing at destination point
(x2 , y2). Determine if it is possible to reach the destination point (x2, y2) from source point (x1 , y1) .
Note: Mario has only two valid moves :
(x1 , y1 ) to (x1 + y1, y1 )
(x1 , y1) to (x1 , y1 + x1)

Example1:
Input:
3 2 5 7
Output:
True
Explanation:
You can reach destination point by taking following moves.
(3,2) -> (5,2) -> (5,7).

Example2:
Input:
1 2 3 4
Output:
FaIse
Explanation:
There are no valid moves by which you can reach the destination point from source point.

Constraints:
1<=x1, yl, x2, y2<=20
*/

#include<iostream>
using namespace std;

bool isPossible(int sx, int sy, int dx, int dy)
{
    while (dx >= sx && dy >= sy)
    {
        if (dx == sx && dy == sy)
        {
            return true;
        }
        if (dx > dy)
        {
            dx = dx - dy;
        }
        else
        {
            dy = dy - dx;
        }
    }
    return false;
}

int main()
{
    int sx, sy, dx, dy;
    cin >> sx >> sy >> dx >> dy;
    if(isPossible(sx, sy, dx, dy))
    {
        cout << "True" << endl;
    }
    else cout << "False" << endl;
    return 0;
}

// Explanation:
// sx = 3, sy = 2, dx = 5, dy = 7

// going from destination to source:
// dy >= dx (7 >= 5) -> dy = 7-5 = 2       dy = 2;
// dx >= dy (5 >= 2) -> dx = 5-2 = 3       dx = 3;

// sx = dx and sy = dy
// we could have gone from source to destination (+ src instead of - dest)