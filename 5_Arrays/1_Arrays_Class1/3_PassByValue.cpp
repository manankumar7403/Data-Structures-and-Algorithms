#include <iostream>
using namespace std;
void printNumber(int num)
{
    cout<<num<<endl;
    cout<<"Address of num is: "<<&num<<endl;
}

int main()
{
    // function call
    int a = 5;
    printNumber(a);
    cout<<"Address of a is: "<<&a<<endl;
    return 0;
}


// In pass by value, the variable in the function is a copy of the variable in the main function
// stored at a different memory location. So, that's why 'num' is a copy of 'a'.
// Therefore, when num is printed (copy of a) -> the value of a is printed.