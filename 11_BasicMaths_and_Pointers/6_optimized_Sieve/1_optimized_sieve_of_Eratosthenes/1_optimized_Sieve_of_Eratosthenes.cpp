#include <iostream>
#include <vector>
using namespace std;

vector<bool> soe(int n)
{
    // create an array of n size telling isPrime
    vector<bool>sieve(n+1, true);
    sieve[0] = sieve[1] = false;

    for(int i=2; i*i<=n; i++)    // Optimization 2 => i*i<=n
    {
        if(sieve[i] == true)
        {
            // int j=i*2
            int j = i*i;        // Optimisation 1: first unmarked number would be i*i, as others have been marked by i*2 to i*(i-1)

            while(j <= n)
            {
                sieve[j] = false;
                j = j+i;
            }
        }
    }
    return sieve;
}

int main()
{
    int n;
    cout << "Enter the value of n: " << endl;
    cin >> n;
    vector<bool> result = soe(n);
    for(int i=0; i<=n; i++)
    {
        if(result[i])
        {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}

// Time Complexity: O(n*log(log(n)))
// Space Complexity: O(n)

