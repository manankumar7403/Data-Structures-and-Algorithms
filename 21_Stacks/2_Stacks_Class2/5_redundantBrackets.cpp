// There should be no extra brackets.
// Example 1: (a*b+(c/d)) -> No
// Example 2: ((a/b)) -> Yes
// Logic sirf ye hai ki opening aur closing brackets ke beech mein ek operator hona chahiye

#include <iostream>
#include <stack>
using namespace std;

bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for(int i=0; i<s.length(); i++)
    {
        char ch = s[i];

        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')  // opening bracket ya operator hai toh seedha push kardo
        {
            st.push(ch);
        }

        else
        {
            // ch ya toh ')' hai ya lowercase letter hai 
            if(ch == ')')    // toh hume check karna hai ki '(' aur ')' beech me koi operator hai ki nahi
            {
                bool isRedundant = true;
                while(st.top() != '(')
                {
                    char top = st.top();
                    if(top == '+' || top == '-' || top == '*' || top == '/')  // matlab redundant nahi hai
                    {
                        isRedundant = false;
                    }
                    st.pop();
                }
                if(isRedundant == true)
                {
                    return true;
                }
                st.pop();   // us opening bracket ko bhi hata do
            }
        }
    }
    return false;
}

int main()
{
    string s;
    cout << "Enter the string operation:" << endl;
    getline(cin, s);
    if(findRedundantBrackets(s))
    {
        cout << s << " contains redundant brackets." << endl;
    }
    else
    {
        cout << s << " doesn't contain redundant brackets." << endl;
    }

    return 0;
}