//⭐⭐ prev smaller element(index) and next smaller element(index) are the pre-requisite⭐⭐
// 🔴🔴🔴🔴 LEETCODE 84 -> Largest Rectangle In Histogram 🔴🔴🔴🔴
// Refer 21_Stacks -> 3_Stacks_Class3 -> 5_Largest_Rect_In_Histogram
/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is
1, return the area of the largest rectangle in the histogram.

Example 1:
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
 
Example 2:
Input: heights = [2,4]
Output: 4

Constraints:
1 <= heights.length <= 10^5
0 <= heights[i] <= 10^4
*/
// _______________________________________________________________________________________________

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> prevSmallerElementIndex(vector<int> &input)
{
    stack<int> st;
    st.push(-1);

    vector<int> ans(input.size());

    for (int i = 0; i < input.size(); i++)
    {
        int curr = input[i];   // current element

        // aapka answer stack mein
        while (st.top() != -1 && input[st.top()] >= curr)  // top me valid index hona chahiye aur stack ke top me jo index hai uska corresponding element >= curr
        {
            st.pop();
        }

        // chota element ka index mil chuka hai -> answer mein store
        ans[i] = st.top();

        st.push(i);       // current element ka index insert kiya stack mein
    }
    return ans;
}

vector<int> nextSmallerElementIndex(vector<int> &input)
{
    stack<int> st;
    st.push(-1);

    vector<int> ans(input.size());

    for (int i = input.size()-1; i >= 0; i--)
    {
        int curr = input[i];   // current element

        // aapka answer stack mein
        while (st.top() != -1 && input[st.top()] >= curr)  // top me valid index hona chahiye aur stack ke top me jo index hai uska corresponding element >= curr
        {
            st.pop();
        }

        // chota element ka index mil chuka hai -> answer mein store
        ans[i] = st.top();

        st.push(i);       // current element ka index insert kiya stack mein
    }
    return ans;
}

int getRectangularAreaHistogramHeight(vector<int> &height)
{
    // Step1:
    vector<int> prev = prevSmallerElementIndex(height);

    // Step2:
    vector<int> next = nextSmallerElementIndex(height);

    // Step3: Finding the area
    int maxArea = INT_MIN;
    int size = height.size();    // for putting -1 to size of heights array (here, 6)

    for(int i=0; i<height.size(); i++)
    {
        int length =  height[i];
        if(next[i] == -1)
        {
            next[i] = size;
        }
        int width = next[i] - prev[i] - 1;
        int area = length * width;
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int main()
{
    int n;
    cout << "Enter the size of the heights array:" << endl;
    cin >> n;
    vector<int> height(n);
    cout << "Enter the elements in the heights array:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> height[i];
    }
    cout << "Area of the largest rectangle in histogram is: " << getRectangularAreaHistogramHeight(height);
    cout << endl;
    return 0;
}


// Time Complexity: O(n)
// Space Complexity: O(n)