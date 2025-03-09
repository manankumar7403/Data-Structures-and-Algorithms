#include <iostream>
#include <stack>
using namespace std;

void insertSorted(stack<int>&s, int target)
{
    // Base Case
    if(s.empty())        // stack empty hai toh koi bhi element insert kardo sorted hi maana jayega
    {
        s.push(target);
        return;
    }
    
    if(s.top() >= target)    // we need the smallest element at the top of the stack
    {
        s.push(target);
        return;
    }

    int topElement = s.top();   // we will keep on storing and popping the top element until we get a
                                // bigger element than the target
    s.pop();

    // Recursion
    insertSorted(s, target);

    // Backtracking
    s.push(topElement);        // pushing back the smaller elements back on top of the target after we
                              // placed the target at its right position
}

void sortStack(stack<int> &s)
{
    // Base Case
    if(s.empty())
    {
        return;
    }

    int target = s.top();
    s.pop();

    sortStack(s);

    insertSorted(s, target);
}

int main()
{
    stack<int> s;
    s.push(7);
    s.push(11);
    s.push(3);
    s.push(5);
    s.push(9);

    sortStack(s);

    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;

    return 0;

}

/*
Same as 2_reverse_A_Stack

original stack                 target stack
9                                3                               
5                                5
3                                7
11                               9
7                                11

toh sabse pehle sortStack wale function me target nikal liya 9
target = s.top() = 9
s.pop()  -> bacha hua stack 5 se lekar 7 tak recursive call kar diya toh har element apni apni call
ke liye pop ho rha hai aur target ban rha hai.

In sortStack function
1) 9 target bana aur pop hua
2) 5 target bana aur pop hua
3) 3 target bana aur pop hua
4) 11 target bana aur pop hua
5) 7 target bana aur pop hua

ab stack empty hai toh return ho gya.

toh abhi target 7 hai aur hum insertSorted wale function me gaye.

In insertSorted function
1) Stack empty hai toh target = 7 push kar diya and return kar diya.

In sortStack function
Target 11 hai -> passed in insertSorted function.

In insertSorted function
abhi stack mein 7 pada hai aur target hai 11
Toh 7 ko topElement me store karaya and pop kar diya, fir recursive call maari
dekha ki stack empty hai toh target push kar diya aur return kard diya.
Ab backtracking se jo element pop kiya tha(7) usse wapas push kardiya
So stack is 7
            11

In sortStack function
Target 3 hai -> passed in insertSorted function.

In insertSorted function
abhi stack mein 7 aur 11 pada hai aur target hai 3
7 >= 3
3 seedha stack me push kar diya aur return kar diya
So stack is 3
            7
            11

In sortStack function
Target 5 hai -> passed in insertSorted function.

In insertSorted function
abhi stack mein 3, 7 aur 11 pada hai aur target hai 5
Toh 3 ko topElement me store karaya and pop kar diya, fir recursive call maari
Now, 7 >= 5
5 seedha stack me push kar diya aur return kar diya
Ab backtracking se jo element pop kiya tha(3) usse wapas push kardiya
So stack is 3
            5
            7
            11

In sortStack function
Target 9 hai -> passed in insertSorted function.

In insertSorted function
abhi stack mein 3, 5, 7 aur 11 pada hai aur target hai 9
Toh 3 ko topElement me store karaya and pop kar diya, fir recursive call maari
aur 5 ko topElement me store karaya and pop kar diya, fir recursive call maari
aur 7 ko topElement me store karaya and pop kar diya, fir recursive call maari
Now, 11 >= 9
9 seedha stack me push kar diya and return kar diya
Ab backtracking se jo element pop kiya tha(3, 5, aur 7) unhe wapas push kardiya
So stack is 3
            5
            7
            9
            11

*/ 