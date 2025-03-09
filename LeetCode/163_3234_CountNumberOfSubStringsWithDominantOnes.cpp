// 🔴🔴LEETCODE 3234 -> Count the Number of Substrings with Dominant Ones🔴🔴
/*
You are given a binary string s. Return the number of substrings with dominant ones.
A string has dominant ones if the number of ones in the string is greater than or equal to the square of the number of
zeros in the string.

Example 1:
Input: s = "00011"
Output: 5
Explanation:
The substrings with dominant ones are shown in the table below.
i	j	s[i..j]	Number of Zeros	Number of Ones
3	3	1	0	1
4	4	1	0	1
2	3	01	1	1
3	4	11	0	2
2	4	011	1	2

Example 2:
Input: s = "101101"
Output: 16
Explanation:
The substrings with non-dominant ones are shown in the table below.
Since there are 21 substrings total and 5 of them have non-dominant ones, it follows that there are 16 substrings with
dominant ones.
i	j	s[i..j]	Number of Zeros	Number of Ones
1	1	0	1	0
4	4	0	1	0
1	4	0110	2	2
0	4	10110	2	3
1	5	01101	2	3

Constraints:
1 <= s.length <= 4 * 10^4
s consists only of characters '0' and '1'.
*/
// _________________________________________________________________________________________________________

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int numberOfSubstrings(string s)
{
    int ans = 0;
    int n = s.length();
    vector<int> prefix(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            prefix[i] = 1;
        }
    }
    // Prefix sum
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i] + prefix[i - 1];
    }

    for (int i = 0; i < n; i++)
    {
        int zeros = 0, ones = 0;
        for (int j = i; j < n; j++)
        {
            // sub-array from i to j (whether it is a dominant sub-array or not)
            ones = prefix[j];
            if (i != 0)
            {
                ones = ones - prefix[i - 1];
            }
            zeros = j - i + 1 - ones;

            // if condition is false
            if (zeros * zeros > ones) // optimizing the brute force as we are jumping to make sure a substring is possible
            {
                j = j + ((zeros * zeros) - ones - 1);
            }
            // if condition is true
            if (zeros * zeros <= ones)
            {
                ans++;
                // Check for other sub-string starting from i
                if (zeros * zeros < ones)
                {
                    int diff = sqrt(ones) - zeros;
                    int nextj = j + diff;
                    if (nextj >= n)
                    {
                        ans = ans + (n - j - 1);
                    }
                    else
                    {
                        ans = ans + diff;
                    }
                    j = nextj;
                }
            }
        }
    }
    return ans;
}

int main()
{
    string s;
    cout << "Enter the string: " << endl;
    cin >> s;
    int ans = numberOfSubstrings(s);
    cout << "Number of substrings are: " << ans << endl;
    return 0;
}
// TC -> O(n^2)
// SC -> O(n)

// Need to calculate the number of substrings where square of the number of zeros is less than or equal to ones.

/*
Prefix Sum Array:
The array prefix is initialized to store cumulative counts of 1s in the string s.
prefix[i] represents the number of 1s from the start of the string up to index i.
for(int i=0; i<n; i++) {
    if(s[i] == '1') {
        prefix[i] = 1;
    }
}
for(int i=1; i<n; i++) {
    prefix[i] = prefix[i] + prefix[i-1];
}
Example: For s = "101101", prefix becomes [1, 1, 2, 3, 3, 4].
*/

