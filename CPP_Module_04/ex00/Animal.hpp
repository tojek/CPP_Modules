#pragma once

#include <iostream>

class Animal
{
    protected:
        std::string type;
    public:
        // constructors && destructors
        Animal();
        Animal(std::string type);
        Animal(Animal const &copy);
        virtual ~Animal();

        // operators
        Animal &operator=(Animal const &other);

        // getters && setters
        std::string getType() const;
        void        setType(std::string type);

        // member functions
        virtual void makeSound() const;

};