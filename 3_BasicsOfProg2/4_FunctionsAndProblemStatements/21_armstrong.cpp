// Write a program to check if the entered number by the user is an armstrong number or not.
// Armstrong number is the number which is equal to the sum of the cubes of it's digits. Ex: 0,1,153,370,371,407
// say 153 = (1*1*1) + (5*5*5) + (3*3*3) = 1+125+27=153

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int num, rem, total = 0, temp, count = 0;
    cout << "Enter a number: ";
    cin >> num;
    temp = num;
    
    while (temp != 0) {
        temp = temp / 10;
        count++;
    }

    temp = num; // Reset temp to the original number

    while (temp > 0) {
        rem = temp % 10;
        total = total + pow(rem, count);
        temp = temp / 10;
    }

    if (num == total) {
        cout << num << " is an Armstrong number." << endl;
    } else {
        cout << num << " is not an Armstrong number." << endl;
    }

    return 0;
}