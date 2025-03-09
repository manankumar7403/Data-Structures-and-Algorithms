// ⭐⭐⭐⭐ Refer: https://www.geeksforgeeks.org/heap-data-structure/ ⭐⭐⭐⭐

// A Heap is a special Tree-based data structure in which the tree is a complete binary tree.
// that holds a heap property (Min Heap and Max Heap)

// 🔴🔴🔴🔴 Hum creation arrays se karenge par visualize trees ke form me karenge 🔴🔴🔴🔴
/*
Generally, Heaps can be of two types:
1) Max-Heap: In a Max-Heap the key present at the root node must be greatest among the keys present at all of
it’s children. The same property must be recursively true for all sub-trees in that Binary Tree.

2) Min-Heap: In a Min-Heap the key present at the root node must be minimum among the keys present at all of
it’s children. The same property must be recursively true for all sub-trees in that Binary Tree.
*/

// ✅✅ We have covered
// 1) Insertion in Max Heap
// 2) Deletion in Max Heap

#include <iostream>
using namespace std;

class Heap
{
    // static allocation kar rhe idhar, dynamic bhi kar sakte hai
    public:
    int arr[101];
    int size;       // kitne elements insert ho chuke hai uska track rakhne ke liye

    // Constructors
    Heap()
    {
        size = 0;
    }

    // ✅ MAX HEAP MEIN INSERTION WALA LOGIC
    void insertVal(int value)
    {
        // value insert end me karo
        size = size + 1;
        int index = size;
        arr[index] = value;

        // is value ko iski right position par leke jana hai(by default max heap ko dhyan me rakh ke kaam karenge)
        while(index > 1)
        {
            int parentIndex = index/2;

            if(arr[index] > arr[parentIndex])
            {
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            else
            {
                break;
            }
        }
    }
    // Takes O(logN) time


    // ✅ MAX HEAP MEIN DELETION WALA LOGIC
    // Heap mein jab bhi deletion ki baat kar rahe ho matlab top wali node(root node) hi delete hogi aur koi nahi
    // Toh root node ko last value se replace kara do
    // Last node ko delete kar do
    // Ab updated root node ko uski correct position par pahuchao
    int deleteVal()
    {
        int ans = arr[1];
        // replace root node value with last node data
        arr[1] = arr[size];   // root node replaced by last node ka data 
        size--;               // last node deleted

        // place root node ka data on its correct position
        int index = 1;
        while(index < size)
        {
            int left = 2 * index;
            int right = 2 * index + 1;

            int largest = index;

            // ab left aur right childs me traverse karenge aur left child, right child, aur parent me se largest value 'largest' me store kar lenge 
            if(left < size && arr[largest] < arr[left])
            {
                largest = left;
            }

            if(right < size && arr[largest] < arr[right])
            {
                largest = right;
            }

            if(largest == index)
            {
                // value is at correct location
                break;
            }
            
            // ab largest value find kar li hai toh parent(index) ko largest value(largest) se swap kara do AND parent(index) ko update karke 'largest' kardo 
            else
            {
                swap(arr[index], arr[largest]);
                index = largest;
            }
        }
        return ans;        // if(largest == index) is condition ke liye likhi hai kyuki function 'int' type ka hai toh kuch toh return karna padega.
    }
    
    // Takes O(logN) time
    // ✅ 🔴 ⭐ IS TAREEKE SE HUM MAX ELEMENT ARRAY KA O(1) TC ME NIKAL SAKTE HAI ✅ 🔴 ⭐
};



int main()
{
    /*
    Heap h;
    h.arr[0] = -1;
    h.arr[1] = 100;
    h.arr[2] = 50;
    h.arr[3] = 60;
    h.arr[4] = 40;
    h.arr[5] = 45;

    h.size = 5;

    cout << endl;
    cout << "Printing the normal heap as it is: " << endl;
    for(int i=0; i <= h.size; i++)
    {
        cout << h.arr[i] << " ";
    }
    cout << endl << endl;

    h.insertVal(110);

    cout << "Printing the max heap: " << endl;
    for(int i=0; i <= h.size; i++)
    {
        cout << h.arr[i] << " ";
    }
    cout << endl << endl;
    return 0;
    */

    Heap h;
    h.insertVal(50);
    h.insertVal(30);
    h.insertVal(70);
    h.insertVal(40);
    h.insertVal(80);
    h.insertVal(100);

    cout << endl;
    cout << "Printing the max heap: " << endl;
    for (int i = 1; i <= h.size; i++)
    {
        cout << h.arr[i] << " ";
    }
    cout << endl << endl;

    h.deleteVal();

    cout << "Printing the max heap after deletion: " << endl;
    for (int i = 1; i <= h.size; i++)
    {
        cout << h.arr[i] << " ";
    }
    cout << endl << endl;
}