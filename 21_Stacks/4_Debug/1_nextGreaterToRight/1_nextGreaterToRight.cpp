/*
void nextGreaterElementRight(vector<int> input, int n){
		vector<int> right(n,-1);
		stack<int> s;
		for(int i=0; i<n; i++){
				if(s.empty()){
						s.push(i);
				}
				while(!s.empty() && input[s.top()] < input[i]){
						right[s.top()] = input[i];
						s.pop();
				}
		}
}
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void nextGreaterElementRight(vector<int> &arr, int n) {
    vector<int> right(n, -1);
    stack<int> s;
    for(int i=n-1; i>=0; i--)
    {
        // jab tak stack me bada element nhi milta list se tab tak pop karte rahenge
        while(!s.empty() && s.top() <= arr[i])
        {
            s.pop();
        }
        // agar stack empty nahi hai toh next bada element mil gya
        if(!s.empty())
        {
            // usko right[i] wali position me daal denge
            right[i] = s.top();
        }
        // aakhir me use bade element ko stack me insert karenge kyuki vo left wale elements ka answer ho sakta hai
        s.push(arr[i]);
    }

    // printing the next greater element to the right array
    for(auto i: right)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
  int n;
  cout << "Enter the size of the array: ";
  cin >> n;

  vector<int> arr(n);
  cout << "Enter the elements of the array: ";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << "Next greater elements: ";
  nextGreaterElementRight(arr, n);

  return 0;
}

// TC -> O(n)
// SC -> O(n)