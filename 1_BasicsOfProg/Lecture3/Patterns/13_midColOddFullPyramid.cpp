#include <iostream>
using namespace std;
int main() {
  int rows;
  cout<<"Enter the number of rows: ";
  cin>>rows;
  for (int i=1; i<=rows; i++)
  {
    for (int j=1; j<=rows-i; j++)
    {
      cout<<"  ";
    }
    for (int j=i; j<2*i; j++)
    {
      cout<<j<<" ";
    }
    int ele = 2 * (i - 1);
    for (int j = 1; j <i; j++)
    {
      cout<<ele--<<" ";
    }
    cout<<endl;
  }
  return 0;
}