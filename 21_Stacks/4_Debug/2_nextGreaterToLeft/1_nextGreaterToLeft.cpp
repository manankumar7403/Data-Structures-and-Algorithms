// also called previous Greater element

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void prevGreaterElement(vector<int>& arr)
{
    int n = arr.size();
    stack<int>s;
    s.push(arr[0]);
    cout << "-1 ";
    
    for(int i=1; i<n; i++)
    {
        while(!s.empty() && s.top() <= arr[i])
        {
            s.pop();
        }
        if(s.empty()) cout << "-1 ";
        else cout << s.top() << " ";
        s.push(arr[i]);
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array:" << endl;
    cin >> n;
    vector<int>arr(n);
    cout << "Enter the elements in the array:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    prevGreaterElement(arr);
    return 0;
}