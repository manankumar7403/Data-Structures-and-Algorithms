// Given two integer arrays nums1 and nums2, return an array of their intersection.
// Each element in the result must appear as many times as it shows in both arrays and you
// may return the result in any order.

// Example 1:
// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2,2]

// Example 2:
// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [4,9]
// Explanation: [9,4] is also accepted.

// #include <iostream>
// #include <vector>
// #include <algorithm>
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
    
//     sort(arr.begin(), arr.end());
//     sort(brr.begin(), brr.end());
//     int i=0; int j=0;
//     vector<int> ans;
//     while(i < arr.size() && j < brr.size())
//     {
//         if(arr[i]==brr[j])
//         {
//             ans.push_back(arr[i]);
//             i++;
//             j++;
//         }
//         else if(arr[i] < brr[j])
//         {
//             i++;
//         }
//         else
//         {
//             j++;
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
// Time Complexity - O(nlogn)
// ________________________________________________________________________


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> intersect(vector<int> &arr, vector<int> &brr)
{
    unordered_map<int, int> count1, count2;
    vector<int> result;

    for(int i: arr)
    {
        count1[i]++;            // freq of elements in arr are stored in key-value pair in count1 -> count1 = {1:2, 2:2}
    }
    
    for(int i: brr)
    {
        if(count1.find(i) != count1.end() && count1[i] > 0)
        {
            result.push_back(i);
            count1[i]--;
        }
    }
    return result;
}
// count1.find(i) -> If the element i of brr is present in the count1 unordered map which
// contains the elements and their freq of arr in a key-value pair format.

// != count1.end() -> this is in continuation with the previous condition that element is found 
// and this is also not the end of the count1 unordered map which results in true.
// like if you are present you won't be pointing to the last item

// count1[i] > 0 -> if the frequency of element i in count1 map is greater than 0. then this 
// condition is also true

// count1.find(i) != count1.end() && count1[i] > 0 -> this results in true and if loop proceeds with
// execution.

// Take example: arr = [1,2,2,1] and brr = [2,2]

// for(int i: arr)
// {count1[i]++;} -> O/P = {1:2, 2:2}

// for(int i: brr)
// {if(count1.find(i) != count1.end() && count1[i] > 0){
//             result.push_back(i);
//             count1[i]--;}}

// 1) For loop Iterates through elements of brr
// 2) count1.find(2) != count1.end(): This condition compares the iterator returned by
// find with count1.end(). If the iterator is not equal to count1.end(), it means that the
// key 2 was found in the map, and the condition evaluates to true. If the key 2 was not found,
// the iterator would be equal to count1.end(), and the condition would evaluate to false.
// 3) Now that if condition is true, 2 would be pushed back in result and the frequency of 2 would
// be decremented from count1 unordered map.
// 4) Now count1 is {1:2, 2:1}.
// 5) The second for loop (iterating through brr) now points to the second '2'(index 1) in [2,2].
// 6) As 2 is still present in count1 map once, it is again pushed back in result and the
// frequency of 2 is decremented.
// 7) Now count1 is {1:2}.
// 8) The second for loop has reached the end of brr so it terminates as no more elements are
// available in brr for intersection.
// 9) result is returned as [2,2]

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

    vector<int> result = intersect(arr, brr);
    for(int num: result)
    {
        cout << num << " ";
    }
    return 0;
}

// Time complexity - O(n)