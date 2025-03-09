// 🔴🔴LEETCODE 1023 -> Camelcase Matching🔴🔴
/*
Given an array of strings queries and a string pattern, return a boolean array answer where answer[i] is true if
queries[i] matches pattern, and false otherwise.
A query word queries[i] matches pattern if you can insert lowercase English letters pattern so that it equals the query.
You may insert each character at any position and you may not insert any characters.

Example 1:
Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FB"
Output: [true,false,true,true,false]
Explanation: "FooBar" can be generated like this "F" + "oo" + "B" + "ar".
"FootBall" can be generated like this "F" + "oot" + "B" + "all".
"FrameBuffer" can be generated like this "F" + "rame" + "B" + "uffer".

Example 2:
Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBa"
Output: [true,false,true,false,false]
Explanation: "FooBar" can be generated like this "Fo" + "o" + "Ba" + "r".
"FootBall" can be generated like this "Fo" + "ot" + "Ba" + "ll".

Example 3:
Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBaT"
Output: [false,true,false,false,false]
Explanation: "FooBarTest" can be generated like this "Fo" + "o" + "Ba" + "r" + "T" + "est".

Constraints:
1 <= pattern.length, queries.length <= 100
1 <= queries[i].length <= 100
queries[i] and pattern consist of English letters.
*/
// ________________________________________________________________________________________________________________
// 🔴🔴Method1: Brute Force🔴🔴
/*
#include<iostream>
#include<vector>
using namespace std;

bool check(string &str, string &pattern)
{
    int i = 0, cap = 0;
    for (int j = 0; j < str.size(); j++)
    {
        if (i < pattern.size() && str[j] == pattern[i])
        {
            i++;
        }
        else if (str[j] >= 'A' && str[j] <= 'Z')
        {
            cap++;
        }
    }
    return (i == pattern.size() && cap == 0);
}

vector<bool> camelMatch(vector<string> &queries, string pattern)
{
    int n = queries.size();
    vector<bool> ans(n);
    for (int i = 0; i < queries.size(); i++)
    {
        ans[i] = check(queries[i], pattern);
    }
    return ans;
}

int main()
{
    int n;
    string pattern;
    cout << "Enter the size of the array:" << endl;
    cin >> n;
    vector<string>queries(n);
    cout << "Enter the elements in the array:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> queries[i];
    }

    cout << "Enter the pattern:" << endl;
    cin >> pattern;
    vector<bool>ans = camelMatch(queries, pattern);
    for(auto i: ans)
    {
        cout << i << " ";
    }
    return 0;
}
// TC -> O(n*m)
// SC -> O(1)
*/

// ________________________________________________________________________________________________________________
// 🔴🔴Method2: Using Tries🔴🔴

#include<iostream>
#include<vector>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode* children[58];
    bool isTerminal;

    TrieNode(char d)
    {
        this->data = d;
        for(int i=0; i<58; i++)
        {
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

class Trie {
    TrieNode* root;
    
    void insertWord(TrieNode* root, const string& word)
    {
        // Base case
        if(word.length() == 0)   // nothing left to insert, standing after terminal, so root is terminal
        {
            root->isTerminal = true;
            return;
        }

        // inserting 1 character
        char ch = word[0];
        int index = getIndex(ch);
        TrieNode* child;

        // child present
        if(root->children[index] != NULL)
        {
            child = root->children[index];
        }

        // absent
        else
        {
            child = new TrieNode(ch);
            root->children[index] = child;
        }

        // recursion will take care of the rest of the characters
        insertWord(child, word.substr(1)); // leaving the 1 char just inserted and giving the remaining str to recursion
    }

    bool searchWord(TrieNode* root, const string& word)
    {
        // Base case
        if(word.length() == 0)
        {
            return root->isTerminal;
        }

        char ch = word[0];
        int index = getIndex(ch);
        TrieNode* child;

        // child present
        if(root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // Check if it's a lowercase letter
            if(islower(ch))
            {
                // Continue searching after skipping the current character
                return searchWord(root, word.substr(1));
            }
            // Not found
            return false;
        }

        // Recursive call
        return searchWord(child, word.substr(1));
    }

    int getIndex(char ch)
    {
        if(isupper(ch)) return ch - 'A';
        else if(islower(ch)) return ch - 'a' + 26;
        return -1;
    }

public:
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insert(string& word) {
        insertWord(root, word);
    }
    
    bool search(string& word) {
        return searchWord(root, word);
    }
};

vector<bool> camelMatch(vector<string> &queries, string pattern)
{
    vector<bool> ans;
    Trie trie;
    trie.insert(pattern);
    for (auto &query : queries)
    {
        ans.push_back(trie.search(query));
    }
    return ans;
}

int main()
{
    int n;
    string pattern;
    cout << "Enter the size of the array:" << endl;
    cin >> n;
    vector<string>queries(n);
    cout << "Enter the elements in the array:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> queries[i];
    }

    cout << "Enter the pattern:" << endl;
    cin >> pattern;
    vector<bool>ans = camelMatch(queries, pattern);
    for(auto i: ans)
    {
        cout << i << " ";
    }
    return 0;
}

// TC -> O((p + q*m)*L), p is len of pattern, q->num of queries, m is avg length of queries, L is the trie nodes.
// SC -> O(p + q*L)