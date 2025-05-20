#include <iostream>


template <typename T> 
void iter(T *x, size_t size, void (*f)(T &)) 
{
	if (!x || !f)
		return ;
	// if (size > x.size())
	// 	return ;
	for (size_t i = 0; i < size; i++)
	{
		f(x[i]);
	}
	
   
}
