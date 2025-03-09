// LEARNING WHILE LOOP
// Print all digits in an Integer
// #include <iostream>
// using namespace std;
// int main()
// {
//     int n;
//     cout<<"Enter an integer: ";
//     cin>>n;
//     while (n!=0)
//     {
//         int rem = n % 10;
//         cout<< rem <<" ";
//         n = n / 10;
//     }
//     cout<<endl;
// }


// for (; n !=0; n=n/10)
// {
//     int rem = n % 10;
//     cout<< rem <<" ";
// }

// both while and for are valid but they reverse the digits
// For input 123 , they print 3 2 1 instead of 1 2 3. 


// ____________________________________________________________________
// Using array

#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter a number: ";
    cin>>n;

    if (n<=0)
    {
        cout<<0<<endl;
        return 0;
    }

    int original_num = n;
    int num_digits = 0;
    while (original_num > 0)
    {
        original_num /= 10;
        num_digits++;
    }
    cout<<"Number of digits are: "<<num_digits<<endl;

    int digits[num_digits];
    int i = 0;
    while (n>0)
    {
        digits[i] = n % 10;
        n = n/10;
        i++;
    }

    for (int j=num_digits-1; j>=0; j--)
    {
        cout<<digits[j]<<" ";
    }

    return 0;
}