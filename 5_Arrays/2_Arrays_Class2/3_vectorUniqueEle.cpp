// All the elements in the given array appear twice except one. Find that unique element.
// Example: 1 1 2 2 3
// Unique element is 3
// Famously asked in many interviews

#include <iostream>
#include <vector>
using namespace std;

int findUnique(vector<int> arr)
{
    int ans = 0;
    for(int i=0; i<arr.size(); i++)
    {
        ans = ans^arr[i];
    }
    return ans;
}

int main()
{
    int n;
    cout<<"Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout<<"Enter the elements: "<<endl;
    for(int i=0; i<arr.size(); i++)
    {
        cin >> arr[i];
    }

    int uniqueElement = findUnique(arr);

    cout<<"Unique element is: "<<uniqueElement<<endl;
    return 0;
}