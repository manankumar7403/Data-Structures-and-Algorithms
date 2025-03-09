/*
Geek is busy solving problems on Bitwise operators. Today while solving problems, he observed something which
intrigued him very much. He discovered that there are some awesome pairs in a list of integers whose Bitwise AND is
strictly greater than Bitwise XOR among them.
Given a list arr[] of N integers find the number of awesome pairs.

Example 1:
Input:
N=4
arr[] = {6, 2, 5, 3}
Output: 2
Explanation:
Awesome pairs are (6, 5) and (2, 3).

Example 2:
Input:
N=3
arr[] = {1,1,1}
Output: 3
Explanation: All pairs are awesome.

Your Task:
You don't need to read input or print anything. Your task is to complete
the function pairs() that takes the array arro and its size N as input
parameters and return the number of awesome pairs.
Constraints:
1<=N<=10^6
0 <= arr[i] <= 10^9
*/

// _________________________________________________________________________________________________________

/*
#include <iostream>
#include <vector>
using namespace std;

long long pairs(vector<int> &arr)
{
    int n = arr.size();
    long long count = 0;

    // Compare each pair (i, j) only once
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if ((arr[i] & arr[j]) > (arr[i] ^ arr[j]))
            {
                count++;
            }
        }
    }

    return count;
}

int main()
{
    int n;
    cout << "Enter the size of array: " << endl;
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements in the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Minimum number of pairs: " << pairs(arr) << endl; // Output: 2
    return 0;
}
*/

// ________________________________________________________________________________________________________________

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

long long pairs(vector<int>& arr)
{
    int size = arr.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < size; i++)
    {
        int temp = arr[i];
        int count = 0;
        while (temp)
        {
            count++;
            temp = temp >> 1;
        }
        mp[count]++;
    }
    long long ans = 0;
    for (auto it : mp)
    {
        long long n = it.second;
        ans = ans + n * (n - 1) / 2;
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of array: " << endl;
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements in the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Minimum number of pairs: " << pairs(arr) << endl;
    return 0;
}