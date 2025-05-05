#include "ShrubberyCreationForm.hpp"
#include <fstream> 

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("ShrubberyCreationForm",145,137), _target("Dummy")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
: AForm("ShrubberyCreationForm",145,137), _target(target)
{
	std::cout << "ShrubberyCreationForm overload constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy)
:AForm(copy), _target(copy._target)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	std::cout <<  "Copy assigment operator for ShrubberyCreationForm Class called" << std::endl;
	if (this != &rhs)
	{
		_target = rhs._target;
	}
	return (*this);	
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void	ShrubberyCreationForm::executeForm() const
{
	static const char* ascii_tree =
	"                                                         .\n"
	"                                              .         ;  \n"
	"                 .              .              ;%     ;;   \n"
	"                   ,           ,                :;%  %;   \n"
	"                    :         ;                   :;%;'     .,   \n"
	"           ,.        %;     %;            ;        %;'    ,;\n"
	"             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
	"              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n"
	"               ;%;      %;        ;%;        % ;%;  ,%;'\n"
	"                `%;.     ;%;     %;'         `;%%;.%;'\n"
	"                 `:;%.    ;%%. %@;        %; ;@%;%'\n"
	"                    `:%;.  :;bd%;          %;@%;'\n"
	"                      `@%:.  :;%.         ;@@%;'   \n"
	"                        `@%.  `;@%.      ;@@%;         \n"
	"                          `@%%. `@%%    ;@@%;        \n"
	"                            ;@%. :@%%  %@@%;       \n"
	"                              %@bd%%%bd%%:;     \n"
	"                                #@%%%%%:;;\n"
	"                                %@@%%%::;\n"
	"                                %@@@%(o);  . '         \n"
	"                                %@@@o%;:(.,'         \n"
	"                            `.. %@@@o%::;         \n"
	"                               `)@@@o%::;         \n"
	"                                %@@(o)::;        \n"
	"                               .%@@@@%::;         \n"
	"                               ;%@@@@%::;.          \n"
	"                              ;%@@@@%%:;;;. \n"
	"                          ...;%@@@@@%%:;;;;,..    Gilo97\n";

	std::ofstream outFile;
	std::string filename = _target + "._shrubbery";
	outFile.open(filename.c_str());
	if (outFile.is_open())
	{
		outFile << ascii_tree;
		outFile.close();
	}
}