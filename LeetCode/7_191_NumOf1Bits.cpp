#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cout<<"Enter a number: ";
    cin>>n;

    if(n < 0)
    {
        cout<<"Enter a positive number!";
        return 1;
    }

    vector<int> binaryBits;

    if(n == 0)
    {
        binaryBits.push_back(0);
    }

    while(n > 0)
    {
        binaryBits.push_back(n % 2);
        n = n / 2;
    }

    cout << "Binary representation: ";
    for(int i = binaryBits.size() - 1; i >= 0; i--)
    {
        cout<<binaryBits[i];
    }
    cout << endl;

    int count = 0;
    for(int bit: binaryBits)       // this for loop takes index value, not index
    {
        if(bit == 1)
        {
            count++;
        }
    }

    cout << "Number of set bits: " << count << endl;
    return 0;
}

// _____________________________________________________________________________
// For set bits calculation given decimal number input, simply do
// int count = 0;
// while(n!=0)
// {
//     // checking last bit
//     if(n&1)
//     {
//         count++;
//     }
//     n = n>>1;
// }
// return count;
