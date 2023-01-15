#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("prove", 145, 137)
{
//	std::cout << "[ShrubberyCreationForm] Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& name) : AForm(name, _grade_sign, _grade_exec)
{
//	std::cout << "[ShrubberyCreationForm] constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
: AForm(src.getName(), src.getGradeSign(), src.getGradeExec())
{
//	std::cout << "[ShrubberyCreationForm] Copy constructor called" << std::endl;
    *this = src;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
//	std::cout << "[ShrubberyCreationForm] Copy assignment constructor called" << std::endl;
    if (this != &src)
        this->setSign(src.getSign());
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
//	std::cout << "[ShrubberyCreationForm] Destructor called" << std::endl;
}

int ShrubberyCreationForm::execute(Bureaucrat const & executor)
{
	if (!getSign())
	{
		std::cout << "Form "<< getName() <<" is not signed so cannot be executed.\n";
	}
	else if (executor.getGrade() > getGradeExec())
	{
		std::cout << "Executor's grade is not high enough to execute " << getName() << std::endl;
	}
	else
	{
		std::ofstream ofs;
		ofs.open(getName());
		if (ofs.fail())
		{
			std::cout << "File create error\n";
			return (1);
		}
		ofs << "           *             ,\n"
			   "                       _/^\\_\n"
			   "                      <     >\n"
			   "     *                 /.-.\\         *\n"
			   "              *        `/&\\`                   *\n"
			   "                      ,@.*;@,\n"
			   "                     /_o.I %_\\    *\n"
			   "        *           (`'--:o(_@;\n"
			   "                   /`;--.,__ `')             *\n"
			   "                  ;@`o % O,*`'`&\\\n"
			   "            *    (`'--)_@ ;o %'()\\      *\n"
			   "                 /`;--._`''--._O'@;\n"
			   "                /&*,()~o`;-.,_ `\"\"`)\n"
			   "     *          /`,@ ;+& () o*`;-';\\\n"
			   "               (`\"\"--.,_0 +% @' &()\\\n"
			   "               /-.,_    ``''--....-'`)  *\n"
			   "          *    /@%;o`:;'--,.__   __.'\\\n"
			   "              ;*,&(); @ % &^;~`\"`o;@();         *\n"
			   "              /(); o^~; & ().o@*&`;&%O\\\n"
			   "              `\"=\"==\"\"==,,,.,=\"==\"===\"`\n"
			   "           __.----.(\\-''#####---...___...-----._\n"
			   "         '`         \\)_`\"\"\"\"\"`\n"
			   "                 .--' ')\n"
			   "               o(  )_-\\\n"
			   "                 `\"\"\"` `\n"
			   "\n";
		ofs.close();
		std::cout << getName() << " is executed" << std::endl;
		return (0);
	}
	return (1);
}