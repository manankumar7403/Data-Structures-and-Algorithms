#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int x, int y, int row, int col, int maze[][3], vector<vector<bool> > &visited) // int x aur int y wo position hai jaha rat agle step pe jaana chahte hai aur hum check kar rhe kya waha jana safe hai
{
    if( ((x >= 0 && x < row) && (y >= 0 && y < col)) &&     // maze ke andar hi hona chahiye
        (maze[x][y] == 1) &&                                // jaha jaana hai wo 1 hona chahiye 0 nahi
        (visited[x][y] == false) )                          // pehle se visited nhi hona chahiye
    {
        return true;                                        // toh rat waha ja sakta hai
    }
    else
    {
        return false;                                       // warna nahi ja sakta
    }
}

void solveMaze(int maze[3][3], int row, int col, int i, int j, vector<vector<bool> > &visited,
vector<string>& path, string output) // int i aur j source ka x aur y coordinate yaani 0,0 shuru me and then i and j will be updated according to the rat's current position
{
    // Base Case (i==row-1 -> 3-1=2, j==col-1 -> 3-1=2, so (2,2) -> humne right bottom ko destination liya tha)
    if(i == row-1 && j == col-1)   // matlab destination par pahuch gaya rat (destination kuch bhi ho sakta hai) -> humne assume kiya hai right bottom me hai
    {
        // answer found
        path.push_back(output);   // jo poora path traverse kiya destination par jaane ke liye use 'path' me daalo
        return;
    }

    // Down -> (i+1, j)
    if(isSafe(i+1, j, row, col, maze, visited))
    {
        visited[i+1][j] = true;
        solveMaze(maze, row, col, i+1, j, visited, path, output+'D');

        // Backtracking -> multiple solutions find karne hai toh jo visit kar liya usko false karna padega
        // taaki dobara kisi dusre path me vo cell include kar sake
        visited[i+1][j] = false;
    }

    // Left -> (i, j-1)
    if(isSafe(i, j-1, row, col, maze, visited))
    {
        visited[i][j-1] = true;
        solveMaze(maze, row, col, i, j-1, visited, path, output+'L');

        // Backtracking
        visited[i][j-1] = false;
    }

    // Right -> (i, j+1)
    if(isSafe(i, j+1, row, col, maze, visited))
    {
        visited[i][j+1] = true;
        solveMaze(maze, row, col, i, j+1, visited, path, output+'R');

        // Backtracking
        visited[i][j+1] = false;
    }

    // Up -> (i-1, j)
    if(isSafe(i-1, j, row, col, maze, visited))
    {
        visited[i-1][j] = true;
        solveMaze(maze, row, col, i-1, j, visited, path, output+'U');

        // Backtracking
        visited[i-1][j] = false;
    }
}

int main()
{
    int maze[3][3] = {{1,0,0},
                      {1,1,0},
                      {1,1,1}};    // 3x3 ka maze hai, nxn ka bhi ban sakta hai
    
    if(maze[0][0] == 0)            // agar source hi 0 ho gaya matlab rat ka starting point hi nhi hai
    {
        cout << "No path exists." << endl;
        return 0;
    }
    
    int row = 3;
    int col = 3;

    vector<vector<bool> > visited(row, vector<bool>(col, false));  // will keep track of the visited parts of the maze -> warna infinite loop me phas jayenge

    // source ki value ko true mark kar dete hai (matlab jaha rat currently hai -> shuruat)
    visited[0][0] = true;   // abhi ek dum left top pe hai rat, par hum question ke hisab se source kuch bhi le sakte hai

    vector<string> path; // agar destination par pahuch gya rat(base case) toh us poore path ko vector 'path' me push kar denge
    string output = "";  // output string me ek ek cell se jo path ban rha hai real time me vo concatenate hota ja rha hai

    solveMaze(maze, row, col, 0, 0, visited, path, output);
    // poori maze jaha rat chalega, maze size ke liye row aur col, source ka x aur y coordinate yaani 0,0,
    // visited arr mark karne ke liye, aur path and output 'path' store karne ke liye

    cout << "Printing the paths: " << endl;
    for(auto i: path)         // jo path form hua hai usse print kardo bas
    {
        cout << i << " ";
    }
    cout << endl;

    if(path.size() == 0)
    {
        cout << "No path exists." << endl;  // There is no path from source to destination
    }

    return 0;
}

// Time Complexity: O(4^(m*n)), because on every cell we have to try 4 different directions.
// Auxiliary Space: O(m*n), Maximum Depth of the recursion tree(auxiliary space).
