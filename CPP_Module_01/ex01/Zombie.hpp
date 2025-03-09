#ifndef ZOMBIEHORD_HPP
# define ZOMBIEHORD_HPP

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie( void );
		Zombie( std::string name );
		~Zombie();
		void		announce( void );
		void		setName( std::string name );

};

Zombie* zombieHorde( int N, std::string name );

#endif
