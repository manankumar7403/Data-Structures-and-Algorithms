#include <iostream>
#include <string>
using namespace std;

void reverse(string&s, int start, int end)
{
    // Base case
    if(start >= end)
    {
        return;
    }

    // ek case solve kardo
    swap(s[start], s[end]);

    // Baaki recursion sambhal lega
    reverse(s, start+1, end-1);
}

int main()
{
    string s;
    cin >> s;
    reverse(s, 0, s.size()-1);
    cout << s << endl;
    return 0;
}

