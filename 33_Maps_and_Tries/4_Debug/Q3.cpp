/*
#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap;
    myMap[1] = "Apple";
    myMap[2] = "Banana";
    myMap[3] = "Orange";

    int key = 4;
    std::cout << "Value for key " << key << ": " << myMap.at(key) << std::endl;

    return 0;
}
*/
// ___________________________________________________________________________________________________________

#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> myMap;
    myMap[1] = "Apple";
    myMap[2] = "Banana";
    myMap[3] = "Orange";

    int key = 4;
    if(myMap.find(key) != myMap.end())
    {
        cout << "Value for key " << key << ": " << myMap.at(key) << endl;
    }
    else
    {
        cout << "Key not present." << endl;
    }
    return 0;
}