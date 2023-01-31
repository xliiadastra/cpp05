#include "Intern.hpp"

AForm *Intern::makeForm(std::string const &name, std::string const &target) const
{
	std::string	formlist[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int 		index = 0;

	for (; formlist[index].compare(name) && index < 3; ++index) ;
	try
	{
		if (index < 3 && index >= 0)
			std::cout << "Intern creates " << name << std::endl;
		switch (index)
		{
			case 0:
				return new ShrubberyCreationForm(target);
			case 1:
				return new RobotomyRequestForm(target);
			case 2:
				return new PresidentialPardonForm(target);
		}
		throw NoFormExistException();
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	return (NULL);
}

Intern::Intern()
{
//	std::cout << "[Intern] Default constructor called\n";
}

Intern::Intern(const Intern &src)
{
//	std::cout << "[Intern] Copy constructor called\n";
	*this = src;
}

Intern& Intern::operator=(const Intern &src)
{
//	std::cout << "[Intern] Copy assignment operator called\n";
	static_cast<void>(src);
	return (*this);
}

Intern::~Intern()
{
	std::cout << "[Intern] Destructor called\n";
}

const char* Intern::NoFormExistException::what(void) const throw()
{
	return "No such name exists\n";
}
