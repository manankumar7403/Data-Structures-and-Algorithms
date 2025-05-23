#include <iostream>
#include <cmath>
using namespace std;

int binaryToDecimal(int n)
{
    int decimal = 0;
    int i = 0;
    while(n)
    {
        int bit = n % 10;
        decimal = decimal + bit * pow(2, i++);
        n /= 10;
    }
    return decimal;
}

int main()
{
    int binaryno;
    cout<<"Enter the binary number: ";
    cin >> binaryno;
    cout<<binaryToDecimal(binaryno)<<endl;
}

// while(n) means until n becomes zero