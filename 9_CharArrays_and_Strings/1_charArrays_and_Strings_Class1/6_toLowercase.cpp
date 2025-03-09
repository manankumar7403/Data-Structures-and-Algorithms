#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int getLength(char arr[])
{
    int length = 0;
    int i = 0;

    while(arr[i] != '\0')
    {
        length++;
        i++;
    }
    return length;
}

void toUppercase(char arr[])
{
    int n = getLength(arr);
    for(int i=0; i<n; i++)
    {
        if(arr[i] < 'a' && arr[i] < 'z')  // a=97, A=65
        arr[i] = arr[i] - 'A' + 'a';   // to uppercase
    }
}

// Alternatively can use islower of cctype and strlen of cstring 
// void toUppercase(char arr[])
// {
//     int n = getLength(arr);
//     for(int i = 0; i < n; i++)
//     {
//         if (isupper(arr[i])) // Check if the character is a uppercase letter
//         {
//             arr[i] = arr[i] - 'A' + 'a';
//         }
//     }
// }

int main()
{
    char arr[100] = "MANAN";
    toUppercase(arr);
    cout << arr << endl;
}
// _____________________________________________________________________________________________
