#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &copy);
		Fixed &operator = (const Fixed &fixed_operator);
		~Fixed();

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
	private:
		int					value;
		static const int	fractional_bits = 8;
};

#endif
