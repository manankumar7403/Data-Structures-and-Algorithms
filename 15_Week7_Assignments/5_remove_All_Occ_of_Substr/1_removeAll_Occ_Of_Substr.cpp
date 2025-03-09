#include <iostream>
using namespace std;

void removeOCC(string &s, string &part)
{
    int found = s.find(part);
    if(found != string::npos)
    {
        // part string has been located
        // remove it
        string left_part = s.substr(0, found); // from index 0 to the length of str where last occ is found(found)
        string right_part = s.substr(found+part.size(), s.size());
        // say found = 2, so left_part is 0, 2 -> from index 0 to length 2 (index 0 and 1) is the left_part
        // say found = 2, part length=3, so right_part is found+part.size() =2+3=5 -> from index 5 to str.size() is the right_part

        s = left_part + right_part;
        removeOCC(s, part);
    }

    else
    {
        // BASE CASE -> all the occ of the part have been remove from s.
        return;
    }
}

string removeOccurrences(string s, string part)
{
    removeOCC(s, part);
    return s;
}

int main()
{
    string s, part;
    cout << "Enter the string: " << endl;
    cin >> s;
    cout << "Enter the part: " << endl;
    cin >> part;
    cout << removeOccurrences(s, part) << endl;
    return 0;
}

