#include <iostream>
using namespace std;

void printDigits(int n)
{
    // Base case
    if (n == 0)
    {
        return;
    }

    // Baaki recursion sambhal lega
    printDigits(n / 10);             // Head Recursion

    // 1 case solve kardo
    int digit = n % 10;
    cout << digit << " ";
}

int main()
{
    int n = 647;         // gives 647 only
    // int n = 0647;     // gives 423 ??? WHY CHECK THE PDF
    printDigits(n);
    return 0;
}