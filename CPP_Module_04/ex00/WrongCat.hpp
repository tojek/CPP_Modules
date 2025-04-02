#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{

    public:
        WrongCat();
        WrongCat(WrongCat const &copy);
        virtual ~WrongCat();

        WrongCat &operator=(WrongCat const &other);

		std::string getType() const;

        void makeSound() const;
};