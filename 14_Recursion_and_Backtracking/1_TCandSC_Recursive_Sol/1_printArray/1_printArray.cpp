#include <iostream>
using namespace std;

void printArray(int a[], int n)
{
    if(n==0) return;
    cout << *a << " ";
    printArray(a+1, n-1);
}

int main() {
    int a[5] = {1,2,3,4,5};
    int n=5;
    printArray(a, n);
    return 0;
}

// TC -> O(n)
// SC -> O(n)
