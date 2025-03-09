// 🔴🔴LEETCODE 208 -> Implement Trie (Prefix Tree)🔴🔴
/*
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a
dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:
- Trie() Initializes the trie object.
- void insert(String word) Inserts the string word into the trie.
- boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false
    otherwise.
- boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix
    'prefix', and false otherwise.
 

Example 1:
Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]
Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
 
Constraints:
1 <= word.length, prefix.length <= 2000
word and prefix consist only of lowercase English letters.
At most 3 * 10^4 calls in total will be made to insert, search, and startsWith.
*/

#include<iostream>
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

    bool searchWord(TrieNode* root, const string& word)
    {
        // Base case
        if(word.length() == 0)
        {
            return root->isTerminal;
        }

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
            return false;
        }

        // recursive call
        return searchWord(child, word.substr(1));
    }

    bool startsWithUtil(TrieNode* root, const string& prefix)
    {
        if (prefix.length() == 0) {
            return true;
        }

        char ch = prefix[0];
        int index = ch - 'a';
        TrieNode* child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }
        return startsWithUtil(child, prefix.substr(1));
    }

public:
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insert(string word) {
        insertWord(root, word);
    }
    
    bool search(string word) {
        return searchWord(root, word);
    }
    
    bool startsWith(string prefix) {
        return startsWithUtil(root, prefix);
    }
};

int main()
{
    Trie trie;
    
    trie.insert("apple");
    cout << trie.search("apple") << endl;   // return True
    cout << trie.search("app") << endl;     // return False
    cout << trie.startsWith("app") << endl; // return True
    trie.insert("app");
    cout << trie.search("app") << endl;     // return True

    return 0;
}


// Time Complexity: O(number of words * maxLengthOfWord)
// Auxiliary Space: O(number of words * maxLengthOfWord)