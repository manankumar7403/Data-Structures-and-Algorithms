// 🔴🔴🔴🔴 LEETCODE 767 -> Reorganize String 🔴🔴🔴🔴
// Refer LEETCODE 55_767 -> Same Question in O(n) TC and O(1) SC.

/*
Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
Return any possible rearrangement of s or return "" if not possible.

Example 1:
Input: s = "aab"
Output: "aba"

Example 2:
Input: s = "aaab"
Output: ""

Constraints:
1 <= s.length <= 500
s consists of lowercase English letters.
*/
// _________________________________________________________________________________________________________

// Hum bas MAX HEAP mein frequency store kar rhe hai har elements ki fir 2 top elements ko nikal ke ans mein push kar rhe
// hai and then unki frequency-- karke heapify kar de rhe hai

#include <iostream>
#include <queue>
using namespace std;

class Node
{
    public:
    char data;
    int count;

    Node(char d, int c)
    {
        this->data = d;
        this->count = c;
    }
};

class compare
{
    public:
    bool operator()(Node a, Node b)
    {
        return a.count < b.count;
    }  
};

string reorganizeString(string s)
{
    // Create mapping
    int freq[26] = {0}; // as only lowercase characters are present (given)

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        freq[ch - 'a']++; // Storing the frequency of chars, 0 index pe a aaya toh freq[0] = 1
    }

    // Creating a MAX HEAP
    priority_queue<Node, vector<Node>, compare> maxHeap;

    for (int i = 0; i < 26; i++)
    {
        if (freq[i] != 0)
        {
            Node temp(i + 'a', freq[i]); // jab tak freq not 0, tab tak maxHeap me char and uski freq store karte raho
            maxHeap.push(temp);
        }
    }

    string ans = "";

    while (maxHeap.size() > 1) // ye maxHeap.empty() nahi kiya kyuki hum hamesha 2 values nikal rahe hai, suppose 5 elements hai aur 2, then 2 nikal li aur 1 bachi hai par hum 2 nikal rahe hai toh dikkat aa jayegi
    {
        Node first = maxHeap.top();
        maxHeap.pop();
        Node second = maxHeap.top();
        maxHeap.pop();

        ans = ans + first.data;
        ans = ans + second.data;
        first.count--;
        second.count--;

        if (first.count != 0)
        {
            maxHeap.push(first);
        }

        if (second.count != 0)
        {
            maxHeap.push(second);
        }
    }

    // Ab possible hai ki ek element bacha hua ho
    if (maxHeap.size() == 1) // ek element pada hai uski kuch bhi frequency ho sakti hai
    {
        Node temp = maxHeap.top();
        maxHeap.pop();
        if (temp.count == 1) // agar frequency 1 hai toh add kardo
        {
            ans = ans + temp.data;
        }
        else
        {
            return ""; // ek bache hue element ki frequency 1 se zyada hai matlab add nhi kr sakte warna adjacent elements same ho jayenge toh return "" kar denge.
        }
    }
    return ans;
}

int main()
{
    string s;
    cout << "Enter the string:" << endl;
    cin >> s;

    string result = reorganizeString(s);
    cout << "Reorganized string is: " << result;
    cout << endl;
    return 0;
}

// TC -> O(nlogk)
// SC -> O(n)

// A little similar to 3_Longest Happy String -> Heap Logic