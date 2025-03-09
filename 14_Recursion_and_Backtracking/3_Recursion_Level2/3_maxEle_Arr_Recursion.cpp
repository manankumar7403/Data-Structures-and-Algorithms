#include <iostream>
#include <climits>
using namespace std;

void findMax(int arr[], int n, int i, int& maxi)
{
    // Base case
    if(i >= n)
    {
        return;
    }

    // 1 case solve karo
    // current element ko check karo max hai ki nahi
    if(arr[i] > maxi)
    {
        maxi = arr[i];
    }

    // Baaki recursion sambhal lega
    findMax(arr, n, i+1, maxi);
}

int main()
{
    int arr[] = {10, 30, 21, 44, 32, 17, 19, 66};
    int n = 8;

    int i = 0;
    int maxi = INT_MIN;
    findMax(arr, n, i, maxi);

    cout << "Maximum number is: " << maxi << endl;

    return 0;
}