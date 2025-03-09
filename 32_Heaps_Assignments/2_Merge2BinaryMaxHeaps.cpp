// GFG
// Refer: https://www.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1

// Q - Given two binary max heaps as arrays, merge the given heaps to form a new max heap.
/*
Example 1:
Input  : 
n = 4 m = 3
a[] = {10, 5, 6, 2}, 
b[] = {12, 7, 9}
Output : 
{12, 10, 9, 2, 5, 7, 6}

Expected Time Complexity: O(n.Logn)
Expected Auxiliary Space: O(n + m)
*/

#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &a, int n, int i) // arr, size, index
{
    // Using 1-based indexing
    int index = i;
    int leftIndex = 2 * i + 1;
    int rightIndex = 2 * i + 2;
    int largest = index;

    // Check the conditions for heapifying(putting the chosen element at its desired location)
    if (leftIndex < n && a[largest] < a[leftIndex])
    {
        largest = leftIndex;
    }

    if (rightIndex < n && a[largest] < a[rightIndex])
    {
        largest = rightIndex;
    }

    if (index != largest)
    // if(index == largest) -> matlab sahi jagah par pahuch chuka hai, if(index != largest) yaani left ya right
    // child me se koi element > ho gya currentNode se toh swap karenge and index = largest karenge and recursive
    // call marenge until index == largest
    {
        // left ya right child me se koi element > ho gya currentNode se
        swap(a[index], a[largest]);
        index = largest;
        heapify(a, n, index);
    }
    // TC -> O(logN)
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{
    // Step 1: Merge both arrays into one
    a.insert(a.end(), b.begin(), b.end());

    // Step2: Build heap using merged array
    int size = a.size();
    for (int i = size / 2 - 1; i >= 0; i--) // Leaf nodes ko heapify nahi kar rahe
    {
        heapify(a, size, i);
    }
    return a;
}

int main()
{
    vector<int> a = {10,5,6,2};
    vector<int> b = {12,7,9};

    int n = a.size();
    int m = b.size();

    cout << "Max Heap A: ";
    for (int num : a)
    {
        cout << num << " ";
    }
    cout << endl;

    cout << "Max Heap B: ";
    for (int num : b)
    {
        cout << num << " ";
    }
    cout << endl;

    vector<int> mergedHeap = mergeHeaps(a, b, n, m);

    cout << "Merged Binary Max Heap: ";
    for (int num : mergedHeap)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

// Time Complexity: O(N + M)
// Auxiliary Space: O(N + M)  