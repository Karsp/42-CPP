#ifndef _HARL_HPP
# define _HARL_HPP
# include <iostream>
	
class Harl
{
	private:
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
	public:
		Harl(/* args */);
		~Harl();
		void complain( std::string level );
};


#endif