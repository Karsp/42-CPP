#include <iostream>


template <typename T, typename U> 
void iter(T *x, size_t size, const U& f)
{
	if (!x || !f)
		return ;
	for (size_t i = 0; i < size; i++)
	{
		f(x[i]);
	}
	
   
}
