// 🔴🔴🔴🔴 LEETCODE 953 -> Verifying An Alien Dictionary 🔴🔴🔴🔴

// In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different
// order. The order of the alphabet is some permutation of lowercase letters.
// Given a sequence of words written in the alien language, and the order of the alphabet, return true if
// and only if the given words are sorted lexicographically in this alien language.

// Example 1:
// Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
// Output: true
// Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.

// Example 2:
// Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
// Output: false
// Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence
// is unsorted.

// Example 3:
// Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
// Output: false
// Explanation: The first three characters "app" match, and the second string is shorter (in size.)
// According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank
// character which is less than any other character.

// Constraints:
// 1 <= words.length <= 100
// 1 <= words[i].length <= 20
// order.length == 26
// All characters in words[i] and order are English lowercase letters.

// ___________________________________________________________________________________________

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to compare two words based on the alien order
bool compareWords(string &word1, string &word2, unordered_map<char, int> &alienOrder)
{
    int len1 = word1.size();
    int len2 = word2.size();

    // Step 5: Compare each character in the words
    for (int i = 0; i < min(len1, len2); i++)
    {
        if (alienOrder[word1[i]] < alienOrder[word2[i]])
        {
            // If the curr char in word1 comes before the corresponding char in word2, return true
            return true;
        }
        else if (alienOrder[word1[i]] > alienOrder[word2[i]])
        {
            // If the curr char in word1 comes after the corresponding char in word2, return false
            return false;
        }
    }

    // Step 6: Check if one word is a prefix of the other
    return len1 <= len2;
}

bool isAlienSorted(vector<string> &words, string order)
{
    // Step 1: Create a mapping of each character in the alien language to its order in the alphabet
    unordered_map<char, int> alienOrder;
    for (int i = 0; i < order.size(); i++)
    {
        alienOrder[order[i]] = i;
    }

    // Step 2: Check if each pair of adjacent words is sorted
    for (int i = 0; i < words.size() - 1; i++)
    {
        // Step 3: Call the compareWords function to compare two adjacent words
        if (!compareWords(words[i], words[i + 1], alienOrder))
        {
            return false;
        }
    }
    // Step 4: If all pairs of adjacent words are sorted, return true
    return true;
}

int main()
{
    vector<string> words;
    string input;
    int n;
    cout << "Enter the number of words: " << endl;
    cin >> n;

    cin.ignore();         // Ignores the newline character
    
    cout << "Enter the words: " << endl;
    for(int i=0; i<n; i++)
    {
        getline(cin, input);
        words.push_back(input);
    }

    cout << "Enter the order: " << endl;
    string order;
    cin >> order;
    cout << isAlienSorted(words, order) << endl;
    return 0;
}

// T.C. -> O(C)
// S.C. -> O(1)
