// Q3. This code tries to move all negative numbers to one side(left) but have some errors,
// can you spot those errors. Hint: Incomplete conditions applied.

// #include<iostream>
// using namespace std;
// void moveNegative(int arr[], int n){
//     int i=0, j=n-1;
//     while(i<j){
//         while(arr[i]<0){ // swap when a positive element is encountered
//             i++;
//         }
//         while(arr[j]>0){ // swap when a negative element is encountered
//             j--;
//         }
//         swap(arr[i], arr[j]); // swap the elements
//     }
// }
// int main(){
//     int n = 5;
//     int arr[n] = {2, -3, -1, 5, -4};
//     moveNegative(arr, n);
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }

#include<iostream>
using namespace std;
void moveNegative(int arr[], int n){
    int i=0, j=n-1;
    while(i<j){
        while(arr[i]<0 && i<j){ // move i until a positive element is encountered -> also checking i<j to ensure that array from left is moving right until i<j
            i++;
        }
        while(arr[j]>0 && i<j){ // move j until a negative element is encountered -> also checking i<j to ensure that array from right is moving left until i<j
            j--;
        }
        if(i<j){ // swap only when i is less than j
            swap(arr[i], arr[j]); // swap the elements
        }
    }
}
int main(){
    int n = 5;
    int arr[n] = {2, 3, -1, -5, -4};
    moveNegative(arr, n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}