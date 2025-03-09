/*
2. Debug the code. Return index of first non-repeating character.

int firstUniqChar(string s) {
        vector<int> c(26,0);
        queue<char> q;
       
        for(auto i:s){
            c[i]++;
            q.push(i);
        }
        
        int idx=0;
      
        while(q.empty()){
            auto elem = q.front();
            q.pop();
            
            if(c[elem] != 1){
               idx++;
            }
        }
        return idx;
    }
*/

// ___________________________________________________________________________________________________________________
// 🔴🔴SOLUTION🔴🔴

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int firstUniqChar(string s)
{
    vector<int> c(26, 0);
    queue<char> q;

    for (auto i: s)
    {
        c[i-'a']++;
        q.push(i);
    }

    int idx = 0;

    while(!q.empty())
    {
        auto elem = q.front();
        q.pop();

        if (c[elem-'a'] == 1)
        {
            return idx;
        }
        else
        {
            idx++;
        }
    }
    return -1;
}

int main()
{
    string s;
    cout << "Enter the string:" << endl;
    cin >> s;
    int index = firstUniqChar(s);
    cout << "Index of First Non-Rep Char is " << index << endl;
    return 0;
}