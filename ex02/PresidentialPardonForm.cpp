#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("prove", 145, 137)
{
//	std::cout << "[PresidentialPardonForm] Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& name) : AForm(name, _grade_sign, _grade_exec)
{
//	std::cout << "[PresidentialPardonForm] constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src)
: AForm(src.getName(), src.getGradeSign(), src.getGradeExec())
{
//	std::cout << "[PresidentialPardonForm] Copy constructor called" << std::endl;
    *this = src;
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

int PresidentialPardonForm::execute(Bureaucrat const & executor)
{
}