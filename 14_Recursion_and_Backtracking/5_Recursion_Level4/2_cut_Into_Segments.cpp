// Need to cut rod in such a way that segments of length x, y, z are maximized

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int solve(int n, int x, int y, int z)
{
    // Base case
    if(n == 0)             // rod ki length hi zero hai toh kaat hi nahi sakte
    {
        return 0;
    }

    if(n < 0)            // -ve length ki rod aa rhi hai toh invalid case banane ke liye INT_MIN de diya
    {
        return INT_MIN;
    }

    // ab saare segements ki length ko rod me se kaat ke answer nikalenge and jo max hoga usse print kar denge
    int ans1 = solve(n-x, x, y, z) + 1; // n-x returns answer for length upto n-x but we want for the last call also so we do +1
                                        // n se n-x kaise gaye the? rod me se ek segment tod ke so +1

    int ans2 = solve(n-y, x, y, z) + 1; // n-y returns answer for length upto n-y but we want for the last call also so we do +1
                                        // n se n-y kaise gaye the? rod me se ek segment tod ke so +1
    
    
    int ans3 = solve(n-z, x, y, z) + 1; // n-z returns answer for length upto n-z but we want for the last call also so we do +1
                                        // n se n-z kaise gaye the? rod me se ek segment tod ke so +1

    int ans = max(ans1, max(ans2, ans3));
    return ans;
}

int main()
{
    int n = 11, x = 2, y = 3, z = 5;

    // solve function -> returns maximum number of segments
    int ans = solve(n,x,y,z);

    // ans -> could be valid or invalid(INT_MIN case)
    if(ans < 0)
    {
        ans = 0;
    }
    cout << "Answer is: " << ans;
    cout << endl; 
    return 0;
}

// ______________________________________________________________________________________________
// Input: l = 11, p = 2, q = 3, r = 5 
// Output: 5 
// Explanation: Segments of 2, 2, 2, 2 and 3

// Input: l = 7, p = 2, q = 5, r = 5 
// Output: 2 
// Explanation: Segments of 2 and 5