// Q6. Debug the code. This code attempt to reverse all words occur in a sentence.
// All words are space separated.

// void reverseString(char input[], int n, int start)
// {
//     for (int i = start, j = n - 1 + start; i < j; i++, j--)
//     {
//         int temp = input[i];
//         input[j] = input[i];
//         input[i] = temp;
//     }
// }
// void reverseEachWord(char input[])
// {
//     int start = 0, count = 1, i = 0;
//     while (input[i] != 0)
//     {
//         i++;
//         count++;
//         if ((input[i] == ' '))
//         {
//             reverseString(input, count - 1, start);
//             start = i + 1;
//             count = 0;
//         }
//     }
// }
// ___________________________________________________________________________________

#include <iostream>
#include <cstring>
using namespace std;

void reverseString(char input[], int n, int start)
{
    for (int i = start, j = n - 1 + start; i < j; i++, j--)
    {
        int temp = input[i];
        input[i] = input[j];
        input[j] = temp;
    }
}

void reverseEachWord(char input[])
{
    int start = 0, count = 1, i = 0;
    while (input[i] != 0)
    {
        i++;
        count++;
        if ((input[i] == ' ' || input[i] == '\0'))
        {
            reverseString(input, count - 1, start);
            start = i + 1;
            count = 0;
        }
    }
}

int main()
{
    const int MAX_SIZE = 100; // Adjust the size according to your needs
    char input[MAX_SIZE];

    // Take user input for the string
    cout << "Enter a string: ";
    cin.getline(input, MAX_SIZE);

    // Get the length of the input string
    int n = strlen(input);

    // Display the original string
    cout << "Original String: " << input << endl;

    // Reverse each word and display the modified string
    reverseEachWord(input);

    cout << "String after reversing each word: " << input << endl;

    return 0;
}
