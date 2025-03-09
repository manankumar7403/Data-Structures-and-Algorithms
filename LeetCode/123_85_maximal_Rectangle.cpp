// ⭐⭐LEETCODE 84 -> Largest Rectangle in Histogram is the Pre-requisite⭐⭐

// 🔴🔴LEETCODE 85 -> Maximal Rectangle🔴🔴
/*
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its
area.

Example 1:
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.

Example 2:
Input: matrix = [["0"]]
Output: 0

Example 3:
Input: matrix = [["1"]]
Output: 1

Constraints:
rows == matrix.length
cols == matrix[i].length
1 <= row, cols <= 200
matrix[i][j] is '0' or '1'.
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> prevSmallerElementIndex(vector<int> &input)
{
    stack<int> st;
    st.push(-1);

    vector<int> ans(input.size());

    for (int i = 0; i < input.size(); i++)
    {
        int curr = input[i]; // current element

        // aapka answer stack mein
        while (st.top() != -1 && input[st.top()] >= curr) // top me valid index hona chahiye aur stack ke top me jo index hai uska corresponding element >= curr
        {
            st.pop();
        }

        // chota element ka index mil chuka hai -> answer mein store
        ans[i] = st.top();

        st.push(i); // current element ka index insert kiya stack mein
    }
    return ans;
}

vector<int> nextSmallerElementIndex(vector<int> &input)
{
    stack<int> st;
    st.push(-1);

    vector<int> ans(input.size());

    for (int i = input.size() - 1; i >= 0; i--)
    {
        int curr = input[i]; // current element

        // aapka answer stack mein
        while (st.top() != -1 && input[st.top()] >= curr) // top me valid index hona chahiye aur stack ke top me jo index hai uska corresponding element >= curr
        {
            st.pop();
        }

        // chota element ka index mil chuka hai -> answer mein store
        ans[i] = st.top();

        st.push(i); // current element ka index insert kiya stack mein
    }
    return ans;
}

int largestRectangleArea(vector<int> &heights)
{
    // Step1:
    vector<int> prev = prevSmallerElementIndex(heights);

    // Step2:
    vector<int> next = nextSmallerElementIndex(heights);

    // Step3: Finding the area
    int maxArea = INT_MIN;
    int size = heights.size(); // for putting -1 to size of heights array (here, 6)

    for (int i = 0; i < heights.size(); i++)
    {
        int length = heights[i];
        if (next[i] == -1)
        {
            next[i] = size; // VS code me poora explain and check Logic.txt (is line ki wajah se question hard marked hai)
        }
        int width = next[i] - prev[i] - 1;
        int area = length * width;
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int maximalRectangle(vector<vector<char>> &matrix)
{
    int maxi = INT_MIN;
    vector<int> histogram(matrix[0].size(), 0); // stores the height of the histogram, if 1 found in col, inc corresponding j

    for (int i = 0; i < matrix.size(); i++)
    {
        // to create histogram array
        for (int j = 0; j < histogram.size(); j++)
        {
            if (matrix[i][j] == '1')
                histogram[j]++;
            else
                histogram[j] = 0;
        }
        maxi = max(maxi, largestRectangleArea(histogram)); // looks out for every col and returns the one with the max area
    }
    return maxi;
}

int main()
{
    int rows, cols;
    cout << "Enter the number of rows:" << endl;
    cin >> rows;
    cout << "Enter the number of cols:" << endl;
    cin >> cols;
    vector<vector<char>>matrix(rows, vector<char>(cols));
    cout << "Enter the data in the matrix:" << endl;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            cin >> matrix[i][j];
        }
    }
    int ans = maximalRectangle(matrix);
    cout << "Maximum area containing only 1s is: " << ans << endl;
    return 0;
}

// TC -> O(n*(m+n))
// SC -> O(n)