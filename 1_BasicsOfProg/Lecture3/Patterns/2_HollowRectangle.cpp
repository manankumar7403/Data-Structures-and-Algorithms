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
    for(int i=0; i<rows; i++)
    {
        // first row and last row -> print full *
        if(i==0 || i==rows-1)
        {
            for(int j=0; j<columns; j++)
            {
                cout<<"* ";
            }
        }
        else
        {
            // remaining middle rows
            // first star
            cout<<"* ";
            for(int i=0; i<columns-2; i++)
            {
                // spaces
                cout<<"  ";
            }
            // last star
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;        
}