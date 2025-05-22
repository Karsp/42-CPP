#include <iostream>

// (*f)(U &)   //Restricts f to be a function pointer taking a U& parameter  //iter(arr, 4, &print);
// const U& f  //Call it with makes possible to call it from any callable object f via a const referente. //iter(arr, 4, &print<int>);
template <typename T, typename U> 
void iter(T *x, size_t size, const U& f)
{
	if (!x)
		return ;
	for (size_t i = 0; i < size; i++)
	{
		f(x[i]);
	}
	
   
}
