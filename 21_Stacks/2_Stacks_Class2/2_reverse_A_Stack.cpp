#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int>& s, int target)
{
    // Base case
    if(s.empty())
    {
        s.push(target);
        return;
    }

    int topElement = s.top();
    s.pop();

    // Recursive call
    solve(s, target);

    // Backtracking
    s.push(topElement);

}

void reverseStack(stack<int> &s)
{
    if(s.empty())
    {
        return;
    }

    int target = s.top();
    s.pop();

    // Reverse stack using recursion
    reverseStack(s);

    // insert the target at bottom
    solve(s, target);
}

int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    reverseStack(s);

    cout << "Reversed stack is:" << endl;
    while(!s.empty())
    {
        cout<< s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}

/*
insertAtBottom wala hi logic use kiya hai

original stack                 target stack
50                                10                               
40                                20
30                                30
20                                40
10                                50

toh sabse pehle reverseStack wale function me target nikal liya 50
target = s.top() = 50
s.pop()  -> bacha hua stack 40 se lekar 10 tak recursive call kar diya toh har element apni apni call
ke liye pop ho rha hai aur target ban rha hai.

In reverseStack function
1) 50 target bana aur pop hua
2) 40 target bana aur pop hua
3) 30 target bana aur pop hua
4) 20 target bana aur pop hua
5) 10 target bana aur pop hua

ab stack empty hai toh return ho gya.

toh abhi target 10 hai aur hum solve wale function me gaye.

In solve function
1) Stack empty hai toh target = 10 push kar diya and return kar diya.

In reverseStack function
Target 20 hai -> passed in solve function.

In solve function
abhi stack mein 10 pada hai aur target hai 20
Toh 10 ko topElement me store karaya and pop kar diya, fir recursive call maari
dekha ki stack empty hai toh target push kar diya aur return kard diya.
Ab backtracking se jo element pop kiya tha(10) usse wapas push kardiya
So stack is 10
            20

In reverseStack function
Target 30 hai -> passed in solve function.

In solve function
abhi stack mein 20 aur 10 pada hai aur target hai 30
Toh 10 ko topElement me store karaya and pop kar diya, fir recursive call maari
aur 20 ko topElement me store karaya and pop kar diya, fir recursive call maari
dekha ki stack empty hai toh target push kar diya aur return kard diya.
Ab backtracking se jo element pop kiya tha(10 aur 20) unhe wapas push kardiya
So stack is 10
            20
            30

In reverseStack function
Target 40 hai -> passed in solve function.

In solve function
abhi stack mein 30, 20 aur 10 pada hai aur target hai 40
Toh 10 ko topElement me store karaya and pop kar diya, fir recursive call maari
aur 20 ko topElement me store karaya and pop kar diya, fir recursive call maari
aur 30 ko topElement me store karaya and pop kar diya, fir recursive call maari
dekha ki stack empty hai toh target push kar diya aur return kard diya.
Ab backtracking se jo element pop kiya tha(10, 20 aur 30) unhe wapas push kardiya
So stack is 10
            20
            30
            40

In reverseStack function
Target 50 hai -> passed in solve function.

In solve function
abhi stack mein 40, 30, 20 aur 10 pada hai aur target hai 50
Toh 10 ko topElement me store karaya and pop kar diya, fir recursive call maari
aur 20 ko topElement me store karaya and pop kar diya, fir recursive call maari
aur 30 ko topElement me store karaya and pop kar diya, fir recursive call maari
aur 40 ko topElement me store karaya and pop kar diya, fir recursive call maari
dekha ki stack empty hai toh target push kar diya aur return kard diya.
Ab backtracking se jo element pop kiya tha(10, 20, 30 aur 40) unhe wapas push kardiya
So stack is 10
            20
            30
            40
            50


*/ 
