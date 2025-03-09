// 🔴🔴LEETCODE 3227 -> Vowels Game In A String (Contest 407)🔴🔴
/*
Alice and Bob are playing a game on a string.
You are given a string s, Alice and Bob will take turns playing the following game where Alice starts first:
On Alice's turn, she has to remove any non-empty substring from s that contains an odd number of vowels.
On Bob's turn, he has to remove any non-empty substring from s that contains an even number of vowels.
The first player who cannot make a move on their turn loses the game. We assume that both Alice and Bob play optimally.
Return true if Alice wins the game, and false otherwise.
The English vowels are: a, e, i, o, and u.

Example 1:
Input: s = "leetcoder"
Output: true
Explanation:
Alice can win the game as follows:
Alice plays first, she can delete the underlined substring in s = "leetcoder" which contains 3 vowels. The resulting string is
s = "der". Bob plays second, he can delete the underlined substring in s = "der" which contains 0 vowels. The resulting string
is s = "er". Alice plays third, she can delete the whole string s = "er" which contains 1 vowel.
Bob plays fourth, since the string is empty, there is no valid play for Bob. So Alice wins the game.

Example 2:
Input: s = "bbcd"
Output: false
Explanation:
There is no valid play for Alice in her first turn, so Alice loses the game.

Constraints:

1 <= s.length <= 10^5
s consists only of lowercase English letters.
*/

#include<iostream>
using namespace std;

// Alice goes first, if there are odd number of vowels say 5, Alice takes them all, so Bob loses
// If there are even number of vowels, say 6, Alice take 5 and leave 1 (always odd), so Bob can't choose and Bob loses
// So Alice wins if vowel count > 0 and Bob wins if vowel count = 0

bool isVowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool doesAliceWin(string s)
{
    int countVowels = 0;
    for (auto c : s)
    {
        if (isVowel(c))
        {
            countVowels++;
        }
    }
    if (countVowels > 0)
        return true;
    return false;
}

int main()
{
    string s;
    cout << "Enter the string:" << endl;
    cin >> s;
    if(doesAliceWin(s))
    {
        cout << "Alice won the game!" << endl;
    }
    else
    {
        cout << "Alice lost the game!" << endl;
    }
    return 0;
}

// TC -> O(n)
// SC -> O(1)