#include <iostream>
#include <vector>
using namespace std;

int firstOccurrence(vector<int>v, int target)
{
    int start = 0;
    int end = v.size()-1;
    int mid = start + (end - start)/2;
    int ans = -1;

    while(start <= end)
    {
        if(v[mid] == target)
        {
            // ans store and then move to left
            ans = mid;
            end = mid - 1;
        }
        else if(target > v[mid])
        {
            // search in right
            start = mid + 1;

        }
        else if(target < v[mid])
        {
            // search left
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}

int main()
{
    vector<int> v{1,3,4,4,4,4,6,7};
    int target = 4;
    int indexOfFirstOcc = firstOccurrence(v, target);
    cout << "First occurrence of "<< target <<" is at index " << indexOfFirstOcc << endl;
    return 0;
}

// We can also use the STL function lower bound to get the first occ
// #include <alogorithm>

// auto ans2 = lower_bound(v.begin(), v.end(), target);
// cout << "ans2 is " << ans2 - v.begin() << endl;