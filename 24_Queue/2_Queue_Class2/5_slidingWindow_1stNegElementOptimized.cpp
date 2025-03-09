#include <iostream>
using namespace std;

void solve(int arr[], int size, int k)
{
    int firstNegativeIndex = 0;
    int firstNegativeElement;

    for (int i = k - 1; i < size; i++)
    {

        // skip out of window and positive elements
        while ((firstNegativeIndex < i) && (firstNegativeIndex <= i - k || arr[firstNegativeIndex] >= 0))
        {
            firstNegativeIndex++;
        }

        // check if a negative element is found, otherwise
        // use 0
        if (arr[firstNegativeIndex] < 0)
        {
            firstNegativeElement = arr[firstNegativeIndex];
        }
        else
        {
            firstNegativeElement = 0;
        }
        cout << firstNegativeElement << " ";
    }
}

int main()
{
    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int size = 8;
    int k = 3;

    solve(arr, size, k);

    return 0;
}

/*
while ((firstNegativeIndex < i) && (firstNegativeIndex <= i - k || arr[firstNegativeIndex] >= 0))

i basically har particular window ke last element ko point kar rha hai 
toh firstNegativeIndex jo hai vo i se chota hi hona chahiye matlab i ke left me hona chahiye 

agar firstNegativeIndex <= i-k hai toh firstNegativeIndex us particular window ke bahar lie kar raha hai
toh usse skip kar de rhe hai

agar arr[firstNegativeIndex] >= 0 hai matlab vo element negative nahi hai toh usse skip kar de rhe hai
*/

// TC -> O(n)
// SC -> O(1)
