#include <iostream>
using namespace std;

class abc
{
    int x;
    int *y;
    const int z; // const variables ko initialize karne ke baad re-assign nhi kar sakte 

public:

    // constructor old style
    // abc(int _x, int _y, int _z = 0, int _u = 6)  // ye _z aur _u default arguments hai kyuki niche se bas (1,2) ki value aa rhi hai
    // {
    //     x = _x;
    //     y = new int (_y);
    //     z = _z;     //gives error, old style ctor ke andar z re-assign nhi kar sakte kyuki z const hai -> use init list suppose z ko init karna chahte the 0 se
    // }

    // Initialization List: New style to create constructors
    // abc(int _x, int _y, int _z=0):x(_x), y(new int (_y)), z(_z) {} // z(_z) -> z initialize ho rha dobara se idhar unlike old ctor
    
    // {} brackets ke andar likh sakte hai jaise..

    abc(int _x, int _y, int _z=0):x(_x), y(new int (_y)), z(_z) {
        cout << "In init List" << endl;
        // z = 10;  // gives error kyuki re-assign(modify) nhi kar sakte const variable ko
        *y = *y * 10;
    }

    int getX() const // now it won't modify x value in this function
    {
      //x = 10;
        return x;
    }
    void setX(int _val)
    {
        x = _val;
    }

    int getY() const
    {
        return *y;
    }
    void setY(int _val)
    {
        *y = _val;
    }

    int getZ() const
    {
        return z;
    }
};

void printABC(const abc &a)
{
    cout << a.getX() << " " << a.getY() << " " << a.getZ() << endl;
}

int main()
{
    abc a(1, 2, 3);
    printABC(a);
    return 0;
}
