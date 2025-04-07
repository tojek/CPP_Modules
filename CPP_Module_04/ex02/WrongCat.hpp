/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:16:57 by mwojtcza          #+#    #+#             */
/*   Updated: 2025/04/07 12:16:58 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    private:
        std::string type;
    public:
        WrongCat();
        WrongCat(WrongCat const &copy);
        virtual ~WrongCat();

        WrongCat &operator=(WrongCat const &other);

		std::string getType() const;

        void makeSound() const;
};