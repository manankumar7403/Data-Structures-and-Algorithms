// Two different vector array sets a and b, you have to print their union.
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main()
{
    vector<int> arr, brr;
    int n, m;

    cout<<"Enter the number of elements in arr: ";
    cin >> n;

    cout<<"Enter the elements in arr: ";
    for(int i=0; i<n; i++)
    {
        int element;
        cin >> element;
        arr.push_back(element);
    }

    cout<<"Enter the number of elements in brr: ";
    cin >> m;

    cout<<"Enter the elements in brr: ";
    for(int i=0; i<m; i++)
    {
        int element;
        cin >> element;
        brr.push_back(element);
    }

    vector<int> ans;
    for(int i=0; i<arr.size(); i++)
    {
        ans.push_back(arr[i]);
    }
    for(int i=0; i<brr.size(); i++)
    {
        ans.push_back(brr[i]);
    }

    set<int> unionSet(ans.begin(), ans.end());

    cout<<"Union without duplicates: ";
    for(int element: unionSet)
    {
        cout << element << " ";
    }

    cout << endl;
    return 0;
}