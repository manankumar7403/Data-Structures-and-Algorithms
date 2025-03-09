#include <iostream>
#include <queue>
using namespace std;

int main()
{
    string str;
    cout << "Enter a string:" << endl;
    cin >> str;
    int freq[26] = {0};
    queue<char> q;
    
    string ans = "";

    for(int i=0; i<str.length(); i++)
    {
        char ch = str[i];

        // increment frequency
        freq[ch - 'a']++;

        // q.push
        q.push(ch);

        while(!q.empty())
        {
            if(freq[q.front() - 'a'] > 1)   // checks for repeating character and pops the rep char
            {
                q.pop();
            }
            else     // only occurring once -> freq = 1
            {
                ans.push_back(q.front());
                break;
            }
        }

        if(q.empty())              // no non-repeating character found
        {
            ans.push_back('#');
        }
    }

    cout << "Final answer is: " << ans << endl;

    return 0;
}

// TC -> O(n)
// SC -> O(n)