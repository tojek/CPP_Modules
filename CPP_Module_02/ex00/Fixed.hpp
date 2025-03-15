#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &copy);
		Fixed &operator = (const Fixed &operator);
		~Fixed();
	private:
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};


#endif
