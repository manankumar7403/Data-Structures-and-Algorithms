// ⭐⭐ TRIE VERY IMPORTANT QUESTION ⭐⭐

// 🔴🔴LEETCODE 648 -> Replace Words🔴🔴
/*
In English, we have a concept called root, which can be followed by some other word to form another longer word -
let's call this word derivative. For example, when the root "help" is followed by the word "ful", we can form a
derivative "helpful".
Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the
derivatives in the sentence with the root forming it. If a derivative can be replaced by more than one root, replace
it with the root that has the shortest length.
Return the sentence after the replacement.

Example 1:
Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"

Example 2:
Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
Output: "a a b c"

Constraints:
1 <= dictionary.length <= 1000
1 <= dictionary[i].length <= 100
dictionary[i] consists of only lower-case letters.
1 <= sentence.length <= 10^6
sentence consists of only lower-case letters and spaces.
The number of words in sentence is in the range [1, 1000]
The length of each word in sentence is in the range [1, 1000]
Every two consecutive words in sentence will be separated by exactly one space.
sentence does not have leading or trailing spaces.
*/

#include<iostream>
#include<vector>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char d)
    {
        this->data = d;
        for(int i=0; i<26; i++)
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
        int index = ch - 'a';
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

    int searchWord(TrieNode* root, const string& word)
    {
        TrieNode* current = root;
        for(int i=0; i<word.size(); i++)
        {
            char ch = word[i];
            int index = ch - 'a';
            if(current->children[index] != NULL)
            {
                current = current->children[index];
                if(current->isTerminal)
                {
                    return i+1;
                }
            }
            else break;
        }
        return -1;
    }

public:
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insert(string word) {
        insertWord(root, word);
    }
    
    int search(string word) {
        return searchWord(root, word);
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ans;
        Trie trie;

        // insert dictionary into trie
        for(auto root: dictionary)
        {
            trie.insert(root);
        }

        // pick each word and find in trie whether the root is available or not
        int start = 0, end = 0;
        while(end < sentence.size())
        {
            if(sentence[end] == ' ' || end == sentence.size() - 1)
            {
                int len = end == sentence.size()-1 ? sentence.size() : end - start;
                string word = sentence.substr(start, len);
                int trieMatchIndex = trie.search(word);
                ans += trieMatchIndex != -1 ? word.substr(0, trieMatchIndex) : word;
                if(sentence[end] == ' ')
                {
                    ans += ' ';
                }
                start = end + 1;
            }
            end++;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    int n;
    cout << "Enter the length of the dictionary:" << endl;
    cin >> n;
    vector<string>dictionary(n);
    cout << "Enter the roots in the dictionary:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> dictionary[i];
    }

    // clear the input buffer before reading the sentence
    cin.ignore();
    
    string sentence;
    cout << "Enter the sentence:" << endl;
    getline(cin, sentence);

    string ans = sol.replaceWords(dictionary, sentence);

    cout << ans << endl;

    return 0;
}

// TC -> O(N*L + M*K)
// SC -> O(N*L)