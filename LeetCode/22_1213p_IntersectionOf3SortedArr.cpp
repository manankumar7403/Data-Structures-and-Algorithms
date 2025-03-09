// Given three integer arrays arr1, arr2 and arr3 sorted in strictly increasing order,
// return a sorted array of only the integers that appeared in all three arrays.

// Example 1:
// Input: arr1 = [1,2,3,4,5], arr2 = [1,2,5,7,9], arr3 = [1,3,4,5,8]
// Output: [1,5]
// Explanation: Only 1 and 5 appeared in the three arrays.

// Constraints:
// 1 <= arr1.length, arr2.length, arr3.length <= 1000
// 1 <= arr1[i], arr2[i], arr3[i] <= 2000

#include <iostream>
#include <vector>
using namespace std;

vector<int> commonElements(vector<int>& A, vector<int>& B, vector<int>& C)
{
    vector<int> ans;
    int i=0, j=0, k=0;

    while(i<A.size() && j<B.size() && k<C.size())
    {
        if(A[i]==B[j] && B[j]==C[k])
        {
            ans.push_back(A[i]);
            i++; j++; k++;
        }
        else if(A[i] < B[j])
        {
            i++;
        }
        else if(B[j] < C[k])
        {
            j++;
        }
        else
        {
            k++;
        }
        int xx = A[i-1];
        while(A[i]==xx) i++;
        int yy = B[j-1];
        while(B[j]==yy) j++;
        int zz = C[k-1];
        while(C[k]==zz) k++;
    }

    if(ans.size()==0)
    {
        return {-1};
    }
    return ans;
}

int main()
{
    int n1, n2, n3;
    cout << "Enter the size of first array: ";
    cin >> n1;
    vector<int>A(n1);
    cout << "Enter the elements in the first array: " << endl;
    for(int i=0; i<n1; i++)
    {
        cin >> A[i];
    }
    cout << "Enter the size of second array: ";
    cin >> n2;
    vector<int>B(n2);
    cout << "Enter the elements in the second array: " << endl;
    for(int i=0; i<n2; i++)
    {
        cin >> B[i];
    }
    cout << "Enter the size of third array: ";
    cin >> n3;
    vector<int>C(n3);
    cout << "Enter the elements in the third array: " << endl;
    for(int i=0; i<n3; i++)
    {
        cin >> C[i];
    }

    vector<int> result = commonElements(A,B,C);
    for(auto j: result)
    {
        cout << j <<" ";
    }
    return 0;
}

// Time Complexity - O(n1 + n2 + n2)
// Space Complexity - O(n)              -> min of O(n1,n2,n3)