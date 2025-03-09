// Given A.P. is 3*n+7;
#include <iostream>
using namespace std;

int APterm(int n)
{
    int ans = 3*n+7;
    return ans;
}

int main()
{
    int n;
    cout << "Enter a number to find A.P.: ";
    cin >> n;
    
    int answer = APterm(n);
    cout << "The Nth term is: " << answer << endl;
}