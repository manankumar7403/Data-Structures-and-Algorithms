// Write a program to check if the entered number by the user is a palindrome or not.
// palindrome is the number or string which is the same from the beginning and end, For eg: 121, nitin

#include <iostream>
using namespace std;
int main()
{
    int num, rem, reversed = 0, temp;
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