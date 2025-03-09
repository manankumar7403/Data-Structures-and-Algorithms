// Q3. Debug the code. It tries to remove duplicates from the given string.

// #include <bits/stdc++.h>
// using namespace std;

// char *removeDuplicate(char str[], int n) {
//   // str is character array and n is the lenght of the character array
// 	int index = 0;
// 	for (int i=0; i<n; i++) {
// 		int j;
// 		for (j=0; j<i; j++)
// 			if (str[i] == str[j])
// 				str[index++] = str[i];
// 		}
		
// 	return str;
// }

// _________________________________________________________________

#include <bits/stdc++.h>
using namespace std;

char *removeDuplicate(char str[], int n) {
    // str is character array and n is the length of the character array
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = 0; j < i; j++)
        {
            if (str[i] == str[j])
            {
                break;
            }
        }
        // If the above loop did not break, then the character is unique
        if (j == i) {
            str[index++] = str[i];
        }
    }

    // Null-terminate the modified string
    str[index] = '\0';

    return str;
}

int main() {
    const int MAX_SIZE = 100;
    char str[MAX_SIZE];
    
    cout << "Enter a string: ";
    cin.getline(str, MAX_SIZE);
    
    int n = strlen(str);

    cout << "Original String: " << str << endl;

    removeDuplicate(str, n);

    cout << "String after removing duplicates: " << str << endl;

    return 0;
}
