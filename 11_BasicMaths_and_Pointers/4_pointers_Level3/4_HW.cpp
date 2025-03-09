// 🔴🔴🔴🔴 Returning a pointer to a local variable (here, 'a' of type integer) 🔴🔴🔴🔴

#include <iostream>
using namespace std;

int* solve()
{
    int a = 5;
    int* ans = &a;
    return ans;
}

int main()
{
    cout << solve() << endl;
    return 0;
}
/*
The solve function is declared to return an integer pointer (int*). Inside the function, a local variable a
is declared and assigned the value of 5. Then, a pointer ans is created, pointing to the address of a.
Finally, this pointer ans is returned from the function.

The problem with this code is that it returns a pointer to a local variable (a). Once the solve function
exits, the local variable a goes out of scope, and its memory is no longer guaranteed to be valid.
Therefore, attempting to use the pointer returned by solve in the main function can lead to undefined behavior.

In the main function, the pointer returned by solve is printed using cout. This can lead to unexpected results,
as the memory location being pointed to (&a) is no longer guaranteed to contain a valid value.

To fix this issue, you should allocate memory dynamically using new to create an integer on the heap.
This ensures that the memory persists beyond the scope of the function. However, in practice, it's better to
avoid dynamic memory allocation when not necessary and prefer other solutions like passing variables by
reference if possible.
*/