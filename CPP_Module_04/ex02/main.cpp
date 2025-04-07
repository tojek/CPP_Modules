/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:16:43 by mwojtcza          #+#    #+#             */
/*   Updated: 2025/04/07 12:16:44 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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