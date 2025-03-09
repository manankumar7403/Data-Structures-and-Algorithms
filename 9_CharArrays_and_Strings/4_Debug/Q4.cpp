// Q4. Debug the code. It tries to check if given string a Palindrome or not.

// string isPalindrome(string S)
// {
//     int N = S.length();
//     for (int i = 0; i < (N / 2) - 1; i++)
//     {
//         if (S[i] != S[N - i])
//         {
//             return "No";
//         }
//     }
//     return "Yes";
// }
// _____________________________________________________________________________________

#include <iostream>
#include <string>
using namespace std;

string isPalindrome(string s)
{
    int n = s.length();
    for(int i = 0; i < (n/2); i++)
    {
        if(s[i] != s[n-i-1])
        {
            return "No";
        }
    }
    return "Yes";
}

int main()
{
    string s;
    cout << "Enter a string to check palindrome: " << endl;
    getline(cin, s);
    string result = isPalindrome(s);
    cout << result;
    cout << endl;
    return 0;
}