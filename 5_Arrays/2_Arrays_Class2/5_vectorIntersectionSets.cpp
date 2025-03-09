// Given two vector arrays - find the intersection
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
    
    set<int> setA(arr.begin(), arr.end());
    set<int> setB(brr.begin(), brr.end());

    vector<int> ans;

    for(int element : setA)
    {
        if(setB.count(element) > 0)
        {
            ans.push_back(element);
        }
    }

    cout << "Intersection without duplicates: ";
    for(int element : ans)
    {
        cout << element << " ";
    }

    cout << endl;
    return 0;
}


// -------------------------------------------------------------------------------------------
// set<int> setA(arr.begin(), arr.end());
// set<int> setB(brr.begin(), brr.end());

// setA and setB are two instances of the std::set container, a container that stores unique elements in a
// sorted order. In this case, it is used to store the unique elements from the vectors arr and brr.

// The set constructor is used to create these sets by passing two iterators, arr.begin() and arr.end()
// for setA, and brr.begin() and brr.end() for setB. This constructor effectively initializes the sets
// with the elements from the respective vectors.
// -------------------------------------------------------------------------------------------

// for (int element : setA)
// {
//     if (setB.count(element) > 0)
//     {
//         ans.push_back(element);
//     }
// }

// The code uses a range-based for loop to iterate through each element in setA, which contains the unique
// elements from the arr vector.

// For each element in setA, it checks whether that element is present in setB using setB.count(element).
// The count method returns 1 if the element is found and 0 if it's not. This check effectively identifies
// the common elements between the two sets.

// If the element is found in both sets (i.e., setB.count(element) > 0), it is considered part of the
// intersection, and it is added to the ans vector using ans.push_back(element).

// ------------------------------------------------------------------------------------------
