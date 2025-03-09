#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> arr{10, 1, 7, 6, 14, 9};
    int n = arr.size();

    // Bubble sort

    for(int round = 1; round < n; round++)    // starting from 1 as we need to do n-1 comparisons because the leftmost element could not be compared at the last round
    {
        bool swapped = false;
        for (int j=0; j < n-round; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swapped = true;
                swap(arr[j], arr[j+1]);
            }
        }
        if(swapped == false)
        {
            // sorting is done, no need to go through the remaining rounds
            break;
        }
    }

    // printing the sorted array
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

// In arr = [10, 1, 7, 6, 14, 9]
//           0   1  2  3   4  5
// n = 6
// round = 1 to 5
// j = 0 to 6-round

// i) round = 1
//    j = 0 to 4 -> compares all adjacent elements and places 14 at last
//                  arr = [10, 1, 7, 6, 14, 9]
//                  arr = [1, 10, 7, 6, 14, 9]
//                  arr = [1, 7, 10, 6, 14, 9]
//                  arr = [1, 7, 6, 10, 14, 9]
//                  arr = [1, 7, 6, 10, 14, 9]
//                  arr = [1, 7, 6, 10, 9, 14]

// ii) round = 2
//    j = 0 to 4 -> compares all adjacent elements and places 10 at second last
//                  arr = [1, 7, 6, 10, 9, 14]
//                  arr = [1, 7, 6, 10, 9, 14]
//                  arr = [1, 6, 7, 10, 9, 14]
//                  arr = [1, 6, 7, 10, 9, 14]
//                  arr = [1, 6, 7, 10, 9, 14]
//                  arr = [1, 6, 7, 9, 10, 14]

// iii) round = 3
//                 arr = [1, 6, 7, 9, 10, 14]

// Now array is already sorted after round 2, so the swapped condition will break (false) the loop,
// as no swapping is done.
// The swapped condition is making the bubble sort somewhat optimized.
// If it is not used, the code will run for additional rounds (unnecessary).
// NOTE: The time complexity still remains O(n^2)
