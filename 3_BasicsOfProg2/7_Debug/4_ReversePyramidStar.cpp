// Q4. Reverse Pyramid star pattern.
// e.g., N=5
// *********
//  *******
//   *****
//    ***
//     *       

// #include <iostream>
// using namespace std;

// int main() {
//   // size of the pyramid
//   int size; cin>>size;
//   for (int i = 0; i < size; i++) {
//     // print spaces
//     for (int j = 0; j < i; j++) {
//       cout << "  ";
//     }
//     // print stars
//     for (k = 0; k < 2 * size - 1; k++) {
//       cout << "*";
//     }
//     cout << "\n";
//   }
//   return 0;
// }

// SOLUTION

#include <iostream>
using namespace std;
int main()
{
    int rows;
    cout<<"Enter the number of rows: ";
    cin>>rows;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<i; j++)
        {
            cout<<" ";
        }

        for(int k = 0; k < 2*(rows-i)-1; k++)
        {
            cout<<"*";
        }
        cout<<endl;
    }

    return 0;
}