#include<iostream>
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

bool searchWord(TrieNode* root, string word)
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

void insertWord(TrieNode* root, string word)
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

void removeWord(TrieNode* root, string word)
{
    // simple logic: search the word, mark the last character(terminal) as false
    if(word.length() == 0)
    {
        root->isTerminal = false;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;

    //child present
    if(root->children[index] != NULL)
    {
        child = root->children[index];
    }

    // absent
    else
    {
        return;
    }

    // recursive call
    removeWord(child, word.substr(1));

    // If the child is not terminal and has no children, delete it
    bool hasChildren = false;
    for (int i = 0; i < 26; i++) {
        if (child->children[i] != NULL) {
            hasChildren = true;
            break;
        }
    }

    if (!child->isTerminal && !hasChildren) {    //!child->isTerminal checks if the current child node is not the end of another word.
        delete child;
        root->children[index] = NULL;
    }
}

int main()
{
    TrieNode* root = new TrieNode('-');
    
    insertWord(root, "coding");
    insertWord(root, "code");
    insertWord(root, "coder");
    insertWord(root, "codehelp");
    insertWord(root, "baba");
    insertWord(root, "baby");
    insertWord(root, "babbar");
    
    if (searchWord(root, "abab"))
    {
        cout << "Present" << endl;
    }
    else
    {
        cout << "Absent" << endl;
    }

    removeWord(root, "code");
    
    if (searchWord(root, "code"))
    {
        cout << "Present" << endl;
    }
    else
    {
        cout << "Absent" << endl;
    }

    if (searchWord(root, "coder"))
    {
        cout << "Present" << endl;
    }
    else
    {
        cout << "Absent" << endl;
    }

    return 0;
}

// Time Complexity: O(number of words * maxLengthOfWord)
// Auxiliary Space: O(number of words * maxLengthOfWord)