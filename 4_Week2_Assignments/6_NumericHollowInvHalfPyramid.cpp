// #include <iostream>
// using namespace std;
// int main()
// {
//     int rows;
//     cout<<"Enter the number of rows: ";
//     cin>>rows;
//     for (int i=0; i<rows; i++)
//     {
//         for (int j=0; j<rows-i; j++)
//         {
//             if(i==0)
//             {
//                 cout<<j+1<<" ";
//             }
//             else if (j==0)
//             {
//                 cout<<i+1<<" ";
//             }
//             else if (j==rows-i-1)
//             {
//                 cout<<rows;
//             }
//             else
//             {
//                 cout<<"  ";
//             }
//         }
//         cout<<endl;
//     }
// }

// 2nd method
#include <iostream>
using namespace std;
int main()
{
    int rows;
    cout<<"Enter the number of rows: ";
    cin>>rows;
    for (int i=0; i<rows; i++)
    {
        for (int j=i+1; j<=rows; j++)
        {
            if(j==i+1 || j==rows || i==0)
            {
                cout<<j<<" ";
            }
            else
            {
                cout<<"  ";
            }
        }
        cout<<endl;
    }
}
