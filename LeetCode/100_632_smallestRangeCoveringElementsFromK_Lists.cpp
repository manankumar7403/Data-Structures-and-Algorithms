// 🔴🔴🔴🔴 LEETCODE 632 -> Smallest Range Covering Elements from K Lists 🔴🔴🔴🔴
// Refer 3_smallestRangeCoveringElementsFromK_Lists.cpp
/*
You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number
from each of the k lists.

We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

Example 1:
Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].

Example 2:
Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
Output: [1,1]

Constraints:
nums.length == k
1 <= k <= 3500
1 <= nums[i].length <= 50
-10^5 <= nums[i][j] <= 10^5
nums[i] is sorted in non-decreasing order.
*/
// _________________________________________________________________________________________________________________

// ✅ Amazon and Microsoft Most Asked

// mini aur maxi jo 2 elements liye hai unme se sirf mini ko aage increase kar sakte hai kyuki
// singly linked list hai so backward traversal is not possible, therefore, mini ko aage badhayenge.
// aur kyuki hume regularly mini ko aage badhana hai (next minimum element chahiye smallest range find karne ke liye),
// hume next minimum element dhundna hoga that's why we will use a MIN HEAP.

// ⭐⭐ Merge k Sorted Arrays Logic ⭐⭐

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Node
{
public:
    int data;
    int row;
    int col;

    Node(int d, int r, int c)
    {
        this->data = d;
        this->row = r;
        this->col = c;
    }
};

class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

vector<int> smallestRange(vector<vector<int>> &nums)
{
    int mini = INT_MAX;
    int maxi = INT_MIN;

    priority_queue<Node *, vector<Node *>, compare> minHeap;
    int k = nums.size();

    // har list(array) ka pehla element minHeap mein insert kardo
    for (int i = 0; i < k; i++)
    {
        int element = nums[i][0];
        maxi = max(maxi, element);
        mini = min(mini, element);
        minHeap.push(new Node(element, i, 0));
    }

    int ansStart = mini;
    int ansEnd = maxi;

    while (!minHeap.empty())
    {
        Node *top = minHeap.top();
        int topElement = top->data;
        int topRow = top->row;
        int topCol = top->col;
        minHeap.pop();

        // mini updated
        mini = topElement;
        // toh range bhi update hui hogi -> check karo kahi yahi toh answer nahi hai

        // check for answer
        int currRange = maxi - mini;
        int ansRange = ansEnd - ansStart;
        if (currRange < ansRange)
        {
            ansStart = mini;
            ansEnd = maxi;
        }

        // check for new element in the same list
        if (topCol + 1 < nums[topRow].size()) // check for new element in the same list
        {
            // update maxi if there is a new element
            maxi = max(maxi, nums[topRow][topCol + 1]);
            Node *newNode = new Node(nums[topRow][topCol + 1], topRow, topCol + 1);
            minHeap.push(newNode);
        }

        else
        {
            // there is no element in the same array or list
            break;
        }
    }
    vector<int> ans;
    ans.push_back(ansStart);
    ans.push_back(ansEnd);
    return ans;
}

int main()
{
    // Take user input for the 2D vector nums
    int k;
    cout << "Enter the number of lists (k): ";
    cin >> k;

    vector<vector<int>> nums(k);
    for (int i = 0; i < k; ++i)
    {
        int size;
        cout << "Enter the size of list " << i + 1 << ": ";
        cin >> size;

        cout << "Enter the elements of list " << i + 1 << ": ";
        for (int j = 0; j < size; ++j)
        {
            int element;
            cin >> element;
            nums[i].push_back(element);
        }
    }

    // Call the smallestRange function and print the result
    vector<int> result = smallestRange(nums);
    cout << "Smallest Range Covering Elements from K Lists: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}

/*
Time Complexity:

Overall: O(N * K * log K), where N is the total number of elements in all lists combined, and K is the number of lists.

Breakdown:

Initialization: O(K) for initializing variables and creating the priority queue.
Heap operations: O(N * log K) for pushing and popping elements from the min-heap.
Inner loop: O(K) for finding the next element in the same list, updating the heap, and potentially updating the answer.
Space Complexity:

O(K), primarily due to:
The priority queue, which can hold up to K elements.
The auxiliary variables used for tracking the current range and smallest range.
The Node objects created for the heap, but their memory is reclaimed as elements are popped.

Explanation:
Heap Operations: The algorithm iterates through up to N elements, performing O(log K) operations for each push and pop in
the min-heap.
Inner Loop: The inner loop runs at most K times within each heap operation, contributing to the overall N * K * log K
time complexity.
Space: The min-heap and auxiliary variables are the primary contributors to space complexity.
*/