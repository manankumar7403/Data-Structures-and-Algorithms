#include <iostream>
#include <vector>
using namespace std;

int lastOcc(vector<int>v, int target)
{
    int start = 0;
    int end = v.size()-1;
    int mid = start + (end - start)/2;
    int ans = -1;
    while(start <= end)
    {
        if(v[mid] == target)
        {
            // ans store
            ans = mid;
            // right search
            start = mid+1;
        }
        else if(target < v[mid])
        {
            // left search
            end = mid - 1;
        }
        else if(target > v[mid])
        {
            // right search
            start = mid+1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}

int main()
{
    vector<int> v{1,3,7,7,7,7,7,7,7,7,7,7,7,7,9};
    int target = 7;
    int ans = lastOcc(v, target);
    cout << "Last occurrence of " << target <<" is at index " << ans << endl;
    return 0;
}

// We can also use the STL function upper bound to get the last occ
// #include <alogorithm>

// auto ans2 = upper_bound(v.begin(), v.end(), target);
// cout << "ans2 is " << ans2 - v.begin() - 1 << endl; 


// 🔴🔴🔴🔴
// To find the total number of occurrences use the first and last occurrence codes:

// Total Number of occurrences: last occ - first occ + 1
// 🔴🔴🔴🔴