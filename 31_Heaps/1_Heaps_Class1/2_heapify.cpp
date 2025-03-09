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

// TC -> n/2 -> O(N)

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

    return 0;
}

// Time Complexity: O(N)
// Auxiliary Space: O(N) (Recursive Stack Space)

// ✅ Check the  special case of why is TC O(N) instead of O(NlogN) -> pdf ✅
// Also refer: https://www.geeksforgeeks.org/time-complexity-of-building-a-heap/
