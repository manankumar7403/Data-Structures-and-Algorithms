// VIT-absolute grading system
#include <iostream>
using namespace std;
int main()
{
    cout << "Enter the marks obtained: " <<endl;
    int marks;
    cin >> marks;
    if (marks>=90)
    {
        cout << "S grade!";
    }
    else if (marks>=80)
    {
        cout << "A grade!";
    }
    else if (marks>=70)
    {
        cout << "B grade!";
    }
    else if (marks>=60)
    {
        cout << "C grade!";
    }
    else if (marks>=55)
    {
        cout << "D grade!";
    }
    else if (marks>=50)
    {
        cout << "E grade!";
    }
    else
    {
        cout << "F grade!";
    }
    return 0;
}