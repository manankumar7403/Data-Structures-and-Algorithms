// 🔴🔴LEETCODE 692 -> Top K Frequent Words🔴🔴
/*
Given an array of strings words and an integer k, return the k most frequent strings.
Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their
lexicographical order.

Example 1:
Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.

Example 2:
Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
Output: ["the","is","sunny","day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being
4, 3, 2 and 1 respectively.

Constraints:
1 <= words.length <= 500
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
k is in the range [1, The number of unique words[i]]
Follow-up: Could you solve it in O(n log(k)) time and O(n) extra space?
*/
// ____________________________________________________________________________________________________________
// 🔴🔴METHOD 1: Using unordered map and priority queue🔴🔴

/*
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

// custComp is the comparator so that we can get the decreasing order for the frequency of the strings and
// increasing order in the lexiographical way. p1.first > p2.first will return true only when the frequency of
// first string is more than the second and p1.second < p2.second will return true when the 
//string in p1 is alphabetically smaller then string in p2.
struct custComp
{
    bool operator()(const pair<int, string> &p1, const pair<int, string> &p2)
    {
        if (p1.first != p2.first)
        {
            return p1.first > p2.first;
        }
        else
        {
            return p1.second < p2.second;
        }
    }
};

vector<string> topKFrequent(vector<string> &words, int k)
{
    unordered_map<string, int> mp;
    for (string &word : words)
    {
        mp[word]++; // stores the string, frequency
    }

    priority_queue<pair<int, string>, vector<pair<int, string>>, custComp> pq;

    for (auto it : mp)
    {
        pq.push({it.second, it.first}); // stores frequency, string
        if (pq.size() > k)
        {
            pq.pop();
        }
    }

    vector<string> ans;
    while (k--)
    {
        ans.insert(ans.begin(), pq.top().second); // adds answer to begin as in pq, high lex value word is at top
        pq.pop();
    }
    return ans;
}

int main()
{
    int n, k;
    cout << "Enter the size of array:" << endl;
    cin >> n;
    vector<string>words(n);
    cout << "Enter the words in the array:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> words[i];
    }
    cout << "Enter the value of k:" << endl;
    cin >> k;
    vector<string> ans = topKFrequent(words, k);
    for(string str: ans)
    {
        cout << str << " ";
    }
    return 0;
}
// TC -> O(nlogk)
// SC -> O(n)
*/

// ____________________________________________________________________________________________________________
// 🔴🔴METHOD 2: Using trie and priority queue🔴🔴
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class comp
{
    public:
    bool operator() (const pair<int, string>& p1, const pair<int, string>& p2)
    {
        if(p1.first != p2.first)
        {
            return p1.first > p2.first;
        }
        else
        {
            return p1.second < p2.second;
        }
    }
};

class TrieNode
{
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int freq;

    TrieNode(char d)
    {
        this->data = d;
        for(int i=0; i<26; i++)
        {
            children[i] = NULL;
        }
        this->isTerminal = false;
        freq = 0;
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
            ++root->freq;
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

    // void printPriorityQueue(priority_queue<pair<int, string>, vector<pair<int, string>>, comp> &pq)
    // {
    //     priority_queue<pair<int, string>, vector<pair<int, string>>, comp> temp = pq;
    //     while (!temp.empty())
    //     {
    //         auto top = temp.top();
    //         temp.pop();
    //         cout << "(" << top.first << ", " << top.second << ") ";
    //     }
    //     cout << endl;
    // }

    void traverseUtil(TrieNode* root, string& s, priority_queue<pair<int, string>, vector<pair<int, string>>, comp>&pq, int &k)
    {
        // Base case
        if(root == NULL) return;

        if(root->isTerminal)
        {
            // stores top k frequent words
            if(pq.size() < k)
            {
                pq.push({root->freq, s});
                // cout << "After push: ";
                // printPriorityQueue(pq);
            }
            else if(pq.size()==k && root->freq > pq.top().first)
            {
                pq.pop();
                pq.push({root->freq, s});
                // cout << "After push: ";
                // printPriorityQueue(pq);
            }
        }
        for(int i=0; i<26; i++)
        {
            if(root->children[i] != NULL)
            {
                s.push_back(i + 'a');
                cout << s << endl;
                traverseUtil(root->children[i], s, pq, k);
                s.pop_back(); // backtracking
            }
        }
    }

public:
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insert(string word) {
        insertWord(root, word);
    }

    void traverse(priority_queue<pair<int, string>, vector<pair<int, string>>, comp>& pq, int k)
    {
        string s; // making a string like l+o+v+e = love while traversing through the trie
        traverseUtil(root, s, pq, k);
    }
};

vector<string> topKFrequent(vector<string> &words, int k)
{
    Trie trie;
    vector<string> ans;
    for (auto word : words)
    {
        trie.insert(word);
    }

    priority_queue<pair<int, string>, vector<pair<int, string>>, comp> pq;
    trie.traverse(pq, k);

    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        ans.insert(ans.begin(), top.second);
    }
    return ans;
}

int main()
{
    int n, k;
    cout << "Enter the size of array:" << endl;
    cin >> n;
    vector<string>words(n);
    cout << "Enter the words in the array:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> words[i];
    }
    cout << "Enter the value of k:" << endl;
    cin >> k;
    vector<string> ans = topKFrequent(words, k);
    for(string str: ans)
    {
        cout << str << " ";
    }
    return 0;
}

// TC -> O(n*l + nlogk)
// SC -> O(n*l)


