// You are given an array 'ARR' of size 'N' containing each number between 1 and 'N' - 1 at
// least once. There is a single integer value that is present in the array twice. Your
// task is to find the duplicate integer value present in the array.
// Example: 4 2 1 3 1
// Output: 1


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
    
    for(int i=1; i<arr.size(); i++)
    {
        ans = ans^i;
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