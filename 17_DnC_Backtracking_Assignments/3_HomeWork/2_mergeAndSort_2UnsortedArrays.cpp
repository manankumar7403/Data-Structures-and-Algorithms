#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    
    int i = m - 1;     // index of last element of nums1 (uptil 0)
    int j = n - 1;     // index of last element of nums2
    int k = m + n - 1; // all elements of nums1 array
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[k--] = nums1[i--];
        }
        else
        {
            nums1[k--] = nums2[j--];
        }
    }
    while (i >= 0)
    {
        nums1[k--] = nums1[i--]; // remaining values of nums1
    }
    while (j >= 0)
    {
        nums1[k--] = nums2[j--]; // remaining values of nums2
    }
}

int main() {
    int m;
    cout << "Enter the size of nums1: ";
    cin >> m;
    vector<int> nums1(m);

    cout << "Enter elements for nums1:" << endl;
    for (int i = 0; i < m; ++i) {
        cin >> nums1[i];
    }

    int n;
    cout << "Enter the size of nums2: ";
    cin >> n;
    vector<int> nums2(n);

    cout << "Enter elements for nums2:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> nums2[i];
    }

    merge(nums1, m, nums2, n);

    cout << "Merged array: "<< endl;
    for (int i = 0; i < m + n; ++i) {
        cout << nums1[i] << " ";
    }
    cout << endl;
    return 0;
}

// Time Complexity: O (nlogn + mlogm + (n + m)) 
// Space Complexity: O ( (n + m) )