#ifndef CHARACTER
# define CHARACTER

# include <iostream>
# include <map>
# include "ICharacter.hpp"
# include "AMateria.hpp"

# define BAG_SIZE 4

class AMateria;


class Character: public ICharacter
{
	private:
		std::string _name;
		AMateria** _bag;
		int		_size;
		// AMateria*  _dropped_bag;

	public:
		Character();
		Character(const std::string name);
		Character(const Character& other);
		Character& operator=(const Character& rhs);
		~Character();
	
		virtual std::string const & getName() const;
		virtual void 				equip(AMateria* m);
		virtual void 				unequip(int idx);
		virtual void 				use(int idx, ICharacter& target);
};

#endif