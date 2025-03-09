// ⭐⭐Refer: https://en.cppreference.com/w/cpp/container/unordered_map⭐⭐

#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
    // creation
    unordered_map<string, int> m;

    // insertion method 1
    pair<string, int>p = make_pair("Scorpio", 9);
    m.insert(p);

    // insertion method 2
    pair<string, int> p2("alto", 2);
    m.insert(p2);

    // insertion method 1
    m["fortuner"] = 10;


    // access
    cout << m.at("alto") << endl;   // 2
    cout << m.at("Scorpio") << endl; // 9
    cout << m["fortuner"] << endl; // 10

    // search
    cout << m.count("Scorpio") << endl; // 1 as Scorpio is present
    cout << m.count("Innova") << endl; // 1 as Innova is absent

    // search method 2
    if(m.find("fortuner") != m.end())  // fortuner find karte karte map ke end tak nahi pahuche then present hai
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }    

    // size of map
    cout << m.size() << endl; // prints 3 as 3 entries(fortuner, alto, scorpio)
    cout << m["hummer"] << endl;  // prints 0 as not found, but creates an entry of hummer and assigns 0 to it
    cout << m.size() << endl; // prints 4 as 4 entries(fortuner, alto, scorpio, hummer)

    // check if empty
    if(m.empty()) cout << "Map is empty!" << endl;
    else cout << "Map is not empty!" << endl;

    // iterating through the map
    for(auto i: m)
    {
        cout << i.first << " -> " << i.second << endl;
    }

    return 0;
}