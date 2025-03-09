#include <iostream>
using namespace std;
int main(){
    int rows;
    cout<<"Enter the number of rows: ";
    cin>>rows;
    for (int i=0; i<rows; i++) {
        int k=0;
        for (int j=0; j<rows*2-1; j++) { /*always 0 to 9*/
            if(j<rows-i-1){
                cout<<" ";
            }
            else if(k < 2*i+1){
                if(k==0 || k == 2*i || i == rows - 1){
                    cout<<"*";
                }
                else{
                    cout<<" ";
                }
                k++;
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}