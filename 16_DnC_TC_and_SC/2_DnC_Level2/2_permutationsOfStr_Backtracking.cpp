#include <iostream>
using namespace std;

void printPermutation(string& str, int i)
{
    // Base case
    if(i >= str.length())
    {
        cout << str << " ";  // printing the permutation if i out of range
        return;
    }

    // Swapping 
    for(int j=i; j<str.length(); j++)
    {
        // swap
        swap(str[i], str[j]);

        // recursive call
        printPermutation(str, i+1);

        // backtracking -> ye niche swap wali line kyu likhi hai? -> To recreate the original input string.
        // Check the images (3rd one to be specific)
        // We use &str -> pass by reference, so the string changes at some recursive call and is not abc
        // In order to work on abc only, we swap the elements back such that the string remains abc only.
        // Backtracking ka concept hi yahi hai ki starting point se ending point ka ek tareeka dhundo,
        // then wapas starting point pe aao, dusra tareeka dhundo, wapas starting point pe aao...
        swap(str[i], str[j]);
    }
}

int main()
{
    string str = "abc";
    int i = 0;
    printPermutation(str, i);
    return 0;
}

/*
**Time Complexity:**
The time complexity is determined by the number of recursive calls made. In this case, the function
`printPermutation` uses a nested loop that iterates through each character in the string, creating recursive
calls for each permutation. The number of recursive calls is n! (factorial of the length of the string),
where n is the length of the string. This is because, at each position, you have n choices, then n-1 choices
for the next position, and so on until you reach 1 choice.

Therefore, the time complexity is O(n!), where n is the length of the input string.

**Space Complexity:**
The space complexity is determined by the depth of the recursion stack. In each recursive call, the function
uses a constant amount of space for variables like `i`, `j`, and the function parameters. The depth of the
recursion stack is the length of the input string.

Therefore, the space complexity is O(n), where n is the length of the input string.

In summary:
- Time Complexity: O(n!)
- Space Complexity: O(n)
*/