#ifndef _HARL_HPP
# define _HARL_HPP
# include <iostream>
	
enum levels
{
	DEBUG,
	INFO, 
	WARNING, 
	ERROR
};

class Harl
{
	private:
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
		void	def( void );
	public:
		Harl();
		Harl(std::string level);
		~Harl();
		void complain( std::string level );
		void filter_complain(std::string level);
};


#endif