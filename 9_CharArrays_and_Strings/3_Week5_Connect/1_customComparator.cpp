#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(char first, char second)
{
    return first > second;             // puts in descending order
}

bool compare(int a, int b)
{
    return a > b;                    // sorts in descending order
}

int main()
{
    string s = "babbar";
    sort(s.begin(), s.end(), cmp);
    cout << s << endl;

    vector<int> v{5,3,1,2,4};
    sort(v.begin(), v.end(), compare);
    for(auto i: v)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}