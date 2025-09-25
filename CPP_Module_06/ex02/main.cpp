#include "Base.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Type Identification Test ===" << std::endl;

    // Generate 10 random instances and identify them
    for (int i = 0; i < 10; i++)
    {
        std::cout << "\nTest " << (i + 1) << ":" << std::endl;

        Base* ptr = generate();

        std::cout << "Identify by pointer: ";
        identify(ptr);

        std::cout << "Identify by reference: ";
        identify(*ptr);

        delete ptr;
    }

    std::cout << "\n=== Manual Type Test ===" << std::endl;

    // Test with known types
    A* a = new A();
    B* b = new B();
    C* c = new C();

    std::cout << "\nTesting A:" << std::endl;
    std::cout << "By pointer: ";
    identify(a);
    std::cout << "By reference: ";
    identify(*a);

    std::cout << "\nTesting B:" << std::endl;
    std::cout << "By pointer: ";
    identify(b);
    std::cout << "By reference: ";
    identify(*b);

    std::cout << "\nTesting C:" << std::endl;
    std::cout << "By pointer: ";
    identify(c);
    std::cout << "By reference: ";
    identify(*c);

    delete a;
    delete b;
    delete c;

    return 0;
}