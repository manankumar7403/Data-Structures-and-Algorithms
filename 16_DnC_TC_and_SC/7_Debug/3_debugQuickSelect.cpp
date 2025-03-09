// // Q3. Debug the code. This is implementation of quick-select algorithm.
// int partition(int arr[], int l, int r) {
// 	int x = arr[r], i = l;
// 	for (int j = l; j <= r - 1; j++) {
// 		if (arr[j] <= x) {
// 			swap(arr[i], arr[j]);
// 			i++;
// 		}
// 	}
// 	swap(arr[i], arr[r]);
// 	return i;
// }

// int kthSmallest(int arr[], int l, int r, int k) {
// 	int index = partition(arr, l, r);
// 	if(index - l == k - 1)
// 		return arr[index];
// 	if(index - l > k - 1)
// 		return kthSmallest(arr, l, index - 1, k);
// 	return kthSmallest(arr, index + 1, r, k - index + l - 1);
// }
// _______________________________________________________________________________________________

#include <iostream>
using namespace std;

int partition(int arr[], int l, int r)
{
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}

int kthSmallest(int arr[], int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1)
    {
        int index = partition(arr, l, r);
        if (index - l == k - 1)
            return arr[index];
        if (index - l > k - 1)
            return kthSmallest(arr, l, index - 1, k);
        return kthSmallest(arr, index + 1, r, k - index + l - 1);
    }
    return INT_MAX; // Return a value indicating invalid input or out-of-bounds k
}

int main()
{
    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3; // Choose k value as needed

    int result = kthSmallest(arr, 0, n - 1, k);
    if (result != INT_MAX)
        cout << "Kth smallest element is " << result << endl;
    else
        cout << "Invalid k value." << endl;

    return 0;
}
/*
The time complexity of the quick select algorithm is generally O(n^2) in the worst case, but it can achieve
an average-case time complexity of O(n). The space complexity is O(1) because the algorithm sorts the array
in-place and does not require additional memory proportional to the input size.

In the worst case, where the partitioning consistently selects the maximum or minimum element as the pivot,
the algorithm degrades to \(O(n^2)\) time complexity. However, on average, quick select performs well and has
an expected time complexity of \(O(n)\). The choice of pivot and the partitioning strategy play a crucial role
in determining the algorithm's performance.

It's important to note that the worst-case scenario is less likely to occur in practice due to various
strategies for selecting a good pivot, such as using a random pivot or selecting the median of three random
elements. These strategies help improve the average-case time complexity.
*/