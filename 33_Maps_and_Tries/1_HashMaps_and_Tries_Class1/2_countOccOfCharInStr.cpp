/*
#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
    string str = "thiruvananthapuram";
    unordered_map<char, int> freq;
    for(int i=0; i<str.length(); i++)
    {
        char ch = str[i];
        freq[ch]++;
    }
    for(auto i: freq)
    {
        cout << i.first << " -> " << i.second << endl;  // gives random order
    }
    return 0;
}
*/
// __________________________________________________________________________________________________________

#include<iostream>
#include<map>
using namespace std;

int main()
{
    string str = "thiruvananthapuram";
    map<char, int> freq;
    for(int i=0; i<str.length(); i++)
    {
        char ch = str[i];
        freq[ch]++;
    }
    for(auto i: freq)
    {
        cout << i.first << " -> " << i.second << endl;  // gives in alphabetical sorted order
    }
    return 0;
}