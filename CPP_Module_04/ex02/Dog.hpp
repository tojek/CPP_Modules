/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:16:40 by mwojtcza          #+#    #+#             */
/*   Updated: 2025/04/07 12:16:40 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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