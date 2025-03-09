#include<iostream>
using namespace std;
void hollowDiamond(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (2 * n); j++) {
      if (i + j <= n - 1) // upper left triangle
        cout << "*";
      else
        cout << " ";
      if ((i + n) <= j) // upper right triangle
        cout << "*";
      else
        cout << " ";
    }
    cout << "\n";
  }
  // bottom half of the pattern
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (2 * n); j++) {
      if (i >= j) // bottom left triangle
        cout << "*";
      else
        cout << " ";
      if (i >= ((2 * n) - 1) - j) // bottom right triangle
        cout << "*";
      else
        cout << " ";
    }
    cout << "\n";
  }
}
int main() {
  int num;
  cout << "Enter number of levels of the pattern :" << endl;
  cin >> num;
  hollowDiamond(num);
  return 0;
}