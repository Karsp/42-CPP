#ifndef CHARACTER
# define CHARACTER

# include <iostream>
# include <map>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class AMateria;


class Character
{
	private:
		std::string _name;
		AMateria* _bag[4];
		int		_size;
		std::map<std::string, AMateria*> _dropped_bag;

	public:
		Character();
		Character(const std::string name);
		Character(const Character& other);
		Character& operator=(const Character& rhs);
		virtual ~Character() {}
	
		virtual std::string const & getName() const;
		virtual void 				equip(AMateria* m);
		virtual void 				unequip(int idx);
		virtual void 				use(int idx, ICharacter& target);
};

#endif