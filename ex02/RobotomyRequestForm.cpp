#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("prove", 145, 137)
{
//	std::cout << "[RobotomyRequestForm] Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& name) : AForm(name, _grade_sign, _grade_exec)
{
//	std::cout << "[RobotomyRequestForm] constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
: AForm(src.getName(), src.getGradeSign(), src.getGradeExec())
{
//	std::cout << "[RobotomyRequestForm] Copy constructor called" << std::endl;
    *this = src;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
//	std::cout << "[RobotomyRequestForm] Copy assignment constructor called" << std::endl;
    if (this != &src)
        this->setSign(src.getSign());
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
//	std::cout << "[RobotomyRequestForm] Destructor called" << std::endl;
}

int RobotomyRequestForm::execute(Bureaucrat const & executor)
{
}