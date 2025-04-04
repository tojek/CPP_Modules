#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog();
        Dog(Dog const &copy);
        virtual ~Dog();

        Dog &operator=(Dog const &other);

        std::string getType() const;

        void makeSound() const;
};