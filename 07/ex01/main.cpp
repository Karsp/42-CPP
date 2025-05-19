// #include "whatever.hpp"


#include <cstddef>
#include <iostream>

#include "iter.hpp"

class Test {
	private:
		int _age;
	public:
		Test();
		Test(const Test&);
		Test& operator=(const Test&);
		~Test();
		static void sayHello(Test&);
};

Test::~Test() {}

Test::Test()
	:_age(1)
{

	std::cout << "constructor called" << std::endl;
}

Test::Test(const Test& other) {
  *this = other;
}

Test& Test::operator=(const Test& rhs) {
  if (this != &rhs) this->_age = rhs._age;
  return *this;
}


void Test::sayHello(Test& a) {
	std::cout << "Hello!! I am " << a._age << " years old" << std::endl;
}

void	incr(int& n) {
	++n;
}

void print(int& n) {
  std::cout << n << " ";
}

int main() {
	int arr[4] = {1, 2, 3, 4};
	int i;

	std::cout << "=======================================================================" << std::endl;
	std::cout << "Lets start with a simple test, array of 4 integers => foreach increment" << std::endl;
	std::cout << "=======================================================================" << std::endl;
  	iter(arr, 4, &print);
	std::cout << std::endl;

	iter(arr, 4, &incr);

  iter(arr, 4, &print);
	std::cout << std::endl;


	std::cout << "=======================================================================" << std::endl;
	std::cout << "Now lets do something that is also quite generic, pass a null pointer" << std::endl;
	std::cout << "=======================================================================" << std::endl;

	iter((int*)NULL, 100, &incr);

	std::cout << "(no crash)" << std::endl;

	std::cout << "=======================================================================" << std::endl;
	std::cout << "Now, just for fun, lets create an array of instances of the Test class" << std::endl;
	std::cout << "=======================================================================" << std::endl;

	Test *t = new Test[5];
	iter(t, 5, &(t[i].sayHello));
}