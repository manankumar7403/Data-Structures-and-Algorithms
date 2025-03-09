#include <iostream>
#include <cctype>    // for isalnum
using namespace std;

bool isPalindrome(string s)
{
    string cleanedString = "";
    for(char c: s)
    {
        if(isalnum(c))
        {
            cleanedString += tolower(c);
        }
    }
    return cleanedString == string(cleanedString.rbegin(), cleanedString.rend());
}

int main()
{
    string s;
    cout << "Enter a string: " << endl;
    getline(cin, s);                           // for a line of text(string)
    bool result = isPalindrome(s);
    if(result)
    {
        cout << s << " is a palindrome." << endl;
    }
    else
    {
        cout << s << " is not a palindrome." << endl;
    }
    return 0;
}
