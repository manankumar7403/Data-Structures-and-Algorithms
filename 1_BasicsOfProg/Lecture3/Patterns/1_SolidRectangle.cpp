#include <iostream>
using namespace std;
int main()
{
    int rows;
    cout<<"Enter the number of rows: "<<endl;
    cin>>rows;
    int columns;
    cout<<"Enter the number of columns: "<<endl;
    cin>>columns;
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<columns; j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}