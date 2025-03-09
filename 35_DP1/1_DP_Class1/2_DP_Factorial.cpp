#include <iostream>
#include <vector>
using namespace std;

int fact(int n)
{
    vector<int> result(n, 0);
    if (n >= 0)
    {
        result[0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            result[i] = i * result[i - 1];
        }
        return result[n];
    }
    return 0;
}
int main()
{
    int n;
    cout << "Enter the number: " << endl;
    cin >> n;
    cout << "The factorial of " << n << " is: " << fact(n) << endl;
    return 0;
}