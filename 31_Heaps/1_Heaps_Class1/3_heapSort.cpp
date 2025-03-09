// ⭐ Heapify is the process of converting a binary tree into a heap data structure. A heap is a complete
// binary tree, meaning each level of the tree is completely filled, except possibly the bottom level. ⭐

// Ek element jiska index de rakha hai usse sahi element par pahuchana hai
// Example heapify(arr, n, i) -> arr, size, index
// Toh ab i ko compare karo left aur right(2i aur 2i+1) wale elements se
// i == largest -> sahi jagah par pahuch chuka hai
// 1_Heaps_Intro_MaxHeap.cpp -> ⭐Same poora deletion wala logic hai⭐

/*
✅ Leaf Nodes ko Heapify karne ki zarurat nahi hoti kyuki vo sahi jagah par padi hai ✅
⭐ Complete Binary Tree ke andar (n/2 + 1) -> n, saari leaf nodes hoti hai ⭐
*/ 

#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)    // arr, size, index
{
    int index = i;
    int leftIndex = 2*i;
    int rightIndex = 2*i+1;
    int largest = index;

    // Check the conditions for heapifying(putting the chosen element at its desired location)
    if(leftIndex <= n && arr[largest] < arr[leftIndex])
    {
        largest = leftIndex;
    }

    if(rightIndex <= n && arr[largest] < arr[rightIndex])
    {
        largest = rightIndex;
    }

    if(index != largest) 
    // if(index == largest) -> matlab sahi jagah par pahuch chuka hai, if(index != largest) yaani left ya right
    // child me se koi element > ho gya currentNode se toh swap karenge and index = largest karenge and recursive
    // call marenge until index == largest
    {
        // left ya right child me se koi element > ho gya currentNode se
        swap(arr[index], arr[largest]);
        index = largest;
        heapify(arr, n, index);
    }
    // TC -> O(logN)
}

// Leaf Nodes ko heapify nahi karte heap banate time uska function hai ye
void buildHeap(int arr[], int n)
{
    for(int i = n/2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n)  // array and array size
{
    while(n != 1)
    {
        swap(arr[1], arr[n]);
        n--;

        // heapify
        heapify(arr, n, 1);    // top wale element ko heapify karna hai isliye 1 bhej rhe hai heapify wale function mein
    }

    return;
}

int main()
{
    int arr[] = {-1, 12, 15, 13, 11, 14};
    int n = 5;
    buildHeap(arr, n);

    cout << "Printing the heap:" << endl;
    for(int i=0; i<=n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Printing the heap sort: " << endl;
    heapSort(arr, n);
    for(int i=1; i<=n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

/*
Complexity Analysis of Heap Sort
Time Complexity: O(N log N)
Auxiliary Space: O(log n), due to the recursive call stack. However, auxiliary space can be O(1) for iterative
implementation.

Important points about Heap Sort:
1) Heap sort is an in-place algorithm. 
2) Its typical implementation is not stable but can be made stable (See this)
3) Typically 2-3 times slower than well-implemented QuickSort.  The reason for slowness is a lack of locality of
reference.

Advantages of Heap Sort:
1) Efficient Time Complexity: Heap Sort has a time complexity of O(n log n) in all cases. This makes it efficient
for sorting large datasets. The log n factor comes from the height of the binary heap, and it ensures that the
algorithm maintains good performance even with a large number of elements.
2) Memory Usage – Memory usage can be minimal because apart from what is necessary to hold the initial list of
items to be sorted, it needs no additional memory space to work.
3) Simplicity –  It is simpler to understand than other equally efficient sorting algorithms because it does not use
advanced computer science concepts such as recursion.

Disadvantages of Heap Sort:
1) Costly: Heap sort is costly.
2) Unstable: Heap sort is unstable. It might rearrange the relative order.
3) Efficient: Heap Sort is not very efficient when working with highly complex data. 

Frequently Asked Questions Related to Heap Sort

Q1. What are the two phases of Heap Sort?
The heap sort algorithm consists of two phases. In the first phase, the array is converted into a max heap.
And in the second phase, the highest element is removed (i.e., the one at the tree root) and the remaining elements
are used to create a new max heap.

Q2. Why Heap Sort is not stable?
The heap sort algorithm is not a stable algorithm. This algorithm is not stable because the operations that are
performed in a heap can change the relative ordering of the equivalent keys.

Q3. Is Heap Sort an example of the “Divide and Conquer” algorithm?
Heap sort is NOT at all a Divide and Conquer algorithm. It uses a heap data structure to efficiently sort its element
and not a “divide and conquer approach” to sort the elements.

Q4. Which sorting algorithm is better – Heap sort or Merge Sort?
The answer lies in the comparison of their time complexity and space requirements. The Merge sort is slightly
faster than the Heap sort. But on the other hand merge sort takes extra memory. Depending on the requirement,
one should choose which one to use.

Q5. Why is Heap sort better than Selection sort?
Heap sort is similar to selection sort, but with a better way to get the maximum element. It takes advantage of
the heap data structure to get the maximum element in constant time 
*/