// #include <iostream>
// #include <cmath>
// using namespace std;

// int decimalToBinaryMethod2(int n)
// {
//     int binaryno = 0;
//     int i = 0;
//     while(n>0)
//     {
//         int bit = (n & 1);
//         binaryno = binaryno + bit * pow(10, i++);
//         n = n >> 1;
//     }
//     return binaryno;
// }

// int main()
// {
//     int n;
//     cout<<"Enter a number: ";
//     cin>>n;
//     int binary = decimalToBinaryMethod2(n);
//     cout<<binary<<endl;
// }

// THIS IS NOT WORKING BECAUSE OF FLOATING POINT COMPILER PROGRAM BUT WORKS IN ANY ONLINE COMPILER.
// USING STRING HERE
// ___________________________________________________________________________________________________

#include <iostream>
#include <string>
using namespace std;

string decimalToBinaryMethod(int n)
{
    if (n == 0)
        return "0";

    string binaryno = "";
    while (n > 0)
    {
        int bit = n % 2;
        binaryno = to_string(bit) + binaryno;
        n = n / 2;
    }
    return binaryno;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    string binary = decimalToBinaryMethod(n);
    cout << binary << endl;
}
