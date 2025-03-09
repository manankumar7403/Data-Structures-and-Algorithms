#include <iostream>
#include <string.h>
using namespace std;

void replaceSpaces(char sentence[])
{
    int i = 0;
    int n = strlen(sentence);
    for(int i=0; i<n; i++)
    {
        if(sentence[i] == ' ')
        {
            sentence[i] = '@';
        }
    }
}

int main()
{
    char sentence[100];
    cin.getline(sentence, 100);
    replaceSpaces(sentence);
    cout << "After replacing spaces with @: " << sentence << endl;
    return 0;
}

// T.C. - O(n)
// S.C. - O(1)