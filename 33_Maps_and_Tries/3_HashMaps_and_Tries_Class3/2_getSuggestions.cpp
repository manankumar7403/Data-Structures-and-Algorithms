#include<iostream>
#include<vector>
using namespace std;

class TrieNode
{
    public:
        char data;
        TrieNode * children[26];  // pointer to children, children array ki tarah store kr sakte hai
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
        root->children[index] = child;
    }

    // recursion will take care of the rest of the characters
    insertWord(child, word.substr(1)); // leaving the 1 char just inserted and giving the remaining str to recursion
}

void storeSuggestions(TrieNode* curr, vector<string>& temp, string& prefix)
{
    if(curr->isTerminal)
    {
        temp.push_back(prefix);
    }

    // a to z tak choices dedo
    for(char ch = 'a'; ch <= 'z'; ch++)
    {
        int index = ch - 'a';

        TrieNode* next = curr->children[index];

        if(next != NULL)
        {
            // if child exists
            prefix.push_back(ch);
            storeSuggestions(next, temp, prefix);
            prefix.pop_back(); // backtracking to ensure that word is removed to look for the next string 
        }
    }
}

vector<vector<string>>getSuggestions(TrieNode* root, string input)
{
    TrieNode* prev = root;
    vector<vector<string>>output;
    string prefix = "";

    for(int i=0; i<input.length(); i++)
    {
        char lastch = input[i];
        int index = lastch - 'a';
        TrieNode* curr = prev->children[index];  // first it points to l, then lo, lov, lovi

        if(curr == NULL)
        {
            break;
        }
        else
        {
            // iske andar mein saare suggestions dhund ke launga
            vector<string>temp;
            prefix.push_back(lastch);   // it stores l first, then lo, lov, lovi
            storeSuggestions(curr, temp, prefix); // in 1st call returns all strings starting from l, then 2nd call lo, 3rd call lov, 4th col lovi
            output.push_back(temp);
            prev = curr;
        }
    }
    return output;
}

int main()
{
    vector<string> v;
    v.push_back("love");
    v.push_back("lover");
    v.push_back("loving");
    v.push_back("last");
    v.push_back("lost");
    v.push_back("lane");
    v.push_back("lord");

    string input = "lovi"; // answer should be loving

    TrieNode* root = new TrieNode('-');
    for(int i=0; i<v.size(); i++)
    {
        insertWord(root, v[i]);   // all input strings inserted into the string
    }

    vector<vector<string>> ans = getSuggestions(root, input);
    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
        {
            cout << ans[i][j] << ", ";
        }
        cout << endl;
    }

    return 0;
}

// TC -> O(n*m^2) where n is the number of strings and m is the average length of the strings
// SC -> O(n*m)