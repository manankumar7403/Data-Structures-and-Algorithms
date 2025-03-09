/*
// Debug the following code:
#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap;
    myMap[1] = "One";
    myMap[2] = "Two";
    myMap[3] = "Three";

    for (auto it = myMap.begin(); it != myMap.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
        if (it->first == 2) {
            myMap.erase(it);
        }
    }

    return 0;
}
*/
// _______________________________________________________________________________________________________________

// SOLUTION
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> myMap;
    myMap[1] = "One";
    myMap[2] = "Two";
    myMap[3] = "Three";

    for (auto it = myMap.begin(); it != myMap.end();) {
        cout << it->first << ": " << it->second << endl;
        if (it->first == 2) {
            it = myMap.erase(it);
        }
        else
        {
            it++;
        }
    }

    for(auto i: myMap)
    {
        cout << i.first << " -> " << i.second << endl; 
    }

    return 0;
}


// ⭐⭐IMPORTANT⭐⭐
/*
The difference between `i.first` and `i->first` is based on whether `i` is an object or an iterator (or pointer).
Here's a clear distinction:

### `i.first`

- **Direct Member Access**: This syntax is used when `i` is an object of a class or struct that has a member named
`first`.
- **Example**:
  std::pair<int, std::string> p = {1, "One"};
  std::cout << p.first << std::endl;  // Accessing the first element of the pair directly

### `i->first`

- **Pointer/Iterator Member Access**: This syntax is used when `i` is a pointer to an object (or an iterator acting
like a pointer) that has a member named `first`. The `->` operator dereferences the pointer and accesses the member.
- **Example**:
  std::map<int, std::string> myMap = {{1, "One"}, {2, "Two"}};
  auto it = myMap.begin();  // 'it' is an iterator pointing to a std::pair<const int, std::string>
  std::cout << it->first << std::endl;  // Accessing the first element of the pair through the iterator

### In Context
In your code:

- **Range-based for loop**:
  for (auto i : myMap) {
      std::cout << i.first << " -> " << i.second << std::endl;
  }
  Here, `i` is a `std::pair<const int, std::string>` because `myMap` is a `std::map`. Thus, you use `i.first` to
  access the first element of the pair.

- **Iterator-based loop**:
  for (auto it = myMap.begin(); it != myMap.end();) {
      std::cout << it->first << ": " << it->second << std::endl;
      if (it->first == 2) {
          it = myMap.erase(it);
      } else {
          ++it;
      }
  }
  Here, `it` is an iterator (specifically, a `std::map<int, std::string>::iterator`). To access the elements of the
  `std::pair` that the iterator points to, you use `it->first` and `it->second`.

### Summary

- **Use `i.first`** when `i` is a direct object.
- **Use `i->first`** when `i` is a pointer or an iterator to the object.
*/