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

    for(int i = 0; i<=v.size()-1; i++)
    {
        int curr = v[i];

        // aapka answer stack mein
        while(st.top() >= curr)
        {
            st.pop();
        }

        // chota element mil chuka hai -> answer mein store
        ans[i] = st.top();

        st.push(curr);
    }

    cout << "Printing the previous smaller element array: " << endl;
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
// v vector me left se right traversal kar rhe hai
// prev smaller element find karna hai v me toh obviously first element(2) ka usse smaller eleemnt nahi hoga

// 1) curr = v[i] = 2
// st.top() = -1 >= curr = 2? No
// ans[i] = st.top -> ans[0] = -1                        ✅      
// st.push(curr) = st.push(2) -> stack = 2 -1

// 2) curr = v[i] = 1
// st.top() = 2 >= curr = 1? Yes
// st.pop() -> stack = -1
// st.top() = -1 >= curr = 1? No
// ans[i] = st.top -> ans[1] = -1                        ✅
// st.push(curr) = st.push(1) -> stack = 1 -1        

// 3) curr = v[i] = 4
// st.top() = 1 >= curr = 4? No
// ans[i] = st.top -> ans[2] = 1                         ✅
// st.push(curr) = st.push(4) -> stack = 4 1 -1       

// 4) curr = v[i] = 3
// st.top() = 4 >= curr = 3? Yes
// st.pop() -> stack = 1 -1
// st.top() = 1 >= curr = 3? No
// ans[i] = st.top -> ans[3] = 1                         ✅
// st.push(curr) = st.push(3) -> stack = 3 1 -1          

// Answer is -1 -1 1 1