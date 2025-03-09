// https://www.geeksforgeeks.org/memset-in-cpp/

// Memset() is a C++ function. It copies a single character for a specified number of times to an
// object. It is useful for filling a number of bytes with a given value starting from a specific
// memory location. It is defined in <cstring> header file.

// Syntax:

// void* memset( void* str, int ch, size_t n);

// Memset() converts the value ch to unsigned char and copies it into each of the first n characters
// of the object pointed to by str[]. If the object is not trivially-copyable (e.g., scalar, array,
// or a C-compatible struct), the behavior is undefined. If n is greater than the size of the object
// pointed to by str, the behavior is undefined. 

// C++ program to demonstrate memset 
#include <cstring> 
#include <iostream> 
using namespace std; 

// Driver Code 
int main() 
{ 
	char str[] = "geeksforgeeks"; 
	memset(str, 't', sizeof(str)-1); 
	cout << str; 
	return 0; 
}

// did str-1 to remove the Ç symbol at the end of string which is used to mark the end of C-style
// strings.


// sizeof() determines the total size of the array (memory it is occupying), not the total elements.
// Example:
// int arr[10] = {1,2,3};
// sizeof(arr)/sizeof(int) = (4*10)/(4) = 10
