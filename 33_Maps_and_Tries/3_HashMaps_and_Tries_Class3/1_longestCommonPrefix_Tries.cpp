// 🔴🔴LEETCODE 14 -> Longest Common Prefix🔴🔴
//⭐⭐ Already did in Week5 - Assignments Char Arrays and Strings⭐⭐

/*
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Constraints:
1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
*/

#include<iostream>
#include<vector>
using namespace std;

// ⭐⭐Solving Using Tries⭐⭐
class TrieNode
{
    public:
        char data;
        TrieNode * children[26];  // pointer to children, children array ki tarah store kr sakte hai
        bool isTerminal;
        int childCount;

        TrieNode(char d)
        {
            this->data = d;
            for(int i=0; i<26; i++)
            {
                children[i] = NULL;
            }
            childCount = 0;
            this->isTerminal = false;
        }
};

bool searchWord(TrieNode *root, string word)
{
    // Base case
    if (word.length() == 0)
    {
        return root->isTerminal;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child;

    // child present
    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }

    // absent
    else
    {
        return false;
    }

    // recursive call
    return searchWord(child, word.substr(1));
}

void insertWord(TrieNode *root, string word)
{
    // Base case
    if (word.length() == 0) // nothing left to insert, standing after terminal, so root is terminal
    {
        root->isTerminal = true;
        return;
    }

    // inserting 1 character
    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child;

    // child present
    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }

    // absent
    else
    {
        child = new TrieNode(ch);
        root->childCount++;
        root->children[index] = child;
    }

    // recursion will take care of the rest of the characters
    insertWord(child, word.substr(1)); // leaving the 1 char just inserted and giving the remaining str to recursion
}

void findLCP(string first, string &ans, TrieNode *root)
{
    if (root->isTerminal)
        return; // chances of mistake here, this checks empty string

    for (int i = 0; i < first.length(); i++)
    {
        char ch = first[i];
        if (root->childCount == 1)
        {
            ans.push_back(ch);
            int index = ch - 'a';
            root = root->children[index];
        }
        else
            break;

        if (root->isTerminal) // after traversing when we have reached the terminal node, no more childs, so no more prefix
            break;
    }
}

string longestCommonPrefix(vector<string> &strs)
{
    TrieNode *root = new TrieNode('-');
    // insert strings
    for (int i = 0; i < strs.size(); i++)
    {
        insertWord(root, strs[i]);
    }

    string ans = "";
    string first = strs[0];
    findLCP(first, ans, root);
    return ans;
}

int main()
{
    int n;
    cout << "Enter the number of strings: " << endl;
    cin >> n;
    vector<string> strs(n);
    cout << "Enter the strings: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> strs[i];
    }
    cout << "Longest common prefix is: " << longestCommonPrefix(strs);
    cout << endl;
    return 0;
}

// TC -> O(n*m)
// SC -> O(n*m)