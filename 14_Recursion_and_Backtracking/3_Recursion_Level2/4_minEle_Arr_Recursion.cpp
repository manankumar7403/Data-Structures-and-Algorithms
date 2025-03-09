#include <iostream>
#include <climits>
using namespace std;

void findMin(int arr[], int n, int i, int& mini)
{
    // Base case
    if(i >= n)
    {
        return;
    }

    // 1 case solve karo
    // current element ko check karo min hai ki nahi
    if(arr[i] < mini)
    {
        mini = arr[i];
    }

    // Baaki recursion sambhal lega
    findMin(arr, n, i+1, mini);
}

int main()
{
    int arr[] = {10, 30, 21, 44, 32, 17, 19, 66};
    int n = 8;

    int i = 0;
    int mini = INT_MAX;
    findMin(arr, n, i, mini);

    cout << "Minimum number is: " << mini << endl;

    return 0;
}