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

#include"Dog.hpp"
#include"Cat.hpp"
#include"WrongCat.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;

std::cout <<  std::endl;

i->makeSound(); //will output the cat sound!
j->makeSound();  //will output the dog sound!
meta->makeSound();

std::cout <<  std::endl;

delete i;
delete j;
delete meta;


std::cout <<  std::endl;
std::cout << "Wrong animal test" << std::endl;

const WrongAnimal* wrongmeta = new WrongAnimal();
const WrongAnimal* not_i = new WrongCat();

std::cout <<  std::endl;

std::cout << not_i->getType() << " " << std::endl;
not_i->makeSound(); //will output the wrong animal sound!
wrongmeta->makeSound();

std::cout <<  std::endl;

delete not_i;
delete wrongmeta;

return 0;
}