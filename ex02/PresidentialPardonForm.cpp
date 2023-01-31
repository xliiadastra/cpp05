#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PForm", 25, 5)
{
//	std::cout << "[PresidentialPardonForm] Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& name) : AForm(name, 25, 5)
{
//	std::cout << "[PresidentialPardonForm] constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src)
: AForm(src)
{
//	std::cout << "[PresidentialPardonForm] Copy constructor called" << std::endl;
//    *this = src;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
//	std::cout << "[PresidentialPardonForm] Copy assignment constructor called" << std::endl;
    if (this != &src)
        this->setSign(src.getSign());
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
//	std::cout << "[PresidentialPardonForm] Destructor called" << std::endl;
}

int PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!getSign())
	{
		std::cout << "Form "<< getName() <<" is not signed so cannot be executed.\n";
	}
	else if (executor.getGrade() > getGradeExec())
	{
		std::cout << "Executor's grade is not high enough to execute " << getName() << '\n';
	}
	else
	{
		std::cout << getName() << " has been pardoned by Zaphod Beeblebrox\n";
		return (0);
	}
	return (1);
}