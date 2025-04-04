#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat(Cat const &copy);
        virtual ~Cat();

        Cat &operator=(Cat const &other);

        std::string getType() const;

        void makeSound() const;
};