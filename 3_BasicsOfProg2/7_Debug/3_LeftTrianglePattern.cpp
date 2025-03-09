// Q3. Left Triangle Star Pattern
// E.g., For N = 5
// *
// **
// ***
// ****
// *****
// #include <iostream>
// using namespace std;

// int main() {
//   // size of the triangle
//   int size = N;
//   // loop to print the pattern
//   for (int i = 0; i < size; i++) {
//     // print column
//     for (int j = 0; j < i; j++) {
//       cout << "**";
//     }
//     cout << "\n";
//   }
//   return 0;
// }

// SOLUTION:
#include <iostream>
using namespace std;
int main()
{
    int rows;
    cout<<"Enter the number of rows: ";
    cin>>rows;
    for(int i=1; i<=rows; i++)
    {
        for(int j=1 ;j<=i; j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}