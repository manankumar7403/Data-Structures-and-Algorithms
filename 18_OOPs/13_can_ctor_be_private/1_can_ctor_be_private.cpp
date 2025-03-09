/*
#include <iostream>
using namespace std;

class Box
{
    int width;

    public:
        // Constructor
        Box(int _w):width(_w) {};

        int getWidth() const
        {
            return width;
        }

        void setWidth(int _val)
        {
            width = _val;
        }
};

int main()
{
    Box b(5);
    cout << b.getWidth() << endl;
    return 0;
}
// This works fine
*/
// __________________________________________________________________________________________________

// Now let's try making the ctor private

/*
#include <iostream>
using namespace std;

class Box
{
    int width;
    // Constructor
    Box(int _w):width(_w) {};
    
    public:
        int getWidth() const
        {
            return width;
        }

        void setWidth(int _val)
        {
            width = _val;
        }
};

int main()
{
    return 0;
}
*/
// If we write this

// Box b(5);
//     cout << b.getWidth() << endl;

// in the main function, then if ctor is private, we get an error -> implicit declaration of ctor -> private
// otherwise, the code compiles without an error.

// ⭐⭐⭐⭐ So, YES, A CONSTRUCTOR COULD BE MADE PRIVATE ⭐⭐⭐⭐
// BUT WHAT IS THE USE CASE?

// ____________________________________________________________________________________________________

// Agar use case yeh hai ki Box ka koi bhi directly object na bana paye -> toh Box class ke ctor ko private
// kar do
// Box bola ki mujhe sirf BoxFactory naame ki class initialize kar sakta hai, wahi mere name ke objects bana
// sakta hai par koi aur nahi kar sakta, na hi main kar sakta coz Box ne friend sirf BoxFactory ko declare
// kiya hai

#include <iostream>
using namespace std;

class Box
{
    int width;
    // Constructor
    Box(int _w):width(_w) {};
    
    public:
        int getWidth() const
        {
            return width;
        }

        // void setWidth(int _val)
        // {
        //     width = _val;
        // }
    
        friend class BoxFactory;
};

class BoxFactory
{
    int count;

    public:
        Box getABox(int _w)
        {
            ++count;
            return Box(_w);
        }
};

int main()
{
    BoxFactory bfact;
    Box b = bfact.getABox(5);
    cout << b.getWidth() << endl;
    return 0;
}
