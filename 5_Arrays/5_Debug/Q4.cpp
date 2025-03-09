//Q4. This code attempts to print elements (only once) which appear more than one time.
// Can you spot the error in the code:
// #include<iostream>
// #include<cstring>
// using namespace std;

// void printDuplicates(int arr[], int n){
//     int freq[n+1];
//     memset(freq, 0, sizeof(freq)); // initialize the frequency array to 0
//     bool flag = false; // added a flag to check if there are no duplicate elements
//     for(int i=0;i<=n;i++){
//         freq[arr[i]]++;
//         if(freq[arr[i]] > 1){
//             flag = true;
//             cout<<arr[i]<<" ";
//         }
//     }
//     if(!flag){
//         cout<<"No duplicate elements";
//     }
// }

// int main(){
//     int n = 6;
//     int arr[n] = {3, 2, 1, 2, 2, 3};
//     printDuplicates(arr, n);
//     return 0;
// }

#include<iostream>
#include<cstring>
using namespace std;

void printDuplicates(int arr[], int n){
    int freq[n];
    memset(freq, 0, sizeof(freq)); // initialize the frequency array to 0
    bool flag = false; // added a flag to check if there are no duplicate elements
    for(int i=0; i<n; i++){
        freq[arr[i]]++;
        if(freq[arr[i]] == 2){
            flag = true;
            cout<<arr[i]<<" ";
        }
    }
    if(!flag){
        cout<<"No duplicate elements";
    }
}

int main(){
    int n = 7;
    int arr[n] = {3, 2, 1, 2, 2, 3, 1};
    printDuplicates(arr, n);
    return 0;
}

// {3, 2, 1, 2, 2, 3, 1};
// freq[arr[i]]++;
//         if(freq[arr[i]] == 2)

// First, we will check the element present at ith index of the array.
// After we get the element we then increment the element present at that location in
// the frequency array.

// First iteration -> i=0
// arr[i] = 3
// freq[3]++ = 4th index location has to be incremented by 1, so it becomes 0+1=1
// and the array becomes freq = [0, 0, 0, 0, 1, 0, 0]

// Second iteration -> i=1
// arr[i] = 2
// freq[2]++ = 3rd index location has to be incremented by 1, so it becomes 0+1=1
// and the array becomes freq = [0, 0, 0, 1, 1, 0, 0]

// Third iteration -> i=2
// arr[i] = 1
// freq[1]++ = 2nd index location has to be incremented by 1, so it becomes 0+1=1
// and the array becomes freq = [0, 0, 1, 1, 1, 0, 0]

// Fourth iteration -> i=3
// arr[i] = 2
// freq[2]++ = 3rd index location has to be incremented by 1, so it becomes 1+1=2
// and the array becomes freq = [0, 0, 1, 2, 1, 0, 0]

// as if(freq[arr[i]] == 2) is true
// 2 IS RETURNED AS OUTPUT

// Fifth iteration -> i=4
// arr[i] = 2
// freq[2]++ = 3rd index location has to be incremented by 1, so it becomes 2+1=3
// and the array becomes freq = [0, 0, 1, 3, 1, 0, 0]

// Sixth iteration -> i=5
// arr[i] = 3
// freq[3]++ = 4th index location has to be incremented by 1, so it becomes 1+1=2
// and the array becomes freq = [0, 0, 1, 3, 2, 0, 0]

// as if(freq[arr[i]] == 2) is true
// 3 IS RETURNED AS OUTPUT

// Seventh iteration -> i=6
// arr[i] = 1
// freq[1]++ = 2nd index location has to be incremented by 1, so it becomes 1+1=2
// and the array becomes freq = [0, 0, 2, 3, 2, 0, 0]

// as if(freq[arr[i]] == 2) is true
// 1 IS RETURNED AS OUTPUT