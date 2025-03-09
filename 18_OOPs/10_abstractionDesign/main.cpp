#include <iostream>
#include "bird.h"
using namespace std;

void birdDoesSomething(Bird *&bird)
{
    bird->eat();
    bird->fly();
    bird->eat();
}

int main()
{
    // Bird *bird = new Sparrow();   // Bird interface hai usse hi kuch call kar sakte
    // birdDoesSomething(bird);
    // Sparrow *sp = new Sparrow();  // koi specific object bana ke call nahi kar sakte
    // birdDoesSomething(sp);  // gives error (cannot bind non-const lvalue ref of type Bird*& to rvalue of type Bird*)
    
    // Bird *bird = new Eagle();
    // birdDoesSomething(bird);

    Bird *bird = new Pigeon();
    birdDoesSomething(bird);

    return 0;
}

// ⭐⭐⭐⭐ KISI BHI ABSTRACT KA YA C++ KE INTERFACE KA OBJECT NAHI BAN SAKTA
// Example:
// Bird *b2 = new Bird();