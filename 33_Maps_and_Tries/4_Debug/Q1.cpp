/*
#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap;
    myMap[1] = "Apple";
    myMap[2] = "Banana";
    myMap[3] = "Orange";

    int key = 3;
    if (myMap.find(key)) {
        std::cout << "Key " << key << " exists." << std::endl;
    } else {
        std::cout << "Key " << key << " does not exist." << std::endl;
    }

    return 0;
}
*/

// __________________________________________________________________________________________________________________

#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> myMap;
    myMap[1] = "Apple";
    myMap[2] = "Banana";
    myMap[3] = "Orange";

    int key = 3;
    if (myMap.find(key) != myMap.end())
    {
        cout << "Key " << key << " exists." << endl;
    }
    else
    {
        cout << "Key " << key << " does not exist." << std::endl;
    }

    for(auto i: myMap)
    {
        cout << i.first << " -> " << i.second << endl;
    }

    return 0;
}