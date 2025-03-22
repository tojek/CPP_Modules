#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
    private:
        std::string type;
    public:
        Dog();
        Dog(std::string type);
        Dog(Dog const &copy);
        virtual ~Dog();

        Dog &operator=(Dog const &other);

        std::string getType() const;
        void        setType(std::string type);

        void makeSound() const;
}