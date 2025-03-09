#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // vector<int> arr{10, 20, 30, 40, 50, 60, 70};
    // int sum = 80;

    // for(int i=0; i<arr.size(); i++)
    // {
    //     int element = arr[i];

    //     for(int j=i+1; j<arr.size(); j++)
    //     {
    //         if(element + arr[j] == sum)
    //         {
    //             cout<<"Pair found: "<<element<<","<<arr[j]<<endl;
    //         }
    //     }
    // }

    // TRIPLET
    vector<int> arr{10,20,30,40};
    int sum = 80;

    for(int i=0; i<arr.size(); i++)
    {
        int element1 = arr[i];

        for(int j=i+1; j<arr.size(); j++)
        {
            int element2 = arr[j];

            for(int k=j+1; k<arr.size(); k++)
            {
                int element3 = arr[k];

                if(element1 + element2 + element3 == sum)
                {
                    cout<<"Pair found: "<<element1<<","<<element2<<","<<element3<<endl;
                }
            }
        }
    }
}