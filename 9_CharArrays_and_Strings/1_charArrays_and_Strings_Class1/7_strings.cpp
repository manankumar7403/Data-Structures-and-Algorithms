// #include <iostream>
// #include <string>
// using namespace std;
// int main()
// {
//     // create string
//     string str;
//     // input
//     getline(cin, str);
//     // print
//     cout << str;
//     return 0;
// }

// ____________________________________________________________________________________

// #include <iostream>
// #include <string>
// using namespace std;
// int main()
// {
//     string str;
//     getline(cin, str);                          // Hindustan Times
//     cout << "Length: " << str.length() << endl;  // 15
//     cout << "Is Empty: " << str.empty() << endl;  // 0
//     str.push_back('A');                    // Hindustan TimesA
//     cout << str<< endl;                    
//     str.pop_back();                        // Hindustan Times      
//     cout << str << endl;
//     cout << str.substr(0, 6) << endl;  // substr from index 0 to string of length 6 -> Hindus
//     cout << str.substr(1, 3) << endl;  // substr from index 1 to string of length 3 -> ind
//     cout << str << endl; // no change in original string  -> Hindustan Times
//     return 0;
// }

// ____________________________________________________________________________________

// #include <iostream>
// #include <string>
// using namespace std;
// int main()
// {
//     string a = "Love";
//     string b = "Lover";
//     if(a.compare(b) == 0)
//     {
//         cout << "a and b are exactly the same strings." << endl;
//     }
//     else
//     {
//         cout << "a and b are not same." << endl;
//     }
//     return 0;
// }

// ____________________________________________________________________________________

// #include <iostream>
// #include <string>
// using namespace std;
// int main()
// {
//     string a = "Love";
//     string b = "Love";
//     if(a.compare(b) == 0)
//     {
//         cout << "a and b are exactly the same strings." << endl;
//     }
//     else
//     {
//         cout << "a and b are not same." << endl;
//     }
//     return 0;
// }

// ____________________________________________________________________________________

// #include <iostream>
// #include <string>
// using namespace std;

// bool compareString(string a, string b)
// {
//     if(a.length() != b.length())
//     {
//         return false;
//     }
//     else
//     {
//         for(int i=0; i<a.length(); i++)
//         {
//             if(a[i] != b[i])
//             {
//                 return false;
//             }
//         }
//     }
//     return true;
// }

// int main()
// {
//     string a = "Love";
//     string b = "Lover";
//     cout << compareString(a, b) << endl;
//     return 0;
// }

// ____________________________________________________________________________________

// #include <iostream>
// #include <string>
// using namespace std;
// int main()
// {
//     string x = "abcd";
//     string y = "bcda";
//     cout << x.compare(y) << endl;   // gives -1 as a < b

//     string q = "cbcd";
//     string r = "bcda";
//     cout << q.compare(r) << endl;   // gives 1 as c > b

//     string s = "bbbb";
//     string t = "bbbba";
//     cout << s.compare(t) << endl;   // gives -1 as len(s) < len(t)

//     return 0;
// }

// If char of string 1 is less than that of string 2 we get a negative value.
// If char of string 1 is greater than that of string 2 we get a positive value.

// ____________________________________________________________________________________

// #include <iostream>
// #include <string>
// using namespace std;
// int main()
// {
//     string sentence = "Toh kaise hain aap log?";
//     string target = "kaise";
//     cout << sentence.find(target) << endl;    // gives starting index of target if found -> 4

//     string target2 = "everyone";
//     cout << sentence.find(target2) << endl;    // gives garbage value if not found

//     // to print something instead of garbage value
//     string target3 = "idhar";
//     if(sentence.find(target3) == string::npos)  // npos means not found
//     {
//         cout << "Not found" << endl;
//     }
//     return 0;
// }

// ____________________________________________________________________________________

// #include <iostream>
// #include <string>
// using namespace std;
// int main()
// {
//     string str = "This is my first message";
//     string word = "Manan";

//     str.replace(0, 4, word);  // starting index, replacing length, char length to be replaced
//     cout << str << endl;      // Manan is my first message.

//     string sec = "second";
//     str.replace(12, 5, sec);
//     cout << str << endl;      // Manan is my second message.
//     return 0;
// }

// ____________________________________________________________________________________

#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    str.erase(0, 4);   // erases (starting index, length to be erased)
    cout << str << endl;
    return 0;
}