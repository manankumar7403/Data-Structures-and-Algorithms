// Usually questions like these (kth smallest number) requires HEAPS only.

// 1st approach -> sort(arr, arr+n) -> kth smallest would be at arr[k-1] -> TC = O(nlogn)

// 2nd approach -> MIN HEAP -> n sized heap -> popped (n-k) times
// 1st pop -> 1st smallest element, 2nd pop -> 2nd smallest element,
// kth pop -> kth smallest element
// But SC is O(n) as n size ka heap ban gaya
// TC is O(n)

// Aur kam TC me karna hai

// ✅ 3rd approach -> MAX HEAP
// First k element ka MAX HEAP bana diya
// ab uske aage ke elements ko tab hi insert karenge agar element to be inserted is less than the top of the heap.
// Toh pehle heap ke top element ko pop karunga fir vo new element insert kar dunga.
// Toh har time par heap ka size k hi hoga -> SC = O(k) and TC = O(n)
// So, MAX HEAP k size ka hoga uske andar k small elements honge and top par kth smallest element hoga

#include <iostream>
#include <queue>
using namespace std;

// Top par MAX HEAP ke hamesha kthSmallestElement hi pada rahega kyuki hum top se chote elements ko hi insert
// karte hai aur fir priority_queue khud usko heapify kar deta hai
int getKthSmallestElement(int arr[], int n, int k)
{
    // Step1: Create a MAX HEAP
    priority_queue<int> pq;
    
    // Step2: Insert initial k elements of the array in the heap
    for(int i=0; i<k; i++)
    {
        pq.push(arr[i]);
    }

    // Step3: For remaining elements, only push if they are less than the top of the MAX HEAP
    for(int i=k; i<n; i++)
    {
        int element = arr[i];
        if(element < pq.top())
        {
            pq.pop();
            pq.push(element);
        }
    }
    int ans = pq.top();
    return ans;

}

// Similarly hum kthGreatestElement ke liye bhi kar sakte hai
int getKthGreatestElement(int arr[], int n, int k)
{
    // Step1: Create a MAX HEAP
    priority_queue<int, vector<int>, greater<int> > pq;    // MIN HEAP
    
    // Step2: Insert initial k elements of the array in the heap
    for(int i=0; i<k; i++)
    {
        pq.push(arr[i]);
    }

    // Step3: For remaining elements, only push if they are greater than the top of the MIN HEAP
    for(int i=k; i<n; i++)
    {
        int element = arr[i];
        if(element > pq.top())
        {
            pq.pop();
            pq.push(element);
        }
    }
    int ans = pq.top();
    return ans;

}

int main()
{
    int arr[] = {10, 5, 20, 4, 15};
    int n = 5;
    int k = 2;

    int ans = getKthSmallestElement(arr, n, k);
    cout << "kth Smallest element is: " << ans << endl;

    int result = getKthGreatestElement(arr, n, k);
    cout << "kth Greatest element is: " << result << endl;
    return 0;
}

