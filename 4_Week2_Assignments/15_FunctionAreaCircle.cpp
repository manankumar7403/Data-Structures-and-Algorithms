#include <iostream>
using namespace std;

float circleArea(float radius)
{
    float area = 3.14 * radius * radius;
    return area;
}

int main()
{
    float radius;
    cout<<"Enter the radius of the circle: ";
    cin>>radius;
    float area = circleArea(radius);
    cout<<"Area of the circle is: "<<area<<endl;
    return 0;
}