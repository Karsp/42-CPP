#ifndef CHARACTER
# define CHARACTER

# include <iostream>
# include "ICharacter.hpp"

class AMateria;

class Character
{
	public:
		virtual ~Character() {}
	
		virtual std::string const & getName() const = 0;
		virtual void 				equip(AMateria* m) = 0;
		virtual void 				unequip(int idx) = 0;
		virtual void 				use(int idx, ICharacter& target) = 0;
};

#endif