//Pre/Post -> Increment/Decrement Operators
// a++ -> first value of a is printed and then incremented. (POST-INCREMENT)
// ++a -> first value of a is incremented and then printed. (PRE-INCREMENT)
// a-- -> first value of a is printed and then decremented. (POST-DECREMENT)
// --a -> first value of a is decremented and then printed. (PRE-DECREMENT)

#include <iostream>
using namespace std;
int main()
{
    //POST-INCREMENT
    int a = 11;
    cout<<a++<<endl;   // prints 11
    cout<<a<<endl;     // prints 12

    //PRE-INCREMENT
    int b = 11;
    cout<<++b<<endl;   // prints 12
    cout<<b<<endl;     // prints 12

    // POST-DECREMENT
    int c = 11;
    cout<<c--<<endl;   // prints 11
    cout<<c<<endl;     // prints 10

    //PRE-DECREMENT
    int d = 11;
    cout<<--d<<endl;   // prints 10
    cout<<d<<endl;     // prints 10

    //SOME OTHER EXPERIMENTS
    int e = 5;
    cout<<(++e)*(++e);  //GIVES 49
    // IN PRE-INCREMENT OPERATORS (OPERATOR PRECEDENCE) THE VALUE IS INCREMENTED FIRST BUT NOT
    // STORED OR PRINTED UNTIL ALL OPERATIONS ON THAT VARIABLE ARE PERFORMED.
    // So, ++e becomes 6.
    // The 2nd ++e becomes 7 and stored as it is the last operation.
    // Basically the memory location of e is same, first e becomes 6 and then is updated to 7.
    // Therefore, the value of e becomes 7.
    // 7*7=49
}