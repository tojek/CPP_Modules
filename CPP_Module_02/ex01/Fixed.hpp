#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &copy);
		Fixed &operator = (const Fixed &fixed_operator);
		~Fixed();

		friend std::ostream &operator << (std::ostream &out, const Fixed &fixed);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
	private:
		int					value;
		static const int	fractional_bits = 8;
};

#endif
