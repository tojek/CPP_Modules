#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
    private:
        std::string type;
    public:
        Dog();
        Dog(Dog const &copy);
        virtual ~Dog();

        Dog &operator=(Dog const &other);

        void makeSound() const;
};