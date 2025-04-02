#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:
		Brain *brain;
    public:
        Dog();
        Dog(Dog const &copy);
        virtual ~Dog();

        Dog &operator=(Dog const &other);

		std::string getType() const;
		Brain *getBrain() const;

        void makeSound() const;
};