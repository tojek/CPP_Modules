/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:15:55 by mwojtcza          #+#    #+#             */
/*   Updated: 2025/04/07 12:15:55 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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