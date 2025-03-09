// Another example of abstract class and abstract function (pure virtual function)
#include <iostream>
using namespace std;

class Bank
{
    public:
        float a, interest, totBalance;
        int accountNo;
        virtual void calcInterest(float balance) = 0;

        void showInfo(int a)
        {
            accountNo = a;
            cout << "Your account number is: " << accountNo << endl;
        }
};

class Sbi: public Bank
{
    public:
        void calcInterest(float balance)
        {
            a = balance;
            interest = a * 5 / 100;
            totBalance = a + interest;
            cout << "The interest is: " << interest << endl;
            cout << "Your total balance is: " << totBalance << endl;
        }
};

int main()
{   
    Sbi obj;
    obj.showInfo(102);
    obj.calcInterest(500);
    return 0;
}