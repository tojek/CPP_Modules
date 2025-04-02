#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        ideas[i] = "Empty idea";
}

Brain::Brain(const Brain& other)
{
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        ideas[i] = other.ideas[i];
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Brain assignment operator called" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; i++)
            ideas[i] = other.ideas[i];
    }
    return *this;
}

std::string Brain::getIdea(int index)
{
	if (index < 0 || index >= 100)
		return ("Invalid index");
    return this->ideas[index];
}

void Brain::setIdea(int index, const std::string idea)
{
    if (index >= 0 && index < 100)
        ideas[index] = idea;
}
