#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
		Brain *brain;
    public:
        Cat();
        Cat(Cat const &copy);
        virtual ~Cat();

        Cat &operator=(Cat const &other);

		std::string getType() const;
		Brain *getBrain() const;

        void makeSound() const;
};