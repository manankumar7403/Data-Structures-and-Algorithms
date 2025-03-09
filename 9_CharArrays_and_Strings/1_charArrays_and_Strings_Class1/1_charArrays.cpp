// #include <iostream>
// using namespace std;

// int main()
// {
//     char name[100];
//     cout << "Enter your name: " << endl;

//     cin >> name;

//     cout << "Your name is " << name << endl;
//     return 0;
// }

// _____________________________________________________________________

// #include <iostream>
// using namespace std;

// int main()
// {
//     char ch[100];

//     ch[0] = 'a';
//     ch[1] = 'b';
//     cin >> ch[2];
//     cout << ch[0] << ch[1] << ch[2] << endl;
//     return 0;
// }

// __________________________________________________________________________

// #include <iostream>
// using namespace std;

// int main()
// {
//     char name[100];

//     cin >> name;               // Babbar
//     for(int i=0; i<7; i++)
//     {
//         cout << "Index: " << i << " | " << "value: " << name[i] << endl;
//     }

//     int value = (int)name[6];                  // gives 0 (null char ASCII value) for index 6
//     cout << "Value is: " << value << endl;
//     return 0;
// }

// ____________________________________________________________________________________

// #include <iostream>
// using namespace std;

// int main()
// {
//     char name[100];           // Manan Kumar

//     cin >> name;
//     cout << name;
//     return 0;
// }

// Doesn't print the full name as cin only reads char ch till it gets a space, tab, \n, enter.
// Only prints "Manan"

// _______________________________________________________________________________
// Using getline function to read breaks and spaces as well

// #include <iostream>
// using namespace std;

// int main()
// {
//     char arr[100];
//     cin.getline(arr, 100); // Use cin.getline
//     cout << arr;
//     cout << endl;
//     return 0;
// }

// getline is used when string is used instead of char and cin.getline() is used when char is used.

// ____________________________________________________________________________________________

// 🔴🔴🔴🔴 How to find length of an char array manually (without using strlen function of string.h)🔴🔴🔴🔴

#include <iostream>
#include <string.h>
using namespace std;

int getLength(char name[])
{
    int length = 0;
    int i = 0;

    while(name[i] != '\0')
    {
        length++;
        i++;
    }
    return length;
}

int main()
{
    char name[100];
    cin >> name;
    cout << "Length is: " << getLength(name) << endl;
    cout << "Length is: " << strlen(name) << endl;
    return 0;
}