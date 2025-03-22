#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
    private:
        std::string type;
    public:
        Cat();
        Cat(Cat const &copy);
        virtual ~Cat();
        
}