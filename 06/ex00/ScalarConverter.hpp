#ifndef _ScalarConverter_HPP
# define _ScalarConverter_HPP

# include <iostream>
# include <limits>
# include <exception>
# include <cstdlib>
# include <limits.h> // for INT_MAX, INT_MIN
# include <iomanip> // for std::fixed and std::setprecision
# include <cfloat>    // for FLT_MAX, FLT_MIN
# include <cerrno> // for errno



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

		static void	printChar(std::string &input);
		static void	printInt(std::string &input);
		static void	printFloat(std::string &input);
		static void	printDouble(std::string &input);
		static void	printPseudoLiteral(std::string &input);
		static void	printUnknown();
		
		static char convertToChar(std::string &input);
		static int convertToInt(std::string &input);
		static float convertToFloat(std::string &input);
		static double convertToDouble(std::string &input);
		static std::string convertToPseudoLiteral(std::string &input);

		class	nonDisplayException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class	impossibleException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};



#endif
