/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:15:48 by mwojtcza          #+#    #+#             */
/*   Updated: 2025/04/07 12:15:48 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Brain.hpp"

class Animal
{
    protected:
        std::string type;
    public:
        // constructors && destructors
        Animal();
        Animal(Animal const &copy);
        virtual ~Animal();

        // operators
        Animal &operator=(Animal const &other);

        // getters && setters
        std::string getType() const;
        void        setType(std::string type);

        // member functions
        virtual void makeSound() const;
		virtual Brain *getBrain() const = 0;

};