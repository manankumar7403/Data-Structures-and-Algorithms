#include <iostream>
using namespace std;

bool isPalindrome(string& s, int start, int end)
{
    // Base Case
    if(start >= end)                  // abhi tak false nhi aaya matlab true hoga
    {
        return true;
    }

    // One case solution
    if(s[start] != s[end])
        return false;
    
    // Baaki recursion sambhal lega
    return isPalindrome(s, start+1, end-1);
}

int main()
{
    string s;
    cout << "Enter a string: " << endl;
    cin >> s;
    cout << isPalindrome(s, 0, s.size()-1) << endl;
}
