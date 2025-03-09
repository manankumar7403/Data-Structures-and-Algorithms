// Q5. Debug the code.

// #include <iostream>
// using namespace std;
// int main()
// {
//     char char_array[] = {'L', 'A', 'K', 'S', 'H', 'A', 'Y'};
//     int array_size = sizeof(char_array);
//     string j = "";
//     int i;
//     for (i = 0; i < array_size; i++)
//     {
//         j = j + char_array[i];
//     }
//     cout << j << endl;
// }

// ___________________________________________________________________________________
// Converts character array to string.

#include <iostream>
using namespace std;
int main()
{
    char char_array[] = {'L', 'A', 'K', 'S', 'H', 'A', 'Y'};
    int array_size = sizeof(char_array)/sizeof(char);
    string j = "";
    for (int i = 0; i < array_size; i++)
    {
        j = j + char_array[i];
    }
    cout << j << endl;
}