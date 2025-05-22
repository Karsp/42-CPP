#include <iostream>
#include <algorithm>


template <typename T> 
typename T::iterator easyfind(T &container, int key) 
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), key);
	if (it == container.end())
		throw std::out_of_range("Key not found.");
	return (it);



   
}
