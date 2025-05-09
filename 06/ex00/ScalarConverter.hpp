#ifndef _ScalarConverter_HPP
# define _ScalarConverter_HPP

# include <iostream>
# include <limits>

enum type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDOLIT,
	UNKNOWN
};

class ScalarConverter
{
	private:
		ScalarConverter();
		
	public:
		ScalarConverter(ScalarConverter const &copy);
		~ScalarConverter();

		ScalarConverter & operator=(ScalarConverter const &rhs);

		static void convert(std::string &input);

		static enum type checkType(std::string &input);
		static bool isChar(std::string &input);
		static bool isInt(std::string &input);
		static bool isFloat(std::string &input);
		static bool isDouble(std::string &input);
		static bool isPseudoLiteral(std::string &input);

};



#endif
