// 🔴🔴🔴🔴 LEETCODE 1405 -> Longest Happy String 🔴🔴🔴🔴
// Refer 31_Heaps -> 4_Heaps_Class4 -> 3_LongestHappyString.cpp
/*
A string s is called happy if it satisfies the following conditions:
s only contains the letters 'a', 'b', and 'c'.
s does not contain any of "aaa", "bbb", or "ccc" as a substring.
s contains at most a occurrences of the letter 'a'.
s contains at most b occurrences of the letter 'b'.
s contains at most c occurrences of the letter 'c'.
Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings,
return any of them. If there is no such string, return the empty string "".

A substring is a contiguous sequence of characters within a string.

Example 1:
Input: a = 1, b = 1, c = 7
Output: "ccaccbcc"
Explanation: "ccbccacc" would also be a correct answer.

Example 2:
Input: a = 7, b = 1, c = 0
Output: "aabaa"
Explanation: It is the only correct answer in this case.

Constraints:
0 <= a, b, c <= 100
a + b + c > 0
*/
// _____________________________________________________________________________________________

#include <iostream>
#include <queue>
using namespace std;

class Node
{
    public:
    char data;
    int count;

    Node(char d, int c)
    {
        this->data = d;
        this->count = c;
    }
};

class compare
{
    public:
    bool operator()(Node a, Node b)
    {
        return a.count < b.count;
    }  
};

string longestDiverseString(int a, int b, int c)   // a,b,c are the frequency
{
    // Creating a MAX HEAP
    priority_queue<Node, vector<Node>, compare> maxHeap;

    if (a > 0)
    {
        Node temp('a', a); // char, count
        maxHeap.push(temp);
    }

    if (b > 0)
    {
        Node temp('b', b); // char, count
        maxHeap.push(temp);
    }

    if (c > 0)
    {
        Node temp('c', c); // char, count
        maxHeap.push(temp);
    }

    string ans = "";

    while (maxHeap.size() > 1) // ye maxHeap.empty() nahi kiya kyuki hum hamesha 2 values nikal rahe hai, suppose 5 elements hai aur 2, then 2 nikal li aur 1 bachi hai par hum 2 nikal rahe hai toh dikkat aa jayegi
    {
        Node first = maxHeap.top();
        maxHeap.pop();
        Node second = maxHeap.top();
        maxHeap.pop();

        if (first.count >= 2) // 2 ya 2 se zyada frequency hai toh 2 bar insert kardo vo element ans mein
        {
            ans = ans + first.data;
            ans = ans + first.data;
            first.count = first.count - 2;
        }
        else // frequency us element ki 1 hai
        {
            ans = ans + first.data;
            first.count--;
        }

        // Similarly, for the second element
        if (second.count >= 2 && second.count >= first.count)
        /*
        maxHeap me jo element 2nd number par pada hai usko sirf tab hi 2 bar insert karenge agar uski frequency jo
        usse upar pada hai maxHeap mein usse kam hai ya barabar hai.
        agar hum second most freq element ko tab 2 baar insert karte rahenge jab uski frequency first most freq element
        se kam hai toh fir vo second most freq element pehle khatam ho jayega and hum properly usse utilize nahi kar
        payenge.
        check slides heaps class 4 -> page 7
        */
        {
            ans = ans + second.data;
            ans = ans + second.data;
            second.count = second.count - 2;
        }
        else // frequency us element ki 1 hai
        {
            ans = ans + second.data;
            second.count--;
        }

        // We have now pushed the 2 most freq elements at most 2 times in the ans string.
        // Then we reduced their frequency accordingly.
        // Now, we want to push them back in maxHeap if they have freq > 0
        if (first.count > 0)
        {
            maxHeap.push(first);
        }

        if (second.count > 0)
        {
            maxHeap.push(second);
        }
    }

    // Ab possible hai ki ek element bacha hua ho
    if (maxHeap.size() == 1) // ek element pada hai uski kuch bhi frequency ho sakti hai
    {
        Node temp = maxHeap.top();
        maxHeap.pop();

        if (temp.count >= 2) // agar frequency 2 hai toh 2 baar add kardo
        {
            ans = ans + temp.data;
            ans = ans + temp.data;
            temp.count = temp.count - 2;
        }
        else // frequency 1 baar hai toh ek baar add kardo
        {
            ans = ans + temp.data;
            temp.count--;
        }
    }
    return ans;
}

int main()
{
    int a, b, c;
    cout << "Enter the freq of a:" << endl;
    cin >> a;
    cout << "Enter the freq of b:" << endl;
    cin >> b;
    cout << "Enter the freq of c:" << endl;
    cin >> c;

    string result = longestDiverseString(a, b, c);
    cout << "The Longest Happy String: " << result;
    cout << endl;
    return 0;
}

// TC -> O(nlogn)
// SC -> O(n)

// Similar to 2_Reorganize String -> Heap Logic