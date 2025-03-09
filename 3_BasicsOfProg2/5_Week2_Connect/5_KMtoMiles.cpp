#include <iostream>
using namespace std;
int main()
{
    float km;
    cout<<"Enter the value in km: "<<endl;
    cin >> km;
    cout<<"Value in miles is: "<<(1/1.609344)*km <<endl;
}