#include<iostream>
using namespace std;

void printArray(int arr[], int size)
{
    cout<<"print the array"<<endl;
    for (int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout << endl << "done printing" << endl;
}

int main()
{
    int fifth[10] = {0};
    int n = 10;
    printArray(fifth, n);
    
    cout << "everything is fine!" << endl;

    int fifthsize = sizeof(fifth)/sizeof(int);
    cout<<"Size of fifth is "<<fifthsize<<"."<<endl;

    return 0;

    
}
