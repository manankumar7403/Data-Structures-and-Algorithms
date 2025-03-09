#include <iostream>
using namespace std;

bool find(int arr[], int size, int key)
{
    // Linear Search
    for (int i=0; i<size; i++)
    {
        if(arr[i]==key)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int arr[5] = {1,2,3,4,5};
    int size = 5;
    cout<<"Enter a key to find: "<<endl;
    int key;
    cin>>key;

    if (find(arr, size, key))
    {
        cout<<"Found"<<endl;
    }
    else
    {
        cout<<"Not found"<<endl;
    }
    return 0;
}

// Time complexity - O(n)