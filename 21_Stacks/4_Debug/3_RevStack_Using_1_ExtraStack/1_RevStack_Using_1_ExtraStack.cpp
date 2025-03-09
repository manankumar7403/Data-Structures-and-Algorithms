/*
void reverseStack(stack<int> &input, stack<int> &extra) {
    int x = input.top();
    input.pop();
    reverseStack(input, extra);
    for(int i=0; input.empty(); i++){
        extra.push(input.top());
        input.pop();
    }
    input.push(x);
    for(int i=0; extra.empty(); i++){
        input.push(extra.top());
        extra.pop();
    }
}
*/

#include<iostream>
#include<stack>
using namespace std;

void reverseStack(stack<int> &input, stack<int> &extra) {
	if(input.empty()){
        return;
    }
    int x = input.top();
    input.pop();
    reverseStack(input,extra);
    while(!input.empty()){
        extra.push(input.top());
        input.pop();
    }
    input.push(x);
    while(!extra.empty()){
        input.push(extra.top());
        extra.pop();
    }
    return;
}

int main()
{
    stack<int> input;
    input.push(1);
    input.push(2);
    input.push(3);
    input.push(4);

    stack<int>temp;
    reverseStack(input, temp);
    while(!input.empty())
    {
        cout << input.top() << " ";
        input.pop();
    }
    return 0;
}