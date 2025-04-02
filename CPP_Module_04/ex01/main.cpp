#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Basic Array Tests ===" << std::endl;
    int arraySize = 4;
    Animal* animals[arraySize];

    // Fill array with half dogs and half cats
    for (int i = 0; i < arraySize; i++) {
        if (i < arraySize / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    // Test sounds
    for (int i = 0; i < arraySize; i++)
        animals[i]->makeSound();

    // Cleanup array
    for (int i = 0; i < arraySize; i++)
        delete animals[i];

    std::cout << "\n=== Deep Copy Tests ===" << std::endl;
    // Test deep copy
    Dog* dog1 = new Dog();
    dog1->getBrain()->setIdea(0, "I love bones!");

    // Test copy constructor
    Dog* dog2 = new Dog(*dog1);
    // Test assignment operator
    Dog dog3;
    dog3 = *dog1;

    // Verify ideas were deeply copied
    std::cout << "Original dog idea: " << dog1->getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied dog (constructor) idea: " << dog2->getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied dog (assignment) idea: " << dog3.getBrain()->getIdea(0) << std::endl;

    // Change original dog's idea to verify deep copy
    dog1->getBrain()->setIdea(0, "I love sleeping!");
    std::cout << "\nAfter changing original dog's idea:" << std::endl;
    std::cout << "Original dog idea: " << dog1->getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied dog (constructor) idea: " << dog2->getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied dog (assignment) idea: " << dog3.getBrain()->getIdea(0) << std::endl;

    // Cleanup
    delete dog1;
    delete dog2;

    return 0;
}