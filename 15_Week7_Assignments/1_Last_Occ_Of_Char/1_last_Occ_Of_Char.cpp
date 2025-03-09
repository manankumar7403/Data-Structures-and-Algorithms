// // Implementing left to right
// #include <iostream>
// using namespace std;

// void lastOccLTR(string& s, char x, int i, int& ans)
// {
//     // Base case
//     if(i >= s.size())
//     {
//         return;
//     }

//     // 1 case solve kardo
//     if(s[i] == x)
//     {
//         ans = i;
//     }
//     lastOccLTR(s, x, i+1, ans);
// }

// int main()
// {
//     string s;
//     cin >> s;

//     char x;
//     cin >> x;

//     int ans = -1;
//     int i = 0;

//     lastOccLTR(s, x, i, ans);
//     cout << ans << endl;
//     return 0;
// }
// _________________________________________________________________________

// Implementing right to left
#include <iostream>
using namespace std;

void lastOccRTL(string& s, char x, int i, int& ans)
{
    // Base case
    if(i < 0)
    {
        return;
    }

    // 1 case solve kardo
    if(s[i] == x)
    {
        ans = i;
        return;
    }
    lastOccRTL(s, x, i-1, ans);
}

int main()
{
    string s;
    cin >> s;

    char x;
    cin >> x;

    int ans = -1;
    int i = s.size()-1;

    lastOccRTL(s, x, i, ans);
    cout << ans << endl;
    return 0;
}


// FUNCTION strchr() works for the same functionality
// https://cplusplus.com/reference/cstring/strchr/