// MACROS imporove readibility of the code
#include <iostream>
using namespace std;

#define PI 3.14159465  // Creation of MACROS -> doesn't take any space -> read by compiler at preprocessing
#define MAXX(x, y)(x > y ? x : y)

float circleArea(float r)
{
    return PI * r * r;
}

float circlePerimeter(float r)
{
    return 2 * PI * r;
}

int fun()
{
    int a = 6;
    int b = 17;
    int c = MAXX(a, b);
    return c;
}

int main()
{
    cout << circleArea(65.4) << endl;
    cout << circlePerimeter(65.4) << endl;
    cout << fun();

    return 0;
}