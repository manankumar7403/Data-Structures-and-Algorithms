// #include <iostream>
// #include <vector>
// #include <set>
// using namespace std;

// int main()
// {
//     vector<int> arr, brr;
//     int n, m;
    
//     cout<<"Enter the number of elements in arr: ";
//     cin >> n;

//     cout<<"Enter the elements in arr: ";
//     for(int i=0; i<n; i++)
//     {
//         int element;
//         cin >> element;
//         arr.push_back(element);
//     }

//     cout<<"Enter the number of elements in brr: ";
//     cin >> m;

//     cout<<"Enter the elements in brr: ";
//     for(int i=0; i<m; i++)
//     {
//         int element;
//         cin >> element;
//         brr.push_back(element);
//     }
    
//     set<int> setA(arr.begin(), arr.end());
//     set<int> setB(brr.begin(), brr.end());

//     vector<int> ans;

//     for(int element : setA)
//     {
//         if(setB.count(element) > 0)
//         {
//             ans.push_back(element);
//         }
//     }

//     cout << "Intersection without duplicates: ";
//     for(int element : ans)
//     {
//         cout << element << " ";
//     }

//     cout << endl;
//     return 0;
// }

// Time Complexity - O(n)
// ________________________________________________________________

#include <iostream>
#include <vector>
#include <algorithm>
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
    
    sort(arr.begin(), arr.end());
    sort(brr.begin(), brr.end());
    int i=0; int j=0;
    vector<int> ans;
    while(i < arr.size() && j < brr.size())
    {
        if(arr[i]==brr[j])
        {
            ans.push_back(arr[i]);
            i++;
            j++;
        }
        else if(arr[i] < brr[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    cout << "Intersection without duplicates: ";
    for(int element : ans)
    {
        cout << element << " ";
    }

    cout << endl;
    return 0;
}
// O(nlogn)

// Example explanation:
// arr = [1,2,2,1] and brr = [2,2]

// After intersection we get [2,2] in ans vector.

// ans.erase(unique(ans.begin(), ans.end()), ans.end());

// unique(ans.begin(), ans.end()) rearranges the elements in the ans vector to place all
// unique elements at the beginning of the vector. It doesn't physically remove the duplicates;
// it just moves them to the end of the vector. The 'unique' also returns an iterator pointing
// to the first element in the rearranged unique range. In this case, it points to the first 2
// in the vector (index 0).
// So ans still [2,2].

// Unique elements at left followed by duplicates till the end.
// The second ans.end() points the iterator at the end of the ans vector
// from where the duplicate elements should be removed.
