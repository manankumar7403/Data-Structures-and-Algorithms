#include <iostream>
using namespace std;
int main()
{
    long long num, rem, reversed = 0, temp;
    cout << "Enter a number: ";
    cin >> num;
    temp = num;
    while(num > 0)
    {
        rem = num%10;
        reversed = reversed * 10 + rem;
        num = num / 10;
    }
    if(temp==reversed)
    {
        cout << temp << " is a palindrome." << endl;
    }
    else
    {
        cout << temp << " is not a palindrome." << endl;
    }
    return 0;
}