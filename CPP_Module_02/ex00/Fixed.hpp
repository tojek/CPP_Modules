/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:05:54 by mwojtcza          #+#    #+#             */
/*   Updated: 2025/03/19 14:07:16 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &copy);
		Fixed &operator = (const Fixed &fixed_operator);
		~Fixed();

		int		getRawBits( void ) const;
		void		setRawBits( int const raw );
	private:
		int					value;
		static const int	fractional_bits = 8;
};

#endif
