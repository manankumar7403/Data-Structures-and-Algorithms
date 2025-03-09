#include <iostream>
using namespace std;
int main()
{
    int rows;
    cout<<"Enter the number of rows: ";
    cin>>rows;
    for (int i=0; i<rows; i++)
    {
        // Left Half Pyramid
        for (int j=0; j<rows-i; j++)
        {
            cout<<"* ";
        }

        //Mid space full pyramid
        for (int j=0; j<2*i+1; j++)
        {
            cout<<"  ";
        }

        //Right Half Pyramid
        for (int j=0; j<rows-i; j++)
        {
            cout<<"* "; 
        }
        cout<<endl;
    }

    for (int i=0; i<rows; i++)
    {
        // Bottom Left Half Pyramid
        for (int j=0; j<i+1; j++)
        {
            cout<<"* ";
        }

        //Mid space full pyramid
        for (int j=0; j<2*rows - 2*i - 1; j++)
        {
            cout<<"  ";
        }

        //Bottom Right Half Pyramid
        for (int j=0; j<i+1; j++)
        {
            cout<<"* "; 
        }
        cout<<endl;
    }
}
