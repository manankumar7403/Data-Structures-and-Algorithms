#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class info
{
    public:
    int data;   // konse number ki baat kar rhe hai
    int row;    // row ki value honi chahiye -> konse array se aaya hai
    int col;    // konse array index par hai

    // Constructor
    info(int val, int r, int c)
    {
        this->data = val;
        this->row = r;
        this->col = c;
    }
};

// Creating the Custom Comparator
class compare
{
    public:
        bool operator()(info* a, info* b)
        {
            return a->data > b->data;
        }
};

vector<int> mergeKSortedArrays(int arr[][4], int k, int n)
{
    // Creating Min Heap on our own custom comparator
    priority_queue<info*, vector<info*>, compare > minHeap;  // 'compare' khud ke data type(class info) par minHeap create kar liya par minHeap ko nahi pata kis value ko min aur kisko max maanu so iska logic define kar diya using the custom comparator 'compare'.
 
    // har sorted array ka first element insert karo
    for(int i=0; i<k; i++)
    {
        info* temp = new info(arr[i][0], i, 0); // har array par traverse karke uske 0th element ko minHeap me store kar diye
        minHeap.push(temp);
    }

    vector<int> ans;

    while(!minHeap.empty())
    {
        info* temp = minHeap.top();
        int topElement = temp->data;    // min heap ka top element minimum hoga
        int topRow = temp->row;
        int topCol = temp->col;
        minHeap.pop();                // topElement me store kar liya tha top element toh ab pop kar diya next min element ke liye

        ans.push_back(topElement);   // sab arrays me se current jo heap me 3 elementspade hai unme min element ko ans me push kardo

        // ab dekhna hai ki jis array ka element ans me insert karke pop kiya hai us array me aage bhi koi index hai 
        if(topCol + 1 < n)
        {
            info* newInfo = new info(arr[topRow][topCol+1], topRow, topCol+1);

            minHeap.push(newInfo);
        }
    }
    return ans;
}

int main()
{
    int arr[][4] = {{2,4,6,8}, {1,3,5,7}, {0,9,10,11}};
    int k = 3;     // total number of arrays
    int n = 4;     // number of elements in each array

    vector<int> ans = mergeKSortedArrays(arr, k, n);

    for(auto i: ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

// TC -> O(nklogk)

// Custom Comparator
/*
A Compare type providing a strict weak ordering.
Note that the Compare parameter is defined such that it returns true if its first argument comes before its second
argument in a weak ordering. But because the priority queue outputs largest elements first, the elements that "come
before" are actually output last. That is, the front of the queue contains the "last" element according to the weak
ordering imposed by Compare.
*/