#include <iostream>
#include <stack>
using namespace std;

void printMiddleElement(stack<int> &s, int &totalSize)
{
    if(s.size() == 0)
    {
        cout << "There is no element in the stack." << endl;
        return;
    }

    // Base case
    if(s.size() == totalSize/2 + 1)
    {
        cout << "Middle element is: " << s.top() << endl;
        return;
    }

    int temp = s.top();
    s.pop();

    // Recursive call
    printMiddleElement(s, totalSize);

    // Backtracking
    s.push(temp);
} 

int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);

    int totalSize = s.size();
    printMiddleElement(s, totalSize);

    return 0;
}

/*
Hum bas temp mein top element ko store karate ja rahe hai aur pop kar rhe hai until we reach
s.size() == totalSize/2 + 1

then we print the middle element which is the top element of the current stack.

After that we push back the respective temp = s.top() values back to the stack so the original stack
contains all the elements.
*/