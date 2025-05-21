#include <iostream>
#include <algorithm>


template <typename T> 
typename T::iterator easyfind(T *container, int key) 
{
	typename T::iterator *it;

	it = container.find(container.begin(), container.end(), key);
	if (it != container.end())
		return (it);
	throw std::out_of_range("Key not found.");


	// if (!x)
	// 	return ;

// 	int i = 0;
// 	for (size_t i = 0; i < arr.size(); ++i)
// 	{
// 		if (arr[i] == key)
// 			return i;
// 	}

// if (index >= _size)
// 		throw std::out_of_range("Array index out of range");
	
   
}