/*
Iterate Over All Starting Indices:
Outer loop iterates over all starting indices (i) of potential substrings.
Inner loop (j) expands the window starting from i and computes:
    ones: The number of 1s in the substring s[i..j].
    zeros: The number of 0s in s[i..j] (calculated as length - ones).

for (int i = 0; i < n; i++)
    {
        int zeros = 0, ones = 0;
        for (int j = i; j < n; j++)
        {
            // sub-array from i to j (whether it is a dominant sub-array or not)
            ones = prefix[j];
            if (i != 0)
            {
                ones = ones - prefix[i - 1];
            }
            zeros = j - i + 1 - ones;
This part of the code is responsible for calculating the number of 1s (ones) and 0s (zeros) in the current
substring s[i..j] using the prefix sum technique. 

Step-by-Step Explanation
Outer Loop (i):
    The variable i represents the starting index of the substring. The loop iterates over all possible starting indices of
    substrings in the string s.
Inner Loop (j):
    The variable j represents the ending index of the substring. For each starting index i, this loop iterates over all
    possible ending indices j (from i to n-1).

Calculating ones:
    The prefix array is used to compute the total number of 1s in the substring s[i..j] efficiently.
    prefix[j]: This contains the cumulative count of 1s from the start of the string (s[0..j]).
    If the starting index i > 0:
        Subtract the count of 1s from s[0..(i-1)] using prefix[i-1] to get the count for s[i..j].
        Formula:
            ones = prefix[j] - prefix[i-1]
    If i == 0:
        The substring starts from the very beginning, so ones = prefix[j].

Calculating zeros:
    The number of 0s in the substring s[i..j] can be derived from the total length of the substring and the count of 1s:
    Substring length = j - i + 1
    Formula:
        zeros = (j - i + 1) - ones

EXAMPLE WALKTHROUGH:
    Let s = "101101" and prefix = [1,1,2,3,3,4]
    For i=0 and j=2, the substring is "101"
    ones = prefix[2] = 2
    zeros = (j - i + 1) - ones = (2 - 0 + 1) - 2 = 1

    For i=1 and j=4, the substring is "0110"
    ones = prefix[j] - prefix[i-1] = prefix[4] - prefix[0] = 3-1 = 2
    zeros = j - i + 1 - ones = (4 - 1 + 1) - 2 = 4 - 2 = 2
*/

/*
// if condition is false
if (zeros * zeros > ones) // optimizing the brute force as we are jumping to make sure a substring is possible
{
    j = j + ((zeros * zeros) - ones - 1);
}
EXAMPLE WALKTHROUGH:
Let s = "1001011101111"
prefix = [1,1,1,2,2,3,4,5,5]
For i=0 and j=4, then substring is "10010"
ones  = prefix[j] = 2
zeros = (j - i + 1) - ones = (4 - 0 + 1) - ones = 5 - 2 = 3
Checking dominance condition:
    zeros * zeros > ones => 3 * 3 > 2 => 9 > 2 : This means that the ones are not dominant
Skipping logic:
    j = j  + ((zeros*zeros) - ones - 1)
    j = 4 + ((9) - 2 - 1)
    j = 10 (greater than string length on this case so we will break out of the inner loop)
*/

/*
// if condition is true
if (zeros * zeros <= ones)
{
    ans++;
    // Check for other sub-string starting from i
    if (zeros * zeros < ones)
    {
        int diff = sqrt(ones) - zeros;
        int nextj = j + diff;
        if (nextj >= n)
        {
            ans = ans + (n - j - 1);
        }
        else
        {
            ans = ans + diff;
        }
        j = nextj;
    }
}

if(zeros * zeros <= ones)
It satisfies the condition, so count it as a valid substring -> ans++;

if(zeros * zeros < ones) -> the substring has extra room for dominance
Future substrings starting from j+1 upto j+diff will also satisfy the condition because the number of zeros will
grow slower compared to the square of the number of ones.

diff = sqrt(ones) - zeros tells how many characters can be added while maintaining dominance.
nextj = j + diff gives the index at which j can be skipped to

if(nextj >= n)
{
    ans = ans + (n - j - 1);
}
if nextj exceeds the length of the string, the remaining substrings starting at j+1 upto the end of the string
n will be valid. Add them directly to the end of the ans.
Let s = "101101"
Let j = 3
Suppose we want to count the number of substrings from j+1 = 4 to end of string (n-1=5)
Number of substrings = n - j - 1 = 6 - 3 - 1 = 2
Therefore, substrings are: 0 and 01

else
{
    ans = ans + diff;
}
j = nextj;

It is also executed when zeros*zeros < ones and there is room to skip the further iterations.
diff is the calculated number of steps you can skip, starting from current j
Let s = "110101"
Let i=1 and j=2
ones = 2, zeros = 1
1*1 < 2 holds true
diff = sqrt(ones) - zeros = sqrt(2) - 1 = 0
ans = ans + diff but diff is 0 so, skipping doesn't occur

Let s = "111000"
Let i=0 and j=2
ones = 3, zeros = 0
0*0 < 3 holds true
diff = sqrt(ones) - zeros = sqrt(3) - 0 = 1
ans = ans + diff and diff is 1 so, skipping occurs

Finally, j = nextj; is set to update the j for the next iteration
*/