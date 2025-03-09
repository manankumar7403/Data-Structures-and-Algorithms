/*
⭐🔴
Refer: https://www.youtube.com/watch?v=S-LXeuHGF98  (Knowledge Center - Rabin Karp String Matching Algorithm)

Like the Naive Algorithm, the Rabin-Karp algorithm also check every substring. But unlike the Naive algorithm,
the Rabin Karp algorithm matches the hash value of the pattern with the hash value of the current substring of text, and
if the hash values match then only it starts matching individual characters. So Rabin Karp algorithm needs to calculate
hash values for the following strings.

1) Pattern itself
2) All the substrings of the text of length m which is the size of pattern.

⭐🔴

How is Hash Value calculated in Rabin-Karp?
Hash value is used to efficiently check for potential matches between a pattern and substrings of a larger text.
The hash value is calculated using a rolling hash function, which allows you to update the hash value for a new
substring by efficiently removing the contribution of the old character and adding the contribution of the new character.
This makes it possible to slide the pattern over the text and calculate the hash value for each substring without
recalculating the entire hash from scratch.

Here’s how the hash value is typically calculated in Rabin-Karp:

Step 1: Choose a suitable base and a modulus:
Select a prime number ‘p‘ as the modulus. This choice helps avoid overflow issues and ensures a good distribution of hash
values.
Choose a base ‘b‘ (usually a prime number as well), which is often the size of the character set (e.g., 256 for ASCII
characters).

Step 2: Initialize the hash value:
Set an initial hash value ‘hash‘ to 0.

Step 3: Calculate the initial hash value for the pattern:
Iterate over each character in the pattern from left to right.
For each char ‘c’ at position ‘i’, calculate its contribution to the hash value as ‘c * (b^(pattern_length – i – 1)) % p
and add it to ‘hash‘.
This gives you the hash value for the entire pattern.

Step 4: Slide the pattern over the text:
Start by calculating the hash value for the first substring of the text that is the same length as the pattern.

Step 5: Update the hash value for each subsequent substring:
To slide the pattern one position to the right, you remove the contribution of the leftmost character and add the
contribution of the new character on the right.

The formula for updating the hash value when moving from position ‘i’ to ‘i+1’ is:
hash = (hash - (text[i - pattern_length] * (b^(pattern_length - 1))) % p) * b + text[i]

Step 6: Compare hash values:
When the hash value of a substring in the text matches the hash value of the pattern, it’s a potential match.
If the hash values match, we should perform a character-by-character comparison to confirm the match, as hash collisions
can occur.


Limitations of Rabin-Karp Algorithm
Spurious Hit: When the hash value of the pattern matches with the hash value of a window of the text but the window is
not the actual pattern then it is called a spurious hit. Spurious hit increases the time complexity of the algorithm.
In order to minimize spurious hit, we use good hash function. It greatly reduces the spurious hit.
*/

// _______________________________________________________________________________________________________________________

#include <iostream>
using namespace std;

void rabin_karp(string& T, string& P)
{
    int n = T.length();                    // length of the text
    int m = P.length();                    // length of the pattern
    int q = INT_MAX;                       // modulo -> to avoid overflowing, big value to avoid collisions
    int x = 11;                            // multiplier -> prime number
    int x_m = 1;                           // x^(m-1) used for next hash computation
    int hash_P = 0;                        // hash value for the pattern
    int hash_T = 0;                        // hash value for the text

    for(int i = 0; i < m-1; i++)           // m-1 tak chala rhe hai kyuki x^(m-1) calculate karna hai
    {
        x_m = (x_m * x) % q;               // x_m holds the pre-computed value for (x^(m-1))%q
    }
    /*
    In the main loop of the Rabin-Karp algorithm, as the window slides over the text, the algorithm needs to efficiently update the hash value.
    The rolling hash update involves subtracting the contribution of the character leaving the window and adding the contribution of the character entering the window.
    Pre-computing (x^(m-1))%q, avoids redundant calculations in each iteration of the main loop, making the Rolling Hash update more computationally efficient.
    */

    // hash of pattern and the hash of text for the first window are calculated
    for(int i=0; i<m; i++)
    {
        hash_P = (hash_P*x + P[i]) % q;
        hash_T = (hash_T*x + T[i]) % q;
    }
    // Now hash_P and hash_T holds the hash value for the initial window of the text


    for(int i=0; i<n-m+1; i++)       // iterates throught the text, checking for the potential macthes of the pattern with each window of the text.
    {
        if(hash_P == hash_T)         // possible match(hash value of pattern and text is matched), a char by char verification is required to confirm
        {
            bool found = true;       // initially set to true, assuming it is a match.
            // char by char
            for(int j=0; j<m; j++)   // responsible for comparing each character of the pattern(P) with the corresponding char in the current window of the text(T).
            {
                if(P[j] != T[i+j])   // this condition checks if the char at index j in the pattern (P[j]) is not equal to the char at index i+j in the current window of the text(T)
                {
                    found = false;   // mismatch of char found, bool found = false, indicates that the entire pattern does not match the current window
                    break;           // loop terminated using break, as once a mismatch is found the remaining char comparisons is not required
                }
            }
            if(found) cout << "Match found at index: " << i << endl;  // If didn't break, pattern macthed, index returned.
        }

        // hash did not match, calculate the hash for the next window if this was not the last window
        if(i < n-m)                  // Text size - pattern size will check for the current window
        {
            hash_T = (x*(hash_T - T[i]*x_m) + T[i+m]) % q;   // formula to calculate the hash value for the next window using the Rabin-Karp rolling hash update.
            /*
            The current hash value (hash_T) is updated by subtracting the contribution of the character leaving the window (T[i]) and adding the contribution of the character entering the window (T[i+m]).The multiplication by (x) and modulo (q) operations are applied to avoid integer overflow and ensure the hash value remains within a specified range.
            */

            if(hash_T < 0)                 // checks if the hash value is negative
            {
                hash_T = hash_T+q;         // if it is negative, it adds q to ensure the hash value remains non-negative.
            }
        }

    }
}

int main()
{
    string T = "AABCAAABCAADAABAABCAB";
    string P = "ABCA";

    rabin_karp(T, P);
    return 0;
}

/*
Time Complexity: 
The average and best-case running time of the Rabin-Karp algorithm is O(n+m), but its worst-case time is O(nm).
The worst case of the Rabin-Karp algorithm occurs when all characters of pattern and text are the same as the hash values
of all the substrings of T[] match with the hash value of P[]. 
Eg: T = AAAAAAAAAA, P = AAA

Auxiliary Space: O(1)
*/