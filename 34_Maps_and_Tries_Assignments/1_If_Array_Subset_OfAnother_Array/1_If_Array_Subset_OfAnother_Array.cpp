// GFG
/*
Given two arrays: a1[0..n-1] of size n and a2[0..m-1] of size m, where both arrays may contain duplicate elements.
The task is to determine whether array a2 is a subset of array a1. It's important to note that both arrays can be
sorted or unsorted. Additionally, each occurrence of a duplicate element within an array is considered as a separate
element of the set.

Example 1:
Input:
a1[] = {11, 7, 1, 13, 21, 3, 7, 3}
a2[] = {11, 3, 7, 1, 7}
Output:
Yes
Explanation:
a2[] is a subset of a1[]

Example 2:
Input:
a1[] = {1, 2, 3, 4, 4, 5, 6}
a2[] = {1, 2, 4}
Output:
Yes
Explanation:
a2[] is a subset of a1[]

Example 3:
Input:
a1[] = {10, 5, 2, 23, 19}
a2[] = {19, 5, 3}
Output:
No
Explanation:
a2[] is not a subset of a1[]
*/

#include<iostream>
#include<unordered_map>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int, int>map;
    string ans = "Yes";
    
    for(int i=0; i<n; i++)
    {
        map[a1[i]]++;
    }
    
    // check whether all elements of a2 are present in a1
    for(int i=0; i<m; i++)
    {
        if(map.find(a2[i]) == map.end())
        {
            ans = "No";
            break;
        }
        else
        {
            // present
            if(map[a2[i]] > 0)
            {
                map[a2[i]]--;
            }
            else
            {
                ans = "No";
                break;
            }
        }
    }
    return ans;
}

int main()
{
    int n, m;
    cout << "Enter the number of elements in a1 arr:" << endl;
    cin >> n;
    int a1[n];
    cout << "Enter the elements in a1:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> a1[i];
    }
    cout << "Enter the number of elements in a2 arr:" << endl;
    cin >> m;
    int a2[m];
    cout << "Enter the elements in a2:" << endl;
    for(int i=0; i<m; i++)
    {
        cin >> a2[i];
    }

    cout << isSubset(a1, a2, n, m) << endl;
    return 0;
}

// TC -> O(n+m)
// SC -> O(n)