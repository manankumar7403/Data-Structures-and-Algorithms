/*
#include <iostream>
using namespace std;

int factorial(int n)
{
    // Base condition
    if(n == 1)
    {
        return 1;
    }

    // Recursive relation
    return n * factorial(n-1);
}

int main()
{
    int n;
    cout << "Enter the value of n: " << endl;
    cin >> n;
    cout << "Factorial of " << n << " is " << factorial(n);
    cout << endl;
    return 0;
}
*/
// _______________________________________________________________________________________________

// TAIL RECURSION
/*
#include <iostream>
using namespace std;

void printCounting(int n)
{
    // Base case
    if(n == 0)
    {
        return;
    }

    // Processing
    cout << n << " ";              // Prints reverse counting

    // Recursive relation
    printCounting(n-1);
}

int main()
{
    int n;
    cout << "Enter the value of n: " << endl;
    cin >> n;
    printCounting(n);
    cout << endl;
    return 0;
}
*/
// ____________________________________________________________________________________________

// HEAD RECURSION
#include <iostream>
using namespace std;

void printCounting(int n)
{
    // Base case
    if(n == 0)
    {
        return;
    }

    // Recursive relation
    printCounting(n-1);
    
    // Processing
    cout << n << " ";              // Prints sequential counting
}

int main()
{
    int n;
    cout << "Enter the value of n: " << endl;
    cin >> n;
    printCounting(n);
    cout << endl;
    return 0;
}

// CHECK SLIDES 24-26 to understand head(specifically) and tail recursion.