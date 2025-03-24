#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
    private:
        std::string type;
    public:
        Cat();
        Cat(std::string const type);
        Cat(Cat const &copy);
        virtual ~Cat();

        Cat &operator=(Cat const &other);

        std::string getType() const;
        void        setType(std::string type);

        void makeSound() const;
};