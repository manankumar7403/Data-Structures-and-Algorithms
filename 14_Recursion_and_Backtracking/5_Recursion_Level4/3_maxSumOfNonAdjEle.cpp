// Need to find the max sum of non - adjacent elements
// Using the inclusion-exclusion principle

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void solve(vector<int>& arr, int i, int sum, int& maxi)
{
    // BASE CASE
    if(i >= arr.size())
    {
        // Update maxi
        maxi = max(sum, maxi);
        return;
    }
    
    // exclude
    solve(arr, i+1, sum, maxi);

    // include
    solve(arr, i+2, sum+arr[i], maxi);
}

int main()
{
    vector<int> arr{2,1,4,9};
    int sum = 0;
    int maxi = INT_MIN;
    int i = 0;
    solve(arr, i, sum, maxi);

    cout << "Maximum sum of non-adj elements: " << maxi << endl;
    return 0;
}