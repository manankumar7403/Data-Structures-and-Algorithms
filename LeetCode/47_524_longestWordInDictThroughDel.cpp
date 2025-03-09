// 🔴🔴🔴🔴 LEETCODE 524 -> Longest Word In Dictionary Through Deleting 🔴🔴🔴🔴

// Given a string s and a string array dictionary, return the longest string in the dictionary that can be
// formed by deleting some of the given string characters. If there is more than one possible result,
// return the longest word with the smallest lexicographical order. If there is no possible result,
// return the empty string.

// Example 1:
// Input: s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
// Output: "apple"

// Example 2:
// Input: s = "abpcplea", dictionary = ["a","b","c"]
// Output: "a"

// Constraints:
// 1 <= s.length <= 1000
// 1 <= dictionary.length <= 1000
// 1 <= dictionary[i].length <= 1000
// s and dictionary[i] consist of lowercase English letters.

// ___________________________________________________________________________________

#include <iostream>
#include <vector>
using namespace std;

// Function to check if one string is a subsequence of another
bool isSubsequence(string &s, string &target)
{
    int m = s.size(), n = target.size();
    int i = 0, j = 0;

    // Iterate through both strings
    while (i < m && j < n)
    {
        // If characters match, move to the next character in the target string
        if (s[i] == target[j])
        {
            j++;
        }
        // Move to the next character in the source string
        i++;
    }

    // If j reached the end of the target string, it means the target is a subsequence
    return j == n;
}

string findLongestWord(string s, vector<string> &dictionary)
{
    // Initialize the answer string
    string ans = "";

    // Iterate through each word in the dictionary
    for (string &currentWord : dictionary)
    {
        // Check if the currentWord can be formed by deleting characters from s
        if (isSubsequence(s, currentWord) &&
            (ans.size() < currentWord.size() || (ans.size() == currentWord.size() && currentWord < ans)))
        {
            // Update the answer based on length and lexicographical order
            ans = currentWord;
        }
    }

    // Return the final result
    return ans;
}

int main()
{
    cout << "Enter a string: ";
    string s;
    getline(cin, s);

    cout << "Enter the number of words in the dictionary: ";
    int numWords;
    cin >> numWords;

    vector<string> dictionary;
    cout << "Enter the words in the dictionary, one per line:" << endl;
    for (int i = 0; i < numWords; i++)
    {
        string word;
        cin >> word;
        dictionary.push_back(word);
    }

    cout << findLongestWord(s, dictionary);
    cout << endl;
    return 0;
}

// Time Complexity: O(N * (M + K))
// The overall time complexity is O(N * (M + K)), where N is the number of words in the dictionary,
// M is the length of the given string s, and K is the maximum length of words in the dictionary.

// Space Complexity: O(1)