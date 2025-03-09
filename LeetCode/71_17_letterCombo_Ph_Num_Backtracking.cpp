// 🔴🔴🔴🔴 LEETCODE 17 -> Letter Combinations of a Phone Number 🔴🔴🔴🔴
// Refer 16_DnC_TC_SC -> DnC Level 5 -> 2_letterCombo_Ph_Num
/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number
could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to
any letters.

Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
Input: digits = ""
Output: []

Example 3:
Input: digits = "2"
Output: ["a","b","c"]

Constraints:
0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/
// ____________________________________________________________________________________________________

#include <iostream>
#include <vector>
using namespace std;

void solve(vector<string> &ans, int index, string output, string digits, vector<string> &mapping)
{
    // Base case -> index >= length of digits means we have found the answer, so store it
    if (index >= digits.length())
    {
        ans.push_back(output);
        return;
    }

    // 1 case solve karo baaki recursion sambhal lega
    int digit = digits[index] - '0';         // jaise number 23 hai aur hum 2 par khade hai so digit = 2 (-'0' to convert from str to int)
    string value = mapping[digit];           // value se 2 ki corresponding string nikal li 'abc'
    for (int i = 0; i < value.length(); i++) // 'abc' par traverse karo
    {
        char ch = value[i];
        // har char ko include karo
        output.push_back(ch);

        // recursive call
        solve(ans, index + 1, output, digits, mapping);
        // index+1 number par traverse ka rha toh pehle 23 pe 2 par tha, index+1 se 3 par aa jayega,
        // fir 3 ki mapping dekhega 'def' hai. So, 'a' ke saath pehle 'd','e','f',
        // then 'b' ke saath 'd','e','f', then 'c' ke saath 'd','e','f'.

        // Backtracking
        output.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    vector<string> ans;
    if (digits.length() == 0) // agar empty string hai toh empty ans return kardo
        return ans;

    int index = 0;
    string output = "";
    vector<string> mapping(10);
    mapping[2] = "abc";
    mapping[3] = "def";
    mapping[4] = "ghi";
    mapping[5] = "jkl";
    mapping[6] = "mno";
    mapping[7] = "pqrs";
    mapping[8] = "tuv";
    mapping[9] = "wxyz";

    // Alternatively
    // unordered_map<int, string> mapping;
    // mapping[2] = "abc";
    // mapping[3] = "def";
    // mapping[4] = "ghi";
    // mapping[5] = "jkl";
    // mapping[6] = "mno";
    // mapping[7] = "pqrs";
    // mapping[8] = "tuv";
    // mapping[9] = "wxyz";

    solve(ans, index, output, digits, mapping);
    return ans;
}

int main()
{
    string digits;
    cout << "Enter the digits: " << endl;
    cin >> digits;
    vector<string> result = letterCombinations(digits);
    for(auto i: result)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

// TC -> O(m^n)
// SC -> O(n + m^n)

/*
### Time Complexity:
The time complexity is determined by the number of recursive calls and the work done in each call.
In the worst case, the function explores all possible combinations of letters for each digit in the input string.

Let n be the length of the input string `digits`, and m be the average number of characters mapped to each
digit (in this case, m is constant, as each digit maps to a fixed set of characters).

The time complexity is O(m^n), where n is the length of the input string.

### Space Complexity:
The space complexity is influenced by the space required for the recursion stack and the space needed for
the output vector.

1. **Recursion Stack:**
   - The maximum depth of the recursion stack is n (the length of the input string). This is because each
     recursive call corresponds to processing one digit of the input string.
   - Therefore, the space complexity due to the recursion stack is O(n).

2. **Output Vector:**
   - The output vector `ans` stores all the combinations of letters. In the worst case, the number of
     combinations is O(m^n) (as each digit can map to m characters).
   - Therefore, the space complexity due to the output vector is also O(m^n).

Combining both, the overall space complexity is O(n + m^n).

### Summary:
- Time Complexity: O(m^n)
- Space Complexity: O(n + m^n)

It's important to note that m is constant in this case (as each digit maps to a fixed set of characters),
so the space complexity can be simplified to O(n). The time complexity is exponential due to the exploration of
all possible combinations.
*/