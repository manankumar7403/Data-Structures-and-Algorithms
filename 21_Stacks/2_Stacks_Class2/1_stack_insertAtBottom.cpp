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

void insertAtBottom(stack<int> &s)
{
    if(s.empty())
    {
        cout << "Stack is empty, can't insert at bottom." << endl;
        return;
    }

    int target = s.top();
    s.pop();
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

    insertAtBottom(s);

    cout << "Initially top element is now at bottom: " << endl;
    while(!s.empty())
    {
        cout<< s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}

/*
1_Stacks_Class1 -> 4_findMiddle_elementOfStack wala hi logic use kiya hai

original stack                 target stack
50                                40                               
40                                30
30                                20
20                                10
10                                50

toh sabse pehle insertAtBottom wale function me target nikal liya 50
target = s.top() = 50
s.pop()  -> bacha hua stack 40 se lekar 10 tak solve wale function mein bhej diya

solve function me hum baar baar(recursion) top element store karke pop kar rhe hai until the stack is empty

jaise hi stack empty hua humne target push kar diya 50 

then backtracking se jo elements pop kiye the vo wapas unke original order me stack me push kar diya
*/ 
