#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void getSubsequences(string str)
{
    vector<string> ans;
    int n = str.length();
    for(int num=0; num < (1 << n); num++)       // (1 << n) is the same as 2^n
    {
        string temp = "";
        // we will create subsequence string in the temp string
        for(int i=0; i<n; i++)
        {
            char ch = str[i];
            if(num & (1 << i))
            {
                // non-zero value ke liye include curr character
                temp.push_back(ch);
            }
        }
        if(temp.length() >= 0)
        {
            // store in ans
            ans.push_back(temp);
        }
    }
    sort(ans.begin(), ans.end());
    cout << "Count of subsequences: " << ans.size() << endl; 
    cout << "Printing the subsequence:" << endl;
    for(auto i: ans)
    {
        cout << i << endl;
    }
}

int main()
{
    string str;
    cout << "Enter the string:" << endl;
    cin >> str;
    getSubsequences(str);
    return 0;
}

// TC -> O(n * 2^n)
// SC -> O(n * 2^n)