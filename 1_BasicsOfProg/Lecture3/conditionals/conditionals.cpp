#include <iostream>
using namespace std;
int main()
{
    int score;
    cout << "Enter the score: " << endl;
    cin >> score;
    if(score < 300)
    {
        cout << "India Wins!" << endl; 
    }
    else
    {
        cout << "Pak wins!" << endl;
    }
    return 0;
}