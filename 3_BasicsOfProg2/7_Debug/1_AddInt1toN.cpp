// Q1. Add integers from 1 to N and display the sum on console.
// void main(){
//     int n;cin>>n;
//     int8_t sum=0;
//     for(int i=0;i<n;++i){
//         sum+=i;
//     }
//     cout<<sum<<endl;
// 		return 0;
// }

// SOLUTION:
#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    int sum=0;
    for(int i=0; i<=n; i++)
    {
        sum=sum+i;
    }
    cout<<"The sum from 1 to "<<n<<" is: "<<sum<<endl;
    return 0;
}
