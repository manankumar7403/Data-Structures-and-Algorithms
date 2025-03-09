//🔴🔴 Important Algorithm for finding the kth Smallest Element in Array in TC->O(n) and SC->O(1)
// Refer: https://www.geeksforgeeks.org/floyd-rivest-algorithm/
/*
The Floyd-Rivest algorithm is a selection algorithm used to find the kth smallest element in an array of distinct elements.
It is similar to the QuickSelect algorithm but has a better running time in practice. 
Like QuickSelect, the algorithm works on the idea of partitioning. After partitioning an array, the partition element
ends up in the corrected sorted position. If the array has all distinct elements, retrieving the (k+1)th smallest
element is the same as retrieving the (k+1)th element after sorting. Because a full sort is
expensive(takes O(N log N) to compute), the Floyd-Rivest algorithm leverages partitioning to accomplish the same in
O(N) time.

Algorithm: 
If the size of the array S being considered is small enough, then the QuickSelect algorithm is applied directly to get
the K-th smallest element. This size is an arbitrary constant of the algorithm, which the authors choose as 600.
Otherwise, 2 pivots are chosen- newLeftIndex and newRightIndex using random sampling such that they have the highest
probability of containing the K-th largest element. Then, the function is called recursively with left and right
boundaries of the array now set to newLeftIndex and newRightIndex.
Like QuickSelect, after partitioning the subarray, the left and right boundaries need to be set such that they contain
the K-largest element. 
After partitioning the array around K, the Kth element is in its correct sorted position. So, the left and right
boundaries are set in such a way that the subarray being considered contains array[k] 
*/

// ✅✅ Floyd-Rivest Algorithm for finding the kth smallest element in an array ✅✅

// _____________________________________________________________________________________________________________________

#include <iostream>
#include <math.h>
using namespace std;

// Function to return the sign of a number
int sign(double x)
{
	if (x < 0)
		return -1;
	if (x > 0)
		return 1;
	return 0;
}

// Function to swap two numbers in an array.
void swap(int arr[], int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int select(int arr[], int left, int right, int k)
{
	while (right > left) {
		if (right - left > 600) {
			// Choosing a small subarray S based on sampling.
			// 600, 0.5 and 0.5 are arbitrary constants
			int n = right - left + 1;
			int i = k - left + 1;
			double z = log(n);
			double s = 0.5 * exp(2 * z / 3);
			double sd = 0.5 * sqrt(z * s * (n - s) / n)	* sign(i - n / 2);

			int newLeft = max(left,	(int)(k - i * s / n + sd));

			int newRight = min(right, (int)(k + (n - i) * s / n	+ sd));

			select(arr, newLeft, newRight, k);
		}

		// Partition the subarray S[left..right] with arr[k] as pivot
		int t = arr[k];
		int i = left;
		int j = right;
		swap(arr, left, k);
		if (arr[right] > t) {
			swap(arr, left, right);
		}

		while (i < j) {
			swap(arr, i, j);
			i++;
			j--;

			while (arr[i] < t)
				i++;
			while (arr[j] > t)
				j--;
		}

		if (arr[left] == t)
			swap(arr, left, j);
		else {
			j++;
			swap(arr, right, j);
		}

		// Adjust the left and right pointers to select the subarray having k
		if (j <= k)
			left = j + 1;
		if (k <= j)
			right = j - 1;
	}
	return arr[k];
}

int main()
{
	int arr[] = { 7, 3, 4, 0, 1, 6 };
	int n = sizeof(arr) / sizeof(int);

	int k = 2;
	int res = select(arr, 0, n - 1, k - 1);
	cout << "The " << k << "-th smallest element is " << res << endl;
	return 0;
}
