#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);

    stack<int> st;
    st.push(-1);

    vector<int> ans(v.size());

    for(int i = v.size()-1; i>=0; i--)
    {
        int curr = v[i];

        // aapka answer stack mein
        while(st.top() >= curr)
        {
            st.pop();
        }

        // chota element mil chuka hai -> answer mein store
        ans[i] = st.top();

        // push kardo current element ko kyuki ab jo hum next element dekhenge usse chota element chahiye
        st.push(curr);
    }

    cout << "Printing the next smaller element array: " << endl;
    for(int i=0; i<ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}

// vector v = 2 1 4 3
// stack st = -1
// vector ans banaya vector v size ka (4)
// v vector me right se left traversal kar rhe hai
// next smaller element find karna hai v me toh obviously last element(3) ka usse smaller element nahi hoga

// 1) curr = v[i] = 3
// st.top() = -1 >= curr = 3? No
// ans[i] = st.top -> ans[3] = -1                    ✅
// st.push(curr) = st.push(3) -> stack = 3 -1

// 2) curr = v[i] = 4
// st.top() = 3 >= curr = 4? No
// ans[i] = st.top -> ans[2] = 3                     ✅
// st.push(curr) = st.push(4) -> stack = 4 3 -1

// 3) curr = v[i] = 1
// st.top() = 4 >= curr = 1? Yes
// st.pop() -> stack = 3 -1
// st.top() = 3 >= curr = 1? Yes
// st.pop() -> stack = -1
// st.top() = -1 >= curr = 1? No
// ans[i] = st.top -> ans[1] = -1                    ✅
// st.push(curr) = st.push(1) -> stack = 1 -1

// 4) curr = v[i] = 2
// st.top() = 1 >= curr = 2? No
// ans[i] = st.top -> ans[0] = 1                     ✅
// st.push(curr) = st.push(2) -> stack = 2 1 -1