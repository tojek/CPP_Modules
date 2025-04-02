#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
#include <iostream>

int main()
{
     //Animal  *animal = new Animal();
	 Animal  *cat = new Cat();
	 Animal  *dog = new Dog();

	 // animal->makeSound();
	 cat->makeSound();
	 dog->makeSound();

	 // delete animal;
	 delete cat;
	 delete dog;

	 return (0);
}