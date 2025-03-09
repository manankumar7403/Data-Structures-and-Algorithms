#include <iostream>
using namespace std;
int main()
{
    int val;
    cout<<"Enter a value: "<<endl;;
    cin>>val;

    switch(val)
    {
        case 1: cout<<"Manan";
        break;
        case 2: cout<<"Kumar";
        break;
        case 3: cout<<"Cristiano";
        break;
        case 4: cout<<"R9";
        break;
        default: cout<<"Meh.."; 
    }
}

/*
In C++, a `switch` statement is typically used to perform different actions based on the
value of an integer or an enumerated type. The condition or expression inside the `switch`
statement is used to determine which case label to execute. The expression must result in an
integral value, such as an integer or an enumerated type.

You cannot use just any arbitrary condition as the expression in a `switch` statement.
The condition must be one that results in an integral value (integer, character, or
enumerated type). The following are some valid expressions for a `switch` statement:

1. Integer variables or constants:
   ```cpp
   int x = 5;
   switch (x) {
       case 1:
           // Code for case 1
           break;
       case 5:
           // Code for case 5
           break;
       default:
           // Default code
   }
   ```

2. Characters:
   ```cpp
   char ch = 'A';
   switch (ch) {
       case 'A':
           // Code for case 'A'
           break;
       case 'B':
           // Code for case 'B'
           break;
       default:
           // Default code
   }
   ```

3. Enumerated types:
   ```cpp
   enum Color { RED, GREEN, BLUE };
   Color color = GREEN;
   switch (color) {
       case RED:
           // Code for case RED
           break;
       case GREEN:
           // Code for case GREEN
           break;
       default:
           // Default code
   }
   ```

You cannot use expressions that result in floating-point values, objects, or non-integral
types as the condition in a `switch` statement. If you need to perform actions based on other
conditions, you may need to use `if` or `else if` statements.

In C++17 and later, you can use `if` with initializer (if you have a more complex condition
to evaluate before the `switch` statement) to create more flexible conditions:

```cpp
if (condition) {
    switch (x) {
        // cases
    }
} else {
    // code for a different condition
}
```

Always ensure that the condition you use in a `switch` statement is appropriate for the
task you want to accomplish.
*/