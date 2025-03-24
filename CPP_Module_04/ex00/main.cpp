#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	const WrongAnimal *meta2 = new WrongAnimal();
	const WrongAnimal *i2 = new WrongCat();

	std::cout << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();
	i2->makeSound();
	meta2->makeSound();

	delete meta;
	delete j;
	delete i;
	delete meta2;
	delete i2;
	return (0);
}