/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:42:00 by daviles-          #+#    #+#             */
/*   Updated: 2025/03/27 17:42:02 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define RESET   "\033[0m"
# define BLUE "\033[34m"
# define GREEN "\033[32m"
# define RED "\033[31m"
# define YELLOW "\033[0;33m" 

#include <cstring>
#include"Ice.hpp"
#include"Cure.hpp"
#include"Character.hpp"
#include"MateriaSource.hpp"




int main()
{
	std::cout << YELLOW <<  "========= SUBJECT TEST ===========" << RESET << std::endl;
	std::cout << YELLOW <<  "========= SUBJECT MAIN ===========" << RESET << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	std::cout << std::endl;
	src->learnMateria(new Cure());
	std::cout << std::endl;
	ICharacter* me = new Character("me");
	std::cout << std::endl;
	std::cout << std::endl;
	AMateria* tmp;
	std::cout << std::endl;
	tmp = src->createMateria("ice");
	std::cout << std::endl;
	me->equip(tmp);
	std::cout << std::endl;
	tmp = src->createMateria("cure");
	std::cout << std::endl;
	me->equip(tmp);
	std::cout << std::endl;
	ICharacter* bob = new Character("bob");
	std::cout << std::endl;
	me->use(0, *bob);
	std::cout << std::endl;
	me->use(1, *bob);

	std::cout << std::endl;
	std::cout << std::endl;
	// ================ MY TESTS =================
	
	std::cout << YELLOW <<  "========= MY TESTS ===========" << RESET << std::endl;
	std::cout << YELLOW <<  "========= ERROR HANDLING ===========" << RESET << std::endl;
	std::cout << YELLOW <<  "Lets create a materia source with only ice materias" << RESET << std::endl;

	MateriaSource* ms1 = new MateriaSource();
	ms1->learnMateria(new Ice());
	ms1->learnMateria(new Ice());
	ms1->learnMateria(new Ice());
	ms1->learnMateria(new Ice());
	std::cout << std::endl;
	AMateria* a = new Cure();
	std::cout << YELLOW <<  "Now lets try to add a 5th materia" << RESET << std::endl;
	ms1->learnMateria(a);
	std::cout << YELLOW <<  "As expected, you cannot add a 5th materia" << RESET << std::endl;
	std::cout << std::endl;
	delete a;
	delete ms1;
	std::cout << std::endl;
	std::cout << std::endl;

	// =======================================================================
	std::cout << YELLOW <<  "Now lets use these materias, of course, in an invalid manner" << RESET << std::endl;

	AMateria* m1 = new Ice();
	me->equip(m1);
	std::cout << YELLOW <<  "Let's use our famous materia at index -4 and at index 172, and lets unequip them aswell" << RESET << std::endl;
	me->use(-4, *bob);
	me->use(172, *bob);
	me->unequip(-4);
	me->unequip(172);
	std::cout << std::endl;

	std::cout << YELLOW <<  "Lets also equip more than 4 materias" << RESET << std::endl;

	AMateria* m3 = new Ice();
	AMateria* m4 = new Cure();
	me->equip(m3);
	me->equip(m4);
	delete m4;
	std::cout << std::endl;

	std::cout << YELLOW <<  "Lets try this: let BOB, an innocent NPC, try to equip an already equipped materia" << RESET << std::endl;
	bob->equip(m1);

	delete me;
	delete bob;
	delete src;
	std::cout << std::endl;
	std::cout << std::endl;


	return 0;
}