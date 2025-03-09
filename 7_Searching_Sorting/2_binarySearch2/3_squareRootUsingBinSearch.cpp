#include <iostream>
#include <vector>
using namespace std;

int findSqrt(int num)
{
    int target = num;
    int start = 0;
    int end = num;
    int mid = start + (end-start)/2;
    int ans = -1;

    while(start <= end)
    {
        if(mid*mid == target)
        {
            return mid;
        }
        else if(mid*mid > target)
        {
            // left search
            end = mid - 1;
        }
        else
        {
            // ans store
            ans = mid;
            // right search
            start = mid + 1; 
        }
        mid = start + (end - start)/2;
    }
    return ans;
}

int main()
{
    int num;
    cout << "Enter the number: " << endl;
    cin >> num;

    int ans = findSqrt(num);

    int precision;
    cout << "Enter the number of floating digits in precision: " << endl;
    cin >> precision;

    double step=0.1;
    double finalAns = ans;
    for(int i=0; i<precision; i++)
    {
        for(double j = finalAns; j*j<=num; j=j+step)
        {
            finalAns = j;
        }
        step = step/10;
    }
    cout << "Square root of "<< num << " is: " << finalAns << endl;
    return 0;
}