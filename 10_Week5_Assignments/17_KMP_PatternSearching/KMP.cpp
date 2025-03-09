// 🔴🔴🔴🔴 Stands for Knuth-Morris-Pratt 🔴🔴🔴🔴
// Refer this video: https://www.youtube.com/watch?v=qases-9gOpk

/*
Given a text txt[0 . . . N-1] and a pattern pat[0 . . . M-1], write a function search(char pat[], char txt[]) that prints
all occurrences of pat[] in txt[]. You may assume that N > M. 

Examples:

Input:  txt[] = “THIS IS A TEST TEXT”, pat[] = “TEST”
Output: Pattern found at index 10

Input:  txt[] =  “AABAACAADAABAABA”
          pat[] =  “AABA”
Output: Pattern found at index 0, Pattern found at index 9, Pattern found at index 12


Matching Overview

txt = “AAAAABAAABA” 
pat = “AAAA”
We compare first window of txt with pat

txt = “AAAAABAAABA” 
pat = “AAAA”  [Initial position]
We find a match. This is same as Naive String Matching.

In the next step, we compare next window of txt with pat.

txt = “AAAAABAAABA” 
pat =  “AAAA” [Pattern shifted one position]

This is where KMP does optimization over Naive. In this second window, we only compare fourth A of pattern
with fourth character of current window of text to decide whether current window matches or not. Since we know 
first three characters will anyway match, we skipped matching first three characters. 

Need of Preprocessing?

An important question arises from the above explanation, how to know how many characters to be skipped. To know this, 
we pre-process pattern and prepare an integer array lps[] that tells us the count of characters to be skipped.

   lps[i] = the longest proper prefix of pat[0..i] which is also a suffix of pat[0..i]. 

Note: lps[i] could also be defined as the longest prefix which is also a proper suffix. We need to use it properly in one
place to make sure that the whole substring is not considered.

*/

// _____________________________________________________________________________________________________________________


#include<iostream>
#include<vector>
using namespace std;

// LPS calculation code
void computeLPS(string &pat, vector<int>& LPS, int m)
{
    int len = 0;   // length of previous longest suffix and prefix which were equal
    LPS[0] = 0;
    int i = 1;
    while(i < m)
    {
        if(pat[i] == pat[len])
        {
            len++;
            LPS[i] = len;
            i++;
        }
        else
        {
            if(len != 0)
            {
                len = LPS[len-1];
            }
            else
            {
                LPS[i] = 0;
                i++;
            }
        }
    }
}


vector<int> search(string &txt, string &pat)
{
    int n = txt.length();
    int m = pat.length();

    vector<int> result;

    // Create an LPS array to store the length of longest proper prefix which is also a suffix.
    // lps[i] = the longest proper prefix of pat[0..i] which is also a suffix of pat[0..i]

    vector<int> LPS(m, 0);
    computeLPS(pat, LPS, m);

    // Apply KMP code
    int i=0;
    int j=0;
    while(i < n)
    {
        if(txt[i] == pat[j])
        {
            i++;
            j++;
        }
        if(j==m)          // found
        {
            result.push_back(i-m);
            j = LPS[j-1];
        }
        else if(txt[i] != pat[j])
        {
            if(j != 0)
            {
                j = LPS[j-1];
            }
            else i++;
        }
    }
    return result;
}

int main()
{
    string txt, pat;
    cout << "Enter the text string: " << endl;
    getline(cin, txt);
    cout << "Enter the pattern string: " << endl;
    getline(cin, pat);
    
    vector<int> result = search(txt, pat);
    for(auto index: result)
    {
        cout << "Pattern found at index: " << index << endl;
    }
    return 0;
}

/*
Time Complexity: O(n+m) where n is the length of the text and m is the length of the pattern to be found.
Auxiliary Space: O(m)
*/