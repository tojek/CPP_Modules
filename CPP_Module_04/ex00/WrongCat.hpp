/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:15:43 by mwojtcza          #+#    #+#             */
/*   Updated: 2025/04/07 12:15:44 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{

    public:
        WrongCat();
        WrongCat(WrongCat const &copy);
        virtual ~WrongCat();

        WrongCat &operator=(WrongCat const &other);

		std::string getType() const;

        void makeSound() const;
};