#include <iostream>
using namespace std;
bool checkEven(int n)
{
    if(n % 2 == 0)             // for bitwise just put if ((n&1)==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int n;
    cout<<"Enter a number to check if it's even or odd: ";
    cin>>n;
    bool isEven = checkEven(n);
    if(isEven)
    {
        cout<<n<<" is an even number."<<endl;
    }
    else
    {
        cout<<n<<" is an odd number."<<endl;
    }
}

// ALTERNATIVE
// In registers, the number are stored bitwise in registers.
// If it's an even number the LSB is 0.
// If it's an odd number the LSB is 1.
// So if we perform (n&1) and result == 0 -> its an even number
// if we perform (n&1) and result == 1 -> its an odd number