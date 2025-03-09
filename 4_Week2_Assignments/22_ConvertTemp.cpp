#include <iostream>
#include <vector>
using namespace std;

vector<double> convertTemperature(double celsius)
{
        double k = celsius + 273.15;
        double f = celsius * 1.80 + 32.00;

        vector<double> v;
        v.push_back(k);
        v.push_back(f);
        return v;
}

int main()
{
    double celsius;
    cout<<"Enter the temperature in Celsius: ";
    cin>>celsius;

    vector<double> result = convertTemperature(celsius);

    cout << "Kelvin: " << result[0] << endl;
    cout << "Fahrenheit: " << result[1] << endl;
    return 0;
}