#include <iostream>
using namespace std;

int add (int a, int b)
{
    int result = a + b;
    return result;
}

int main()
{
    int a;
    cout<<"Enter the value of a: "<<endl;
    cin>>a;

    int b;
    cout<<"Enter the value of b: "<<endl;
    cin>>b;

    int sum = add(a, b);
    cout<<"The result of addition is: "<<sum<<endl;
    
    return 0;
}

// You can declare a function above the main function like
// int add (int a, int b);

// and define it below the main function like
// int add (int a, int b)
// {
//     int result = a + b;
//     return result;
// }


// but declaring and defining after the main function would lead to an error as the function
// name is not defined before.