// ⭐⭐LEETCODE 72 -> Edit Distance⭐⭐
/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
You have the following three operations permitted on a word:
Insert a character
Delete a character
Replace a character

Example 1:
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

Constraints:
0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.
*/
// __________________________________________________________________________________________________________________________

/*
// 🔴🔴RECURSION🔴🔴
#include<iostream>
using namespace std;

int solveUsingRecursion(string &a, string &b, int i, int j)
{
    // Base Condition
    if (i == a.length())
        return b.length() - j;
    if (j == b.length())
        return a.length() - i;

    int ans = 0;
    // If a match
    if (a[i] == b[j])
    {
        ans = solveUsingRecursion(a, b, i + 1, j + 1);
    }
    else
    {
        // perform the operations
        int insert = 1 + solveUsingRecursion(a, b, i, j + 1);
        int deleted = 1 + solveUsingRecursion(a, b, i + 1, j);
        int replace = 1 + solveUsingRecursion(a, b, i + 1, j + 1);
        ans = min(insert, min(deleted, replace));
    }
    return ans;
}

int minDistance(string word1, string word2)
{
    if (word1.length() == 0)
        return word2.length();
    if (word2.length() == 0)
        return word1.length();
    int i = 0;
    int j = 0;
    return solveUsingRecursion(word1, word2, i, j);
}

int main()
{
    string word1, word2;
    cout << "Enter word1: " << endl;
    getline(cin, word1);
    cout << "Enter word2: " << endl;
    getline(cin, word2);
    int ans = minDistance(word1, word2);
    cout << "Minimum number of operations required are: " << ans << endl;
    return 0;
}
*/
// ___________________________________________________________________________________________________________________

/*
// 🔴🔴MEMOIZATION(Top-Down)🔴🔴
#include<iostream>
#include<vector>
using namespace std;

int solveUsingMem(string &a, string &b, int i, int j, vector<vector<int>> &dp)
{
    // Base Condition
    if (i == a.length())
        return b.length() - j;
    if (j == b.length())
        return a.length() - i;

    // Step2: Check if the answer is already present inside the dp array or not
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int ans = 0;
    // If a match
    if (a[i] == b[j])
    {
        ans = solveUsingMem(a, b, i + 1, j + 1, dp);
    }
    else
    {
        // perform the operations
        int insert = 1 + solveUsingMem(a, b, i, j + 1, dp);
        int deleted = 1 + solveUsingMem(a, b, i + 1, j, dp);
        int replace = 1 + solveUsingMem(a, b, i + 1, j + 1, dp);
        ans = min(insert, min(deleted, replace));
    }
    dp[i][j] = ans;
    return dp[i][j];
}

int minDistance(string word1, string word2)
{
    if (word1.length() == 0)
        return word2.length();
    if (word2.length() == 0)
        return word1.length();
    int i = 0;
    int j = 0;
    // Step1: Create the dp array
    vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));
    return solveUsingMem(word1, word2, i, j, dp);
}

int main()
{
    string word1, word2;
    cout << "Enter word1: " << endl;
    getline(cin, word1);
    cout << "Enter word2: " << endl;
    getline(cin, word2);
    int ans = minDistance(word1, word2);
    cout << "Minimum number of operations required are: " << ans << endl;
    return 0;
}
// TC -> O(nxm)
// SC -> O(nxm)
*/
// ___________________________________________________________________________________________________________________

/*
// 🔴🔴TABULATION(Bottom-Up)🔴🔴
#include<iostream>
#include<vector>
using namespace std;

int solveUsingTab(string &a, string &b)
{
    // Step1: Create the dp array
    vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, 0));

    // Step2: Check the Base Condition
    // if(i==a.length()) return b.length()-j;
    // if(j==b.length()) return a.length()-i;
    for (int j = 0; j <= b.length(); j++)
    {
        dp[a.length()][j] = b.length() - j;
    }
    for (int i = 0; i <= a.length(); i++)
    {
        dp[i][b.length()] = a.length() - i;
    }

    // Step3: Main iteration logic
    for (int i = a.length() - 1; i >= 0; i--)
    {
        for (int j = b.length() - 1; j >= 0; j--)
        {
            int ans = 0;
            // If a match
            if (a[i] == b[j])
            {
                ans = dp[i + 1][j + 1];
            }
            else
            {
                // perform the operations
                int insert = 1 + dp[i][j + 1];
                int deleted = 1 + dp[i + 1][j];
                int replace = 1 + dp[i + 1][j + 1];
                ans = min(insert, min(deleted, replace));
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}

int minDistance(string word1, string word2)
{
    if (word1.length() == 0)
        return word2.length();
    if (word2.length() == 0)
        return word1.length();
    return solveUsingTab(word1, word2);
}

int main()
{
    string word1, word2;
    cout << "Enter word1: " << endl;
    getline(cin, word1);
    cout << "Enter word2: " << endl;
    getline(cin, word2);
    int ans = minDistance(word1, word2);
    cout << "Minimum number of operations required are: " << ans << endl;
    return 0;
}
// TC -> O(nxm)
// SC -> O(nxm)
*/
// ______________________________________________________________________________________________________________________

// 🔴🔴Space Optimized🔴🔴

#include<iostream>
#include<vector>
using namespace std;

int solveUsingSO(string &a, string &b)
{
    vector<int> curr(b.length() + 1, 0);
    vector<int> next(b.length() + 1, 0);

    // Step2: Check the Base Condition
    // if(i==a.length()) return b.length()-j;
    // if(j==b.length()) return a.length()-i;
    for (int j = 0; j <= b.length(); j++)
    {
        next[j] = b.length() - j; // 1st base condition: total rows a.length()+1 size so a.length() would be last row so in curr, next it is next row, so we replaced a.length() with next
    }

    // Step3: Main iteration logic
    for (int i = a.length() - 1; i >= 0; i--)
    {
        // ⭐⭐ CHANCES OF MISTAKE IN THIS NEXT LINE ⭐⭐
        // every row starts here, we didn't write this above with 1st base condition as then we would only have 2 rows but we need to do it for every row (dp[i])
        curr[b.length()] = a.length() - i; // 2nd base condition: dp[i] means every row which is the curr row in the curr, next concept so we replaced dp[i] with curr
        for (int j = b.length() - 1; j >= 0; j--)
        {
            int ans = 0;
            // If a match
            if (a[i] == b[j])
            {
                ans = next[j + 1];
            }
            else
            {
                // perform the operations
                int insert = 1 + curr[j + 1];
                int deleted = 1 + next[j];
                int replace = 1 + next[j + 1];
                ans = min(insert, min(deleted, replace));
            }
            curr[j] = ans;
        }
        // Shifting
        next = curr;
    }
    return curr[0];
}

int minDistance(string word1, string word2)
{
    if (word1.length() == 0)
        return word2.length();
    if (word2.length() == 0)
        return word1.length();
    return solveUsingSO(word1, word2);
}

int main()
{
    string word1, word2;
    cout << "Enter word1: " << endl;
    getline(cin, word1);
    cout << "Enter word2: " << endl;
    getline(cin, word2);
    int ans = minDistance(word1, word2);
    cout << "Minimum number of operations required are: " << ans << endl;
    return 0;
}

// TC -> O(nxm)
// SC -> O(2m)