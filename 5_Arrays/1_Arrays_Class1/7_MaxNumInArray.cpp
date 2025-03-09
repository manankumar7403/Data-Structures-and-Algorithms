#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int arr[] = {2,4,6,7,8,91,102,31,21,65,75,202,109,45,77};
    int size = 15;
    int maxi = INT_MIN;
    for(int i=0; i<size; i++)
    {
        if(arr[i] > maxi)
        {
            maxi = arr[i];
        }
    }

    cout<<"Maximum number is: "<< maxi <<endl;
    return 0;
}