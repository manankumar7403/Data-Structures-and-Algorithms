// Q4. Debug the code. This code uses binary search to find ceil index of the target number.
// #include <bits/stdc++.h>
// using namespace std;

// int ceilSearch(int arr[], int low, int high, int x) {
// 	int mid = (low + high) / 2;
// 	if (arr[mid] == x)
// 		return mid;
// 	else if (arr[mid] < x) {
// 		if (mid + 1 <= high && x <= arr[mid + 1])
// 			return mid;
// 		else
// 			return ceilSearch(arr, mid + 1, high, x);
// 	}
// 	else {
// 		if (mid - 1 >= low && x > arr[mid - 1])
// 			return mid;
// 		else
// 			return ceilSearch(arr, low, mid - 1, x);
// 	}
// }

// int main() {
// 	int arr[] = { 1, 2, 8, 10, 10, 12, 19 };
// 	int n = sizeof(arr) / sizeof(arr[0]);
// 	int x = 10;
// 	int index = ceilSearch(arr, 0, n - 1, x);
// 	if (index == -1)
// 		cout << "Doesn't Exist";
// 	else
// 		cout << "Value at ceil index of " << x << " is " << arr[index];

// 	return 0;
// }
// ______________________________________________________________________________________________________

#include <bits/stdc++.h>
using namespace std;

int ceilSearch(int arr[], int low, int high, int x)
{
    int mid;
    
    if (x <= arr[low])
        return low;
    
    if (x > arr[high])
        return -1;

    mid = (low + high) / 2;
    
    if (arr[mid] == x)
        return mid;
    
    else if (arr[mid] < x)
    {
        if (mid + 1 <= high && x <= arr[mid + 1])
            return mid + 1;
        else
            return ceilSearch(arr, mid + 1, high, x);
    }
    
    else
    {
        if (mid - 1 >= low && x > arr[mid - 1])
            return mid;
        else
            return ceilSearch(arr, low, mid - 1, x);
    }
}

int main()
{
    int arr[] = {1, 2, 8, 10, 10, 12, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 9;
    int index = ceilSearch(arr, 0, n - 1, x);
    if (index == -1)
        cout << "Doesn't Exist";
    else
        cout << "Value at ceil index of " << x << " is " << arr[index];

    return 0;
}