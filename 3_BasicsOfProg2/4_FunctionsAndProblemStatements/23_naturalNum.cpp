// Write a program to check if the entered number is a natural number or not.
// Natural numbers start with 1, till infinity.

#include <iostream>
using namespace std;
int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    if(num>1)
    {
        cout << num << " is a natural number." << endl;
    }
    else
    {
        cout << num << " is not a natural number." << endl;
    }
    return 0;
}