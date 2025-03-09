// 🔴🔴LEETCODE 336 -> Palindrome Pairs🔴🔴
/*
You are given a 0-indexed array of unique strings words.
A palindrome pair is a pair of integers (i, j) such that:
0 <= i, j < words.length, i != j, and words[i] + words[j] (the concatenation of the two strings) is a palindrome.
Return an array of all the palindrome pairs of words.
You must write an algorithm with O(sum of words[i].length) runtime complexity.

Example 1:
Input: words = ["abcd","dcba","lls","s","sssll"]
Output: [[0,1],[1,0],[3,2],[2,4]]
Explanation: The palindromes are ["abcddcba","dcbaabcd","slls","llssssll"]

Example 2:
Input: words = ["bat","tab","cat"]
Output: [[0,1],[1,0]]
Explanation: The palindromes are ["battab","tabbat"]

Example 3:
Input: words = ["a",""]
Output: [[0,1],[1,0]]
Explanation: The palindromes are ["a","a"]

Constraints:
1 <= words.length <= 5000
0 <= words[i].length <= 300
words[i] consists of lowercase English letters.
*/
// _______________________________________________________________________________________________________________

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode* children[26];
    // original words array index of that string
    int stringNumber; //instead of bool isTerminal coz,storing the idx of word at its end, some word might help to be a palindrome

    TrieNode(char d)
    {
        this->data = d;
        for(int i=0; i<26; i++)
        {
            children[i] = NULL;
        }
        this->stringNumber = -1;  // every node except terminal will be -1 and terminal will contain the index
    }
};

class Trie {
    TrieNode* root;
    
    void insertWord(TrieNode* root, const string& word, int i, int stringNumber)
    {
        // Base case
        if(i == word.length())   // nothing left to insert, standing after terminal, so root is terminal
        {
            root->stringNumber = stringNumber;
            return;
        }

        // inserting 1 character
        char ch = word[i];
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
        insertWord(child, word, i+1, stringNumber); // leaving the 1 char just inserted and giving the remaining str to recursion
    }

    void searchCase2(TrieNode* root, vector<int>& myPalindrome, string& s)
    {
        if(root->stringNumber != -1)     // terminal node
        {
            if(isPalindrome(s, 0, s.size()-1))
            {
                myPalindrome.push_back(root->stringNumber);
            }
        }
        for(int i=0; i<26; i++)
        {
            if(root->children[i] != NULL)
            {
                s.push_back(i + 'a');
                searchCase2(root->children[i], myPalindrome, s);
                s.pop_back();  // backtracking
            }
        }
    }

public:
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insert(const string& word, int stringNumber) {
        insertWord(root, word, 0, stringNumber);
    }

    bool isPalindrome(const string& s, int low, int high)
    {
        while(low <= high)
        {
            if(s[low] != s[high]) return false;
            low++, high--;
        }
        return true;
    }
    
    void search(const string& word, vector<int>& myPalindrome) {
        TrieNode* curr = root;

        // Case1: when a prefix of string word exactly matches with a word in trie
        for(int i=0; i<word.size(); i++)
        {
            if(curr->stringNumber != -1)  // means it is a terminal node
            {
                // check rest of the search word is a palindrome or not
                if(isPalindrome(word, i, word.size() - 1))
                {
                    myPalindrome.push_back(curr->stringNumber);
                }
            }

            int index = word[i] - 'a';
            if(curr->children[index] != NULL)
            {
                curr = curr->children[index];
            }
            else return;
        }

        // Case2: Search word is a prefix of a word in the trie. check remaining sub-tries in a trie for palindrome
        string remainingStr = "";
        searchCase2(curr, myPalindrome, remainingStr);
    }
};

vector<vector<int>> palindromePairs(vector<string> &words)
{
    vector<vector<int>> ans;
    Trie trie;

    // insert all words in reverse order and mark its stringNumber as index of words array
    for (int i = 0; i < words.size(); i++)
    {
        auto reverseWord = words[i];
        reverse(reverseWord.begin(), reverseWord.end());
        trie.insert(reverseWord, i);
    }

    // find palindromic pairs of each word
    for (int i = 0; i < words.size(); i++)
    {
        vector<int> myPalindrome; // array that stores palindromic pairs of ith word
        trie.search(words[i], myPalindrome);

        for (auto it : myPalindrome)
        {
            if (it != i)
            {
                ans.push_back({i, it});
            }
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of the words array:" << endl;
    cin >> n;
    vector<string> words(n);
    cout << "Enter the words in the array:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> words[i];
    }
    vector<vector<int>> result = palindromePairs(words);
    for(vector<int> i: result)
    {
        for(int j: i)
        {
            cout << j << ", ";
        }
        cout << endl;
    }
    return 0;
}

// TC -> O(n*l) for insertion + O(n*l^2) for search operation(n words, l prefixes, l palindromes) = O(n*l^2)
// SC -> O(n*l) n words of l length + O(n) for index insertion + O(l) for recursive stack space = O(n*l)