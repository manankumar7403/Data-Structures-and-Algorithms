#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<vector<int> > arr)
{
    for(int i=0; i<arr.size(); i++)
    {
        for(int j=0; j<arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int rows;
    cout<<"Enter the number of rows: "<<endl;
    cin>>rows;
    int cols;
    cout<<"Enter the number of columns: "<<endl;
    cin>>cols;

    cout<<"Enter the elements in the array: "<<endl;
    vector<vector<int> > arr(rows, vector<int>(cols));
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            cin>>arr[i][j];
        }
    }

    printArray(arr);

}