#ifndef _Array_HPP
# define _Array_HPP

# include <iostream>
# include <exception>

template <typename T> class Array
{
	private:
		T *_elements;
		size_t _size;
		
	public:
	
		Array()
		{
			_elements = new T[1];
			_elements[0] = 0;
			_size = 0;
		};

		Array(unsigned int n)
		{
			T *a = new T[n + 1];
			for (size_t i = 0; i < n; i++)
			{
				a[i] = 0;
			}
			_elements = a;
			_size = n;
		};

		Array(Array const &other)
		{
			this->_size = other._size;
			this->_elements = new T[this->_size];
			for (size_t i = 0; i < this->_size; i++)
			{
				this->_elements[i] = other._elements[i];
			}
		};

		Array & operator=(Array const &rhs)
		{
			if (this != &rhs)
			{
				delete[] this->_elements;
				this->_elements = new T[rhs._size];
				for (size_t i = 0; i < rhs._size; i++)
				{
					this->_elements[i] = rhs._elements[i];
				}
				this->_size = rhs._size;
			} 
			return (*this);
		};

		~Array()
		{
			delete[] this->_elements;
		};

		T& operator[](size_t index) 
		{
			if (index >= _size)
			{
				throw std::runtime_error("fatal: index is out of bounds.");
			}
			return _elements[index];
		}

		size_t size() const 
		{
			return (_size);
		};
};



#endif
