// GFG question
/*
A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people,
find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is
set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
Return the index of the celebrity, if there is no celebrity return -1.
Note: Follow 0 based indexing.
Follow Up: Can you optimize it to O(N)

Example 1:
Input:
N = 3
M[][] = {{0 1 0},
         {0 0 0}, 
         {0 1 0}}
Output: 1
Explanation: 0th and 2nd person both
know 1. Therefore, 1 is the celebrity. 

Example 2:
Input:
N = 2
M[][] = {{0 1},
         {1 0}}
Output: -1
Explanation: The two people at the party both
know each other. None of them is a celebrity.

Your Task:
You don't need to read input or print anything. Complete the function celebrity() which takes the matrix M and its
size N as input parameters and returns the index of the celebrity. If no such celebrity is present, return -1.
Expected Time Complexity: O(N^2)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 3000
0 <= M[][] <= 1
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> st;

    // Step1: push all people in the stack
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }

    // Step2: Run discard method, to get a mightBeCelebrity
    while (st.size() != 1)
    {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        // if a knows b?
        if (M[a][b] == 1)
        {
            // a is not celeb, b might be
            st.push(b);
        }
        else
        {
            // b is not celeb, a might be
            st.push(a);
        }
    }

    // Step3: Check of that single person is actually a celeb
    int mightBeCelebrity = st.top();
    st.pop();

    // Celebrity should not know anyone
    for (int i = 0; i < n; i++)
    {
        if (M[mightBeCelebrity][i] != 0)
        {
            return -1;
        }
    }

    // everyone should know the celebrity
    for (int i = 0; i < n; i++)
    {
        if (M[i][mightBeCelebrity] == 0 && i != mightBeCelebrity)
        {
            // i!=mightBeCelebrity is used to ensure that a celebirty can't even know themself. All rows of celeb index should be 0 and all cols of celeb index except for ith celeb M[i][i] col should be 1
            return -1;
        }
    }

    // mightBeCelebrity is the celebrity
    return mightBeCelebrity;
}

int main()
{
    int n;
    cout << "Enter the size of the matrix nxn:" << endl;
    cin >> n;
    vector<vector<int>>M(n, vector<int>(n));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> M[i][j];
        }
    }

    cout << "The celebrity is at index: " << celebrity(M, n);
    return 0;
}