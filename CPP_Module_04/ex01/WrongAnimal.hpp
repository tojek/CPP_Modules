#pragma once

#include <iostream>

class WrongAnimal
{
    protected:
        std::string type;
    public:
        // constructors && destructors
        WrongAnimal();
        WrongAnimal(std::string type);
        WrongAnimal(WrongAnimal const &copy);
        virtual ~WrongAnimal();

        // operators
        WrongAnimal &operator=(WrongAnimal const &other);

        // getters && setters
        std::string getType() const;
        void        setType(std::string type);

        // member functions
        virtual void makeSound() const;

};