/*
#include <iostream>
using namespace std;

bool checkKey(string& str, int i, int& n, char& key)
{
    // Base case
    if(i >= n)
    {
        // key not found
        return false;
    }

    // 1 case solve karo
    if(str[i] == key)
    {
        return true;
    }

    // baaki recursion sambhal lega
    return checkKey(str, i+1, n, key);
}

int main()
{
    string str = "lovebabbar";
    int n = str.length();

    char key = 'r';

    int i = 0;
    bool ans = checkKey(str, i, n, key);

    cout << "Answer is: " << ans << endl;

    return 0;
}
*/
// ___________________________________________________________________________

// Returning the index

/*
#include <iostream>
using namespace std;

int checkKey(string& str, int i, int& n, char& key)
{
    // Base case
    if(i >= n)
    {
        // key not found
        return -1;
    }

    // 1 case solve karo
    if(str[i] == key)
    {
        return i;
    }

    // baaki recursion sambhal lega
    return checkKey(str, i+1, n, key);
}

int main()
{
    string str = "lovebabbar";
    int n = str.length();

    char key = 'r';

    int i = 0;
    int ans = checkKey(str, i, n, key);

    cout << "Answer is: " << ans << endl;

    return 0;
}
*/
// ______________________________________________________________________________________________

// Printing all the indexes where key is present

/*
#include <iostream>
using namespace std;

void checkKey(string& str, int i, int& n, char& key)
{
    // Base case
    if(i >= n)
    {
        // key not found
        return;
    }

    // 1 case solve karo
    if(str[i] == key)
    {
        cout << "Found at: " << i << endl;
    }

    // baaki recursion sambhal lega
    return checkKey(str, i+1, n, key);
}

int main()
{
    string str = "lovebabbar";
    int n = str.length();

    char key = 'b';

    int i = 0;
    checkKey(str, i, n, key);
    return 0;
}
*/
// _______________________________________________________________________________________________

// Storing the indexes where key is found

/*
#include <iostream>
#include <vector>
using namespace std;

void checkKey(string& str, int i, int& n, char& key, vector<int>& ans)
{
    // Base case
    if(i >= n)
    {
        // key not found
        return;
    }

    // 1 case solve karo
    if(str[i] == key)
    {
        // Store in vector
        ans.push_back(i);
    }

    // baaki recursion sambhal lega
    return checkKey(str, i+1, n, key, ans);
}

int main()
{
    string str = "lovebabbar";
    int n = str.length();

    char key = 'b';

    int i = 0;
    vector<int> ans;

    checkKey(str, i, n, key, ans);

    cout << "Printing ans: " << endl;
    for(auto val: ans)
    {
        cout << val << " ";
    }
    cout << endl;


    return 0;
}
*/
// ________________________________________________________________________________________

// Counting the number of occurrences

#include <iostream>
#include <vector>
using namespace std;

void checkKey(string& str, int i, int& n, char& key, int& count)
{
    // Base case
    if(i >= n)
    {
        // key not found
        return;
    }

    // 1 case solve karo
    if(str[i] == key)
    {
        count++;
    }

    // baaki recursion sambhal lega
    return checkKey(str, i+1, n, key, count);
}

int main()
{
    string str = "lovebabbar";
    int n = str.length();

    char key = 'b';

    int i = 0;
    int count = 0;

    checkKey(str, i, n, key, count);
    
    cout << count << endl;
    return 0;
}
