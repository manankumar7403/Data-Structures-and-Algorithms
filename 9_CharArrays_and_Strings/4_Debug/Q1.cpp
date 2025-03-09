// Q1. Debug the code.
// REVERSE WORDS IN A GIVEN STRING
// void reverseWords(string s)
// {
//     vector<string> tmp;
//     string str = "";
//     for (int i = 0; s[i] != '\0'; i++) {
//         if (s[i] == ' ') {
//             tmp.push_back(str);
//             str = "";
//         }
//         else
//             str += s[i];
//     }
//     tmp.push_back(str);
//  return str;
// }

// _____________________________________________________________________________

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void reverseWords(string s)
{
    vector<string> tmp;
    string str = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            tmp.push_back(str);
            str = "";
        }
        else
            str = str + s[i];
    }
    tmp.push_back(str);

    int i;
    for(i = tmp.size()-1; i >= 0; i--)
    {
        cout << tmp[i] << " ";
    }
}

int main()
{
    string s;
    cout << "Enter a string: " << endl;
    getline(cin, s);
    cout << "The reversed string is: ";
    reverseWords(s);
    return 0;
}


