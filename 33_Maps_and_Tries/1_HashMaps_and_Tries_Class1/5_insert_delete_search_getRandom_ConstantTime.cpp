/*
https://www.geeksforgeeks.org/design-a-data-structure-that-supports-insert-delete-search-and-getrandom-in-constant-time/
Design a data structure that supports the following operations in O(1) time.

insert(x): Inserts an item x to the data structure if not already present.
remove(x): Removes item x from the data structure if present. 
search(x): Searches an item x in the data structure.
getRandom(): Returns a random element from the current set of elements 
We can use hashing to support the first 3 operations in O(1) time. How to do the 4th operation? The idea is to use a
resizable array (ArrayList in Java, vector in C) together with hashing. Resizable arrays support insert in O(1)
amortized time complexity. To implement getRandom(), we can pick a random number from 0 to size-1 (size is the number of
current elements) and return the element at that index. The hash map stores array values as keys and array indexes as
values.

Following are detailed operations:
1) insert(x): 
Check if x is already present by doing a hash map lookup. 
If not present, then insert it at the end of the array. 
In the hash table, x is added as the key, and the last array index as the index.

2) remove(x):
Check if x is present by doing a hash map lookup. 
If present, then find its index and remove it from a hash map. 
Swap the last element with this element in an array and remove the last element. 
Swapping is done because the last element can be removed in O(1) time. 
Update index of the last element in a hash map.

3) getRandom(): 
Generate a random number from 0 to last index. 
Return the array element at the randomly generated index.

4) search(x):
Do a lookup for x in hash map.
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class constantTime
{
    vector<int> arr;
    unordered_map<int, int> Map;

    public:
        void insert(int x)
        {
            if(Map.find(x) != Map.end())   // element already present
            {
                return;
            }
            int index = arr.size();
            arr.push_back(x);
            Map.insert({x, index});
        }

        void remove(int x)
        {
            if(Map.find(x) == Map.end())
            {
                return;
            }
            int index = Map.at(x);
            Map.erase(x);
            if(index != arr.size()-1)
            {
                int last = arr.size()-1;
                swap(arr[index], arr[last]);
                Map[arr[index]] = index;
            }
            arr.pop_back();
        }

        int search(int x)
        {
            if(Map.find(x) != Map.end())
            {
                return Map.at(x);
            }
            return -1;
        }

        int getRandom()
        {
            srand(time(NULL));  
            int random_index = rand() % arr.size();
            return arr[random_index];
        }
};

int main()
{
    constantTime ct;
    ct.insert(10);
    ct.insert(20);
    ct.insert(30);
    ct.insert(40);
    cout << ct.search(20) << endl;
    ct.remove(40);
    ct.insert(50);
    cout << ct.search(40) << endl;
    cout << ct.search(50) << endl;
    cout << ct.getRandom() << endl;
    return 0;
}

// TC -> O(1)
// SC -> O(n)

/*
The line of code srand(time(NULL)); is used to initialize the random number generator with a seed value based on the
current time.

Specifically:
srand() is a function that sets the seed for the random number generator. The seed is the starting point for the sequence
of pseudo-random numbers generated.
time(NULL) returns the current time in seconds since the Epoch (January 1, 1970, 00:00:00 UTC).
By using time(NULL) as the argument to srand(), the random number generator is seeded with a value that changes with each
execution of the program. This helps ensure that the sequence of random numbers generated will be different each time the
program runs.
Initializing the random number generator with a time-dependent seed like this is commonly done at the start of programs
that require random numbers, to ensure the random numbers are unpredictable. This is important for applications like games,
simulations, cryptography, etc. where you want the random numbers to be as random as possible.
*/